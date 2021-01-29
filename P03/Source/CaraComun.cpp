//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 03 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "CaraComun.h"
#pragma package(smart_init)


CaraComun::CaraComun () : Cara ()
{
}


CaraComun::CaraComun (Pelo unPelo, Ojos unosOjos, NarizYOrejas unaNarizYOrejas,
                      Boca unaBoca, Menton unMenton) :
    Cara (unPelo, unosOjos, unaNarizYOrejas, unaBoca, unMenton)
{
}


CaraComun::~CaraComun ()
{
}


string CaraComun::getClassName (void) const
{
    return "CaraComun";
}


void CaraComun::dibuja (TCanvas * canvas) const
{
    this->dibujaCara(canvas);
}


bool CaraComun::salvaTXT (ofstream & salida) const
{
	salida << this->getClassName().c_str() << endl;
	return this->salvarDatosTXT(salida);
}


bool CaraComun::cargaTXT (ifstream & entrada)
{
	char aux[256];
    
    entrada.getline(aux, 256);
    if(entrada.eof() || (aux != this->getClassName())) return false;

	return this->cargarDatosTXT(entrada);
}
