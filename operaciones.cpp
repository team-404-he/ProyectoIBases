#include "operaciones.h"

Operaciones::Operaciones()
{
}

Operaciones::~Operaciones()
{
}


void Operaciones::menuPrincipal() {
	bool salir = false;
	SesionActual* sesion = SesionActual::Instance();
	string opc;
	cout<<"Usuario Actual "<<sesion->GetUserActual()->GetNombre()<<endl;
	cout<<"TableSpace: "<<sesion->GetTbActual()->GetNombre()<<endl<<endl;
	while(!salir){
	cout<<"Que desea Hacer ?"<<endl
		<<"1 Crear TableSpace \n"
		<<"2 Crear Usuario \n"
		<<"3 Crear Tabla \n"
		<<"4 Insertar \n"
		<<"5 Selecionar \n"
		<<"6 Actualizar \n"
		<<"7 Borrar \n"
		<<"8 Salir\n";
		switch(opc[0]){
			case '1':
				createTableSpace();
			break;
			case '2':
				createUser();
			break;
			case '3':
				createTable();
			break;
			case '4':
				this->insertInto();
			break;
			case '5':
				this->selectFrom();
			break;
			case '6':
				this->updateFields();
			break;
			case '7':
				this->deleteField();
			break;
			case '8':
				salir = true;
			break;
	
		};
	}
}
bool Operaciones::createTableSpace() {}
bool Operaciones::createTable() {}
bool Operaciones::createUser() {}
bool Operaciones::insertInto() {}
bool Operaciones::selectFrom() {}
bool Operaciones::updateFields() {}
bool Operaciones::deleteField() {}
