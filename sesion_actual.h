#include "user.h"
#include "diccionario_datos.h"
#include "table_space.h"
#include "table.h"

#ifndef SESACT
#define SESACT

class SesionActual
{
	static SesionActual* ms_instance;

public:
	static SesionActual* Instance();
	static void Release();
	void SetMsInstance(SesionActual* ms_instance);
	void SetTablaActual(Table* tablaActual);
	void SetTbActual(TableSpace* tbActual);
	void SetUserActual(user* userActual);
	SesionActual* GetMsInstance();
	Table* GetTablaActual();
	TableSpace* GetTbActual();
	user* GetUserActual() ;

private:
	TableSpace * tbActual;
	user * userActual;
	Table * tablaActual;

	SesionActual();
	~SesionActual();

};

#endif // SESACT
