#ifndef COLUMNA_H
#define COLUMNA_H
#include "SerializadorBinario.h"
#include "definitions.h"
#include "DBElement.h"
#include <sstream>

class Columna: public DBElement
{
private:
	//id ID;
	//string nombre;
	size tamano;
	Tipo_Dato tipo;
	//Tentativamente
	size direcionEnArchivo;
public:
	
	Columna(string _nom, Tipo_Dato _tipo, size antecesor);
	const id& GetID() const;
	void SetID(const id& _ID);
	void SetTamano(const size& tamano);
	void SetTipo(const Tipo_Dato& tipo);
	const size& GetTamano() const ;
	const Tipo_Dato& GetTipo() const;
	const size& GetDireccionArchivo();
	void SetDireccionArchivo(const size& Tam);
	void SetNombre(const string& nombre);
	const string& GetNombre() const;
	void serialize_this(ofstream &);
	static Columna* deserialize_a_Column(ifstream& is);
	string toString();
	Columna();
	~Columna();
	
	int sizeDT(Tipo_Dato t){
		switch(t){
			case BYTE:
				return sizeof(char);
			case DOUBLE:
				return sizeof(float);
			case INTEGER:
				return sizeof(int);
			case STRING:
				return sizeof(char[128]);
	}
	return 0;
}

};

#endif // COLUMNA_H
