//----------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 02 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "Delincuente.h"
#pragma package(smart_init)


bool Delincuente::salvaTXT (ofstream & salida) const
{
	salida << "Delincuente.nombre=" << this->nombre << endl;
	salida << "Delincuente.delitos=" << this->delitos << endl;

	if(this->cara.salvaTXT(salida) == false)
	{
		return false;
	}

	return true;
}


bool Delincuente::cargaTXT (ifstream & entrada)
{
	char aux[256];
	char * tipo;

	entrada.getline(aux, 256);
	if(entrada.eof()) return false;
	tipo = strchr(aux, '=') + 1;
	this->nombre = tipo;

	entrada.getline(aux, 256);
	if(entrada.eof()) return false;
	tipo = strchr(aux, '=') + 1;
	this->delitos = tipo;

	if(this->cara.cargaTXT(entrada) == false)
	{
		return false;
	}

	return true;
}
