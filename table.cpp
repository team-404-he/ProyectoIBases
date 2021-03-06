#include "table.h"

Table::Table(id _id,string _nom,size _tam,size _dir){
	this->ID = _id;
	this->nombre = _nom;
	this->tamano = 0;
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
 const id& Table::GetID() const{
		return this->ID;
} 
void Table::SetID(const id& _ID){
	this->ID=_ID;
}	
const size& Table::GetTamano() const{
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
const string& Table::GetNombre() const{
	return this->nombre;
}
void Table::SetNombre(const string& nombre){
	this->nombre=nombre;
}

Columna* Table::getByIndex(int i){
	if(i >= this->columnas.size()) return NULL;
	list<Columna*>::iterator it;
	it = this->columnas.begin();
	for(int ij = 0;ij < i; ij++ , it++ );
	return (*it);
}
Columna* Table::getByName(std::string& n){
	list<Columna*>::iterator it ;
	for(it = this->columnas.begin(); it != this->columnas.end(); it++){
		if((*it)->GetNombre() == n)
			return (*it);
	}
	return NULL;
}
Columna* Table::operator[](int i){
	return this->getByIndex(i);
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
	this->SetTamano(columnas.size());
	colum->SetID(this->tamano);
	this->columnas.push_back(colum);
	this->SetTamano(columnas.size());
}

string Table::toString(){
	stringstream ss;
	ss<<"Tabla: "<<this->nombre<<" ID: "<<this->ID<<endl;
	typedef list<Columna*>::iterator it;
	for(it i = this->columnas.begin(); i != this->columnas.end(); i++)
		ss<<"\t"<<(*i)->toString()<<endl;
	return ss.str();
}