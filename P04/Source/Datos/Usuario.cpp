//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "Usuario.h"
#pragma package(smart_init)


Usuario::Usuario () : Persona ()
{
	this->password = "";
}


Usuario::Usuario (std::string id, std::string nombre, CaraClasificada * cara,
				  std::string password) : Persona (id, nombre, cara)
{
	this->password = password;
}


Usuario::Usuario (const Usuario & obj)
{
	this->CopyFrom(obj);
}


Usuario::~Usuario ()
{
}


Persona & Usuario::operator = (const Persona & obj)
{
	this->CopyFrom((Usuario &) obj);
	return (*this);
}


Usuario & Usuario::operator = (const Usuario & obj)
{
	this->CopyFrom(obj);
	return (*this);
}


void Usuario::CopyFrom (const Usuario & obj)
{
	this->password = obj.password;
	this->Persona::CopyFrom(obj);
}


std::string Usuario::getPassword (void) const
{
	return this->password;
}


void Usuario::setPassword (std::string password)
{
	this->password = password;
}


void Usuario::setCara (CaraClasificada * cara)
{
	this->Persona::setCara(cara);
}
