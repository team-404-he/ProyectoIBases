#ifndef _dataSet_H
#define _dataSet_H

#include "any.h"
#include <list>
#include <vector>

using namespace std;
class dataSet
{
private:
	std::vector< std::vector<Any*> > Matriz;
public:
	dataSet();
	dataSet(int , int);
	dataSet(std::list< std::vector<Any*> >&);
	std::vector<Any*>& operator[](int);
	~dataSet();

};

#endif // _dataSet_H
