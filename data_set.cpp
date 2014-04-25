#include "data_set.h"
dataSet::dataSet(){}
dataSet::dataSet(int i, int j )
{
	Matriz.resize(i);
	for(int k= 0; k< i; k++)
		Matriz[k].resize(j);
}
dataSet::dataSet(std::list< std::vector<Any*> >& lst){
	unsigned long _size = lst.size(); 
	this->Matriz.resize(_size);
	std::list< std::vector<Any*> >::iterator it;
	int j = 0;
	for(it = lst.begin(); it != lst.end(); it++, j++){
		this->Matriz[j].resize((*it).size());
		//unsigned long _msize = (*it).size();
		for(unsigned int i=0; i<(*it).size(); i++)
			Matriz[j][i] = (*it)[i];
	}
}
dataSet::~dataSet()
{
}	
std::vector<Any*>& dataSet::operator[](int i){
	return Matriz[i];
}