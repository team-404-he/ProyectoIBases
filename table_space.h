#ifndef TABLESPACE_H
#define TABLESPACE_H

#include "definitions.h"
#include "table.h"
#include "SerializadorBinario.h"
#include <list>
using namespace std;

class TableSpace
{
	
public:
	TableSpace();
	TableSpace(id _id, string _nombre);
	void addTable(Table *);
	void removeTable(id);
	void removeTable(Table *);
	void serializate_this(ofstream&);
	static TableSpace* deserialize_a_TableSpace(ifstream&);
	
	void SetID(const id& ID);
	void SetNombre(const string& nombre);
	void SetTamano(const size& tamano);
	const id& GetID() const;
	const string& GetNombre() const;
	const size& GetTamano() const;
	id ID;
	string nombre;
	size tamano;
	std::list<Tabla*> tablas;

	~TableSpace();

};

#endif // TABLESPACE_H
