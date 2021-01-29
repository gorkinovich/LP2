//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Datos_PoliciaH
#define Datos_PoliciaH

#include "Usuario.h"


/**
 * Clase para almacenar los datos referentes a un policía.
 */
class Policia : public Usuario
{
public:
	/**
	 * Constructor que crea un policía ya inicializado.
	 */
	Policia ();

	/**
	 * Constructor que crea un policía ya inicializado.
	 * @param id       ID del policía.
	 * @param nombre   Nombre del policía.
	 * @param cara     Cara del policía.
	 * @param password Password del policía.
	 */
	Policia (std::string id, std::string nombre, CaraClasificada * cara, std::string password);

	/**
	 * Constructor copia.
	 * @param obj Policía que queremos copiar.
	 */
	Policia (const Policia & obj);

	/**
	 * Destructor de la clase.
	 */
    virtual ~Policia ();

	/**
	 * Sobrecarga del operador =.
	 */
	virtual Persona & operator = (const Persona & obj);

	/**
	 * Sobrecarga del operador =.
	 */
	Policia & operator = (const Policia & obj);

	/**
	 * Función para hacer una copia de una persona.
	 * @return La copia de la persona actual.
	 */
	virtual Persona & clone (void) const;

	/**
	 * Función para obtener el tipo de la clase actual.
	 * @return Devuelve el tipo de la clase.
	 */
    virtual std::string getClassName (void) const;

};


#endif