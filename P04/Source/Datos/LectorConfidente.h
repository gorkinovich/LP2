//----------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Datos_LectorConfidenteH
#define Datos_LectorConfidenteH

#include "Lector.h"
#include "DelincuenteConfidente.h"
#include "CaraClasificada.h"


/**
 * Clase para almacenar los datos referentes a un delincuente.
 */
class LectorConfidente : public Lector, public DelincuenteConfidente
{
protected:
	/**
	 * Funci�n para copiar de un objeto.
	 * @param obj Objeto que queremos copiar.
	 */
	void CopyFrom (const LectorConfidente & obj);

	/**
	 * Funci�n para establecer la cara del delincuente indicado.
	 * @param cara Cara de la persona indicada.
	 */
	void setCara (CaraComun * cara);

public:
	/**
	 * Constructor que crea un delincuente ya inicializado.
	 */
	LectorConfidente ();

	/**
	 * Constructor que crea un delincuente ya inicializado.
	 * @param id         ID del delincuente.
	 * @param nombre     Nombre del delincuente.
	 * @param cara       Cara del delincuente.
	 * @param cometidos  Delitos cometidos del delincuente.
	 * @param concretos  Delitos concretos del delincuente.
	 * @param supervisor Nombre del supervisor.
	 */
	LectorConfidente (std::string id, std::string nombre, CaraComun * cara,
					  ListaOrdenada<Delitos> * cometidos,
					  ListaOrdenada<std::string> * concretos, std::string supervisor);

	/**
	 * Constructor copia.
	 * @param obj Delincuente que queremos copiar.
	 */
	LectorConfidente (const LectorConfidente & obj);

	/**
	 * Destructor de la clase.
	 */
    virtual ~LectorConfidente ();

	/**
	 * Sobrecarga del operador =.
	 */
	virtual Persona & operator = (const Persona & obj);

	/**
	 * Operador de asignaci�n sobrecargado.
	 */
    virtual DelincuenteConfidente & operator = (const DelincuenteConfidente & obj);

	/**
	 * Sobrecarga del operador =.
	 */
	LectorConfidente & operator = (const LectorConfidente & obj);

	/**
	 * Funci�n para hacer una copia del objeto.
	 * @return La copia del objeto actual.
	 */
	virtual Persona & clone (void) const;

	/**
	 * Funci�n para obtener el tipo de la clase actual.
	 * @return Devuelve el tipo de la clase.
	 */
    virtual std::string getClassName (void) const;

	/**
	 * Funci�n para establecer la cara del delincuente indicado.
	 * @param cara Cara de la persona indicada.
	 */
	void setCara (CaraClasificada * cara);

};


#endif