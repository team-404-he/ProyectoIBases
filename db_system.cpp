#include "db_system.h"
/*template<typename T>
T whatIsIn(Any * a){
	switch(a->td){
		case BYTE: return *((DataCarrier<char>*)a);
		case INTEGER: return *((DataCarrier<int>*)a);
		case LONG: return *((DataCarrier<long>*)a);
		case DOUBLE: return *((DataCarrier<double>*)a);
		case STRING: return *((DataCarrier<std::string>*)a);
		default: return int(0);
	}
}*/

DBSystem::DBSystem()
{
}
DBSystem::~DBSystem()
{
}
std::string DBSystem::INSERT(TableSpace * tbs, Table* tb,const std::vector<Any*>& data,const std::vector<int>& fields){
	int j = 0, x = 0, integer;
	long l;
	double d;
	std::string s;
	char c, null;
	//bool finded;
	for(int i = 0; i < tb->GetTamano(); i++){
			if(j < fields.size() && fields[j] == i){
				//finded = true;
			switch(data[j]->td){
				case BYTE:
					c = ((DataCarrier<char>*)data[j])->getData();
					null = ((DataCarrier<char>*)data[j])->isNull();
					/*if(finded)*/Writer::getInstance()->write(tbs->GetPath().c_str(),tbs->GetID(),tb->GetID(),(*tb)[i]->GetID(),null,c);
					//else Writer::getInstance()->write(tbs->GetPath().c_str(),tbs->GetID(),tb->GetID(),(*tb)[i]->GetID(),1,char());
				break;
				case INTEGER:
					integer = ((DataCarrier<int>*)data[j])->getData();
					null = ((DataCarrier<char>*)data[j])->isNull();
					/*if(finded)*/Writer::getInstance()->write(tbs->GetPath().c_str(),tbs->GetID(),tb->GetID(),(*tb)[i]->GetID(),null,integer);
					//else Writer::getInstance()->write(tbs->GetPath().c_str(),tbs->GetID(),tb->GetID(),(*tb)[i]->GetID(),1,int());
				break;
				case LONG:
					l = ((DataCarrier<long>*)data[j])->getData();
					null = ((DataCarrier<long>*)data[j])->isNull();
					/*if(finded)*/Writer::getInstance()->write(tbs->GetPath().c_str(),tbs->GetID(),tb->GetID(),(*tb)[i]->GetID(),null,l);
					break;
				case DOUBLE:
					d = ((DataCarrier<double>*)data[j])->getData();
					null = ((DataCarrier<double>*)data[j])->isNull();
					/*if(finded)*/Writer::getInstance()->write(tbs->GetPath().c_str(),tbs->GetID(),tb->GetID(),(*tb)[i]->GetID(),null,d);
				break;
				case STRING:
					s = ((DataCarrier<std::string>*)data[j])->getData();
					null = ((DataCarrier<std::string>*)data[j])->isNull();
					/*if(finded)*/Writer::getInstance()->write(tbs->GetPath().c_str(),tbs->GetID(),tb->GetID(),(*tb)[i]->GetID(),null,s);
				break;
				//SI no es de data !!
			}
			j++;
		}
		else{
			switch((*tb)[i]->GetTipo()){
				case BYTE:
					Writer::getInstance()->write(tbs->GetPath().c_str(),tbs->GetID(),tb->GetID(),(*tb)[i]->GetID(),1,char());
				break;
				case INTEGER:
					Writer::getInstance()->write(tbs->GetPath().c_str(),tbs->GetID(),tb->GetID(),(*tb)[i]->GetID(),1,int());
				break;
				case LONG:
					Writer::getInstance()->write(tbs->GetPath().c_str(),tbs->GetID(),tb->GetID(),(*tb)[i]->GetID(),1,long());
				break;
				case DOUBLE:
					Writer::getInstance()->write(tbs->GetPath().c_str(),tbs->GetID(),tb->GetID(),(*tb)[i]->GetID(),1,double());
				break;
				case STRING:
					Writer::getInstance()->write(tbs->GetPath().c_str(),tbs->GetID(),tb->GetID(),(*tb)[i]->GetID(),1,std::string());
				break;
			}
		}
	}
	return "OK, 1 Row Affected";
}
dataSet DBSystem::SELECT(TableSpace * tbs, vector<Table*> tables , MatrixInt fields){
	//Generar Vectores<Any*> tantos como tablas en tables 
	// llnarlos hacerles producto cruz
	//A;lmacenar el producto cruz en un dataSet y retonarlo
	ifstream ifs;
	long tbid, tid, colid;
	streampos offset, nxt;
	ifs.open(tbs->GetPath().c_str());
	if(ifs.is_open()){
		next = (streampos)SerializadorBinario::deserializeLong(ifs);
		tbid = SerializadorBinario::deserializeLong(ifs);
		tid = SerializadorBinario::deserializeLong(ifs);
		if(tid == 0/*Alguno de las tablas en el vector*/)
	}
	else return dataSet();
}
string DBSystem::UPDATE(TableSpace * tbs,Table* T, vector<Any>& data, vector<int> fields){}
bool DBSystem::WHERE (vector<Any> data, vector<int> fields, int operation){}
dataSet DBSystem::WHERE (dataSet& dts, vector<int> fields, int operation){}
string DBSystem::DELETE(){}
