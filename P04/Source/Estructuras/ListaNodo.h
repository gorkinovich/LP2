//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Estructuras_ListaNodoH
#define Estructuras_ListaNodoH


/**
 * Clase para almacenar el nodo de una lista.
 */
template <class Tipo> class ListaNodo
{
private:
	Tipo dato;
	ListaNodo<Tipo> * anterior;
	ListaNodo<Tipo> * posterior;

public:
	/**
	 * Constructor de la clase.
	 */
	ListaNodo ()
	{
		this->dato      = 0;
		this->anterior  = NULL;
		this->posterior = NULL;
	}

	/**
	 * Constructor de la clase.  
	 * @param dato Dato con el que inicializar el nodo.
	 */
	ListaNodo (Tipo dato)
	{
		this->dato      = dato;
		this->anterior  = NULL;
		this->posterior = NULL;
	}
	
	/**
	 * Destructor de la clase.
	 */
	~ListaNodo ()
	{
	}

	/**
	 * Función para obtener el dato del nodo.
	 * @return Devuelve el dato del nodo.
	 * @see getAnterior(), getPosterior()
	 */
	Tipo getDato (void)
	{
		return this->dato;
	}

	/**
	 * Función para obtener el nodo anterior.
	 * @return Devuelve el nodo anterior.
	 * @see getDato(), getPosterior()
	 */
	ListaNodo<Tipo> * getAnterior (void)
	{
		return this->anterior;
	}

	/**
	 * Función para obtener el nodo posterior.
	 * @return Devuelve el nodo posterior.
	 * @see getDato(), getAnterior()
	 */
	ListaNodo<Tipo> * getPosterior (void)
	{
		return this->posterior;
	}

	/**
	 * Función para establecer el dato del nodo.
	 * @param dato Dato del nodo.
	 * @see setAnterior(), setPosterior()
	 */
	void setDato (Tipo dato)
	{
		this->dato = dato;
	}

	/**
	 * Función para establecer el nodo anterior.
	 * @param anterior Nodo anterior.
	 * @see setDato(), setPosterior()
	 */
	void setAnterior (ListaNodo<Tipo> * anterior)
	{
		this->anterior = anterior;
	}

	/**
	 * Función para establecer el nodo posterior.
	 * @param posterior Nodo posterior.
	 * @see setDato(), setAnterior()
	 */
	void setPosterior (ListaNodo<Tipo> * posterior)
	{
		this->posterior = posterior;
	}
};


#endif