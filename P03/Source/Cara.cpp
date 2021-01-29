//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 03 - Grupo 03.
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
}


Cara::Cara (Pelo unPelo, Ojos unosOjos, NarizYOrejas unaNarizYOrejas,
	        Boca unaBoca, Menton unMenton)
{
	this->pelo         = unPelo;
	this->ojos         = unosOjos;
	this->narizYOrejas = unaNarizYOrejas;
	this->boca         = unaBoca;
	this->menton       = unMenton;
}


Cara::~Cara ()
{
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


bool Cara::operator == (const Cara & cara) const
{
	return (this->boca == cara.boca) && (this->ojos == cara.ojos) &&
		   (this->narizYOrejas == cara.narizYOrejas) &&
		   (this->pelo == cara.pelo) && (this->menton == cara.menton);
}


void Cara::dibujaCara (TCanvas * canvas) const
{                         
    canvas->Font->Name = "Courier New";
    canvas->Font->Size = 16;

    canvas->TextOutA(0, 0,  dibujaPelo(this->pelo).c_str());
    canvas->TextOutA(0, 24, dibujaOjos(this->ojos).c_str());
    canvas->TextOutA(0, 48, dibujaNarizYOrejas(this->narizYOrejas).c_str());
    canvas->TextOutA(0, 72, dibujaBoca(this->boca).c_str());
    canvas->TextOutA(0, 96, dibujaMenton(this->menton).c_str());
}  


bool Cara::salvarDatosTXT (ofstream & salida) const
{
	salida << "Cara.pelo=" << getPeloAsString(this->pelo) << endl;
	salida << "Cara.ojos=" << getOjosAsString(this->ojos) << endl;
	salida << "Cara.narizYOrejas=" << getNarizYOrejasAsString(this->narizYOrejas) << endl;
	salida << "Cara.boca=" << getBocaAsString(this->boca) << endl;
	salida << "Cara.menton=" << getMentonAsString(this->menton) << endl;

	return true;
}


bool Cara::cargarDatosTXT (ifstream & entrada)
{
	char aux[256];
	char * tipo, * contenido;

    for(int i = 0; i < 5; ++i)
    {
    	entrada.getline(aux, 256);
	    if(entrada.eof()) return false;

        tipo = strchr(aux, '.') + 1;
        contenido = strchr(aux, '=') + 1;

        switch(tipo[0])
        {  
        case 'p': 
            getPeloFromString(contenido, this->pelo);
            break;

        case 'o':
            getOjosFromString(contenido, this->ojos);
            break;

        case 'n':
            getNarizYOrejasFromString(contenido, this->narizYOrejas);
            break;
                
        case 'b':
            getBocaFromString(contenido, this->boca);
            break;

        case 'm':
            getMentonFromString(contenido, this->menton);
            break;
        }
    }

	return true;
}
