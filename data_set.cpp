#include "data_set.h"

dataSet::dataSet(int i, int j )
{
	Matriz.resize(i);
	for(int k= 0; k< i; k++)
		Matriz[k].resize(j);
}

dataSet::~dataSet()
{
}	
std::vector<Any>& dataSet::operator[](int i){
	return Matriz[i];
}