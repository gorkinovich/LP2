//----------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 03 - Grupo 03.
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
	int total;  // Tama�o maximo del arbol (-1 == infinito).
	int numero; // Posici�n del primer elemento libre en el array.
	int indice; // Posici�n actual de consulta en la base de datos.
    
    Nodo * raiz;
    Nodo * actual;


	/**
	 * Funci�n para inicializar un �rbol.
	 */
    void Inicializar (void);
         
	/**
	 * Funci�n para agregar un delincuente al arbol. 
	 * @param nodo Nodo actual.
	 * @param nuevo Nodo que agregar.  
     * @return El nodo actual modificado.
	 */
    Nodo * AgregarNodo (Nodo * nodo, Nodo * nuevo);

	/**
	 * Funci�n para obtener el nuevo indice tras agregar un delincuente.
	 * @param nodo Nodo actual.
	 * @param clave Nodo que buscar.     
     * @return Si hemos encontrado el nodo.
	 */
    bool PosicionarEnNodo (Nodo * nodo, Nodo * clave);


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


	/**
	 * Funci�n para buscar recursivamente en un �rbol.
	 * @param nodo Nodo actual donde buscar.      
	 * @param clave Clave de b�squeda.
     * @return El delincuente que buscamos.
	 */
    Delincuente * buscarDelincuente (Nodo * nodo, const Delincuente & clave);

	/**
	 * Funci�n para buscar recursivamente en un �rbol.
	 * @param nodo Nodo actual donde buscar.      
	 * @param clave Clave de b�squeda.
     * @return El delincuente que buscamos.
	 */
    Delincuente * buscarDNI (Nodo * nodo, const string & clave);

	/**
	 * Funci�n para buscar recursivamente en un �rbol.
	 * @param nodo Nodo actual donde buscar.      
	 * @param clave Clave de b�squeda.
     * @return El delincuente que buscamos.
	 */
    Delincuente * buscarCara (Nodo * nodo, const Cara & clave);

	/**
	 * Funci�n para buscar recursivamente en un �rbol.
	 * @param nodo Nodo actual donde buscar.
	 * @param i Posici�n en el arbol.
     * @return El delincuente que buscamos.
	 */
    Delincuente * buscarPorIndice (Nodo * nodo, int & i);

                   
	/**
	 * Funci�n para buscar recursivamente en un �rbol.
	 * @param nodo Nodo actual donde buscar.      
	 * @param clave Clave de b�squeda.
     * @return El delincuente que buscamos.
	 */
    Nodo * buscarNodo (Nodo * nodo, const Delincuente & clave);
                      
	/**
	 * Funci�n para buscar recursivamente en un �rbol.
	 * @param nodo Nodo actual donde buscar.      
	 * @param clave Clave de b�squeda.
     * @return El delincuente que buscamos.
	 */
    Nodo * buscarNodoPadre (Nodo * nodo, Nodo * clave);

	/**
	 * Funci�n para buscar recursivamente en un �rbol.
	 * @param nodo Nodo actual donde buscar.
	 * @param i Posici�n en el arbol.
     * @return El nodo que buscamos.
	 */
    Nodo * buscarNodo (Nodo * nodo, int & i);

        
	/**
	 * Funci�n para salvar recursivamente un �rbol
	 * @param nodo Nodo actual que salvar.
	 * @param salida Stream de salida donde salvar.
	 */
    bool salvaNodo (Nodo * nodo, ofstream & salida) const;

           
	/**
	 * Funci�n para establecer un nuevo valor para el total.
	 * @param total Total m�ximo de nodos que tendremos en el arbol.
	 * @return Devuelve true si ha podido cambiar el total.
	 */
    virtual bool setTotal(int total);

	/**
	 * Funci�n para establecer un nuevo valor para el n�mero.
	 * @param numero N�mero del primer nodo libre que tendremos en el arbol.
	 * @return Devuelve true si ha podido cambiar el n�mero.
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
	 * @param tamanno Tama�o del array.
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


	/**
	 * Funci�n para obtener un delincuente.
	 * @param buscado Delincuente al que buscar.
	 * @param dato Delincuente devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getDelincuente (const Delincuente& buscado, Delincuente*& dato);
                     
	/**
	 * Funci�n para obtener un delincuente.
	 * @param dni DNI que buscar.
	 * @param dato Delincuente devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getDelincuente (string dni, Delincuente*& dato);
       
	/**
	 * Funci�n para obtener un delincuente.
	 * @param cara Cara que buscar.
	 * @param dato Delincuente devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getDelincuente (const Cara& cara, Delincuente*& dato);
       
	/**
	 * Funci�n para obtener un delincuente.
	 * @param indice Indice al que ir.
	 * @param dato Delincuente devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getDelincuente (int indice, Delincuente*& dato);
                         
	/**
	 * Funci�n para obtener el delincuente actual.
	 * @param dato Delincuente devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getDelincuenteIndice (Delincuente*& dato);


	/**
	 * Funci�n que va a agregar un delincuente de la lista.
	 * @param delincuente Delincuente que se va a agregar.
	 * @return Devuelve si ha sido agregad o no.
	 * @see borraDelincuente()
	 */
	virtual bool agregaDelincuente (const Delincuente & delincuente);

	/**
	 * Funci�n que va a borrar un delincuente de la lista.
	 * @param delincuente Delincuente que se va a borrar.
	 * @return Devuelve si ha sido borrado o no.
	 * @see agregaDelincuente()
	 */
	virtual bool borraDelincuente (const Delincuente& delincuente);

	/**
	 * Funci�n para establecer un nuevo valor para el indice.
	 * @param indice Posici�n en la que nos queremos situar.
	 * @return Devuelve true si ha podido cambiar el indice.
	 */
     virtual bool setIndice (int indice);


	/**
	 * Funci�n para saber si est� cierto delincuente.
	 * @param delincuente Datos del delincuente a buscar.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	virtual bool estaDelincuente (const Delincuente & delincuente);
         
	/**
	 * Funci�n para saber si est� cierto delincuente.
	 * @param dni DNI del delincuente a buscar.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	virtual bool estaDelincuente (const string dni);

	/**
	 * Funci�n para saber si est� cierto delincuente.
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