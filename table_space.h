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
	TableSpace(id _id, string _nombre, std::string _path);
	void addTable(Table *);
	void removeTable(id);
	void removeTable(Table *);
	void serializate_this(ofstream&);
	string toString();
	
	static TableSpace* deserialize_a_TableSpace(ifstream&);
	
	void SetID(const id& ID);
	void SetNombre(const string& nombre);
	void SetTamano(const size& tamano);
	void SetPath(std::string _path);
	const std::string& GetPath() const;
	const id& GetID() const;
	const string& GetNombre() const;
	const size& GetTamano() const;
//-------------------------------------------------
	Table* findByName(std::string& name);
	Table* findByID(size _id);
private:
	
	id ID;
	string nombre;
	string path;
	size tamano;
	std::list<Table*> tablas;

	~TableSpace();

};

#endif // TABLESPACE_H
