//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "CaraClasificada.h"
#pragma package(smart_init)


Graphics::TBitmap * CaraClasificada::bitmaps[11] =
{
    Cara::cargarBMP("Images/A pescar.bmp"),
    Cara::cargarBMP("Images/Abanicos.bmp"),
    Cara::cargarBMP("Images/Azteca.bmp"),
    Cara::cargarBMP("Images/Grano de cafe.bmp"),
    Cara::cargarBMP("Images/Lazo azul 16.bmp"),
    Cara::cargarBMP("Images/Plumas.bmp"),
    Cara::cargarBMP("Images/Pompas.bmp"),
    Cara::cargarBMP("Images/Rhododendron.bmp"),
    Cara::cargarBMP("Images/Roca verde.bmp"),
    Cara::cargarBMP("Images/Santa Fe.bmp"),
    Cara::cargarBMP("Images/Viento.bmp")
};



CaraClasificada::CaraClasificada () : Cara ()
{
}


CaraClasificada::CaraClasificada (Pelo unPelo, Ojos unosOjos, NarizYOrejas unaNarizYOrejas,
                      Boca unaBoca, Menton unMenton, std::string unFicheroRetina) :
    Cara (unPelo, unosOjos, unaNarizYOrejas, unaBoca, unMenton, unFicheroRetina)
{
}


CaraClasificada::CaraClasificada (const CaraClasificada & cara)
{
	(*this) = cara;
}


CaraClasificada::~CaraClasificada ()
{
}


std::string CaraClasificada::getClassName (void) const
{
    return "CaraClasificada";
}


Cara & CaraClasificada::operator = (const Cara & cara)
{
	this->Cara::operator = (cara);
	return (*this);
}


CaraClasificada & CaraClasificada::operator = (const CaraClasificada & cara)
{
	this->Cara::operator = (cara);
	return (*this);
}


Cara & CaraClasificada::clone (void) const
{
	CaraClasificada * aux = new CaraClasificada();
	(*aux) = (*this);
	return (*aux);
}


void CaraClasificada::dibujaRetratoRobot (TCanvas * canvas) const
{
    canvas->Draw(0, 0, CaraClasificada::bitmaps[random(11)]);
}


void CaraClasificada::dibujaRetina (Graphics::TBitmap *& canvas)
{
    canvas = CaraClasificada::bitmaps[random(11)];
}


void CaraClasificada::dibujaSupCara (TCanvas * canvas) const
{
    this->dibujarCara(canvas);
}


void CaraClasificada::dibujaSupRetina (Graphics::TBitmap *& canvas)
{
    this->dibujarRetina(canvas);
}
