#include "diccionario_datos.h"

DiccionarioDatos* DiccionarioDatos::ms_instance = 0;

DiccionarioDatos::DiccionarioDatos()
{
}

DiccionarioDatos::~DiccionarioDatos()
{
}

DiccionarioDatos* DiccionarioDatos::Instance()
{
	if (ms_instance == 0) {
		ms_instance = new DiccionarioDatos();
	}
	return ms_instance;
}

void DiccionarioDatos::Release()
{
	if (ms_instance) {
		delete ms_instance;
	}
	ms_instance = 0;
}

