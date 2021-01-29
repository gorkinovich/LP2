//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "Policia.h"
#pragma package(smart_init)


Policia::Policia () : Usuario ()
{
}


Policia::Policia (std::string id, std::string nombre, CaraClasificada * cara,
				  std::string password) : Usuario (id, nombre, cara, password)
{
}


Policia::Policia (const Policia & obj)
{
	this->CopyFrom(obj);
}


Policia::~Policia ()
{
}


Persona & Policia::operator = (const Persona & obj)
{
	this->CopyFrom((Policia &) obj);
	return (*this);
}


Policia & Policia::operator = (const Policia & obj)
{
	this->CopyFrom(obj);
	return (*this);
}


Persona & Policia::clone (void) const
{
	Policia * aux = new Policia();
	aux->Usuario::CopyFrom(*this);
	return (*aux);
}


std::string Policia::getClassName (void) const
{
	return "Policia";
}