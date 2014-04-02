#include "columna.h"

Columna::Columna()
{}
Columna::~Columna()
{}

Columna::Columna(string _nom, size _tam, Tipo_Dato _tipo, size antecesor){
		this->nombre = _nom;
		this->tamano = _tam;
		this->tipo = _tipo;
		this->direcionEnArchivo = antecesor;
}
const id Columna::GetID() const{
		return this->ID;
}
void Columna::SetID(id _ID){
	this->ID = _id;
}
void Columna::SetTamano(const size& tamano){
	 this->tamano = tamano;
}
void Columna::SetTipo(const Tipo_Dato& tipo){
	 this->tipo = tipo;
}
const size& Columna::GetTamano() const {
		return this->tamano;
}
const Tipo_Dato& Columna::GetTipo() const{
		return this->tipo;
}
const size& Columna::GetDireccionArchivo(){
		return this->direcionEnArchivo;
}
void Columna::SetDireccionArchivo(const size& Tam){
		this->direcionEnArchivo = Tam;
}
void Columna::SetNombre(const string& nombre) {
	this->nombre = nombre;
}
const string& Columna::GetNombre() const {
	return nombre;
}

std::ostream& operator<<(std::ostream& os, const Columna& obj)
{
	os<<obj.GetID()<<obj.GetNombre()<<obj.GetTipo()<<obj.GetTamano()<<obj.GetDireccionArchivo();
  return os;
}
std::istream& operator>>(std::istream& is, T& obj)
{
  // read obj from stream
  if( /* no valid object of T found in stream */ )
    is.setstate(std::ios::failbit);
  return is;
}