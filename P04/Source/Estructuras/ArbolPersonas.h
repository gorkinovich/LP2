//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Estructuras_ArbolPersonasH
#define Estructuras_ArbolPersonasH

#include "ContenedorPersonas.h" 
#include "Nodo.h"


/**
 * Clase para almacenar la base de datos de personas.
 */
class ArbolPersonas : public ContenedorPersonas
{
//*--------------------------------------------------------------*
//* Zona privada de la clase                                     *
//*--------------------------------------------------------------*
private:
	int total;  // Tamaño maximo del arbol (-1 == infinito).
	int numero; // Número de elementos dentro del contenedor.
	int indice; // Posición actual de consulta en la base de datos.
    
    Nodo * raiz;
    Nodo * actual;



//*--------------------------------------------------------------*
//* Zona protegida de la clase                                   *
//*--------------------------------------------------------------*
protected:
	//============================================================
	/**
	 * Función para inicializar un árbol.
	 */
    void Inicializar (void);

	/**
	 * Función para agregar una persona al arbol. 
	 * @param nodo Nodo actual.
	 * @param nuevo Nodo que agregar.  
     * @return El nodo actual modificado.
	 */
    Nodo * AgregarNodo (Nodo * nodo, Nodo * nuevo);

	/**
	 * Función para obtener el nuevo indice tras agregar una persona.
	 * @param nodo Nodo actual.
	 * @param clave Nodo que buscar.     
     * @return Si hemos encontrado el nodo.
	 */
    bool PosicionarEnNodo (Nodo * nodo, Nodo * clave);



	//============================================================
	/**
	 * Función para copiar recursivamente un árbol.
	 * @param fuente Nodo que copiar.
     * @return La copia del arbol.
	 */
    Nodo * CopiarArbol (Nodo * fuente);

	/**
	 * Función para borrar recursivamente un árbol.
	 * @param nodo Nodo actual para borrar.
	 */
    void BorrarArbol (Nodo * nodo);



	//============================================================
	/**
	 * Función para buscar recursivamente en un árbol.
	 * @param nodo Nodo actual donde buscar.      
	 * @param clave Clave de búsqueda.
     * @return La persona que buscamos.
	 */
    Persona * buscarPersona (Nodo * nodo, const Persona & clave);

	/**
	 * Función para buscar recursivamente en un árbol.
	 * @param nodo Nodo actual donde buscar.      
	 * @param clave Clave de búsqueda.
     * @return La persona que buscamos.
	 */
    Persona * buscarID (Nodo * nodo, const std::string & clave);

	/**
	 * Función para buscar recursivamente en un árbol.
	 * @param nodo Nodo actual donde buscar.      
	 * @param clave Clave de búsqueda.
     * @return La persona que buscamos.
	 */
    Persona * buscarCara (Nodo * nodo, const Cara & clave);

	/**
	 * Función para buscar recursivamente en un árbol.
	 * @param nodo Nodo actual donde buscar.
	 * @param i Posición en el arbol.
     * @return La persona que buscamos.
	 */
    Persona * buscarPorIndice (Nodo * nodo, int & i);



	//============================================================
	/**
	 * Función para buscar recursivamente en un árbol.
	 * @param nodo Nodo actual donde buscar.      
	 * @param clave Clave de búsqueda.
     * @return La persona que buscamos.
	 */
    Nodo * buscarNodo (Nodo * nodo, const Persona & clave);

	/**
	 * Función para buscar recursivamente en un árbol.
	 * @param nodo Nodo actual donde buscar.      
	 * @param clave Clave de búsqueda.
     * @return La persona que buscamos.
	 */
    Nodo * buscarNodoPadre (Nodo * nodo, Nodo * clave);

	/**
	 * Función para buscar recursivamente en un árbol.
	 * @param nodo Nodo actual donde buscar.
	 * @param i Posición en el arbol.
     * @return El nodo que buscamos.
	 */
    Nodo * buscarNodo (Nodo * nodo, int & i);



	//============================================================           
	/**
	 * Función para establecer un nuevo valor para el número.
	 * @param numero Número del primer nodo libre que tendremos en el arbol.
	 * @return Devuelve true si ha podido cambiar el número.
	 */
    virtual bool setNumero (int numero);



//*--------------------------------------------------------------*
//* Zona pública de la clase                                     *
//*--------------------------------------------------------------*
public:
	/**
	 * Constructor que crea un contenedor ya inicializado.
	 */
	ArbolPersonas ();

	/**
	 * Constructor que crea un contenedor ya inicializado.
	 * @param total Total de nodos del arbol.
	 */
	ArbolPersonas (int total);

	/**
	 * Constructor copia que crea un contenedor ya inicializado.
	 * @param tamanno Tamaño del array.
	 */
	ArbolPersonas (const ArbolPersonas & contenedor);

	/**
	 * Sobrecarga del operador == para Persona.
	 */
	ArbolPersonas & operator = (const ArbolPersonas & contenedor);

	/**
	 * Destructor que libera un contenedor.
	 */
	~ArbolPersonas ();



	//============================================================
	/**
	 * Función para obtener el tamaño total de la base de datos.
	 * @return Devuelve el número total de elementos reservados.
	 * @see getNumero(), getIndice()
	 */
	virtual int getTotal (void) const;

	/**
	 * Función para obtener la posición del primer elemento libre.
	 * @return Devuelve la posición del primer elemento libre.
	 * @see getTotal(), getIndice()
	 */
	virtual int getNumero (void) const;

	/**
	 * Función para obtener el índice actual en la base de datos.
	 * @return Devuelve el índice actual en la base de datos.
	 * @see getTotal(), getNumero()
	 */
	virtual int getIndice (void) const;


	
	//============================================================
	/**
	 * Función para establecer un nuevo valor para el total.
	 * @param total Total máximo de nodos que tendremos en el arbol.
	 * @return Devuelve true si ha podido cambiar el total.
	 */
    virtual bool setTotal (int total);

	/**
	 * Función para establecer un nuevo valor para el indice.
	 * @param indice Posición en la que nos queremos situar.
	 * @return Devuelve true si ha podido cambiar el indice.
	 */
    virtual bool setIndice (int indice);



	//============================================================
	/**
	 * Función para obtener una persona.
	 * @param buscado Persona al que buscar.
	 * @param dato Persona devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getPersona (const Persona & buscado, Persona *& dato);

	/**
	 * Función para obtener una persona.
	 * @param id ID que buscar.
	 * @param dato Persona devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getPersona (std::string id, Persona *& dato);
       
	/**
	 * Función para obtener una persona.
	 * @param cara Cara que buscar.
	 * @param dato Persona devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getPersona (const Cara & cara, Persona *& dato);
       
	/**
	 * Función para obtener una persona.
	 * @param indice Indice al que ir.
	 * @param dato Persona devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getPersona (int indice, Persona *& dato);



	//============================================================
	/**
	 * Función para obtener la persona actual.
	 * @param dato Persona devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getPersonaIndice (Persona *& dato);



	//============================================================
	/**
	 * Función para saber si está cierta persona.
	 * @param persona Datos de la persona a buscar.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	virtual bool estaPersona (const Persona & persona);
         
	/**
	 * Función para saber si está cierta persona.
	 * @param id ID de la persona a buscar.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	virtual bool estaPersona (std::string id);



	//============================================================
	/**
	 * Función que va a agregar una persona de la lista.
	 * @param persona Persona que se va a agregar.
	 * @return Devuelve si ha sido agregad o no.
	 * @see borraPersona()
	 */
	virtual bool agregaPersona (const Persona & persona);

	/**
	 * Función que va a borrar una persona de la lista.
	 * @param persona Persona que se va a borrar.
	 * @return Devuelve si ha sido borrado o no.
	 * @see agregaPersona()
	 */
	virtual bool borraPersona (const Persona & persona);



	//============================================================
	/**
	 * Función que nos indica si el árbol está vacio o no.
	 * @return Devuelve si el árbol está vacio o no.
	 */
	virtual bool vacia (void);
	
	/**
	 * Función para borrar el contenedor.
	 */
	virtual bool nuevo (void);

};


#endif