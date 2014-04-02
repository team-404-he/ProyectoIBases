#include "table.h"

Table::Table()
{
}

Table::~Table()
{
}
const id Table::GetID() const{
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
void Table::SetDireccionArchivo(const size& tam){
	this->direcionEnArchivo=tam;
}
const string& Table::GetNombre(){
	return this->nombre;
}
void Table:: SetNombre(const string& nombre){
	this->nombre=nombre;
}

//list Table::GetColumnas(){
	//return this->columnas;
//}

void Table::serialize_this(ofstream & os){
	{
	SerializadorBinario::serialize(os,(long)this->ID);
	SerializadorBinario::serialize(os,this->nombre);
	this->tamano=columnas.size();
	SerializadorBinario::serialize(os,(long)this->tamano);
	SerializadorBinario::serialize(os,(long)this->direcionEnArchivo);
	SerializadorBinario::serialize(os,(long)this->columnas.size());
	for(list<Columna*>::iterator it=this->columnas.begin();it!=this->columnas.end();it++){
		(*it)->serialize_this(os);
	}
}
	
	}
Table* Table::deserialize_a_Table(ifstream& is){
	Table *table=new Table();
	table->SetID(SerializadorBinario::deserializeLong(is));
	table->SetNombre(SerializadorBinario::deserializeString(is));
	table->SetTamano(SerializadorBinario::deserializeLong(is));
	table->SetDireccionArchivo(SerializadorBinario::deserializeLong(is));
	long x = SerializadorBinario::deserializeLong(is);
	for(int i=0;i<x;i++){
		Columna* columna=Columna::deserialize_a_Column(is);
		table->addColumn(columna);
	}
	return table;
}
void Table::addColumn(Columna * colum){
	this->columnas.push_back(colum);
}