//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "Sonnador.h"
#pragma package(smart_init)


Sonnador::Sonnador ()
{
}


Sonnador::Sonnador (std::string id, std::string nombre, CaraComun * cara,
					ListaOrdenada<Delitos> * cometidos,
					ListaOrdenada<std::string> * concretos)
	: Delincuente (id, nombre, cara, cometidos, concretos)
{
}


Sonnador::Sonnador (const Sonnador & obj)
{
	this->Delincuente::CopyFrom(obj);
}


Sonnador::~Sonnador ()
{
}


Persona & Sonnador::operator = (const Persona & obj)
{
	this->CopyFrom((Sonnador &) obj);
	return (*this);
}


Sonnador & Sonnador::operator = (const Sonnador & obj)
{
	this->Delincuente::CopyFrom(obj);
    return (*this);
}


Persona & Sonnador::clone (void) const
{
	Sonnador * aux = new Sonnador();
	aux->Delincuente::CopyFrom(*this);
	return (*aux);
}


std::string Sonnador::getClassName (void) const
{
	return "Sonnador";
}