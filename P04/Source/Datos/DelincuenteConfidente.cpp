//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "DelincuenteConfidente.h" 
#pragma package(smart_init)


DelincuenteConfidente::DelincuenteConfidente ()
{
    this->supervisor = "";
}


DelincuenteConfidente::DelincuenteConfidente (std::string supervisor)
{
    this->supervisor = supervisor;
}


DelincuenteConfidente::DelincuenteConfidente (const DelincuenteConfidente & obj)
{
    this->CopyFrom(obj);
}


DelincuenteConfidente::~DelincuenteConfidente ()
{
}


void DelincuenteConfidente::CopyFrom (const DelincuenteConfidente & obj)
{
    this->supervisor = obj.supervisor;
}


DelincuenteConfidente & DelincuenteConfidente::operator = (const DelincuenteConfidente & obj)
{
    this->CopyFrom(obj);
    return (*this);
}


std::string DelincuenteConfidente::getSupervisor (void) const
{
	return this->supervisor;
}


void DelincuenteConfidente::setSupervisor (std::string supervisor)
{
	this->supervisor = supervisor;
}