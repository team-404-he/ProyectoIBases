#ifndef _ANY_H
#define _ANY_H
#include "definitions.h"
class Any{
	
private:

public:
	Any(){
		td = BYTE;
	}
	Any (Tipo_Dato _td): td(_td){}
	Tipo_Dato td;
	virtual ~Any(){
	}
};
#endif