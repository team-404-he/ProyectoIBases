#include "sesion_actual.h"

SesionActual* SesionActual::ms_instance = 0;

SesionActual::SesionActual()
{
}

SesionActual::~SesionActual()
{
}

SesionActual* SesionActual::Instance()
{
	if (ms_instance == 0) {
		ms_instance = new SesionActual();
	}
	return ms_instance;
}

void SesionActual::Release()
{
	if (ms_instance) {
		delete ms_instance;
	}
	ms_instance = 0;
}
void SesionActual::SetMsInstance(SesionActual* ms_instance)
{
	this->ms_instance = ms_instance;
}
void SesionActual::SetTablaActual(Table* tablaActual)
{
	this->tablaActual = tablaActual;
}
void SesionActual::SetTbActual(TableSpace* tbActual)
{
	this->tbActual = tbActual;
}
void SesionActual::SetUserActual(user* userActual)
{
	this->userActual = userActual;
}
SesionActual* SesionActual::GetMsInstance()
{
	return ms_instance;
}
Table* SesionActual::GetTablaActual()
{
	return tablaActual;
}
TableSpace* SesionActual::GetTbActual()
{
	return tbActual;
}
user* SesionActual::GetUserActual()
{
	return userActual;
}
