//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Patrones_ControladorH
#define Patrones_ControladorH

#include "../Datos/Persona.h"


/**
 * Interfaz de comunicación con las vistas.
 */
class Controlador
{
public:
	/**
	 * Constructor de la clase.
	 */
	Controlador () {}

	/**
	 * Destructor de la clase.
	 */
	~Controlador () {}

	

	// Funciones auxiliares.
	virtual void vistaAbierta (int numVista) = 0;
	virtual void vistaCerrada (int numVista) = 0;



	// Funciones get.
	virtual int getTotal  (void) const = 0;
	virtual int getNumero (void) const = 0;
	virtual int getIndice (void) const = 0;

	// Funciones set.
	virtual bool setTotal  (int total) = 0;
	virtual bool setIndice (int indice) = 0;

	// Funciones para obtener objetos de tipo persona.
	virtual bool getPersona (const Persona & buscado, Persona *& dato) = 0;
	virtual bool getPersona (std::string id, Persona *& dato) = 0;
	virtual bool getPersona (const Cara & cara, Persona *& dato) = 0;
	virtual bool getPersona (int indice, Persona *& dato) = 0;

	// Función para obtener la persona seleccionada actualmente.
	virtual bool getPersonaIndice (Persona *& dato) = 0;

	// Funciones para saber si una persona está dentro.
	virtual bool estaPersona (const Persona & persona) = 0;
	virtual bool estaPersona (std::string id) = 0;

	// Funciones para modificar el contenido del modelo.
	virtual bool agregaPersona (const Persona & persona) = 0;
	virtual bool borraPersona  (const Persona & persona) = 0;

	// Función para vaciar el modelo.
	virtual bool vacia (void) = 0;
	virtual bool nuevo (void) = 0;

	// Funciones para salvar y guardar un fichero.
    virtual bool cargar (std::string ruta) = 0;
    virtual bool salvar (std::string ruta) = 0;
};

#endif