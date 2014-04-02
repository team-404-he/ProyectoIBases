#ifndef COLUMNA_H
#define COLUMNA_H
#include "SerializadorBinario.h"
#include "definitions.h"
class Columna
{
private:
	id ID;
	string nombre;
	size tamano;
	Tipo_Dato tipo;
	//Tentativamente
	size direcionEnArchivo;
public:
	
	Columna(string _nom, size _tam, Tipo_Dato _tipo, size antecesors);
	const id GetID() const;
	void SetID(id _ID);
	void SetTamano(const size& tamano);
	void SetTipo(const Tipo_Dato& tipo);
	const size& GetTamano() const ;
	const Tipo_Dato& GetTipo() const;
	const size& GetDireccionArchivo();
	void SetDireccionArchivo(const size& Tam);
	void SetNombre(const string& nombre);
	const string& GetNombre();
	void serialize_this(ofstream &);
	static Columna* deserialize_a_Column(ifstream& is);
	Columna();
	~Columna();

};

#endif // COLUMNA_H
