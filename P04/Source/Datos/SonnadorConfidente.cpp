//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "SonnadorConfidente.h"
#pragma package(smart_init)


SonnadorConfidente::SonnadorConfidente ()
{
}


SonnadorConfidente::SonnadorConfidente (std::string id, std::string nombre, CaraComun * cara,
										ListaOrdenada<Delitos> * cometidos,
										ListaOrdenada<std::string> * concretos, std::string supervisor)
	: Sonnador (id, nombre, cara, cometidos, concretos), DelincuenteConfidente (supervisor)
{
}


SonnadorConfidente::SonnadorConfidente (const SonnadorConfidente & obj)
{
	this->CopyFrom(obj);
}


SonnadorConfidente::~SonnadorConfidente ()
{
}


void SonnadorConfidente::CopyFrom (const SonnadorConfidente & obj)
{
	this->Delincuente::CopyFrom(obj);
	this->DelincuenteConfidente::CopyFrom(obj);
}


Persona & SonnadorConfidente::operator = (const Persona & obj)
{
	this->CopyFrom((SonnadorConfidente &)obj);
    return (*this);
}


DelincuenteConfidente & SonnadorConfidente::operator = (const DelincuenteConfidente & obj)
{
	this->CopyFrom((SonnadorConfidente &)obj);
    return (*this);
}


SonnadorConfidente & SonnadorConfidente::operator = (const SonnadorConfidente & obj)
{
	this->CopyFrom(obj);
    return (*this);
}


Persona & SonnadorConfidente::clone (void) const
{
	SonnadorConfidente * aux = new SonnadorConfidente();
	aux->CopyFrom(*this);
	return (*aux);
}


std::string SonnadorConfidente::getClassName (void) const
{
	return "SonnadorConfidente";
}


void SonnadorConfidente::setCara (CaraComun * cara)
{
	this->Persona::setCara(cara);
}


void SonnadorConfidente::setCara (CaraClasificada * cara)
{
	this->Persona::setCara(cara);
}