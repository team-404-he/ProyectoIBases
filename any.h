#ifndef _ANY_H
#define _ANY_H
#include "definitions.h"
class Any{


protected:
	
public:
	Any(){
		td = BYTE;
	}
	Any (Tipo_Dato _td): td(_td){}
	Tipo_Dato td;
	virtual std::string toString() = 0;
	virtual ~Any(){
	}
};
#endif