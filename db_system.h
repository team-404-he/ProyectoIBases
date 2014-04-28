#ifndef DBSYSTEM_H
#define DBSYSTEM_H

#include <list>
#include <vector>
#include "any.h"
#include "definitions.h"
#include "table_space.h"
#include "table.h"
#include "columna.h"
#include "data_set.h"
#include "data_carrier.h"
#include "writer.h"

#include <fstream>

using namespace std;

struct where{
	int   field_a;    // el campo involucrado
	int   field_b;    // el segundo campo si lo hubiera         (   debe haber
	Any*   val_a;      // el valor si lo hubiera			       (   alguno de los 2
	char  operation;  // 0 igual 1 distinto 2 menor 3 mayor
	char  tipo;       // 0 entre campos a y b 1 entre campo a y valor 
	bool  aplicar;    // Aplicar o no aplicar el WHERE  
};
typedef struct where where;

class DBSystem
{
public:
	DBSystem();
	~DBSystem();
	static std::string INSERT(TableSpace *, Table* ,const std::vector<Any*>&,const std::vector<int>&);
	static dataSet* SELECT(TableSpace * , Table*,const std::vector<int>&, where);
	static string UPDATE(TableSpace *,Table* , vector<Any*>&, vector<int>& ,where&);
	static bool WHERE(Any*,Any*,char);
	/*static bool WHERE (vector<Any>, vector<int>, int);
	static dataSet WHERE (dataSet& , vector<int>, int); */
	static string DELETE(TableSpace *, Table*,const where&);
	
	
};

#endif // DBSystem_H
