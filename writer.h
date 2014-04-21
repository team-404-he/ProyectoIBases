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
	int write(const char * path,id tablespace_id, id table_id,id columna_id, char null, std::string data);
	int write(const char * path,id tablespace_id, id table_id,id columna_id, char null, long data);
	int write(const char * path,id tablespace_id, id table_id,id columna_id, char null, int data);
	int write(const char * path,id tablespace_id, id table_id,id columna_id, char null, char data);
	int write(const char * path,id tablespace_id, id table_id,id columna_id, char null, float data);
	int write(const char * path,id tablespace_id, id table_id,id columna_id, char null, double data);
private:

};
#endif
