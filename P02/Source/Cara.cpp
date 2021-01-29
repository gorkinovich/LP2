//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 02 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "Cara.h"
#pragma package(smart_init)


bool Cara::salvaTXT (ofstream & salida) const
{
	salida << "Cara.pelo=" << getPeloAsString(this->pelo) << endl;
	salida << "Cara.ojos=" << getOjosAsString(this->ojos) << endl;
	salida << "Cara.narizYOrejas=" << getNarizYOrejasAsString(this->narizYOrejas) << endl;
	salida << "Cara.boca=" << getBocaAsString(this->boca) << endl;
	salida << "Cara.menton=" << getMentonAsString(this->menton) << endl;

	return true;
}


bool Cara::cargaTXT (ifstream & entrada)
{
	char aux[256];
	char * tipo;

	entrada.getline(aux, 256);
	if(entrada.eof()) return false;
	tipo = strchr(aux, '=') + 1;
	getPeloFromString(tipo, this->pelo);

	entrada.getline(aux, 256);
	if(entrada.eof()) return false;
	tipo = strchr(aux, '=') + 1;
	getOjosFromString(tipo, this->ojos);

	entrada.getline(aux, 256);
	if(entrada.eof()) return false;
	tipo = strchr(aux, '=') + 1;
	getNarizYOrejasFromString(tipo, this->narizYOrejas);

	entrada.getline(aux, 256);
	if(entrada.eof()) return false;
	tipo = strchr(aux, '=') + 1;
	getBocaFromString(tipo, this->boca);

	entrada.getline(aux, 256);
	if(entrada.eof()) return false;
	tipo = strchr(aux, '=') + 1;
	getMentonFromString(tipo, this->menton);

	return true;
}