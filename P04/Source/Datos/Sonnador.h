//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Datos_SonnadorH
#define Datos_SonnadorH

#include "Delincuente.h"


/**
 * Clase para almacenar los datos referentes a un delincuente.
 */
class Sonnador : public Delincuente
{
public:
	/**
	 * Constructor que crea un delincuente ya inicializado.
	 */
	Sonnador ();

	/**
	 * Constructor que crea un delincuente ya inicializado.
	 * @param id        ID del delincuente.
	 * @param nombre    Nombre del delincuente.
	 * @param cara      Cara del delincuente.
	 * @param cometidos Delitos cometidos del delincuente.
	 * @param concretos Delitos concretos del delincuente.
	 */
	Sonnador (std::string id, std::string nombre, CaraComun * cara,
			  ListaOrdenada<Delitos> * cometidos,
			  ListaOrdenada<std::string> * concretos);

	/**
	 * Constructor copia.
	 * @param obj Delincuente que queremos copiar.
	 */
	Sonnador (const Sonnador & obj);

	/**
	 * Destructor de la clase.
	 */
    virtual ~Sonnador ();

	/**
	 * Sobrecarga del operador =.
	 */
	virtual Persona & operator = (const Persona & obj);

	/**
	 * Sobrecarga del operador =.
	 */
	Sonnador & operator = (const Sonnador & obj);

	/**
	 * Función para hacer una copia del objeto.
	 * @return La copia del objeto actual.
	 */
	virtual Persona & clone (void) const;

	/**
	 * Función para obtener el tipo de la clase actual.
	 * @return Devuelve el tipo de la clase.
	 */
    virtual std::string getClassName (void) const;

};


#endif