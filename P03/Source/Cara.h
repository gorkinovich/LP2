//----------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 03 - Grupo 03.
//----------------------------------------------------------------------
#ifndef CaraH
#define CaraH

#include <vcl.h>

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
private:
	Pelo         pelo;         /**< Pelo seleccionado de la cara. */
	Ojos         ojos;         /**< Ojos seleccionados de la cara. */
	NarizYOrejas narizYOrejas; /**< Nariz y orejas seleccionadas de la cara. */
	Boca         boca;         /**< Boca seleccionada de la cara. */
	Menton       menton;       /**< Ment�n seleccionada de la cara. */

protected:
	/**
	 * Dibuja la cara en un control del formulario.
	 * @param canvas Control sobre el que queremos dibujar.
	 */
	void dibujaCara (TCanvas * canvas) const;

	/**
	 * Salva la cara en un fichero de texto.
	 * @param salida Flujo de salida al fichero.
	 * @return Devuelve true si todo ha ido bien.
	 */
	bool salvarDatosTXT (ofstream & salida) const;

	/**
	 * Carga la cara de un fichero de texto.
	 * @param entrada Flujo de entrada al fichero.
	 * @return Devuelve true si todo ha ido bien.
	 */
	bool cargarDatosTXT (ifstream & entrada);

public:
	/**
	 * Constructor que crea una cara ya inicializada.
	 */
	Cara ();

	/**
	 * Constructor que crea una cara ya inicializada.
	 * @param pelo Tipo de pelo de la cara.
	 * @param ojos Tipo de ojos de la cara.
	 * @param nariz Tipo de nariz y orejas de la cara.
	 * @param boca Tipo de boca de la cara.
	 * @param menton Tipo de ment�n de la cara.
	 */
	Cara (Pelo unPelo, Ojos unosOjos, NarizYOrejas unaNarizYOrejas,
		  Boca unaBoca, Menton unMenton);
        
	/**
	 * Destructor de la clase.
	 */
    virtual ~Cara ();
                    
	/**
	 * Funci�n para obtener el tipo de la clase actual.
	 * @return Devuelve el tipo de la clase.
	 */
    virtual string getClassName (void) const = 0;

	/**
	 * Funci�n para obtener el pelo de la cara indicada.
	 * @return Devuelve el pelo de la cara.
	 * @see getBoca(), getOjos(), getNarizYOrejas(), getMenton()
	 */
	Pelo getPelo (void) const;

	/**
	 * Funci�n para obtener los ojos de la cara indicada.
	 * @return Devuelve los ojos de la cara.
	 * @see getBoca(), getNarizYOrejas(), getPelo(), getMenton()
	 */
	Ojos getOjos (void) const;

	/**
	 * Funci�n para obtener la nariz y las orejas de la cara indicada.
	 * @return Devuelve la nariz y las orejas de la cara.
	 * @see getBoca(), getOjos(), getPelo(), getMenton()
	 */
	NarizYOrejas getNarizYOrejas (void) const;

	/**
	 * Funci�n para obtener la boca de la cara indicada.
	 * @return Devuelve la boca de la cara.
	 * @see getOjos(), getNarizYOrejas(), getPelo(), getMenton()
	 */
	Boca getBoca (void) const;

	/**
	 * Funci�n para obtener el ment�n de la cara indicada.
	 * @return Devuelve la ment�n de la cara.
	 * @see getBoca(), getOjos(), getNarizYOrejas(), getPelo()
	 */
	Menton getMenton (void) const;
	          
	/**
	 * Funci�n para establecer el pelo de la cara indicada.
	 * @param pelo Tipo de pelo de la cara.
	 * @see setBoca(), setOjos(), setNarizYOrejas(), setMenton()
	 */
	void setPelo (Pelo pelo);

	/**
	 * Funci�n para establecer los ojos de la cara indicada.
	 * @param ojos Tipo de ojos de la cara.
	 * @see setBoca(), setNarizYOrejas(), setPelo(), setMenton()
	 */
	void setOjos (Ojos ojos);

	/**
	 * Funci�n para establecer la nariz y las orejas de la cara indicada.
	 * @return narizYOrejas Tipo de nariz y orejas de la cara.
	 * @see setBoca(), setOjos(), setPelo(), setMenton()
	 */
	void setNarizYOrejas (NarizYOrejas narizYOrejas);

	/**
	 * Funci�n para establecer la boca de la cara indicada.
	 * @return boca Tipo de boca de la cara.
	 * @see setOjos(), setNarizYOrejas(), setPelo(), setMenton()
	 */
	void setBoca (Boca boca);

	/**
	 * Funci�n para establecer el ment�n de la cara indicada.
	 * @return menton Tipo de ment�n de la cara.
	 * @see setBoca(), setOjos(), setNarizYOrejas(), setPelo()
	 */
	void setMenton (Menton menton);

	/**
	 * Sobrecarga del operador == para Cara.
	 */
	bool operator == (const Cara & cara) const;
     
	/**
	 * Dibuja la cara en un control del formulario.
	 * @param canvas Control sobre el que queremos dibujar.
	 */
	virtual void dibuja (TCanvas * canvas) const = 0;

	/**
	 * Salva la cara en un fichero de texto.
	 * @param salida Flujo de salida al fichero.
	 * @return Devuelve true si todo ha ido bien.
	 */
	virtual bool salvaTXT (ofstream & salida) const = 0;

	/**
	 * Carga la cara de un fichero de texto.
	 * @param entrada Flujo de entrada al fichero.
	 * @return Devuelve true si todo ha ido bien.
	 */
	virtual bool cargaTXT (ifstream & entrada) = 0;
};


#endif