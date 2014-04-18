
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdarg.h>
#include "DBElement.h"

#ifndef DEFS_T_H
#define DEFS_T_H

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
enum privilegios {
	READER,
	WRITER,
	DBA
};

std::string encode(std::string);
std::string decode(std::string);

#endif