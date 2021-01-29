//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "Lector.h"
#pragma package(smart_init)


Lector::Lector ()
{
}


Lector::Lector (std::string id, std::string nombre, CaraComun * cara,
				ListaOrdenada<Delitos> * cometidos,
				ListaOrdenada<std::string> * concretos)
	: Delincuente (id, nombre, cara, cometidos, concretos)
{
}


Lector::Lector (const Lector & obj)
{
	this->Delincuente::CopyFrom(obj);
}


Lector::~Lector ()
{
}


Persona & Lector::operator = (const Persona & obj)
{
	this->CopyFrom((Lector &) obj);
	return (*this);
}


Lector & Lector::operator = (const Lector & obj)
{
	this->Delincuente::CopyFrom(obj);
    return (*this);
}


Persona & Lector::clone (void) const
{
	Lector * aux = new Lector();
	aux->Delincuente::CopyFrom(*this);
	return (*aux);
}


std::string Lector::getClassName (void) const
{
	return "Lector";
}