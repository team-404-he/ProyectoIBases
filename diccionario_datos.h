
#ifndef DIC_DAT_H
#define DIC_DAT_H

#include <list>
using namespace std;
class DiccionarioDatos
{
	static DiccionarioDatos* ms_instance;

public:
	static DiccionarioDatos* Instance();
	static void Release();

private:
	list<TableSpace*> tablaSpaces;
	DiccionarioDatos();
	~DiccionarioDatos();

};

#endif // DIC_DAT_H
