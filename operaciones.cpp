#include "operaciones.h"

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
		}
		else cout<<"Opcion No valida\n";
		if(welldef) {
			string str;
			cout<<"mas Columnas s/n ?\n";
			cin>>str;
			if(str[0] == 's' || str[0] == 'S') mas = true;
			else mas = false;
		} else cout<<"mal definida la columna\n";
	} while(mas);
	DiccionarioDatos::Instance()->serialize();
}
bool Operaciones::createUser() {
	DiccionarioDatos * dic = DiccionarioDatos::Instance();
	TableSpace * tb;
	string nombre, pass, tbname;
	cout<<"Digite Nombre\n";
	cin>>nombre;
	cout<<"Digite pass\n";
	cin>>pass;
	cout<<"Digite el Nombre del TableSpace Asociado, puede Usar TB0 para default\n";
	cin>>tbname;
	while((tb=dic->getTBSByName(tbname)) == NULL){
		cout<<"Digite el Nombre del TableSpace Asociado, puede Usar TB0 para default\n";
		cin>>tbname;
	}
	user * u = new user(0,tb->GetID(),nombre,pass,DBA);
	dic->addUser(u);
	dic->serialize();
}
bool Operaciones::insertInto() {}
bool Operaciones::selectFrom() {}
bool Operaciones::updateFields() {}
bool Operaciones::deleteField() {}
