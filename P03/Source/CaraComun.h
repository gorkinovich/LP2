//----------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 03 - Grupo 03.
//----------------------------------------------------------------------
#ifndef CaraComunH
#define CaraComunH

#include "Cara.h"


/**
 * Clase para almacenar los datos referentes a una cara com�n.
 */
class CaraComun : public Cara
{
public:
	/**
	 * Constructor que crea una cara ya inicializada.
	 */
	CaraComun ();

	/**
	 * Constructor que crea una cara ya inicializada.
	 * @param pelo Tipo de pelo de la cara.
	 * @param ojos Tipo de ojos de la cara.
	 * @param nariz Tipo de nariz y orejas de la cara.
	 * @param boca Tipo de boca de la cara.
	 * @param menton Tipo de ment�n de la cara.
	 */
	CaraComun (Pelo unPelo, Ojos unosOjos, NarizYOrejas unaNarizYOrejas,
	     	   Boca unaBoca, Menton unMenton);
        
	/**
	 * Destructor de la clase.
	 */
    virtual ~CaraComun ();
                    
	/**
	 * Funci�n para obtener el tipo de la clase actual.
	 * @return Devuelve el tipo de la clase.
	 */
    virtual string getClassName (void) const;

	/**
	 * Dibuja la cara en un control del formulario.
	 * @param canvas Control sobre el que queremos dibujar.
	 */
	virtual void dibuja (TCanvas * canvas) const;

	/**
	 * Salva la cara en un fichero de texto.
	 * @param salida Flujo de salida al fichero.
	 * @return Devuelve true si todo ha ido bien.
	 */
	virtual bool salvaTXT (ofstream & salida) const;

	/**
	 * Carga la cara de un fichero de texto.
	 * @param entrada Flujo de entrada al fichero.
	 * @return Devuelve true si todo ha ido bien.
	 */
	virtual bool cargaTXT (ifstream & entrada);
};


#endif
