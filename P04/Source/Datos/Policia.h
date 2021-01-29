//----------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Datos_PoliciaH
#define Datos_PoliciaH

#include "Usuario.h"


/**
 * Clase para almacenar los datos referentes a un polic�a.
 */
class Policia : public Usuario
{
public:
	/**
	 * Constructor que crea un polic�a ya inicializado.
	 */
	Policia ();

	/**
	 * Constructor que crea un polic�a ya inicializado.
	 * @param id       ID del polic�a.
	 * @param nombre   Nombre del polic�a.
	 * @param cara     Cara del polic�a.
	 * @param password Password del polic�a.
	 */
	Policia (std::string id, std::string nombre, CaraClasificada * cara, std::string password);

	/**
	 * Constructor copia.
	 * @param obj Polic�a que queremos copiar.
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
	 * Funci�n para hacer una copia de una persona.
	 * @return La copia de la persona actual.
	 */
	virtual Persona & clone (void) const;

	/**
	 * Funci�n para obtener el tipo de la clase actual.
	 * @return Devuelve el tipo de la clase.
	 */
    virtual std::string getClassName (void) const;

};


#endif