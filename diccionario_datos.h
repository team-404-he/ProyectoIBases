#ifndef DIC_DAT_H
#define DIC_DAT_H

#include <iostream>
#include <fstream>
#include "table_space.h"
#include "definitions.h"
#include "user.h"
#include <list>

using namespace std;
class DiccionarioDatos
{
	static DiccionarioDatos* ms_instance;

public:
	void deserialize();
	void serialize();
	void addTableSpace(TableSpace *);
	static DiccionarioDatos* Instance();
	std::list<TableSpace*>& getList();
	std::list<user*>& getUsersList();
	static void Release();
	
	void addUser(user*);
	TableSpace * getTBSByID(id);
	TableSpace * getTBSByName(std::string);
	user * getUserByID(id);
	user * getUserByName(std::string);

private:
	char * path;
	list<TableSpace*> tablaSpaces;
	list<user*> users;
	DiccionarioDatos();
	~DiccionarioDatos();

};

#endif // DIC_DAT_H
