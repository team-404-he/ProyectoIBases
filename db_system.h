#ifndef DBSYSTEM_H
#define DBSYSTEM_H

#include <vector>
#include "any.h"
#include "definitions.h"
#include "table_space.h"
#include "table.h"
#include "columna.h"
#include "data_set.h"
#include "data_carrier.h"
#include "writer.h"

using namespace std;

class DBSystem
{
public:
	DBSystem();
	~DBSystem();
	static std::string INSERT(TableSpace *, Table* ,const std::vector<Any*>&,const std::vector<int>&);
	static dataSet SELECT(TableSpace * , vector<Table*>, MatrixInt);
	static string UPDATE(TableSpace *,Table* , vector<Any>&, vector<int>);
	static bool WHERE (vector<Any>, vector<int>, int);
	static dataSet WHERE (dataSet& , vector<int>, int);
	static string DELETE();
};

#endif // DBSystem_H
