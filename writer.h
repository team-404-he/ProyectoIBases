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
	//template<typename T>
	int write(char * path,id tablespace_id, id table_id,id columna_id,std::string data) {
		size next = 10*sizeof(unsigned long)+data.size()+1;
		ofstream outFile;
		outFile.open (path, ios::out | ios::app | ios::binary | ios::ate);
		if(!outFile.is_open()) return NO_OPEN_FILE;
		outFile.seekp (0, ios::end);
		SerializadorBinario::serialize(outFile, (long)next);
		SerializadorBinario::serialize(outFile, (long)tablespace_id);
		SerializadorBinario::serialize(outFile, (long)table_id);
		SerializadorBinario::serialize(outFile, (long)columna_id);
		SerializadorBinario::serialize(outFile, (long)data.size()+1);
		SerializadorBinario::serialize(outFile, data);
		outFile.close();
		return EXIT_SUCCESS;
	}
		int write(char * path,id tablespace_id, id table_id,id columna_id,long data) {
		size next = 7*sizeof(unsigned long);
		ofstream outFile;
		outFile.open (path, ios::out | ios::app | ios::binary | ios::ate);
		if(!outFile.is_open()) return NO_OPEN_FILE;
		outFile.seekp (0, ios::end);
		SerializadorBinario::serialize(outFile, (long)next);
		SerializadorBinario::serialize(outFile, (long)tablespace_id);
		SerializadorBinario::serialize(outFile, (long)table_id);
		SerializadorBinario::serialize(outFile, (long)columna_id);
		SerializadorBinario::serialize(outFile, (long)sizeof(data));
		SerializadorBinario::serialize(outFile, (long)data);
		outFile.close();
		return EXIT_SUCCESS;
	}
private:

};
#endif
