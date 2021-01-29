//----------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Datos_CaraClasificadaH
#define Datos_CaraClasificadaH

#include "Cara.h"


/**
 * Clase para almacenar los datos referentes a una cara com�n.
 */
class CaraClasificada : public Cara
{
protected:
    static Graphics::TBitmap * bitmaps[11];

	/**
	 * Dibuja la cara en un control del formulario.
	 * @param canvas Control sobre el que queremos dibujar.
	 */
	virtual void dibujaSupCara (TCanvas * canvas) const;

	/**
	 * Dibuja la retina en un control del formulario.
	 * @param canvas Control sobre el que queremos dibujar.
	 */
	virtual void dibujaSupRetina (Graphics::TBitmap *& canvas);

public:
	/**
	 * Constructor que crea una cara ya inicializada.
	 */
	CaraClasificada ();

	/**
	 * Constructor que crea una cara ya inicializada.
	 * @param unPelo          Tipo de pelo de la cara.
	 * @param unosOjos        Tipo de ojos de la cara.
	 * @param unaNarizYOrejas Tipo de nariz y orejas de la cara.
	 * @param unaBoca         Tipo de boca de la cara.
	 * @param unMenton        Tipo de ment�n de la cara.
	 * @param unFicheroRetina Fichero con la retina de la cara.
	 */
	CaraClasificada (Pelo unPelo, Ojos unosOjos, NarizYOrejas unaNarizYOrejas,
	     	         Boca unaBoca, Menton unMenton, std::string unFicheroRetina);
        
	/**
	 * Constructor copia.
	 */
	CaraClasificada (const CaraClasificada & cara);

	/**
	 * Destructor de la clase.
	 */
    virtual ~CaraClasificada ();
                    
	/**
	 * Funci�n para obtener el tipo de la clase actual.
	 * @return Devuelve el tipo de la clase.
	 */
    virtual std::string getClassName (void) const;

	/**
	 * Sobrecarga del operador =.
	 */
	virtual Cara & operator = (const Cara & cara);
     
	/**
	 * Sobrecarga del operador =.
	 */
	virtual CaraClasificada & operator = (const CaraClasificada & cara);
     
	/**
	 * Funci�n para copiar una cara.
	 * @return Una copia de la cara actual.
	 */
	virtual Cara & clone (void) const;
     
	/**
	 * Dibuja la cara en un control del formulario.
	 * @param canvas Control sobre el que queremos dibujar.
	 */
	virtual void dibujaRetratoRobot (TCanvas * canvas) const;

	/**
	 * Dibuja la cara en un control del formulario.
	 * @param canvas Control sobre el que queremos dibujar.
	 */
	virtual void dibujaRetina (Graphics::TBitmap *& canvas);    

    
    friend class TConfidentes;
	friend class TUsuarios;
};


#endif