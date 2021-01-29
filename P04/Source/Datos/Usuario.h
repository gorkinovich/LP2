//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Datos_UsuarioH
#define Datos_UsuarioH

#include "Persona.h"
#include "CaraClasificada.h"


/**
 * Clase para almacenar los datos referentes a un usuario.
 */
class Usuario : public Persona
{
private:
    std::string password;


protected:
	/**
	 * Función para copiar de una persona.
	 * @param obj Persona de la que queremos copiar.
	 */
	void CopyFrom (const Usuario & obj);


public:
	/**
	 * Constructor que crea un usuario ya inicializado.
	 */
	Usuario ();

	/**
	 * Constructor que crea un usuario ya inicializado.
	 * @param id       ID del usuario.
	 * @param nombre   Nombre del usuario.
	 * @param cara     Cara del usuario.
	 * @param password Password del usuario.
	 */
	Usuario (std::string id, std::string nombre, CaraClasificada * cara, std::string password);

	/**
	 * Constructor copia.
	 * @param obj Usuario que queremos copiar.
	 */
	Usuario (const Usuario & obj);

	/**
	 * Destructor de la clase.
	 */
    virtual ~Usuario ();

	/**
	 * Sobrecarga del operador =.
	 */
	virtual Persona & operator = (const Persona & obj);

	/**
	 * Sobrecarga del operador =.
	 */
	Usuario & operator = (const Usuario & obj);

	/**
	 * Función para hacer una copia de una persona.
	 * @return La copia de la persona actual.
	 */
	virtual Persona & clone (void) const = 0;

	/**
	 * Función para obtener el tipo de la clase actual.
	 * @return Devuelve el tipo de la clase.
	 */
    virtual std::string getClassName (void) const = 0;

	/**
	 * Función para obtener el password del usuario indicado.
	 * @return Devuelve el password del usuario indicado.
	 */
	std::string getPassword (void) const;

	/**
	 * Función para establecer el password del usuario indicado.
	 * @param password Password del usuario indicado.
	 */
	void setPassword (std::string password);

	/**
	 * Función para establecer la cara del usuario indicado.
	 * @param cara Cara de la persona indicada.
	 */
	void setCara (CaraClasificada * cara);

};


#endif