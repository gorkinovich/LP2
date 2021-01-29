//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "Cara.h"
#pragma package(smart_init)


Cara::Cara ()
{
	this->pelo         = peloX;
	this->ojos         = ojosX;
	this->narizYOrejas = narizYOrejasX;
	this->boca         = bocaX;
	this->menton       = mentonX;

	this->ficheroRetina = "";
	this->imagenRetina  = NULL;
}


Cara::Cara (Pelo unPelo, Ojos unosOjos, NarizYOrejas unaNarizYOrejas,
	        Boca unaBoca, Menton unMenton, std::string unFicheroRetina)
{                      
	this->imagenRetina  = NULL;
    
	this->setPelo(unPelo);
	this->setOjos(unosOjos);
	this->setNarizYOrejas(unaNarizYOrejas);
	this->setBoca(unaBoca);
	this->setMenton(unMenton);
	this->setFicheroRetina(unFicheroRetina);
}


Cara::Cara (const Cara & cara)
{
	(*this) = cara;
}


Cara::~Cara ()
{
	this->borraImagenRetina();
}


void Cara::borraImagenRetina (void)
{
	if(this->imagenRetina != NULL)
	{
		delete this->imagenRetina;
		this->imagenRetina = NULL;
	}
}


Cara & Cara::operator = (const Cara & cara)
{
	this->setPelo(cara.getPelo());
	this->setOjos(cara.getOjos());
	this->setNarizYOrejas(cara.getNarizYOrejas());
	this->setBoca(cara.getBoca());
	this->setMenton(cara.getMenton());
	this->setFicheroRetina(cara.getFicheroRetina());

	return (*this);
}

 
Pelo Cara::getPelo (void) const
{
	return this->pelo;
}


Ojos Cara::getOjos (void) const
{
	return this->ojos;
}


NarizYOrejas Cara::getNarizYOrejas (void) const
{
	return this->narizYOrejas;
}


Boca Cara::getBoca (void) const
{
	return this->boca;
}


Menton Cara::getMenton (void) const
{
	return this->menton;
}


std::string Cara::getFicheroRetina (void) const
{
	return this->ficheroRetina;
}


Graphics::TBitmap * Cara::getImagenRetina (void) const
{
	return this->imagenRetina;
}
	       

void Cara::setPelo (Pelo pelo)
{
	this->pelo = pelo;
}


void Cara::setOjos (Ojos ojos)
{
	this->ojos = ojos;
}


void Cara::setNarizYOrejas (NarizYOrejas narizYOrejas)
{
	this->narizYOrejas = narizYOrejas;
}


void Cara::setBoca (Boca boca)
{
	this->boca = boca;
}


void Cara::setMenton (Menton menton)
{
	this->menton = menton;
}


void Cara::setFicheroRetina (std::string ficheroRetina)
{
	this->ficheroRetina = ficheroRetina;
	this->borraImagenRetina();
	this->imagenRetina = Cara::cargarBMP(ficheroRetina);
}


bool Cara::operator == (const Cara & cara) const
{
	return (this->boca == cara.boca) && (this->ojos == cara.ojos) &&
		   (this->narizYOrejas == cara.narizYOrejas) &&
		   (this->pelo == cara.pelo) && (this->menton == cara.menton) &&
		   (this->ficheroRetina == cara.ficheroRetina);
}


bool Cara::parecida (const Cara & cara) const
{
	return (this->boca == cara.boca) && (this->ojos == cara.ojos) &&
		   (this->narizYOrejas == cara.narizYOrejas) &&
		   (this->pelo == cara.pelo) && (this->menton == cara.menton);
}


bool Cara::vacia (void) const
{
	return ((this->getPelo() == peloX) || (this->getOjos() == ojosX) ||
			(this->getNarizYOrejas() == narizYOrejasX) || (this->getBoca() == bocaX) ||
			(this->getMenton() == mentonX));
}


Graphics::TBitmap * Cara::cargarBMP (std::string bmp)
{
    if(bmp != "")
    {
        Graphics::TBitmap * BMP = &Graphics::TBitmap();
        BMP->LoadFromFile(bmp.c_str());
        return BMP;
    }
    else
    {
        return NULL;
    }
}


void Cara::dibujarCara (TCanvas * canvas) const
{                         
    canvas->Font->Name = "Courier New";
    canvas->Font->Size = 16;

    canvas->TextOutA(0, 0,  dibujaPelo(this->pelo).c_str());
    canvas->TextOutA(0, 24, dibujaOjos(this->ojos).c_str());
    canvas->TextOutA(0, 48, dibujaNarizYOrejas(this->narizYOrejas).c_str());
    canvas->TextOutA(0, 72, dibujaBoca(this->boca).c_str());
    canvas->TextOutA(0, 96, dibujaMenton(this->menton).c_str());
}


void Cara::dibujarRetina (Graphics::TBitmap *& canvas)
{
    if(this->imagenRetina != NULL)
        canvas = this->imagenRetina;
}
