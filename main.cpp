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

using namespace std;
int main(int argc, char ** argv){
	DiccionarioDatos * dic = DiccionarioDatos::Instance();
	dic->deserialize();
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
	vector<int> v1(1);
	v1[0] = 0;
	v[0] = new DataCarrier<int>(15,0,INTEGER);
	TableSpace * tbs = dic->getTBSByID(0);
	string name = "Tabla2";
	Table * tb = tbs->findByName(name);
	DBSystem::INSERT(tbs,tb,v,v1);
	
	dic->serialize();
	//cin.get();*/
}