#ifndef DB_ELEM_H
#define DB_ELEM_H

#include "definitions.h"

class DBElement{
protected:
	id ID;
	std::string nombre;
public:
	virtual const id& GetID() const = 0;
	virtual void SetID(const id&) = 0;
	virtual const std::string& GetNombre() const = 0;
	virtual void SetNombre(const std::string&) = 0;
};
#endif