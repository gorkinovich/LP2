//----------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Datos_DelincuenteConfidenteH
#define Datos_DelincuenteConfidenteH

#include <string>


/**
 * Clase para almacenar los datos referentes a un delincuente.
 */
class DelincuenteConfidente
{
private:
    std::string supervisor;

protected:	
	/**
	 * Funci�n para copiar de un objeto.
	 * @param obj Objeto que queremos copiar.
	 */
	void CopyFrom (const DelincuenteConfidente & obj);

public:
	/**
	 * Constructor que crea un delincuente ya inicializado.
	 */
	DelincuenteConfidente ();

	/**
	 * Constructor que crea un delincuente ya inicializado.
	 * @param supervisor Nombre del supervisor.
	 */
	DelincuenteConfidente (std::string supervisor);

	/**
	 * Constructor copia.
	 * @param obj Delincuente que queremos copiar.
	 */
	DelincuenteConfidente (const DelincuenteConfidente & obj);

	/**
	 * Destructor de la clase.
	 */
    virtual ~DelincuenteConfidente ();

	/**
	 * Operador de asignaci�n sobrecargado.
	 */
    virtual DelincuenteConfidente & operator = (const DelincuenteConfidente & obj);

	/**
	 * Funci�n para hacer una copia del objeto.
	 * @return La copia del objeto actual.
	 */
	//virtual DelincuenteConfidente & clone (void) const = 0;

	/**
	 * Funci�n para obtener el supervisor del delincuente indicado.
	 * @return Devuelve el supervisor del delincuente indicado.
	 */
	std::string getSupervisor (void) const;

	/**
	 * Funci�n para establecer el supervisor del delincuente indicado.
	 * @param supervisor Supervisor del delincuente.
	 */
	void setSupervisor (std::string supervisor);

};


#endif