//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
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
	 * Función para copiar de un objeto.
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
	 * Operador de asignación sobrecargado.
	 */
    virtual DelincuenteConfidente & operator = (const DelincuenteConfidente & obj);

	/**
	 * Función para hacer una copia del objeto.
	 * @return La copia del objeto actual.
	 */
	//virtual DelincuenteConfidente & clone (void) const = 0;

	/**
	 * Función para obtener el supervisor del delincuente indicado.
	 * @return Devuelve el supervisor del delincuente indicado.
	 */
	std::string getSupervisor (void) const;

	/**
	 * Función para establecer el supervisor del delincuente indicado.
	 * @param supervisor Supervisor del delincuente.
	 */
	void setSupervisor (std::string supervisor);

};


#endif