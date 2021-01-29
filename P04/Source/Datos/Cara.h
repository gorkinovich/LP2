//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Datos_CaraH
#define Datos_CaraH

#include <vcl.h>
#include <string>
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
	Menton       menton;       /**< Mentón seleccionada de la cara. */

	std::string ficheroRetina;
	Graphics::TBitmap * imagenRetina;

	/**
	 * Borra la imagen cargada en memoria en imagenRetina.
	 */
	void borraImagenRetina (void);

protected:
	/**
	 * Dibuja la cara en un control del formulario.
	 * @param canvas Control sobre el que queremos dibujar.
	 */
	void dibujarCara (TCanvas * canvas) const;
	
	/**
	 * Dibuja la retina en un control del formulario.
	 * @param canvas Control sobre el que queremos dibujar.
	 */
	void dibujarRetina (Graphics::TBitmap *& canvas);

public:
	/**
	 * Constructor que crea una cara ya inicializada.
	 */
	Cara ();

	/**
	 * Constructor que crea una cara ya inicializada.
	 * @param unPelo          Tipo de pelo de la cara.
	 * @param unosOjos        Tipo de ojos de la cara.
	 * @param unaNarizYOrejas Tipo de nariz y orejas de la cara.
	 * @param unaBoca         Tipo de boca de la cara.
	 * @param unMenton        Tipo de mentón de la cara.
	 * @param unFicheroRetina Fichero con la retina de la cara.
	 */
	Cara (Pelo unPelo, Ojos unosOjos, NarizYOrejas unaNarizYOrejas,
		  Boca unaBoca, Menton unMenton, std::string unFicheroRetina);
        
	/**
	 * Constructor copia.
	 */
	Cara (const Cara & cara);

	/**
	 * Destructor de la clase.
	 */
    virtual ~Cara ();
                    
	/**
	 * Función para obtener el tipo de la clase actual.
	 * @return Devuelve el tipo de la clase.
	 */
    virtual std::string getClassName (void) const = 0;

	/**
	 * Sobrecarga del operador =.
	 */
	virtual Cara & operator = (const Cara & cara);
     
	/**
	 * Función para copiar una cara.
	 * @return Una copia de la cara actual.
	 */
	virtual Cara & clone (void) const = 0;

	/**
	 * Función para obtener el pelo de la cara indicada.
	 * @return Devuelve el pelo de la cara.
	 * @see getBoca(), getOjos(), getNarizYOrejas(), getMenton()
	 */
	Pelo getPelo (void) const;

	/**
	 * Función para obtener los ojos de la cara indicada.
	 * @return Devuelve los ojos de la cara.
	 * @see getBoca(), getNarizYOrejas(), getPelo(), getMenton()
	 */
	Ojos getOjos (void) const;

	/**
	 * Función para obtener la nariz y las orejas de la cara indicada.
	 * @return Devuelve la nariz y las orejas de la cara.
	 * @see getBoca(), getOjos(), getPelo(), getMenton()
	 */
	NarizYOrejas getNarizYOrejas (void) const;

	/**
	 * Función para obtener la boca de la cara indicada.
	 * @return Devuelve la boca de la cara.
	 * @see getOjos(), getNarizYOrejas(), getPelo(), getMenton()
	 */
	Boca getBoca (void) const;

	/**
	 * Función para obtener el mentón de la cara indicada.
	 * @return Devuelve la mentón de la cara.
	 * @see getBoca(), getOjos(), getNarizYOrejas(), getPelo()
	 */
	Menton getMenton (void) const;

	/**
	 * Función para obtener el fichero donde está la retina de la cara indicada.
	 * @return Devuelve el fichero donde está la retina de la cara.
	 */
	std::string getFicheroRetina (void) const;

	/**
	 * Función para obtener la imagen de la retina de la cara indicada.
	 * @return Devuelve la imagen de la retina de la cara.
	 */
	Graphics::TBitmap * getImagenRetina (void) const;
	          
	/**
	 * Función para establecer el pelo de la cara indicada.
	 * @param pelo Tipo de pelo de la cara.
	 * @see setBoca(), setOjos(), setNarizYOrejas(), setMenton()
	 */
	void setPelo (Pelo pelo);

	/**
	 * Función para establecer los ojos de la cara indicada.
	 * @param ojos Tipo de ojos de la cara.
	 * @see setBoca(), setNarizYOrejas(), setPelo(), setMenton()
	 */
	void setOjos (Ojos ojos);

	/**
	 * Función para establecer la nariz y las orejas de la cara indicada.
	 * @param narizYOrejas Tipo de nariz y orejas de la cara.
	 * @see setBoca(), setOjos(), setPelo(), setMenton()
	 */
	void setNarizYOrejas (NarizYOrejas narizYOrejas);

	/**
	 * Función para establecer la boca de la cara indicada.
	 * @param boca Tipo de boca de la cara.
	 * @see setOjos(), setNarizYOrejas(), setPelo(), setMenton()
	 */
	void setBoca (Boca boca);

	/**
	 * Función para establecer el mentón de la cara indicada.
	 * @param menton Tipo de mentón de la cara.
	 * @see setBoca(), setOjos(), setNarizYOrejas(), setPelo()
	 */
	void setMenton (Menton menton);

	/**
	 * Función para establecer el fichero donde está la retina de la cara indicada.
	 * @param ficheroRetina Fichero donde está la retina de la cara.
	 */
	void setFicheroRetina (std::string ficheroRetina);

	/**
	 * Sobrecarga del operador == para Cara.
	 */
	bool operator == (const Cara & cara) const;

	/**
	 * Función para saber si dos caras son parecidas.
	 */
	bool parecida (const Cara & cara) const;

	/**
	 * Función para saber si la cara está vacia.
	 */
	bool vacia (void) const;
     
	/**
	 * Dibuja la cara en un control del formulario.
	 * @param canvas Control sobre el que queremos dibujar.
	 */
	virtual void dibujaRetratoRobot (TCanvas * canvas) const = 0;

	/**
	 * Dibuja la cara en un control del formulario.
	 * @param canvas Control sobre el que queremos dibujar.
	 */
	virtual void dibujaRetina (Graphics::TBitmap *& canvas) = 0;
	
	/**
	 * Carga una imagen desde un fichero indicado.
	 * @param bmp Nombre del bmp a cargar.
	 */
    static Graphics::TBitmap * cargarBMP (std::string bmp);
};


#endif