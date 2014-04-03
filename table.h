#ifndef Table_H
#define Table_H
#include "definitions.h"
#include <iostream>
#include <sstream>
#include "columna.h"
#include <list>
using namespace std; 
class Table{
private:
	list<Columna*> columnas;
	id ID;
	size tamano;
	size direcionEnArchivo;
	string nombre;
public:
	Table();
	Table(id,string,size,size);
	~Table();
	const id GetID() const;
	void SetID(id _ID);
	const size& GetTamano() const ; 
	void SetTamano(const size& tamano);
	const size& GetDireccionArchivo();
	void SetDireccionArchivo(const size& Tam);
	const string& GetNombre();
	void SetNombre(const string& nombre);
	void serialize_this(ofstream& os);
	static Table* deserialize_a_Table(ifstream& is);
	void addColumn(Columna * colum);
	string toString();
};

#endif // Table
