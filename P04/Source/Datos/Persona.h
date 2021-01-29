//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Datos_PersonaH
#define Datos_PersonaH

#include <string>
#include "Cara.h"


/**
 * Clase para almacenar los datos referentes a una persona.
 */
class Persona
{
private:
	std::string id;
	std::string nombre;
	Cara * cara;


protected:
	/**
	 * Función para establecer la cara de la persona indicada.
	 * @param cara Cara de la persona indicada.
	 * @see setNombre(), setDNI()
	 */
	void setCara (Cara * cara);

	/**
	 * Función para copiar de una persona.
	 * @param obj Persona de la que queremos copiar.
	 */
	void CopyFrom (const Persona & obj);


public:
	/**
	 * Constructor que crea una persona ya inicializado.
	 */
	Persona ();

	/**
	 * Constructor que crea una persona ya inicializado.
	 * @param id     ID de la persona.
	 * @param nombre Nombre de la persona.
	 * @param cara   Cara de la persona.
	 */
	Persona (std::string id, std::string nombre, Cara * cara);

	/**
	 * Constructor copia.
	 * @param obj Persona que queremos copiar.
	 */
	Persona (const Persona & obj);

	/**
	 * Destructor de la clase.
	 */
    virtual ~Persona ();

	/**
	 * Sobrecarga del operador =.
	 */
	virtual Persona & operator = (const Persona & obj);

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
	 * Función para obtener el nombre de la persona indicada.
	 * @return Devuelve el nombre de la persona indicada.
	 * @see getDNI(), getCara()
	 */
	std::string getNombre (void) const;

	/**
	 * Función para obtener el ID de la persona indicada.
	 * @return Devuelve el ID de la persona indicada.
	 * @see getNombre(), getCara()
	 */
	std::string getID (void) const;  

	/**
	 * Función para obtener la cara de la persona indicada.
	 * @return Devuelve la cara de la persona indicada.
	 * @see getNombre(), getDNI()
	 */
	Cara * getCara (void) const;

	/**
	 * Función para establecer el nombre de la persona indicada.
	 * @param nombre Nombre de la persona indicada.
	 * @see setDNI(), setCara()
	 */
	void setNombre (std::string nombre);

	/**
	 * Función para establecer el ID de la persona indicada.
	 * @param id ID de la persona indicada.
	 * @see setNombre(), setCara()
	 */
	void setID (std::string id);

	/**
	 * Sobrecarga del operador == para Persona.
	 */
	bool operator == (const Persona & persona) const;

	/**
	 * Sobrecarga del operador <= para Persona.
	 */
	bool operator <= (const Persona & persona) const;

	/**
	 * Función que indica si una persona es parecida a otra.
	 * @param cara Cara con la que queremos comparar la persona.
	 * @return Devuelve si tiene la cara igual o no.
	 */
	bool parecido (const Cara & cara) const;

};


#endif