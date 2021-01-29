//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include <fstream>
#include "Caras_IO.h"
#include "../Datos/CaraComun.h"
#include "../Datos/CaraClasificada.h"
#pragma package(smart_init)


//----------------------------------------------------------------------
typedef enum
{
	cara_comun       = 0,
	cara_clasificada = 1
} TCaras;


//----------------------------------------------------------------------
// Constantes y tipos necesarios para la carga de datos.
//----------------------------------------------------------------------
const int MAX_CARACTERES = 200;
typedef char nombre_io[MAX_CARACTERES];

typedef struct
{
        int pelo;
        int ojos;
        int narizYOrejas;
        int boca;
        int menton;
        nombre_io fichero;
} Registro_Cara;


//----------------------------------------------------------------------
/**
 * Función para obtener el tipo de un objeto.
 * @param data Objeto del que queremos saber su tipo.
 * @return Tipo del dato pasado a nuestro formato.
 */
TCaras getTCaras (const Cara * data)
{
	if(typeid(*data) == typeid(CaraComun))
	{
		return cara_comun;
	}
	else if(typeid(*data) == typeid(CaraClasificada))
	{
		return cara_clasificada;
	}
	else
	{
		return cara_comun;
	}
}


//----------------------------------------------------------------------
/**
 * Función para calcular el tamaño de un registro.
 * @param tipo Tipo cuyo tamaño queremos calcular.
 * @return El del tipo que le hemos indicado.
 */
int getTamanno (TCaras tipo)
{
	int tamanno = -1;

	switch (tipo)
	{
		case cara_comun:
			tamanno = sizeof(Registro_Cara);
			break;
		case cara_clasificada:
			tamanno = sizeof(Registro_Cara);
			break;
	}

	return tamanno;
}


//----------------------------------------------------------------------
/**
 * Función para cargar un objeto cara en una estructura.
 * @param dato Objeto cara que vamos a manejar.
 * @return Un puntero a una estructura con los datos del objeto.
 */
Registro_Cara * cargaCara (Cara * dato)
{
    Registro_Cara * tmp = new Registro_Cara;

    tmp->pelo = (int) dato->getPelo();
    tmp->ojos = (int) dato->getOjos();
    tmp->narizYOrejas = (int) dato->getNarizYOrejas();
    tmp->boca = (int) dato->getBoca();
    tmp->menton = (int) dato->getMenton();
    strcpy(tmp->fichero, dato->getFicheroRetina().c_str());

    return tmp;
}


//----------------------------------------------------------------------
/**
 * Función para cargar un objeto desde un registro.
 * @param tipo     Tipo cuyo tamaño queremos cargar.
 * @param dato     Datos con los que vamos a crear el objeto.
 * @param reultado Objeto resultante que vamos a devolver.
 */
void cargaCara (TCaras tipo, Registro_Cara * dato, Cara *& resultado)
{
	Pelo unPelo = (Pelo) dato->pelo;
	Ojos unOjos = (Ojos) dato->ojos;
	NarizYOrejas unNarizYOrejas = (NarizYOrejas) dato->narizYOrejas;
	Boca unBoca = (Boca) dato->boca;
	Menton unMenton = (Menton) dato->menton;
	std::string unFicheroRetina = dato->fichero;

	resultado = NULL;

	switch (tipo)
	{
		case cara_comun:
			resultado = new CaraComun(unPelo, unOjos, unNarizYOrejas,
									  unBoca, unMenton, unFicheroRetina);
			break;
		case cara_clasificada:
			resultado = new CaraClasificada(unPelo, unOjos, unNarizYOrejas,
											unBoca, unMenton, unFicheroRetina);
			break;
	}
}


//----------------------------------------------------------------------
/**
 * Sobrecarga del operador << para escribir una cara.
 * @param output Flujo de salida hacia el fichero.
 * @param data   Datos que estamos salvando.
 * @return El propio flujo de salida.
 */
std::ofstream & operator << (std::ofstream & output, Cara * data)
{
	Registro_Cara * tmp;
	TCaras tipo = getTCaras(data);
	output.write(reinterpret_cast<char *> (&tipo), sizeof(TCaras));
	int tamanno = getTamanno(tipo);

	switch (tipo)
	{
		case cara_comun:
			tmp = cargaCara(data);
			output.write(reinterpret_cast<char *> (tmp), tamanno);
			delete tmp;
			break;

		case cara_clasificada:
			tmp = cargaCara(data);
			output.write(reinterpret_cast<char *> (tmp), tamanno);
			delete tmp;
			break;
	}

	return output;
}


//----------------------------------------------------------------------
/**
 * Sobrecarga del operador >> para cargar una cara.
 * @param input Flujo de entrada hacia el contenedor.
 * @param data  Datos que estamos cargando.
 * @return El propio flujo de entrada.
 */
std::ifstream & operator >> (std::ifstream & input, Cara *& data)
{
	TCaras tipo;
	Registro_Cara * tmp;

	input.read(reinterpret_cast<char *> (&tipo), sizeof(TCaras));
	int tamanno = getTamanno(tipo);

	data = NULL;

	switch (tipo)
	{
		case cara_comun:
			tmp = new Registro_Cara;
			input.read(reinterpret_cast<char *> (tmp), tamanno);
			cargaCara(tipo, tmp, data);
			delete tmp;
			break;

		case cara_clasificada:
			tmp = new Registro_Cara;
			input.read(reinterpret_cast<char *> (tmp), tamanno);
			cargaCara(tipo, tmp, data);
			delete tmp;
			break;
	}

	return input;
}