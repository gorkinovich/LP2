//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 03 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "Delincuente.h"         
#include "CaraComun.h"
#include "CaraConfidente.h"
#pragma package(smart_init)


Delincuente::Delincuente ()
{
	this->dni     = "";
	this->nombre  = "";
	this->delitos = "";
    this->cara    = NULL;
}


Delincuente::Delincuente (string dni, string nombre, string delitos, Cara * cara)
{
	this->dni     = dni;
	this->nombre  = nombre;
	this->delitos = delitos;
	this->cara    = cara;
}


Delincuente::~Delincuente ()
{
    if(this->cara != NULL)
        delete this->cara;
}


Delincuente & Delincuente::operator = (const Delincuente & delincuente)
{ 
	this->dni     = delincuente.dni;
	this->nombre  = delincuente.nombre;
	this->delitos = delincuente.delitos;

    if(this->cara == NULL)
    {
        if(delincuente.cara->getClassName() == "CaraConfidente")
            this->cara = new CaraConfidente();
        else
            this->cara = new CaraComun();
    }

    if(this->cara != NULL)
    	*this->cara = *delincuente.cara;

    return (*this);
}


string Delincuente::getNombre (void) const
{
	return this->nombre;
}


string Delincuente::getDelitos (void) const
{
	return this->delitos;
}


string Delincuente::getDNI (void) const
{
	return this->dni;
}


Cara * Delincuente::getCara (void) const
{
	return this->cara;
}


void Delincuente::setNombre (string nombre)
{
	this->nombre = nombre;
}


void Delincuente::setDelitos (string delitos)
{
	this->delitos = delitos;
}


void Delincuente::setDNI (string dni)
{
	this->dni = dni;
}


void Delincuente::setCara (Cara * cara)
{
	this->cara = cara;
}


bool Delincuente::operator == (const Delincuente & delincuente) const
{
	return this->nombre == delincuente.nombre;
}


bool Delincuente::operator <= (const Delincuente & delincuente) const
{
	return (this->nombre == delincuente.nombre) ||
			(this->nombre < delincuente.nombre) ;
}


bool Delincuente::parecido (const Cara & cara) const
{
	return (*this->cara == cara);
}
