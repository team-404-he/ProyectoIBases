#include "table.h"

Table::Table(id _id,string _nom,size _tam,size _dir){
	this->ID = _id;
	this->nombre = _nom;
	this->tamano = _tam;
	this->direcionEnArchivo = _dir;
}
Table::Table()
{
	this->ID = 0;
	this->nombre = "";
	this->tamano = 0;
	this->direcionEnArchivo = 0;
}

Table::~Table()
{
	//HUEHEUHEUHEUHEUHEUEHUEHEUHEUHEUEU
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

string Table::toString(){
	stringstream ss;
	ss<<"Tabla: "<<this->nombre<<" ID: "<<this->ID<<endl;
	typedef list<Columna*>::iterator it;
	for(it i = this->columnas.begin(); i != this->columnas.end(); i++)
		ss<<"\t"<<(*i)->toString()<<endl;
	return ss.str();
}