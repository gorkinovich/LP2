//----------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 03 - Grupo 03.
//----------------------------------------------------------------------
#ifndef DelincuenteConfidenteH
#define DelincuenteConfidenteH

#include "Delincuente.h"


/**
 * Clase para almacenar los datos referentes a un delincuente.
 */
class DelincuenteConfidente : public Delincuente
{
private:
    string supervisor;

public:
	/**
	 * Constructor que crea un delincuente ya inicializado.
	 */
	DelincuenteConfidente ();

	/**
	 * Constructor que crea un delincuente ya inicializado.
	 * @param nombre Nombre del delincuente.
	 * @param delitos Delitos del delincuente.
	 * @param cara Cara del delincuente.
	 */
	DelincuenteConfidente (string dni, string nombre, string delitos,
                           string supervisor, Cara * cara);

	/**
	 * Destructor de la clase.
	 */
    virtual ~DelincuenteConfidente ();
               
	/**
	 * Operador de asignaci�n sobrecargado.
	 */
    virtual Delincuente & operator = (const Delincuente & delincuente);

	/**
	 * Funci�n para obtener el tipo de la clase actual.
	 * @return Devuelve el tipo de la clase.
	 */
    virtual string getClassName (void) const;
           
	/**
	 * Funci�n para obtener el supervisor del delincuente indicado.
	 * @return Devuelve el supervisor del delincuente indicado.
	 */
	string getSupervisor (void) const;

	/**
	 * Funci�n para establecer el supervisor del delincuente indicado.
	 * @param supervisor Supervisor del delincuente.
	 */
	void setSupervisor (string supervisor);

	/**
	 * Salva el delincuente en un fichero de texto.
	 * @param salida Flujo de salida al fichero.
	 * @return Devuelve true si todo ha ido bien.
	 */
	virtual bool salvaTXT (ofstream & salida) const;

	/**
	 * Carga el delincuente de un fichero de texto.
	 * @param entrada Flujo de entrada al fichero.
	 * @return Devuelve true si todo ha ido bien.
	 */
	virtual bool cargaTXT (ifstream & entrada);


    friend class TConfidentes;
};


#endif