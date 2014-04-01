#ifndef WRITER_H
#define WRITER_H
#include <iostream>
#include <fstream>
#include "definitions.h"
using namespace std;
class Writer{
protected:
	Writer();
	static Writer * instance;
public:
	static Writer * getInstance();
	template<typename T>
int write(char * path,id tablespace_id, id table_id,id columna_id,T data){
	size next = sizeof(tablespace_id)+sizeof(table_id)+sizeof(columna_id)+sizeof(data);
	ofstream outFile;
	outFile.open (path, ios::out | ios::app | ios::binary);
	if(!outFile.is_open()) return NO_OPEN_FILE;
	outFile<<next<<tablespace_id<<table_id<<columna_id<<(sizeof(data))<<data;
	outFile.close();
	return EXIT_SUCCESS;
}
private:
	//ostream& os;
};
#endif