#include "columna.h"


Columna::Columna()
{
		this->ID = 0l;
		this->nombre = "";
		this->tipo = BYTE;
		this->tamano = 0l;
		this->direcionEnArchivo = 0l;
}
Columna::~Columna()
{}

Columna::Columna(string _nom, Tipo_Dato _tipo, size antecesor){
		this->nombre = _nom;
		this->tamano = sizeDT(_tipo);
		this->tipo = _tipo;
		this->direcionEnArchivo = antecesor;
		this->ID = 0l;
}
const id Columna::GetID() const{
		return this->ID;
}
void Columna::SetID(id _ID){
	this->ID = _ID;
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

void Columna::serialize_this(ofstream & os)
{
	SerializadorBinario::serialize(os,(long)this->ID);
	SerializadorBinario::serialize(os,this->nombre);
	SerializadorBinario::serialize(os, static_cast<int>(this->tipo));
	SerializadorBinario::serialize(os,(long)this->tamano);
	SerializadorBinario::serialize(os,(long)this->direcionEnArchivo);
}
Columna* Columna::deserialize_a_Column(ifstream& is){
	Columna * c = new Columna;
	c->SetID(SerializadorBinario::deserializeLong(is));
	c->SetNombre(SerializadorBinario::deserializeString(is));
	c->SetTipo(static_cast<Tipo_Dato>(SerializadorBinario::deserializeInt(is)));
	c->SetTamano(SerializadorBinario::deserializeLong(is));
	c->SetDireccionArchivo(SerializadorBinario::deserializeLong(is));
	return c;
}

string Columna::toString(){
		stringstream ss;
		ss<<" \t Columna: "<<this->nombre<<" ID "<<this->ID;
		return ss.str();
}