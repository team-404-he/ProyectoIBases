#include "login.h"

Login* Login::ms_instance = 0;

Login::Login()
{
}

Login::~Login()
{
}

Login* Login::Instance()
{
	if (ms_instance == 0) {
		ms_instance = new Login();
	}
	return ms_instance;
}

void Login::Release()
{
	if (ms_instance) {
		delete ms_instance;
	}
	ms_instance = 0;
}

bool log(){
	bool nousr = true;
	string usr, pss;
	user * _user;
	do{
		cout<<"Nombre de Usuario"<<endl;
		cin>>usr;
		cout<<"Password: "<<endl;
		cin>>pss;
		if( (_user = DiccionarioDatos::Instance()->getUserByName(usr)) !=NULL){
			if(_user->GetPass().compare(usr) != 0){
				SesionActual::Instance()->SetUserActual(_user);
				SesionActual::Instance()->SetTbActual(DiccionarioDatos::Instance()->getTBSByID(_user->GetTbId()));
				nousr = false;
			}
			else cout<<"Contrasena Incorrecta\n";
		}else cout<<"No existe Usuario\n";
	}while(nousr);
	
}