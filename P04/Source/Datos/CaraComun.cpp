//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "CaraComun.h"
#pragma package(smart_init)


CaraComun::CaraComun () : Cara ()
{
}


CaraComun::CaraComun (Pelo unPelo, Ojos unosOjos, NarizYOrejas unaNarizYOrejas,
                      Boca unaBoca, Menton unMenton, std::string unFicheroRetina) :
    Cara (unPelo, unosOjos, unaNarizYOrejas, unaBoca, unMenton, unFicheroRetina)
{
}


CaraComun::CaraComun (const CaraComun & cara)
{
	(*this) = cara;
}


CaraComun::~CaraComun ()
{
}


std::string CaraComun::getClassName (void) const
{
    return "CaraComun";
}


Cara & CaraComun::operator = (const Cara & cara)
{
	this->Cara::operator = (cara);
	return (*this);
}


CaraComun & CaraComun::operator = (const CaraComun & cara)
{
	this->Cara::operator = (cara);
	return (*this);
}


Cara & CaraComun::clone (void) const
{
	CaraComun * aux = new CaraComun();
	(*aux) = (*this);
	return (*aux);
}


void CaraComun::dibujaRetratoRobot (TCanvas * canvas) const
{
    this->dibujarCara(canvas);
}


void CaraComun::dibujaRetina (Graphics::TBitmap *& canvas)
{
    this->dibujarRetina(canvas);
}