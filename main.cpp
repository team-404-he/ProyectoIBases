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
	vector<Any*> v (1);
	vector<int> v1(1);
	v1[0] = 1;
	v[0] = new DataCarrier<int>(1,0,INTEGER);
	TableSpace * tbs = dic->getTBSByID(0);
	Table * tb = tbs->findByID(0);
	
	DBSystem::INSERT(tbs,tb,v,v1);
	//cin.get();
}