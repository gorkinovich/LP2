//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Datos_AdministradorH
#define Datos_AdministradorH

#include "Usuario.h"


/**
 * Clase para almacenar los datos referentes a un administrador.
 */
class Administrador : public Usuario
{
public:
	/**
	 * Constructor que crea un administrador ya inicializado.
	 */
	Administrador ();

	/**
	 * Constructor que crea un administrador ya inicializado.
	 * @param id       ID del administrador.
	 * @param nombre   Nombre del administrador.
	 * @param cara     Cara del administrador.
	 * @param password Password del administrador.
	 */
	Administrador (std::string id, std::string nombre, CaraClasificada * cara, std::string password);

	/**
	 * Constructor copia.
	 * @param obj Administrador que queremos copiar.
	 */
	Administrador (const Administrador & obj);

	/**
	 * Destructor de la clase.
	 */
    virtual ~Administrador ();

	/**
	 * Sobrecarga del operador =.
	 */
	virtual Persona & operator = (const Persona & obj);

	/**
	 * Sobrecarga del operador =.
	 */
	Administrador & operator = (const Administrador & obj);

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