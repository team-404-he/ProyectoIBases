#ifndef TABLESPACE_H
#define TABLESPACE_H

#include <list>

class TableSpace
{
	list<Tabla*> tablas;
public:
	TableSpace();
private:
	~TableSpace();

};

#endif // TABLESPACE_H
