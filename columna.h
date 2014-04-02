#ifndef COLUMNA_H
#define COLUMNA_H

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
	static enum Tipo_Dato {INTEGER, DOUBLE, STRING, BYTE};
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
	
	Columna();
	~Columna();

};

#endif // COLUMNA_H
