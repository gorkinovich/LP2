//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "Administrador.h"
#pragma package(smart_init)


Administrador::Administrador () : Usuario ()
{
}


Administrador::Administrador (std::string id, std::string nombre, CaraClasificada * cara,
				  std::string password) : Usuario (id, nombre, cara, password)
{
}


Administrador::Administrador (const Administrador & obj)
{
	this->Usuario::CopyFrom(obj);
}


Administrador::~Administrador ()
{
}


Persona & Administrador::operator = (const Persona & obj)
{
	this->CopyFrom((Administrador &) obj);
	return (*this);
}


Administrador & Administrador::operator = (const Administrador & obj)
{
	this->Usuario::CopyFrom(obj);
	return (*this);
}


Persona & Administrador::clone (void) const
{
	Administrador * aux = new Administrador();
	aux->Usuario::CopyFrom(*this);
	return (*aux);
}


std::string Administrador::getClassName (void) const
{
	return "Administrador";
}