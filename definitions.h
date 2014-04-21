
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdarg.h>
#include <vector>

#include "DBElement.h"
#include "any.h"

#ifndef DEFS_T_H
#define DEFS_T_H

#define EXIT_SUCCESS 1
#define NO_OPEN_FILE 2
#define UNSPECIFIED_ID 3

typedef unsigned long size;
typedef unsigned long id;
typedef std::vector< std::vector<int>   > MatrixInt;
typedef std::vector< std::vector<float> > MatrixFloat;
typedef std::vector< std::vector<long>  > MatrixLong;
typedef std::vector< std::vector<char>  > MatrixChar;
typedef std::vector< std::vector<std::string> > MatrixString;
//typedef std::vector< std::vector<Any>   > MatrixAny;

enum Tipo_Dato {
	INTEGER,
	LONG,
	DOUBLE,
	STRING,
	BYTE
};
enum privilegios {
	READER,
	WRITER,
	DBA
};

std::string encode(std::string);
std::string decode(std::string);

#endif