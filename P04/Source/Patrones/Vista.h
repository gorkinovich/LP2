//----------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Patrones_VistaH
#define Patrones_VistaH

#include "Controlador.h"


/**
 * Interfaz de comunicaci�n con las vistas.
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
	 * Funci�n para actualizar la vista.
	 */
	virtual void actualizar (void) = 0;

	/**
	 * Funci�n para registrar un controlador.
	 */
	virtual void registrarControlador (Controlador * unControlador) = 0;
};

#endif