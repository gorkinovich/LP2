//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Patrones_VistaH
#define Patrones_VistaH

#include "Controlador.h"


/**
 * Interfaz de comunicación con las vistas.
 */
class Vista
{
public:
	/**
	 * Constructor de la clase.
	 */
	Vista () {}

	/**
	 * Destructor de la clase.
	 */
	~Vista () {}

	/**
	 * Función para actualizar la vista.
	 */
	virtual void actualizar (void) = 0;

	/**
	 * Función para registrar un controlador.
	 */
	virtual void registrarControlador (Controlador * unControlador) = 0;
};

#endif