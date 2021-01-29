//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Estructuras_NodoH
#define Estructuras_NodoH

#include "../Datos/Persona.h"


/**
 * Clase para almacenar un nodo con una persona.
 */
class Nodo
{
private:
    Persona * dato;
    Nodo * izq;
    Nodo * der;

public:
	/**
	 * Constructor de la clase.
	 */
    Nodo ();
    
	/**
	 * Constructor de la clase.  
	 * @param dato Delincuente con el que inicializar el nodo.
	 */
    Nodo (Persona * dato);

	/**
	 * Destructor de la clase.
	 */
    ~Nodo ();

	/**
	 * Función para obtener el dato del nodo.
	 * @return Devuelve el dato del nodo.
	 * @see getIzq(), getDer()
	 */
    Persona * getDato (void);

	/**
	 * Función para obtener el nodo izquierdo del nodo.
	 * @return Devuelve el nodo izquierdo del nodo.
	 * @see getDato(), getDer()
	 */
    Nodo * getIzq (void);

	/**
	 * Función para obtener el nodo derecho del nodo.
	 * @return Devuelve el nodo derecho del nodo.
	 * @see getDato(), getIzq()
	 */
    Nodo * getDer (void);

	/**
	 * Función para establecer el dato del nodo.
	 * @param dato Dato del nodo.
	 * @see setIzq(), setDer()
	 */
    void setDato (Persona * dato);
    
	/**
	 * Función para establecer el nodo izquierdo del nodo.
	 * @param anterior Nodo izquierdo del nodo.
	 * @see setDato(), setDer()
	 */
    void setIzq (Nodo * anterior);

	/**
	 * Función para establecer el nodo derecho del nodo.
	 * @param posterior Nodo derecho del nodo.
	 * @see setDato(), setIzq()
	 */
    void setDer (Nodo * posterior);
};

#endif
