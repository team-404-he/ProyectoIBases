#include "definitions.h"
#include "user.h"

user::user(id _id, id _tbid, std::string _nombre, std::string _pass, privilegios priv):
	u_id(_id), tb_id(_tbid), nombre(_nombre), pass(_pass)
{
	this->privilegio = priv;
}

user::~user()
{
}

void user::SetNombre(const std::string& nombre)
{
	this->nombre = nombre;
}
void user::SetPass(const std::string& pass)
{
	this->pass = pass;
}
void user::SetPrivilegio(const privilegios& privilegio)
{
	this->privilegio = privilegio;
}
void user::SetTbId(const id& tb_id)
{
	this->tb_id = tb_id;
}
void user::SetID(const id& u_id)
{
	this->u_id = u_id;
}
const std::string& user::GetNombre() const
{
	return nombre;
}
const std::string& user::GetPass() const
{
	return pass;
}
const privilegios& user::GetPrivilegio() const
{
	return privilegio;
}
const id& user::GetTbId() const
{
	return tb_id;
}
const id& user::GetID() const
{
	return u_id;
}
void user::serialize(ostream& os){
	
	SerializadorBinario::serialize(os, (long) this->u_id );
	SerializadorBinario::serialize(os, (long) this->tb_id);
	SerializadorBinario::serialize(os, this->nombre);
	SerializadorBinario::serialize(os, encode(this->pass));
	SerializadorBinario::serialize(os, static_cast<int>(this->privilegio));
	
}
user *  user::deserialize(istream & is){
	user* u = new user(SerializadorBinario::deserializeLong(is),SerializadorBinario::deserializeLong(is),SerializadorBinario::deserializeString(is),decode(SerializadorBinario::deserializeString(is)),static_cast<privilegios>(SerializadorBinario::deserializeInt(is)));
	//u->SetID(SerializadorBinario::deserializeLong(is));
	//u->SetTbId(SerializadorBinario::deserializeLong(is));
	//u->SetNombre(SerializadorBinario::deserializeString(is));
	//u->SetPass(decode(SerializadorBinario::deserializeString(is)));
	//u->SetPrivilegio(static_cast<privilegios>(SerializadorBinario::deserializeInt(is)));
	return u;
}

