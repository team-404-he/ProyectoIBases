#include "table_space.h"

TableSpace::TableSpace()
{
	this->ID = 0;
	this->nombre = "";
	this->tamano = 0l;
}

TableSpace::~TableSpace()
{
}
TableSpace::TableSpace(id _id, string _nombre, std::string _path):ID(_id), nombre(_nombre), path(_path){
		this->tamano = 0;
}
void TableSpace::addTable(Table * t){
	this->tablas.push_back(t);
}
void TableSpace::removeTable(id _id){
	typedef list<Table*>::iterator iter;
	for(iter i = this->tablas.begin(); i != tablas.end() ; i++){
		if( _id == (*i)->GetID()){
			tablas.erase(i);
			return;
		}
	}
}
void TableSpace::removeTable(Table * tb){
			typedef list<Table*>::iterator iter;
	for(iter i = this->tablas.begin(); i != tablas.end() ; i++){
		if(tb == (*i)){
			tablas.erase(i);
			return;
		}
	}
}
void TableSpace::serializate_this(ofstream& os){
	
	typedef list<Table*>::iterator iter;	
	SerializadorBinario::serialize(os,(long)this->ID);
	SerializadorBinario::serialize(os,this->path);
	SerializadorBinario::serialize(os,this->nombre);
	SerializadorBinario::serialize(os,(long)this->tamano);
	SerializadorBinario::serialize(os,(long)this->tablas.size());
		
	for(iter i = this->tablas.begin(); i != tablas.end() ; i++){
		(*i)->serialize_this(os);
	}
}
TableSpace* TableSpace::deserialize_a_TableSpace(ifstream& is){
		TableSpace * t = new TableSpace();
		t->SetID(SerializadorBinario::deserializeLong(is));
		t->SetPath(SerializadorBinario::deserializeString(is));
		t->SetNombre(SerializadorBinario::deserializeString(is));
		t->SetTamano(SerializadorBinario::deserializeLong(is));
		long x = SerializadorBinario::deserializeInt(is);
		for(long h = 0; h < x ; h++){
			t->addTable(Table::deserialize_a_Table(is));
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
void TableSpace::SetPath(std::string _path){
		this->path = _path;
}
const std::string& TableSpace::GetPath() const{
	return this->path;
}

string TableSpace::toString(){
	typedef list<Table*>::iterator it;
	stringstream ss;
	ss<<" TableSpace: "<<this->nombre<<" ID "<<this->ID<<endl;
	for(it i = this->tablas.begin(); i != tablas.end(); i++)
		ss<<(*i)->toString()<<endl;
	return ss.str();
}
Table* TableSpace::findByName(std::string& name){
	typedef list<Table*>::iterator it;
	Table* ret = NULL;
	for(it i = this->tablas.begin(); i != tablas.end(); i++){
			if((*i)->GetNombre() == name){
					ret = (*i);
					i = tablas.end();
			} 
	}
	return ret;	
}
Table* TableSpace::findByID(size _id){
	typedef list<Table*>::iterator it;
	Table* ret = NULL;
	for(it i = this->tablas.begin(); i != tablas.end(); i++){
			if((*i)->GetID() == _id){
					ret = (*i);
					i = tablas.end();
			} 
	}
	return ret;	
}