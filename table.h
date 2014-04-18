#ifndef Table_H
#define Table_H
#include "definitions.h"
#include <iostream>
#include <sstream>
#include "columna.h"
#include <list>
using namespace std; 
class Table : public DBElement{
private:
	list<Columna*> columnas;
	//id ID;
	size tamano;
	size direcionEnArchivo;
	//string nombre;
public:
	Table();
	Table(id,string,size,size);
	~Table();
	
	const id& GetID() const;
	void SetID(const id&);
	
	const size& GetTamano() const ; 
	void SetTamano(const size&);
	
	const size& GetDireccionArchivo();
	void SetDireccionArchivo(const size&);
	
	const std::string& GetNombre() const;
	void SetNombre(const std::string&);
	
	void serialize_this(ofstream&);
	static Table* deserialize_a_Table(ifstream&);
	
	void addColumn(Columna *);
	string toString();
	
	Columna* getByIndex(int);
	Columna* getByName(std::string);
	Columna* operator[](int);
};

#endif // Table
