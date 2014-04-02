#ifndef DEFS_H
#define DEFS_H
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#define EXIT_SUCCESS 1
#define NO_OPEN_FILE 2
#define UNSPECIFIED_ID 3
typedef unsigned long size;
typedef unsigned long id;

enum Tipo_Dato {
	INTEGER,
	DOUBLE,
	STRING,
	BYTE
};
int sizeDT(Tipo_Dato t){
		switch(t){
			case BYTE:
				return sizeof(char);
			case DOUBLE:
				return sizeof(float);
			case INTEGER:
				return sizeof(int);
			case STRING:
				return sizeof(char[128]);
		}
		return 0;
}
#endif