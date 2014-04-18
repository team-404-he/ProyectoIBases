#ifndef _DB_USER_H
#define _DB_USER_H

#include "definitions.h"
#include "SerializadorBinario.h"

class user
{
public:
	//TIPO DE PRIVILEGIOS POSIBLEs PARA EL USUARIO DEFINIDOS EN definitions.h como enum privilegios

	user(id _id, id _tbid, std::string _nombre, std::string _pass, privilegios priv);
	~user();
	//Setterss / Getters a Granel
	void SetNombre(const std::string&);
	void SetPass(const std::string&);
	void SetPrivilegio(const privilegios&);
	void SetTbId(const id&);
	void SetID(const id&);
	const std::string& GetNombre() const;
	const std::string& GetPass() const;
	const privilegios& GetPrivilegio() const;
	const id& GetTbId() const;
	const id& GetID() const;

	void serialize(ostream& os); //SERIALIZAR LA INFORMACION DEL USUARIO
	static user *  deserialize(istream & is); //DESERIALIZAR UN USUARI0
private:
	id u_id; 					//EL id del Usuario
	id tb_id; 					//El TableSpace Designado
	std::string nombre; 		//Nombre Del Usuario
	std::string pass; 	//TOTALLY SECURITY FAULT
	privilegios privilegio;  //EL NIVEL DE PRIVILEGIOS QUE TIENE EL USUARIO

};

#endif // _DB_USER_H
