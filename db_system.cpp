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
	int j = 0, x = 0;
	char c, null;
	bool finded;
	for(int i = 0; i < tb->GetTamano(); i++){
		if(j < fields.size() && fields[j] == i){
			finded = true;
			j++;
		}
		switch(data[0]->td){
			case BYTE:
				c = ((DataCarrier<char>*)data[0])->getData();
				null = ((DataCarrier<char>*)data[0])->isNull();
				if(finded)Writer::getInstance()->write(tbs->GetPath().c_str(),tbs->GetID(),tb->GetID(),(*tb)[i]->GetID(),null,c);
				else Writer::getInstance()->write(tbs->GetPath().c_str(),tbs->GetID(),tb->GetID(),(*tb)[i]->GetID(),1,char());
				break;
			case INTEGER:
				c = ((DataCarrier<int>*)data[0])->getData();
				null = ((DataCarrier<char>*)data[0])->isNull();
				if(finded)Writer::getInstance()->write(tbs->GetPath().c_str(),tbs->GetID(),tb->GetID(),(*tb)[i]->GetID(),null,c);
				else Writer::getInstance()->write(tbs->GetPath().c_str(),tbs->GetID(),tb->GetID(),(*tb)[i]->GetID(),1,int());
				break;

			case LONG:
			break;
	 
		}
	}
	return "OK, 1 Row Affected";
}
dataSet DBSystem::SELECT(TableSpace * tbs, vector<Table*> tables , MatrixInt fields){}
string DBSystem::UPDATE(TableSpace * tbs,Table* T, vector<Any>& data, vector<int> fields){}
bool DBSystem::WHERE (vector<Any> data, vector<int> fields, int operation){}
dataSet DBSystem::WHERE (dataSet& dts, vector<int> fields, int operation){}
string DBSystem::DELETE(){}
