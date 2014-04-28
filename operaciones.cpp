#include "operaciones.h"
void recojerValor(Tipo_Dato td, where & w)
{
	char c;
	int i;
	long l;
	double d;
	string s;
	switch(td) {
	case BYTE:
		cout<<"Digite el Valor char\n";
		cin>>c;
		w.val_a = new DataCarrier<char>(c,0,BYTE);
		break;
	case INTEGER:
		cout<<"Digite el Valor Int\n";
		cin>>i;
		w.val_a = new DataCarrier<int>(i,0,INTEGER);
		break;
	case LONG:
		cout<<"Digite el Valor Long\n";
		cin>>l;
		w.val_a = new DataCarrier<long>(l,0,LONG);
		break;
	case DOUBLE:
		cout<<"Digite el Valor double\n";
		cin>>d;
		w.val_a = new DataCarrier<double>(d,0,DOUBLE);
		break;
	case STRING:
		cout<<"Digite el Valor Strring\n";
		cin>>s;
		w.val_a = new DataCarrier<string>(s,0,STRING);
		break;
	}
}
Operaciones::Operaciones()
{
}

Operaciones::~Operaciones()
{
}


void Operaciones::menuPrincipal()
{
	bool salir = false;
	SesionActual* sesion = SesionActual::Instance();
	string opc;
	cout<<"Usuario Actual "<<sesion->GetUserActual()->GetNombre()<<endl;
	cout<<"TableSpace: "<<sesion->GetTbActual()->GetNombre()<<endl<<endl;
	while(!salir) {
		cout<<"Que desea Hacer ?"<<endl
		    <<"1 Crear TableSpace \n"
		    <<"2 Crear Usuario \n"
		    <<"3 Crear Tabla \n"
		    <<"4 Insertar \n"
		    <<"5 Selecionar \n"
		    <<"6 Actualizar \n"
		    <<"7 Borrar \n"
		    <<"8 Salir\n";
		cin>>opc;
		switch(opc[0]) {
		case '1':
			createTableSpace();
			break;
		case '2':
			createUser();
			break;
		case '3':
			createTable();
			break;
		case '4':
			this->insertInto();
			break;
		case '5':
			this->selectFrom();
			break;
		case '6':
			this->updateFields();
			break;
		case '7':
			this->deleteField();
			break;
		case '8':
			salir = true;
			break;

		};
	}
}
bool Operaciones::createTableSpace()
{
	string nombre, path;
	long id;
	cout<<"Digite Nombre\n";
	cin>>nombre;
	stringstream ss;
	ss<<nombre<<".dbf";
	id = DiccionarioDatos::Instance()->getList().size();
	DiccionarioDatos::Instance()->addTableSpace(new TableSpace(id,nombre,ss.str()));
	cout<<"Creado Correctamente\n";
	DiccionarioDatos::Instance()->serialize();
	cout<<"TBS created\n";
	return true;
}
bool Operaciones::createTable()
{
	string nombre, colname;
	bool mas;
	cout<<"Digite Nombre\n";
	cin>>nombre;
	Table * tb = new Table(0,nombre,0,0);
	SesionActual::Instance()->GetTbActual()->addTable(tb);
	cout<<"id de tabla en este TBS: "<<tb->GetID()<<"\n";
	do {
		bool welldef;
		int tpd;
		cout<<"Nombre de Columna: ";
		cin>>colname;
		cout<<"Tipo columna: \n"
		    <<INTEGER<<" Int \n"
		    <<LONG<<" long \n"
		    <<DOUBLE<<" double \n"
		    <<STRING<<" string \n"
		    <<BYTE<<" char \n";
		cin>>tpd;
		if(tpd>=0 && tpd < 5) {
			Tipo_Dato tdato = (Tipo_Dato)tpd;
			Columna* col = new Columna(0,colname,tdato,0);
			tb->addColumn(col);
			welldef = true;
		} else cout<<"Opcion No valida\n";
		if(welldef) {
			string str;
			cout<<"mas Columnas s/n ?\n";
			cin>>str;
			if(str[0] == 's' || str[0] == 'S') mas = true;
			else mas = false;
		} else cout<<"mal definida la columna\n";
	} while(mas);
	DiccionarioDatos::Instance()->serialize();
	cout<<"table Created\n";
	return true;
}
bool Operaciones::createUser()
{
	DiccionarioDatos * dic = DiccionarioDatos::Instance();
	TableSpace * tb;
	string nombre, pass, tbname;
	cout<<"Digite Nombre\n";
	cin>>nombre;
	cout<<"Digite pass\n";
	cin>>pass;
	cout<<"Digite el Nombre del TableSpace Asociado, puede Usar TB0 para default\n";
	cin>>tbname;
	while((tb=dic->getTBSByName(tbname)) == NULL) {
		cout<<"Digite el Nombre del TableSpace Asociado, puede Usar TB0 para default\n";
		cin>>tbname;
	}
	user * u = new user(0,tb->GetID(),nombre,pass,DBA);
	cout<<"User Created\n";
	dic->addUser(u);
	dic->serialize();
	return true;
}
bool Operaciones::insertInto()
{
	vector<Any*> data(50);
	vector<int> campos(50);
	bool mas = true;
	map<int,Any*> relcampos;
	Table * tabla;
	string tbname, cname;
	int j = 0;
	cout<<"Digite el Nombre de la tabla\n";
	cin>>tbname;
	if( (tabla = SesionActual::Instance()->GetTbActual()->findByName(tbname)) == NULL) {
		cout<<"No Existe Tabla\n";
		return false;
	}
	cout<<"Campos de la tabla:\n";
	for(int x = 0; x<tabla->GetTamano(); x++)
		cout<<(*tabla)[x]->GetNombre()<<" ";
	cout<<"\n";

	while(mas) {
		int i;
		long l;
		char c;
		double d;
		string s;
		cout<<"Digite el campo\n";
		cin>>cname;
		Columna * f = tabla->getByName(cname);
		if(f == NULL)
			cout<<f<<" No es un campo de la tabla\n";
		else {
			switch(f->GetTipo()) {
			case BYTE:
				cout<<"Digite un Char\n";
				cin>>c;
				relcampos[f->GetID()] = new DataCarrier<char>(c,0,BYTE);
				campos[j++] = f->GetID();
				break;
			case INTEGER:
				cout<<"Digite un Entero\n";
				cin>>i;
				relcampos[f->GetID()] = new DataCarrier<int>(i,0,INTEGER);
				campos[j++] = f->GetID();
				break;
			case LONG:
				cout<<"Digite un LONG\n";
				cin>>l;
				relcampos[f->GetID()] = new DataCarrier<long>(l,0,LONG);
				campos[j++] = f->GetID();
				break;
			case DOUBLE:
				cout<<"Digite un Flotante\n";
				cin>>d;
				relcampos[f->GetID()] = new DataCarrier<double>(d,0,DOUBLE);
				campos[j++] = f->GetID();
				break;
			case STRING:
				cout<<"Digite un STRING menor a 128\n";
				cin>>s;
				relcampos[f->GetID()] = new DataCarrier<string>(s,0,STRING);
				campos[j++] = f->GetID();
				break;
			}
		}
		if(j < tabla->GetTamano()) {
			string ss;
			cout<<"Otro campo s/n ?\n";
			cin>>ss;
			if(ss[0] == 's' || ss[0] == 'S') mas = true;
			else mas = false;
		} else mas = false;
	}
	campos.resize(j);
	data.resize(j);
	sort(campos.begin(),campos.end());
	for(int n=0; n< campos.size(); n++) {
		data[n] = relcampos[campos[n]];
	}
	cout<<DBSystem::INSERT(SesionActual::Instance()->GetTbActual(),tabla,data,campos)<<endl;
	return true;
}
bool Operaciones::selectFrom()
{
	dataSet * dts;
	where w;
	vector<int> campos(50);
	bool mas = true;
	Table * tabla;
	string tbname, cname;
	int j = 0;
	cout<<"Digite el Nombre de la tabla\n";
	cin>>tbname;
	if( (tabla = SesionActual::Instance()->GetTbActual()->findByName(tbname)) == NULL) {
		cout<<"No Existe Tabla\n";
		return false;
	}
	cout<<"Campos de la tabla:\n";
	for(int x = 0; x<tabla->GetTamano(); x++)
		cout<<(*tabla)[x]->GetNombre()<<" ";
	cout<<"\n";

	while(mas) {
		cout<<"Digite el campo\n";
		cin>>cname;
		Columna * f = tabla->getByName(cname);
		if(f == NULL)
			cout<<f<<" No es un campo de la tabla\n";
		else {
			campos[j++] = f->GetID();
		}
		if(j < tabla->GetTamano()) {
			string ss;
			cout<<"Otro campo s/n ?\n";
			cin>>ss;
			if(ss[0] == 's' || ss[0] == 'S') mas = true;
			else mas = false;
		} else mas = false;
	}
	string cw;
	campos.resize(j);
	sort(campos.begin(),campos.end());
	cout<<"Desea Incluir una clausula Where s/n ?\n";
	cin>>cw;
	if(cw[0] == 's' || cw[0] == 'S') {
		string fffield;
		int tc;
		Columna * colw = NULL;
		Columna * colx = NULL;
		while(colw == NULL) {
			cout<<"Indique el primer campo del where (como en WHERE a == 2, el a)\n";
			cin>>fffield;
			colw = tabla->getByName(fffield);
			if(colw == NULL) cout<<fffield<<" No es un campo de la tabla\n";
			else w.field_a = colw->GetID();
		}
		cout<<"1)si desea Compararlo contra otro campo, 2) si desea Compararlo contra un valor\n";
		cin>>tc;
		if(tc==1) {
			w.tipo = CAMPO;
			while(colx == NULL) {
				cout<<"Indique el segundo campo a comprar (como en WHERE a == b, el b)\n";
				cin>>fffield;
				colx = tabla->getByName(fffield);
				if(colx == NULL) cout<<fffield<<" No es un campo de la tabla\n";
				else w.field_b = colx->GetID();
			}
		} else {
			w.tipo = VALOR;
			recojerValor(colw->GetTipo(),w);
		}
		int t_op;
		cout<<"Que Operacion Desea\n"
		    <<MENOR<<" Menor\n"
		    <<MAYOR<<" Mayor\n"
		    <<IGUAL<<" IGUal\n"
		    <<DIFERENTE<<" Diferente\n";
		cin>>t_op;
		w.operation = (char)t_op;
		//delete colw; delete colx;
	} else w.aplicar = false;

	dts = DBSystem::SELECT(SesionActual::Instance()->GetTbActual(),tabla,campos,w);
	cout<<dts->toString();
	delete dts;
	return true;
}
bool Operaciones::updateFields()
{
	where w;
	vector<Any*> data(50);
	vector<int> campos(50);
	bool mas = true;
	map<int,Any*> relcampos;
	Table * tabla;
	string tbname, cname, cw;
	int j = 0;
	cout<<"Digite el Nombre de la tabla\n";
	cin>>tbname;
	if( (tabla = SesionActual::Instance()->GetTbActual()->findByName(tbname)) == NULL) {
		cout<<"No Existe Tabla\n";
		return false;
	}
	cout<<"Campos de la tabla:\n";
	for(int x = 0; x<tabla->GetTamano(); x++)
		cout<<(*tabla)[x]->GetNombre()<<" ";
	cout<<"\n";

	while(mas) {
		int i;
		long l;
		char c;
		double d;
		string s;
		cout<<"Digite el campo\n";
		cin>>cname;
		Columna * f = tabla->getByName(cname);
		if(f == NULL)
			cout<<f<<" No es un campo de la tabla\n";
		else {
			switch(f->GetTipo()) {
			case BYTE:
				cout<<"Digite un Char\n";
				cin>>c;
				relcampos[f->GetID()] = new DataCarrier<char>(c,0,BYTE);
				campos[j++] = f->GetID();
				break;
			case INTEGER:
				cout<<"Digite un Entero\n";
				cin>>i;
				relcampos[f->GetID()] = new DataCarrier<int>(i,0,INTEGER);
				campos[j++] = f->GetID();
				break;
			case LONG:
				cout<<"Digite un LONG\n";
				cin>>l;
				relcampos[f->GetID()] = new DataCarrier<long>(l,0,LONG);
				campos[j++] = f->GetID();
				break;
			case DOUBLE:
				cout<<"Digite un Flotante\n";
				cin>>d;
				relcampos[f->GetID()] = new DataCarrier<double>(d,0,DOUBLE);
				campos[j++] = f->GetID();
				break;
			case STRING:
				cout<<"Digite un STRING menor a 128\n";
				cin>>s;
				relcampos[f->GetID()] = new DataCarrier<string>(s,0,STRING);
				campos[j++] = f->GetID();
				break;
			}
		}
		if(j < tabla->GetTamano()) {
			string ss;
			cout<<"Otro campo s/n ?\n";
			cin>>ss;
			if(ss[0] == 's' || ss[0] == 'S') mas = true;
			else mas = false;
		} else mas = false;
	}
	cout<<"Desea Incluir una clausula Where s/n ?\n";
	cin>>cw;
	if(cw[0] == 's' || cw[0] == 'S') {
		w.aplicar = true;
		string fffield;
		int tc;
		Columna * colw = NULL;
		Columna * colx = NULL;
		while(colw == NULL) {
			cout<<"Indique el primer campo del where (como en WHERE a == 2, el a)\n";
			cin>>fffield;
			colw = tabla->getByName(fffield);
			if(colw == NULL) cout<<fffield<<" No es un campo de la tabla\n";
			else w.field_a = colw->GetID();
		}
		cout<<"1)si desea Compararlo contra otro campo, 2) si desea Compararlo contra un valor\n";
		cin>>tc;
		if(tc==1) {
			w.tipo = CAMPO;
			while(colx == NULL) {
				cout<<"Indique el segundo campo a comprar (como en WHERE a == b, el b)\n";
				cin>>fffield;
				colx = tabla->getByName(fffield);
				if(colx == NULL) cout<<fffield<<" No es un campo de la tabla\n";
				else w.field_b = colx->GetID();
			}
		} else {
			w.tipo = VALOR;
			recojerValor(colw->GetTipo(),w);
		}
		int t_op;
		cout<<"Que Operacion Desea\n"
		    <<MENOR<<" Menor\n"
		    <<MAYOR<<" Mayor\n"
		    <<IGUAL<<" IGUal\n"
		    <<DIFERENTE<<" Diferente\n";
		cin>>t_op;
		w.operation = (char)t_op;
		//delete colw; delete colx;
	} else w.aplicar = false;
	campos.resize(j);
	data.resize(j);
	sort(campos.begin(),campos.end());
	for(int n=0; n< campos.size(); n++) {
		data[n] = relcampos[campos[n]];
	}
	cout<<DBSystem::UPDATE(SesionActual::Instance()->GetTbActual(),tabla,data,campos,w)<<"\n";
	return true;

}
bool Operaciones::deleteField()
{
	where w;
	Table * tabla;
	string tbname, cw;
	cout<<"Digite el Nombre de la tabla\n";
	cin>>tbname;
	if( (tabla = SesionActual::Instance()->GetTbActual()->findByName(tbname)) == NULL) {
		cout<<"No Existe Tabla\n";
		return false;
	}
	cout<<"Desea Incluir una clausula Where s/n ?\n";
	cin>>cw;
	if(cw[0] == 's' || cw[0] == 'S') {
		string fffield;
		int tc;
		Columna * colw = NULL;
		Columna * colx = NULL;
		while(colw == NULL) {
			cout<<"Indique el primer campo del where (como en WHERE a == 2, el a)\n";
			cin>>fffield;
			colw = tabla->getByName(fffield);
			if(colw == NULL) cout<<fffield<<" No es un campo de la tabla\n";
			else w.field_a = colw->GetID();
		}
		cout<<"1)si desea Compararlo contra otro campo, 2) si desea Compararlo contra un valor\n";
		cin>>tc;
		if(tc==1) {
			w.tipo = CAMPO;
			while(colx == NULL) {
				cout<<"Indique el segundo campo a comprar (como en WHERE a == b, el b)\n";
				cin>>fffield;
				colx = tabla->getByName(fffield);
				if(colx == NULL) cout<<fffield<<" No es un campo de la tabla\n";
				else w.field_b = colx->GetID();
			}
		} else {
			w.tipo = VALOR;
			recojerValor(colw->GetTipo(),w);
		}
		int t_op;
		cout<<"Que Operacion Desea\n"
		    <<MENOR<<" Menor\n"
		    <<MAYOR<<" Mayor\n"
		    <<IGUAL<<" IGUal\n"
		    <<DIFERENTE<<" Diferente\n";
		cin>>t_op;
		w.operation = (char)t_op;
		//delete colw; delete colx;
	} else w.aplicar = false;
	cout<<DBSystem::DELETE(SesionActual::Instance()->GetTbActual(),tabla,w)<<"\n";
	return true;
}
