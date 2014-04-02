
#ifndef DIC_DAT_H
#define DIC_DAT_H
#include <iostream>
#include <fstream>
#include "table_space.h"
#include "definitions.h"
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
	static void Release();

private:
	char * path;
	list<TableSpace*> tablaSpaces;
	DiccionarioDatos();
	~DiccionarioDatos();

};

#endif // DIC_DAT_H
