#ifndef WRITER_H
#define WRITER_H
#include <iostream>
#include <fstream>
#include "definitions.h"
#include "SerializadorBinario.h"
using namespace std;
class Writer {
protected:
	Writer();
	static Writer * instance;
public:
	static Writer * getInstance();
	int write(char * path,id tablespace_id, id table_id,id columna_id,std::string data);
	int write(char * path,id tablespace_id, id table_id,id columna_id,long data);
	int write(char * path,id tablespace_id, id table_id,id columna_id,int data);
	int write(char * path,id tablespace_id, id table_id,id columna_id,char data);
	int write(char * path,id tablespace_id, id table_id,id columna_id,float data);
	int write(char * path,id tablespace_id, id table_id,id columna_id,double data);
private:

};
#endif
