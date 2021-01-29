//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "LectorConfidente.h"
#pragma package(smart_init)


LectorConfidente::LectorConfidente ()
{
}


LectorConfidente::LectorConfidente (std::string id, std::string nombre, CaraComun * cara,
									ListaOrdenada<Delitos> * cometidos,
									ListaOrdenada<std::string> * concretos, std::string supervisor)
	: Lector (id, nombre, cara, cometidos, concretos), DelincuenteConfidente (supervisor)
{
}


LectorConfidente::LectorConfidente (const LectorConfidente & obj)
{
	this->CopyFrom(obj);
}


LectorConfidente::~LectorConfidente ()
{
}


void LectorConfidente::CopyFrom (const LectorConfidente & obj)
{
	this->Delincuente::CopyFrom(obj);
	this->DelincuenteConfidente::CopyFrom(obj);
}


Persona & LectorConfidente::operator = (const Persona & obj)
{
	this->CopyFrom((LectorConfidente &)obj);
    return (*this);
}


DelincuenteConfidente & LectorConfidente::operator = (const DelincuenteConfidente & obj)
{
	this->CopyFrom((LectorConfidente &)obj);
    return (*this);
}


LectorConfidente & LectorConfidente::operator = (const LectorConfidente & obj)
{
	this->CopyFrom(obj);
    return (*this);
}


Persona & LectorConfidente::clone (void) const
{
	LectorConfidente * aux = new LectorConfidente();
	aux->CopyFrom(*this);
	return (*aux);
}


std::string LectorConfidente::getClassName (void) const
{
	return "LectorConfidente";
}


void LectorConfidente::setCara (CaraComun * cara)
{
	this->Persona::setCara(cara);
}


void LectorConfidente::setCara (CaraClasificada * cara)
{
	this->Persona::setCara(cara);
}