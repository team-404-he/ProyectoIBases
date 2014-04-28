#include "db_system.h"
#include "table.h"
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

void delReg(id tam, std::fstream & strm, std::streampos initial_pos ){
	long nxt, ldel = -1;
	long pos = initial_pos;
	strm.seekg(pos);
	for(int i = 0; i < tam; i++){	
		strm.seekg(pos);
		nxt = SerializadorBinario::deserializeLong((istream&)strm);
		strm.seekp(pos + 16);
		SerializadorBinario::serialize((ostream&)strm,ldel);
		pos += (nxt + 8);
	}
}
void modReg(Table * t , std::fstream & strm, const std::vector<Any*>& data , const std::vector<int>& fields, std::streampos initial_pos){
	long nxt, ldel = -1;
	long pos = initial_pos, gpos, ppos;
	unsigned int j = 0; 
	strm.seekg(pos);
	for(unsigned int i = 0; i < t->GetTamano(); i++){
		gpos = strm.tellg(); ppos = strm.tellp();
		strm.seekg(pos);
		nxt = SerializadorBinario::deserializeLong((istream&)strm);
		strm.seekp(pos + 33);
		gpos = strm.tellg(); ppos = strm.tellp();
		char c; int inte; long lon; double d; std::string s;
		if(i == fields[j]){
			switch((*t)[i]->GetTipo()){
				case BYTE:
					c = ((DataCarrier<char>*)data[j])->getData();
					SerializadorBinario::serialize((ostream&)strm,c);
				break;
				case INTEGER:
					inte = ((DataCarrier<int>*)data[j])->getData();
					SerializadorBinario::serialize((ostream&)strm,inte);
				break;
				case LONG:
					lon = ((DataCarrier<long>*)data[j])->getData();
					SerializadorBinario::serialize((ostream&)strm,lon);	
				break;
				case DOUBLE:
					d = ((DataCarrier<double>*)data[j])->getData();
					SerializadorBinario::serialize((ostream&)strm,d);
				break;
				case STRING:
					s = ((DataCarrier<std::string>*)data[j])->getData();
					SerializadorBinario::serializeFixed((ostream&)strm,s);
				break;
			}
			j++;
		}	
		pos += (nxt + 8);
	}
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
						v[i] = new DataCarrier<std::string>(SerializadorBinario::deserializeFixedString(ifs),isNull,STRING);
						break;
					}
					if( (i + 1) < t->GetTamano()) {
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
					} else {
						Any* b = w.val_a;
						if(WHERE(a,b,w.operation)) push(mtx,fields,t->GetTamano(),v);
					}
				} else push(mtx,fields,t->GetTamano(),v);

			} else ifs.seekg((std::streampos)(nxt-24), ios::cur);
		}
	} else return NULL;
	return new dataSet(mtx);
}
string DBSystem::UPDATE(TableSpace * tbs,Table* t, vector<Any*>& data, vector<int>& fields, where& w)
{
	std::fstream ifs;
	long tbid, tid, colid;
	long nxt;
	ifs.open(tbs->GetPath().c_str());
	if(ifs.is_open()) {
		streampos end, begReg, lstReg;
		ifs.seekg (0, ios::end);
		end = ifs.tellg();
		ifs.seekg (0);

		while(ifs.tellg() != end) {
			begReg = ifs.tellg();
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
						v[i] = new DataCarrier<std::string>(SerializadorBinario::deserializeFixedString(ifs),isNull,STRING);
						break;
					}
					if( (i + 1) < t->GetTamano()) {
						nxt = SerializadorBinario::deserializeLong(ifs);
						tbid = SerializadorBinario::deserializeLong(ifs);
						tid = SerializadorBinario::deserializeLong(ifs);
						colid = SerializadorBinario::deserializeLong(ifs);
					}
				}
				lstReg = ifs.tellg();
				if(w.aplicar) {
					Any* a = v[w.field_a];
					if(w.tipo == 0) {
						Any* b = v[w.field_b];
						if(WHERE(a, b, w.operation)) modReg(t,ifs,data,fields,begReg);
					} else {
						Any* b = w.val_a;
						if(WHERE(a,b,w.operation)) modReg(t,ifs,data,fields,begReg);
					}
				} else modReg(t,ifs,data,fields,begReg);
				ifs.seekg(lstReg);

			} else ifs.seekg((std::streampos)(nxt-24), ios::cur);
		}
	} else return "No rows Affected";
	return "many rows Affected";
}

bool DBSystem::WHERE(Any* f1,Any* f2, char op)
{
	if( f1->td != f2->td ) return false;
	switch(f1->td) {
	case BYTE:
		char a , b;
		a = ((DataCarrier<char>*)f1)->getData();
		b = ((DataCarrier<char>*)f2)->getData();
		if(op == MENOR) return a < b;
		if(op == MAYOR) return a > b;
		if(op == IGUAL) return a == b;
		if(op == DIFERENTE) return a != b;
		return false;
	case INTEGER:
		int c , d;
		c = ((DataCarrier<int>*)f1)->getData();
		d = ((DataCarrier<int>*)f2)->getData();
		if(op == MENOR) return c < d;
		if(op == MAYOR) return c > d;
		if(op == IGUAL) return c == d;
		if(op == DIFERENTE) return c != d;
		return false;
	case LONG:
		long e , f;
		e = ((DataCarrier<long>*)f1)->getData();
		f = ((DataCarrier<long>*)f2)->getData();
		if(op == MENOR) return e < f;
		if(op == MAYOR) return e > f;
		if(op == IGUAL) return e == f;
		if(op == DIFERENTE) return e != f;
		return false;
	case DOUBLE:
		double g , h;
		g = ((DataCarrier<double>*)f1)->getData();
		h = ((DataCarrier<double>*)f2)->getData();
		if(op == MENOR) return g < h;
		if(op == MAYOR) return g > h;
		if(op == IGUAL) return g == h;
		if(op == DIFERENTE) return g != h;
		return false;
	case STRING:
		std::string s1 , s2;
		s1 = ((DataCarrier<std::string>*)f1)->getData();
		s2 = ((DataCarrier<std::string>*)f2)->getData();
		if(op == MENOR) return s1.compare(s2) < 0;
		if(op == MAYOR) return s1.compare(s2) > 0;
		if(op == IGUAL) return s1.compare(s2) == 0;
		if(op == DIFERENTE) return s1.compare(s2) != 0;
		return false;
	}
	return false;
}
string DBSystem::DELETE(TableSpace * tbs, Table* t,const where& w) 
{
	std::fstream ifs;
	long tbid, tid, colid;
	long nxt;
	ifs.open(tbs->GetPath().c_str());
	if(ifs.is_open()) {
		streampos end, begReg, lstReg;
		ifs.seekg (0, ios::end);
		end = ifs.tellg();
		ifs.seekg (0);

		while(ifs.tellg() != end) {
			begReg = ifs.tellg();
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
						v[i] = new DataCarrier<std::string>(SerializadorBinario::deserializeFixedString(ifs),isNull,STRING);
						break;
					}
					if( (i + 1) < t->GetTamano()) {
						nxt = SerializadorBinario::deserializeLong(ifs);
						tbid = SerializadorBinario::deserializeLong(ifs);
						tid = SerializadorBinario::deserializeLong(ifs);
						colid = SerializadorBinario::deserializeLong(ifs);
					}
				}
				lstReg = ifs.tellg();
				if(w.aplicar) {
					Any* a = v[w.field_a];
					if(w.tipo == 0) {
						Any* b = v[w.field_b];
						if(WHERE(a, b, w.operation)) delReg(t->GetTamano(),ifs, begReg);
					} else {
						Any* b = w.val_a;
						if(WHERE(a,b,w.operation)) delReg(t->GetTamano(),ifs, begReg);
					}
				} else delReg(t->GetTamano(),ifs, begReg);
				ifs.seekg(lstReg);

			} else ifs.seekg((std::streampos)(nxt-24), ios::cur);
		}
	} else return "No rows Affected";
	return "many rows Affected";
}
