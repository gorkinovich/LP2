//----------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 04 - Grupo 03.
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
	int total;  // Tama�o maximo del arbol (-1 == infinito).
	int numero; // N�mero de elementos dentro del contenedor.
	int indice; // Posici�n actual de consulta en la base de datos.
    
    Nodo * raiz;
    Nodo * actual;



//*--------------------------------------------------------------*
//* Zona protegida de la clase                                   *
//*--------------------------------------------------------------*
protected:
	//============================================================
	/**
	 * Funci�n para inicializar un �rbol.
	 */
    void Inicializar (void);

	/**
	 * Funci�n para agregar una persona al arbol. 
	 * @param nodo Nodo actual.
	 * @param nuevo Nodo que agregar.  
     * @return El nodo actual modificado.
	 */
    Nodo * AgregarNodo (Nodo * nodo, Nodo * nuevo);

	/**
	 * Funci�n para obtener el nuevo indice tras agregar una persona.
	 * @param nodo Nodo actual.
	 * @param clave Nodo que buscar.     
     * @return Si hemos encontrado el nodo.
	 */
    bool PosicionarEnNodo (Nodo * nodo, Nodo * clave);



	//============================================================
	/**
	 * Funci�n para copiar recursivamente un �rbol.
	 * @param fuente Nodo que copiar.
     * @return La copia del arbol.
	 */
    Nodo * CopiarArbol (Nodo * fuente);

	/**
	 * Funci�n para borrar recursivamente un �rbol.
	 * @param nodo Nodo actual para borrar.
	 */
    void BorrarArbol (Nodo * nodo);



	//============================================================
	/**
	 * Funci�n para buscar recursivamente en un �rbol.
	 * @param nodo Nodo actual donde buscar.      
	 * @param clave Clave de b�squeda.
     * @return La persona que buscamos.
	 */
    Persona * buscarPersona (Nodo * nodo, const Persona & clave);

	/**
	 * Funci�n para buscar recursivamente en un �rbol.
	 * @param nodo Nodo actual donde buscar.      
	 * @param clave Clave de b�squeda.
     * @return La persona que buscamos.
	 */
    Persona * buscarID (Nodo * nodo, const std::string & clave);

	/**
	 * Funci�n para buscar recursivamente en un �rbol.
	 * @param nodo Nodo actual donde buscar.      
	 * @param clave Clave de b�squeda.
     * @return La persona que buscamos.
	 */
    Persona * buscarCara (Nodo * nodo, const Cara & clave);

	/**
	 * Funci�n para buscar recursivamente en un �rbol.
	 * @param nodo Nodo actual donde buscar.
	 * @param i Posici�n en el arbol.
     * @return La persona que buscamos.
	 */
    Persona * buscarPorIndice (Nodo * nodo, int & i);



	//============================================================
	/**
	 * Funci�n para buscar recursivamente en un �rbol.
	 * @param nodo Nodo actual donde buscar.      
	 * @param clave Clave de b�squeda.
     * @return La persona que buscamos.
	 */
    Nodo * buscarNodo (Nodo * nodo, const Persona & clave);

	/**
	 * Funci�n para buscar recursivamente en un �rbol.
	 * @param nodo Nodo actual donde buscar.      
	 * @param clave Clave de b�squeda.
     * @return La persona que buscamos.
	 */
    Nodo * buscarNodoPadre (Nodo * nodo, Nodo * clave);

	/**
	 * Funci�n para buscar recursivamente en un �rbol.
	 * @param nodo Nodo actual donde buscar.
	 * @param i Posici�n en el arbol.
     * @return El nodo que buscamos.
	 */
    Nodo * buscarNodo (Nodo * nodo, int & i);



	//============================================================           
	/**
	 * Funci�n para establecer un nuevo valor para el n�mero.
	 * @param numero N�mero del primer nodo libre que tendremos en el arbol.
	 * @return Devuelve true si ha podido cambiar el n�mero.
	 */
    virtual bool setNumero (int numero);



//*--------------------------------------------------------------*
//* Zona p�blica de la clase                                     *
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
	 * @param tamanno Tama�o del array.
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
	 * Funci�n para obtener el tama�o total de la base de datos.
	 * @return Devuelve el n�mero total de elementos reservados.
	 * @see getNumero(), getIndice()
	 */
	virtual int getTotal (void) const;

	/**
	 * Funci�n para obtener la posici�n del primer elemento libre.
	 * @return Devuelve la posici�n del primer elemento libre.
	 * @see getTotal(), getIndice()
	 */
	virtual int getNumero (void) const;

	/**
	 * Funci�n para obtener el �ndice actual en la base de datos.
	 * @return Devuelve el �ndice actual en la base de datos.
	 * @see getTotal(), getNumero()
	 */
	virtual int getIndice (void) const;


	
	//============================================================
	/**
	 * Funci�n para establecer un nuevo valor para el total.
	 * @param total Total m�ximo de nodos que tendremos en el arbol.
	 * @return Devuelve true si ha podido cambiar el total.
	 */
    virtual bool setTotal (int total);

	/**
	 * Funci�n para establecer un nuevo valor para el indice.
	 * @param indice Posici�n en la que nos queremos situar.
	 * @return Devuelve true si ha podido cambiar el indice.
	 */
    virtual bool setIndice (int indice);



	//============================================================
	/**
	 * Funci�n para obtener una persona.
	 * @param buscado Persona al que buscar.
	 * @param dato Persona devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getPersona (const Persona & buscado, Persona *& dato);

	/**
	 * Funci�n para obtener una persona.
	 * @param id ID que buscar.
	 * @param dato Persona devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getPersona (std::string id, Persona *& dato);
       
	/**
	 * Funci�n para obtener una persona.
	 * @param cara Cara que buscar.
	 * @param dato Persona devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getPersona (const Cara & cara, Persona *& dato);
       
	/**
	 * Funci�n para obtener una persona.
	 * @param indice Indice al que ir.
	 * @param dato Persona devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getPersona (int indice, Persona *& dato);



	//============================================================
	/**
	 * Funci�n para obtener la persona actual.
	 * @param dato Persona devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getPersonaIndice (Persona *& dato);



	//============================================================
	/**
	 * Funci�n para saber si est� cierta persona.
	 * @param persona Datos de la persona a buscar.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	virtual bool estaPersona (const Persona & persona);
         
	/**
	 * Funci�n para saber si est� cierta persona.
	 * @param id ID de la persona a buscar.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	virtual bool estaPersona (std::string id);



	//============================================================
	/**
	 * Funci�n que va a agregar una persona de la lista.
	 * @param persona Persona que se va a agregar.
	 * @return Devuelve si ha sido agregad o no.
	 * @see borraPersona()
	 */
	virtual bool agregaPersona (const Persona & persona);

	/**
	 * Funci�n que va a borrar una persona de la lista.
	 * @param persona Persona que se va a borrar.
	 * @return Devuelve si ha sido borrado o no.
	 * @see agregaPersona()
	 */
	virtual bool borraPersona (const Persona & persona);



	//============================================================
	/**
	 * Funci�n que nos indica si el �rbol est� vacio o no.
	 * @return Devuelve si el �rbol est� vacio o no.
	 */
	virtual bool vacia (void);
	
	/**
	 * Funci�n para borrar el contenedor.
	 */
	virtual bool nuevo (void);

};


#endif