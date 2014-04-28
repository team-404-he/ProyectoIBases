#ifndef OPS_DB_H
#define OPS_DB_H

#include "diccionario_datos.h"
#include "user.h"
#include "db_system.h"
#include "data_set.h"
#include "sesion_actual.h"
#include "definitions.h"
#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Operaciones
{
public:
	Operaciones();
	~Operaciones();
	
	void menuPrincipal();
	bool createTableSpace();
	bool createTable();
	bool createUser();
	bool insertInto();
	bool selectFrom();
	bool updateFields();
	bool deleteField();

};

#endif // OPS_DB_H
