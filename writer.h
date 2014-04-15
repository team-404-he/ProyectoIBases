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
	template<typename T>
	int write(char * path,id tablespace_id, id table_id,id columna_id,T data) {
		size next = 2*sizeof(unsigned long)+sizeof(tablespace_id)+sizeof(table_id)+sizeof(columna_id)+sizeof(data);
		ofstream outFile;
		outFile.open (path, ios::out | ios::app | ios::binary | ios::ate);
		if(!outFile.is_open()) return NO_OPEN_FILE;
		myfile.seekp (0, ios::end);
		SerializadorBinario::serialize(myfile, (long)next);
		SerializadorBinario::serialize(myfile, (long)tablespace_id);
		SerializadorBinario::serialize(myfile, (long)table_id);
		SerializadorBinario::serialize(myfile, (long)columna_id);
		SerializadorBinario::serialize(myfile, (long)sizeof(data));
		outFile.close();
		return EXIT_SUCCESS;
	}
private:

};
#endif
