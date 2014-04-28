#include <iostream>
#include "diccionario_datos.h"
#include "definitions.h"
#include "writer.h"
#include "table.h"
#include "table_space.h"
#include "columna.h"
#include "data_carrier.h"
#include "db_system.h"
#include <vector>
#include "any.h"
#include "data_set.h"
#include "sesion_actual.h"

using namespace std;
int main(int argc, char ** argv){
	DiccionarioDatos * dic = DiccionarioDatos::Instance();
	dic->deserialize();
	
	SesionActual * sesion = SesionActual::Instance();
	
	/*TableSpace * tb = new TableSpace(0,"TB0","TB0.dbf");
	Table* t = new Table(0,"Tabla0",0,0);
	Table* t2 = new Table(1,"Tabla2",0,0);
	t->addColumn(new Columna(t->GetTamano(),"col0",INTEGER,0));
	t->addColumn(new Columna(t->GetTamano(),"col1",STRING,0));
	tb->addTable(t);
	t2->addColumn(new Columna(t2->GetTamano(),"col0",BYTE,0));
	tb->addTable(t2);
	dic->addTableSpace(tb);*/
	/*dic->serialize();*/
	vector<Any*> v (1);
	v[0] = new DataCarrier<std::string>("JOHAN",0,STRING);
	
	vector<int> v1(2);
	v1[0] = 0;
	v1[1] = 1;
	TableSpace * tbs = dic->getTBSByID(0);
	string name = "Tabla0";
	Table * tb = tbs->findByID(0);
	/*for(int i = 0; i < 15; i++){
		stringstream ss;
		v[0] = new DataCarrier<int>(i,0,INTEGER);
		ss<<"Registro: "<<i;
		v[1] = new DataCarrier<std::string>(ss.str(),0,STRING);
		DBSystem::INSERT(tbs,tb,v,v1);
		delete v[0];
		delete v[1];
	}
	//DBSystem::INSERT(tbs,tb,v,v1);*/
	where x;
	x.aplicar = false;
	where w;
	w.aplicar = true;
	w.field_a = 0;
	w.val_a = new DataCarrier<int>(5,0,INTEGER);
	w.operation = MAYOR;
	w.tipo = VALOR;
	
	dataSet* dts = DBSystem::SELECT(tbs, tb,v1, x);
	cout<<dts->toString();
	
	delete dts;
	vector<int> f(1);
	f[0] = 1;
	DBSystem::UPDATE(tbs,tb,v,f,w);
	dts = DBSystem::SELECT(tbs, tb,v1, x);
	cout<<dts->toString();
	
	delete dts; 
	
	dic->serialize();
	delete w.val_a;
	//cin.get();*/
}