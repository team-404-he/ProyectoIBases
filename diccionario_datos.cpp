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

void DiccionarioDatos::addTableSpace(TableSpace * ts){
		this->tablaSpaces.push_back(ts);
}

void DiccionarioDatos::deserialize(){
		ifstream is;
		is.open("dic.dbf", ios::in | ios::binary);
		if(is.is_open()){
			long l = SerializadorBinario::deserializeLong(is);
			for(long i = 0 ; i < l; i++){
					this->addTableSpace(TableSpace::deserialize_a_TableSpace(is));
			}
		}
}
void DiccionarioDatos::serialize(){
	typedef list<TableSpace*>::iterator it;
	long s = (long)this->tablaSpaces.size();
	std::ofstream ofs;
	ofs.open ("dic.dbf", ios::out | ios::binary);
	if (ofs.is_open()){
			SerializadorBinario::serialize(ofs,s);
			for(it ite = tablaSpaces.begin(); ite != tablaSpaces.end(); ite++)
				(*ite)->serializate_this(ofs);
	}

}

void DiccionarioDatos::Release()
{
	if (ms_instance) {
		delete ms_instance;
	}
	ms_instance = 0;
}

