#ifndef DATACARRIER_H
#define DATACARRIER_H

#include "definitions.h"
#include "any.h"

template<typename T>
class DataCarrier: public Any
{
private:
	T data;
	Tipo_Dato td;
public:
	T operator->(){
		return this->data;
	}
	T operator*(){
		return this->data;
	}
	DataCarrier(T dat, Tipo_Dato _td = BYTE) : data(dat), td(_td){}
	T getData(){
		return data;
	}
	Tipo_Dato getTipoDato(){
		return this->td;
	}
	~DataCarrier(){}

};

#endif // DATACARRIER_H
