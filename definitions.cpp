#include "definitions.h"

std::string encode(std::string s){
	for(int i=0 ; i< s.size(); i++)
		s[i] += 3;
	return s;
}
std::string decode(std::string s){
	for(int i=0 ; i< s.size(); i++)
		s[i] -= 3 ;
	return s;
}