//----------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Patrones_FactoriaPersonasH
#define Patrones_FactoriaPersonasH

#include "../Datos/CaraComun.h"
#include "../Datos/CaraClasificada.h"
#include "../Datos/Policia.h"
#include "../Datos/Administrador.h"
#include "../Datos/Lector.h"
#include "../Datos/Sonnador.h"
#include "../Datos/LectorConfidente.h"
#include "../Datos/SonnadorConfidente.h"
#include "../Datos/Tipos.h"



/**
 * Clase para crear diferentes objetos relacionados con Persona.
 */
class FactoriaPersonas
{
private:
	/**
	 * Constructor de la clase.
	 */
	FactoriaPersonas () {}

public:
	/**
	 * Funci�n para crear un objeto que hereda de Usuario.
	 * @param tipo Tipo de objeto que queremos crear.
	 * @return El objeto creado.
	 */
	static Usuario * creaUsuario (TipoUsuario tipo);

	/**
	 * Funci�n para crear un objeto que hereda de Delincuente.
	 * @param tipo Tipo de objeto que queremos crear.
	 * @return El objeto creado.
	 */
	static Delincuente * creaDelincuente (TipoDelincuente tipo);
};


#endif