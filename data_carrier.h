#ifndef DATACARRIER_H
#define DATACARRIER_H

#include "definitions.h"
#include "any.h"

template<typename T>
class DataCarrier: public Any
{
private:
	T data;
	char null;
		
public:
	T operator->(){
		return this->data;
	}
	T operator*(){
		return this->data;
	}
	DataCarrier(T dat,char isnull, Tipo_Dato _td) : data (dat), null(isnull), Any(_td){}
	
	char isNull(){
		return null;
	}
	T getData(){
		return data;
	}
	std::string toString(){
		std::stringstream ss;
		ss<<this->data;
		return ss.str();
	}
	~DataCarrier(){}

};

#endif // DATACARRIER_H
