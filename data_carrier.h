#ifndef DATACARRIER_H
#define DATACARRIER_H

#include "definitions.h"
#include "any.h"

template<typename T>
class DataCarrier: public Any
{
private:
	char null;
	T data;
	
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
	~DataCarrier(){}

};

#endif // DATACARRIER_H
