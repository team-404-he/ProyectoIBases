#include "writer.h"
Writer * Writer::instance = NULL;
Writer::Writer(){}
Writer * Writer::getInstance(){
	if(Writer::instance == NULL) Writer::instance = new Writer();
	return Writer::instance;
}

