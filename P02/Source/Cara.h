//----------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 02 - Grupo 03.
//----------------------------------------------------------------------
#ifndef CaraH
#define CaraH


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "CaraRasgos.h"


/**
 * Clase para almacenar los datos referentes a una cara.
 */
class Cara
{
protected:
	Pelo         pelo;         /**< Pelo seleccionado de la cara. */
	Ojos         ojos;         /**< Ojos seleccionados de la cara. */
	NarizYOrejas narizYOrejas; /**< Nariz y orejas seleccionadas de la cara. */
	Boca         boca;         /**< Boca seleccionada de la cara. */
	Menton       menton;       /**< Ment�n seleccionada de la cara. */

public:
	/**
	 * Constructor que crea una cara ya inicializada.
	 */
	Cara ()
	{
		this->pelo         = peloX;
		this->ojos         = ojosX;
		this->narizYOrejas = narizYOrejasX;
		this->boca         = bocaX;
		this->menton       = mentonX;
	}

	/**
	 * Constructor que crea una cara ya inicializada.
	 * @param pelo Tipo de pelo de la cara.
	 * @param ojos Tipo de ojos de la cara.
	 * @param nariz Tipo de nariz y orejas de la cara.
	 * @param boca Tipo de boca de la cara.
	 * @param menton Tipo de ment�n de la cara.
	 */
	Cara (Pelo unPelo, Ojos unosOjos, NarizYOrejas unaNarizYOrejas,
		  Boca unaBoca, Menton unMenton)
	{
		this->pelo         = unPelo;
		this->ojos         = unosOjos;
		this->narizYOrejas = unaNarizYOrejas;
		this->boca         = unaBoca;
		this->menton       = unMenton;
	}

	/**
	 * Funci�n para obtener el pelo de la cara indicada.
	 * @return Devuelve el pelo de la cara.
	 * @see getBoca(), getOjos(), getNarizYOrejas(), getMenton()
	 */
	Pelo getPelo (void) const
	{
		return this->pelo;
	}

	/**
	 * Funci�n para obtener los ojos de la cara indicada.
	 * @return Devuelve los ojos de la cara.
	 * @see getBoca(), getNarizYOrejas(), getPelo(), getMenton()
	 */
	Ojos getOjos (void) const
	{
		return this->ojos;
	}

	/**
	 * Funci�n para obtener la nariz y las orejas de la cara indicada.
	 * @return Devuelve la nariz y las orejas de la cara.
	 * @see getBoca(), getOjos(), getPelo(), getMenton()
	 */
	NarizYOrejas getNarizYOrejas (void) const
	{
		return this->narizYOrejas;
	}

	/**
	 * Funci�n para obtener la boca de la cara indicada.
	 * @return Devuelve la boca de la cara.
	 * @see getOjos(), getNarizYOrejas(), getPelo(), getMenton()
	 */
	Boca getBoca (void) const
	{
		return this->boca;
	}

	/**
	 * Funci�n para obtener el ment�n de la cara indicada.
	 * @return Devuelve la ment�n de la cara.
	 * @see getBoca(), getOjos(), getNarizYOrejas(), getPelo()
	 */
	Menton getMenton (void) const
	{
		return this->menton;
	}
	
	/**
	 * Sobrecarga del operador == para Cara.
	 */
	bool operator == (const Cara & cara) const
	{
		if((this->boca == cara.boca) && (this->ojos == cara.ojos) &&
		   (this->narizYOrejas == cara.narizYOrejas) &&
		   (this->pelo == cara.pelo) && (this->menton == cara.menton))
			return true;
		else
			return false;
	}

	/**
	 * Salva la cara en un fichero de texto.
	 * @param salida Flujo de salida al fichero.
	 * @return Devuelve true si todo ha ido bien.
	 */
	bool salvaTXT (ofstream & salida) const;
	
	/**
	 * Carga la cara de un fichero de texto.
	 * @param entrada Flujo de entrada al fichero.
	 * @return Devuelve true si todo ha ido bien.
	 */
	bool cargaTXT (ifstream & entrada);
};


#endif