//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 03 - Grupo 03.
//----------------------------------------------------------------------
#ifndef ArbolDelincuentesH
#define ArbolDelincuentesH

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ContenedorDelincuentes.h" 
#include "Nodo.h"


/**
 * Clase para almacenar la base de datos de delincuentes.
 */
class ArbolDelincuentes : public ContenedorDelincuentes
{
protected:
	int total;  // Tamaño maximo del arbol (-1 == infinito).
	int numero; // Posición del primer elemento libre en el array.
	int indice; // Posición actual de consulta en la base de datos.
    
    Nodo * raiz;
    Nodo * actual;


	/**
	 * Función para inicializar un árbol.
	 */
    void Inicializar (void);
         
	/**
	 * Función para agregar un delincuente al arbol. 
	 * @param nodo Nodo actual.
	 * @param nuevo Nodo que agregar.  
     * @return El nodo actual modificado.
	 */
    Nodo * AgregarNodo (Nodo * nodo, Nodo * nuevo);

	/**
	 * Función para obtener el nuevo indice tras agregar un delincuente.
	 * @param nodo Nodo actual.
	 * @param clave Nodo que buscar.     
     * @return Si hemos encontrado el nodo.
	 */
    bool PosicionarEnNodo (Nodo * nodo, Nodo * clave);


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


	/**
	 * Función para buscar recursivamente en un árbol.
	 * @param nodo Nodo actual donde buscar.      
	 * @param clave Clave de búsqueda.
     * @return El delincuente que buscamos.
	 */
    Delincuente * buscarDelincuente (Nodo * nodo, const Delincuente & clave);

	/**
	 * Función para buscar recursivamente en un árbol.
	 * @param nodo Nodo actual donde buscar.      
	 * @param clave Clave de búsqueda.
     * @return El delincuente que buscamos.
	 */
    Delincuente * buscarDNI (Nodo * nodo, const string & clave);

	/**
	 * Función para buscar recursivamente en un árbol.
	 * @param nodo Nodo actual donde buscar.      
	 * @param clave Clave de búsqueda.
     * @return El delincuente que buscamos.
	 */
    Delincuente * buscarCara (Nodo * nodo, const Cara & clave);

	/**
	 * Función para buscar recursivamente en un árbol.
	 * @param nodo Nodo actual donde buscar.
	 * @param i Posición en el arbol.
     * @return El delincuente que buscamos.
	 */
    Delincuente * buscarPorIndice (Nodo * nodo, int & i);

                   
	/**
	 * Función para buscar recursivamente en un árbol.
	 * @param nodo Nodo actual donde buscar.      
	 * @param clave Clave de búsqueda.
     * @return El delincuente que buscamos.
	 */
    Nodo * buscarNodo (Nodo * nodo, const Delincuente & clave);
                      
	/**
	 * Función para buscar recursivamente en un árbol.
	 * @param nodo Nodo actual donde buscar.      
	 * @param clave Clave de búsqueda.
     * @return El delincuente que buscamos.
	 */
    Nodo * buscarNodoPadre (Nodo * nodo, Nodo * clave);

	/**
	 * Función para buscar recursivamente en un árbol.
	 * @param nodo Nodo actual donde buscar.
	 * @param i Posición en el arbol.
     * @return El nodo que buscamos.
	 */
    Nodo * buscarNodo (Nodo * nodo, int & i);

        
	/**
	 * Función para salvar recursivamente un árbol
	 * @param nodo Nodo actual que salvar.
	 * @param salida Stream de salida donde salvar.
	 */
    bool salvaNodo (Nodo * nodo, ofstream & salida) const;

           
	/**
	 * Función para establecer un nuevo valor para el total.
	 * @param total Total máximo de nodos que tendremos en el arbol.
	 * @return Devuelve true si ha podido cambiar el total.
	 */
    virtual bool setTotal(int total);

	/**
	 * Función para establecer un nuevo valor para el número.
	 * @param numero Número del primer nodo libre que tendremos en el arbol.
	 * @return Devuelve true si ha podido cambiar el número.
	 */
    virtual bool setNumero(int numero);

public:
	/**
	 * Constructor que crea un contenedor ya inicializado.
	 */
	ArbolDelincuentes ();

	/**
	 * Constructor que crea un contenedor ya inicializado.
	 * @param total Total de nodos del arbol.
	 */
	ArbolDelincuentes (int total);

	/**
	 * Constructor copia que crea un contenedor ya inicializado.
	 * @param tamanno Tamaño del array.
	 */
	ArbolDelincuentes (const ArbolDelincuentes & contenedor);

	/**
	 * Sobrecarga del operador == para Delincuente.
	 */
	ArbolDelincuentes & operator = (const ArbolDelincuentes & contenedor);

	/**
	 * Destructor que libera un contenedor.
	 */
	~ArbolDelincuentes ();


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


	/**
	 * Función para obtener un delincuente.
	 * @param buscado Delincuente al que buscar.
	 * @param dato Delincuente devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getDelincuente (const Delincuente& buscado, Delincuente*& dato);
                     
	/**
	 * Función para obtener un delincuente.
	 * @param dni DNI que buscar.
	 * @param dato Delincuente devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getDelincuente (string dni, Delincuente*& dato);
       
	/**
	 * Función para obtener un delincuente.
	 * @param cara Cara que buscar.
	 * @param dato Delincuente devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getDelincuente (const Cara& cara, Delincuente*& dato);
       
	/**
	 * Función para obtener un delincuente.
	 * @param indice Indice al que ir.
	 * @param dato Delincuente devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getDelincuente (int indice, Delincuente*& dato);
                         
	/**
	 * Función para obtener el delincuente actual.
	 * @param dato Delincuente devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getDelincuenteIndice (Delincuente*& dato);


	/**
	 * Función que va a agregar un delincuente de la lista.
	 * @param delincuente Delincuente que se va a agregar.
	 * @return Devuelve si ha sido agregad o no.
	 * @see borraDelincuente()
	 */
	virtual bool agregaDelincuente (const Delincuente & delincuente);

	/**
	 * Función que va a borrar un delincuente de la lista.
	 * @param delincuente Delincuente que se va a borrar.
	 * @return Devuelve si ha sido borrado o no.
	 * @see agregaDelincuente()
	 */
	virtual bool borraDelincuente (const Delincuente& delincuente);

	/**
	 * Función para establecer un nuevo valor para el indice.
	 * @param indice Posición en la que nos queremos situar.
	 * @return Devuelve true si ha podido cambiar el indice.
	 */
     virtual bool setIndice (int indice);


	/**
	 * Función para saber si está cierto delincuente.
	 * @param delincuente Datos del delincuente a buscar.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	virtual bool estaDelincuente (const Delincuente & delincuente);
         
	/**
	 * Función para saber si está cierto delincuente.
	 * @param dni DNI del delincuente a buscar.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	virtual bool estaDelincuente (const string dni);

	/**
	 * Función para saber si está cierto delincuente.
	 * @param cara Cara del delincuente a buscar.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	virtual bool estaDelincuente (const Cara & cara);


	/**
	 * Salva el delincuente en un fichero de texto.
	 * @param salida Ruta del fichero de salida.
	 * @return Devuelve true si todo ha ido bien.
	 */
	virtual bool salvaTxt (string salida) const;
	
	/**
	 * Carga el delincuente de un fichero de texto.
	 * @param entrada Ruta del fichero de entrada.
	 * @return Devuelve true si todo ha ido bien.
	 */
	virtual bool cargaTxt (string entrada);
};


#endif