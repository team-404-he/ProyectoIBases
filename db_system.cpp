#include "db_system.h"
void push(std::list< std::vector<Any*> >& mat, const std::vector<int>& fields, int sz, const  std::vector<Any*>& data)
{
	int j = 0;
	std::vector<Any*> vec(fields.size());
	for(int i = 0; i < sz; i++) {
		if(i == fields[j])
			vec[j++] = data[i];
	}
	mat.push_back(vec);
	//unsigned long _s = mat.size();
}
DBSystem::DBSystem()
{
}
DBSystem::~DBSystem()
{
}
std::string DBSystem::INSERT(TableSpace * tbs, Table* tb,const std::vector<Any*>& data,const std::vector<int>& fields)
{
	unsigned int j = 0;
	int  integer;
	long l;
	double d;
	std::string s;
	char c, null;
	//bool finded;
	for(unsigned int i = 0; i < tb->GetTamano(); i++) {
		if(j < fields.size() && fields[j] == i) {
			//finded = true;
			switch(data[j]->td) {
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
		} else {
			switch((*tb)[i]->GetTipo()) {
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
dataSet* DBSystem::SELECT(TableSpace * tbs, Table* t,const std::vector<int>& fields, where w)
{
	std::ifstream ifs;
	std::list< std::vector<Any*> > mtx;
	long tbid, tid, colid;
	long nxt;
	ifs.open(tbs->GetPath().c_str());
	if(ifs.is_open()) {
		
		streampos end;
		ifs.seekg (0, ios::end);
		end = ifs.tellg();
		ifs.seekg (0);

		while(ifs.tellg() != end) {
			nxt = SerializadorBinario::deserializeLong(ifs);
			tbid = SerializadorBinario::deserializeLong(ifs);
			tid = SerializadorBinario::deserializeLong(ifs);
			colid = SerializadorBinario::deserializeLong(ifs);
			if((ifs.tellg()+(nxt-24)) == end && tid != t->GetID()) break;
			if(tid == t->GetID()) {
				std::vector<Any*> v(t->GetTamano());
				for(unsigned long i = 0; i < t->GetTamano(); i++) {
					char isNull = SerializadorBinario::deserializeChar(ifs);
					switch((*t)[i]->GetTipo()) {
					case BYTE: 
						v[i] = new DataCarrier<char>(SerializadorBinario::deserializeChar(ifs),isNull,BYTE);
						break;
					case INTEGER:
						v[i] = new DataCarrier<int>(SerializadorBinario::deserializeInt(ifs),isNull,INTEGER);
						break;
					case LONG:
						v[i] = new DataCarrier<long>(SerializadorBinario::deserializeLong(ifs),isNull,LONG);
						break;
					case DOUBLE:
						v[i] = new DataCarrier<double>(SerializadorBinario::deserializeDouble(ifs),isNull,DOUBLE);
						break;
					case STRING:
						v[i] = new DataCarrier<std::string>(SerializadorBinario::deserializeString(ifs),isNull,STRING);
						break;
					}
					if( (i + 1) < t->GetTamano()){
						nxt = SerializadorBinario::deserializeLong(ifs);
						tbid = SerializadorBinario::deserializeLong(ifs);
						tid = SerializadorBinario::deserializeLong(ifs);
						colid = SerializadorBinario::deserializeLong(ifs);
						}
				}
				if(w.aplicar) {
					Any* a = v[w.field_a];
					if(w.tipo == 0) {
						Any* b = v[w.field_b];
						if(WHERE(a, b, w.operation)) push(mtx,fields,t->GetTamano(),v);
					}
					else{ 
						Any* b = w.val_a;
						if(WHERE(a,b,w.operation)) push(mtx,fields,t->GetTamano(),v);
					}
				} else push(mtx,fields,t->GetTamano(),v);

			} else ifs.seekg((std::streampos)(nxt-24), ios::cur);
		}
	} else return NULL;
	return new dataSet(mtx);
}
string DBSystem::UPDATE(TableSpace * tbs,Table* T, vector<Any>& data, vector<int> fields, where w) { return " ";}
bool DBSystem::WHERE(Any* f1,Any* f2, char op){
		return true;
}
/*bool DBSystem::WHERE (vector<Any> data, vector<int> fields, int operation) { return true;}
dataSet DBSystem::WHERE (dataSet& dts, vector<int> fields, int operation) { return dataSet();}*/
string DBSystem::DELETE() { return string();}

