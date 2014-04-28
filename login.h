#include "diccionario_datos.h"
#include "sesion_actual.h"
#include "user.h"
#include "table.h"
#include "table_space.h"
#include <iostream>
#include <sstream>

using namespace std;

#ifndef logdbusr
#define logdbusr

class Login
{
	static Login* ms_instance;

public:
	static Login* Instance();
	static void Release();
	bool log();

private:
	Login();
	~Login();

};

#endif // logdbusr
