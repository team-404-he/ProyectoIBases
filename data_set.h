#ifndef _dataSet_H
#define _dataSet_H

#include "any.h"
#include <vector>

class dataSet
{
private:
	std::vector< std::vector<Any> > Matriz;
public:
	dataSet(int = 0,int = 0);
	std::vector<Any>& operator[](int);
	dataSet();
	~dataSet();

};

#endif // _dataSet_H
