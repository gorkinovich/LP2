//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "Persona.h"
#pragma package(smart_init)


Persona::Persona ()
{
	this->id     = "";
	this->nombre = "";
    this->cara   = NULL;
}


Persona::Persona (std::string id, std::string nombre, Cara * cara)
{
	this->id     = id;
	this->nombre = nombre;
	this->cara   = cara;
}


Persona::Persona (const Persona & obj)
{
	this->CopyFrom(obj);
}


Persona::~Persona ()
{
    if(this->cara != NULL)
        delete this->cara;
}


Persona & Persona::operator = (const Persona & obj)
{
	this->CopyFrom(obj);
	return (*this);
}


void Persona::CopyFrom (const Persona & obj)
{
	this->id     = obj.id;
	this->nombre = obj.nombre;

	if(this->cara != NULL) delete this->cara;
	this->cara = &(obj.cara->clone());
}


std::string Persona::getNombre (void) const
{
	return this->nombre;
}


std::string Persona::getID (void) const
{
	return this->id;
}


Cara * Persona::getCara (void) const
{
	return this->cara;
}


void Persona::setNombre (std::string nombre)
{
	this->nombre = nombre;
}


void Persona::setID (std::string id)
{
	this->id = id;
}


void Persona::setCara (Cara * cara)
{
    if(this->cara != NULL)
        delete this->cara;

	this->cara = cara;
}


bool Persona::operator == (const Persona & persona) const
{
	return this->nombre == persona.nombre;
}


bool Persona::operator <= (const Persona & persona) const
{
	return (this->nombre == persona.nombre) ||
			(this->nombre < persona.nombre);
}


bool Persona::parecido (const Cara & cara) const
{
	return (*this->cara == cara);
}