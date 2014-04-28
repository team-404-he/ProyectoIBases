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
#include "operaciones.h"
#include "login.h"

using namespace std;
int main(int argc, char ** argv){
	DiccionarioDatos * dic = DiccionarioDatos::Instance();
	dic->deserialize();
	
	if(dic->getList().size() == 0)
			dic->addTableSpace(new TableSpace(0,"TB0","TBO.dbf"));
	if(dic->getUserByID(0) == NULL)
			dic->addUser(new user(0,0,"DBA","1234",DBA));
	cout<<"Default User DBA pass 1234\n";
	dic->serialize();
	SesionActual * sesion = SesionActual::Instance();
	Login::Instance()->log();
	Operaciones op;
	op.menuPrincipal();
	

	dic->serialize();
	
	//cin.get();*/
}