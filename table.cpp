#include "table.h"

Table::Table()
{
}

Table::~Table()
{
}
const Table::id GetID() const{
		return this->ID;
} 
void Table::SetID(id _ID){
	this->ID=_ID;
}	
const size& Table:: GetTamano() const{
	return this->tamano;
} 
void Table::SetTamano(const size& tamano){
	this->tamano=tamano;
}
const size& Table:: GetDireccionArchivo(){
	return this->direcionEnArchivo;
}
void Table::SetDireccionArchivo(const size& Tam){
	this->direcionEnArchivo;=tam;
}
const string& Table::GetNombre(){
	return this->nombre;
}
void Table:: SetNombre(const string& nombre){
	this->nombre=nombre;
}

list Table::GetColumnas(){
	return this->columnas;
}