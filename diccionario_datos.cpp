#include "diccionario_datos.h"

DiccionarioDatos* DiccionarioDatos::ms_instance = 0;

DiccionarioDatos::DiccionarioDatos()
{
	this->path = "dic.dbf";
}

DiccionarioDatos::~DiccionarioDatos()
{
}

DiccionarioDatos* DiccionarioDatos::Instance()
{
	if (ms_instance == 0) {
		ms_instance = new DiccionarioDatos();
	}
	return ms_instance;
}
std::list<TableSpace*>& DiccionarioDatos::getList(){
		return this->tablaSpaces;
}

void DiccionarioDatos::addTableSpace(TableSpace * ts){
		this->tablaSpaces.push_back(ts);
}

void DiccionarioDatos::deserialize(){
		ifstream is;
		is.open("users.dbf", ios::in | ios::binary);
		if(is.is_open()){
			long l = SerializadorBinario::deserializeLong(is);
			for(long i = 0 ; i < l; i++){
					this->users.push_back(user::deserialize(is));
			}
		is.close();
		}
		
		is.open("dic.dbf", ios::in | ios::binary);
		if(is.is_open()){
			long l = SerializadorBinario::deserializeLong(is);
			for(long i = 0 ; i < l; i++){
					this->addTableSpace(TableSpace::deserialize_a_TableSpace(is));
			}
		}
		is.close();
}
void DiccionarioDatos::serialize(){
	std::ofstream ofs;
	typedef list<TableSpace*>::iterator it;
	list<user*>::iterator uit;
	
	ofs.open("users.dbf", ios::out | ios::binary);
		if(ofs.is_open()){
			SerializadorBinario::serialize(ofs,(long) users.size());
			for(uit = users.begin(); uit != users.end(); uit++)
				(*uit)->serialize(ofs);
		}
	ofs.flush();
	ofs.close();
	
	long s = (long)this->tablaSpaces.size();
	ofs.open ("dic.dbf", ios::out | ios::binary);
	if (ofs.is_open()){
			SerializadorBinario::serialize(ofs,s);
			for(it ite = tablaSpaces.begin(); ite != tablaSpaces.end(); ite++)
				(*ite)->serializate_this(ofs);
	}
	ofs.flush();
	ofs.close();
}

void DiccionarioDatos::Release()
{
	if (ms_instance) {
		delete ms_instance;
	}
	ms_instance = 0;
}

TableSpace * DiccionarioDatos::getTBSByID(id _id){
	list<TableSpace*>::iterator it;
	TableSpace * ret = NULL;
	for(it = this->tablaSpaces.begin(); it != tablaSpaces.end();it++){
		if((*it)->GetID() == _id) ret = *it;
	}
	return ret;
}
TableSpace * DiccionarioDatos::getTBSByName(std::string _nombre){
	list<TableSpace*>::iterator it;
	TableSpace * ret = NULL;
	for(it = this->tablaSpaces.begin(); it != tablaSpaces.end();it++){
		if((*it)->GetNombre()== _nombre) ret = *it;
	}
	return ret;
}
std::list<user*>& DiccionarioDatos::getUsersList(){
	return this->users;
}

user * DiccionarioDatos::getUserByID(id _id){
	list<user*>::iterator it;
	user * ret = NULL;
	for(it = this->users.begin(); it != users.end();it++){
		if((*it)->GetID() == _id) ret = *it;
	}
	return ret;
}
user * DiccionarioDatos::getUserByName(std::string _nombre){
	list<user*>::iterator it;
	user * ret = NULL;
	for(it = this->users.begin(); it != users.end();it++){
		if((*it)->GetNombre()== _nombre) ret = *it;
	}
	return ret;
}

void DiccionarioDatos::addUser(user* u){
	this->users.push_back(u);
}
