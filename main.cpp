#include <iostream>
#include "diccionario_datos.h"
#include "definitions.h"
#include "writer.h"
#include "table.h"
#include "table_space.h"
#include "columna.h"

int main(int argc, char ** argv){
	DiccionarioDatos * dic = DiccionarioDatos::Instance();
	dic->deserialize();
	cout<<"Una Pequena implementacion en el Main, a causa de poco tiempo no pudimos Poner Una interfaz para usarlo"<<endl;
	cout<<"Digite la info para un registro de TB despues se muestran los Registros subsequentes\n si lo vuelve a ejecutar el registro esta ahi"<<endl;
	//int x;
	//dic->addUser(new user(0,0,"Johan","123pass",DBA));
	std::string TB_name;
	std::string T_name;
	std::string C_name;
	
	cout<<"Digite el Nombre del TableSpace"<<endl;
	cin>>TB_name;
	cout<<"Digite Nombre de la Tabla"<<endl;
	cin>>T_name;
	cout<<"Digite Nombre de la Columna"<<endl;
	cin>>C_name;
	cout<<endl;
	
	TableSpace * TB = new TableSpace(dic->getList().size(),TB_name, "tb0.dbf");
	Table * tabla = new Table(dic->getList().size(),T_name,0,0);
	TB->addTable(tabla);
	Columna * col = new Columna(C_name,BYTE,0);
	tabla->addColumn(col);
	dic->addTableSpace(TB);
	
	dic->serialize();
	cout<<"----------------Datos Actuales del Diccionario--------------------"<<endl;

	list<TableSpace*>::iterator it;
	for(it = dic->getList().begin(); it != dic->getList().end(); it++)
		cout<<(*it)->toString()<<endl;
	
	/*TableSpace * tb = new TableSpace(0,"TBS");
	Table * t = new Table(0,"unNOmbre",0,0);
	t->addColumn(new Columna("hue",BYTE,0));
	tb->addTable(t);
	DiccionarioDatos * dic = DiccionarioDatos::Instance();
	dic->addTableSpace(tb);
	dic->serialize();
	DiccionarioDatos * dic = DiccionarioDatos::Instance();
	dic->deserialize();
	cout<<dic->getList().size()<<endl;
	TableSpace * t = dic->getList().front();
	cout<<t->GetID()<<endl<<t->GetNombre();
	cin.get();*/
	cin.get();
}