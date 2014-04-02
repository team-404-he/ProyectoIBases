#include "table_space.h"

TableSpace::TableSpace()
{
	this->ID = 0;
	this->nombre = "";
	this->tamano = 0l
}

TableSpace::~TableSpace()
{
}
TableSpace::TableSpace(id _id, string nombre):ID(_id), nombre(_nombre){
		this->tamano = 0;
}
void TableSpace::addTable(Table * t){
	this->tablas.push_back(t);
}
void TableSpace::removeTable(id){
	typedef list<Table*>::iterator iter;
	for(iter i = this->tablas.begin(); i != tablas.end() ; i++){
		if( id == (*i)->id){
			tablas.erase(i)
			return;
		}
}
void TableSpace::removeTable(Table *){
			typedef list<Table*>::iterator iter;
	for(iter i = this->tablas.begin(); i != tablas.end() ; i++){
		if(id == (*i)){
			tablas.erase(i)
			return;
		}
}
void TableSpace::serializate_this(ofstream& os){
	
	typedef list<Table*>::iterator iter;	
	SerializadorBinario::serialize(os,this->ID);
	SerializadorBinario::serialize(os,this->nombre);
	SerializadorBinario::serialize(os,this->tamano);
	SerializadorBinario::serialize(os,(long)this->tablas->size());
		
	for(iter i = this->tablas.begin(); i != tablas.end() ; i++){
		(*i)->serializate_this(os);
}
TableSpace* TableSpace::deserialize_a_TableSpace(ifstream& is){
		TableSpace * t = new TableSpace();
		t->SetID(SerializadorBinario::deserializeLong(is));
		t->SetNombre(SerializadorBinario::deserializeString(is));
		t->SetTamano(SerializadorBinario::deserializeLong(is));
		long x = SerializadorBinario::deserializeInt(is);
		for(long h = 0; h < x ; h++){
			this->addTable(Table::deserialize_a_table(is));
		}
		return t;
}

void TableSpace::SetID(const id& ID) 
{this->ID = ID;}
void TableSpace::SetNombre(const string& nombre)
 {this->nombre = nombre;}
void TableSpace::SetTamano(const size& tamano) 
{this->tamano = tamano;}
const id& TableSpace::GetID() const 
{return ID;}
const string& TableSpace::GetNombre() const 
{return nombre;}
const size& TableSpace::GetTamano() const {
	return this->tamano;
}