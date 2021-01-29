//----------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Estructuras_ListaOrdenadaH
#define Estructuras_ListaOrdenadaH

#include "ListaNodo.h"


/**
 * Clase para almacenar una lista ordenada.
 */
template <class Tipo> class ListaOrdenada
{
//*--------------------------------------------------------------*
//* Zona privada de la clase                                     *
//*--------------------------------------------------------------*
private:
	int total;  // Tama�o maximo de la lista (-1 == infinito).
	int numero; // N�mero de elementos dentro del contenedor.
	int indice; // Posici�n actual de consulta en la lista.
    
    ListaNodo<Tipo> * inicio;
    ListaNodo<Tipo> * actual;
    ListaNodo<Tipo> * fin;



//*--------------------------------------------------------------*
//* Zona protegida de la clase                                   *
//*--------------------------------------------------------------*
protected:
	/**
	 * Funci�n para copiar otra lista ordenada.
	 * @param obj Lista que vamos a copiar.
	 */
	void CopyFrom (const ListaOrdenada & obj)
	{
		this->Clear();

		ListaNodo<Tipo> * aux = NULL;

		for(aux = obj.inicio; aux != NULL; aux = aux->getPosterior())
		{
			this->agregaElemento(aux->getDato());
		}
	}
	
	/**
	 * Funci�n para borrar el contenido de la lista.
	 */
	void Clear (void)
	{
		ListaNodo<Tipo> * aux     = NULL;
		ListaNodo<Tipo> * victima = NULL;
    
		for(aux = this->inicio; aux != NULL; )
		{
			victima = aux;
			aux = aux->getPosterior();
			delete victima;
		}


		this->total  = -1;
		this->numero =  0;
		this->indice = -1;

		this->inicio = NULL;
		this->actual = NULL;
		this->fin    = NULL;
	}



	//============================================================
	/**
	 * Funci�n para encontrar un nodo en la lista.
	 * @param data Dato que tratamos de buscar.
	 * @return El nodo que buscamos.
	 */
	ListaNodo<Tipo> * findNode (const Tipo & data)
	{
		ListaNodo<Tipo> * aux = NULL;

		for(aux = this->inicio; aux != NULL; aux = aux->getPosterior())
		{
			if(aux->getDato() == data)
			{
				return aux;
			}
		}

		return NULL;
	}

	/**
	 * Funci�n para encontrar un nodo mayor en la lista.
	 * @param data Dato que guiar� la b�squeda.
	 * @return El nodo que buscamos.
	 */
	ListaNodo<Tipo> * findUpper (const Tipo & data)
	{
		ListaNodo<Tipo> * aux = NULL;

		for(aux = this->inicio; aux != NULL; aux = aux->getPosterior())
		{
			if(data <= aux->getDato())
			{
				return aux;
			}
		}

		return NULL;
	}

	/**
	 * Funci�n para modificar un elemento de la lista.
	 * @param data Dato que deseamos modificar.
	 * @return Nos devuelve si se ha podido modificar algo.
	 */
	bool modificarElemento (const Tipo & dato)
	{
		ListaNodo<Tipo> * nodo = this->findNode(dato);

		if(nodo != NULL)
		{
			nodo->setDato(dato);
			return true;
		}
		else
		{
			return false;
		}
	}



	//============================================================          
	/**
	 * Funci�n para establecer un nuevo valor para el n�mero.
	 * @param numero N�mero de elementos en la lista ordenada.
	 * @return Devuelve true si ha podido cambiar el n�mero.
	 */
    bool setNumero (int numero)
	{
		this->numero = numero;
		return true;
	}



//*--------------------------------------------------------------*
//* Zona p�blica de la clase                                     *
//*--------------------------------------------------------------*
public:
	/**
	 * Constructor de la clase.
	 */
	ListaOrdenada ()
	{
		this->total  = -1;
		this->numero =  0;
		this->indice = -1;
    
		this->inicio = NULL;
		this->actual = NULL;
		this->fin    = NULL;
	}

	/**
	 * Constructor de la clase.
	 * @param total Total m�ximo de nodos de la lista.
	 */
	ListaOrdenada (int total)
	{
		this->total = total;

		this->numero =  0;
		this->indice = -1;
    
		this->inicio = NULL;
		this->actual = NULL;
		this->fin    = NULL;
	}
	
	/**
	 * Constructor copia de la clase.
	 */
	ListaOrdenada (const ListaOrdenada & obj)
	{
		this->CopyFrom(obj);
	}
	
	/**
	 * Sobrecarga del operador =.
	 */
	ListaOrdenada & operator = (const ListaOrdenada & unaListaOrdenada)
	{
		this->CopyFrom(unaListaOrdenada);
		return (*this);
	}

	/**
	 * Destructor de la clase.
	 */
	~ListaOrdenada ()
	{
		this->Clear();
	}



	//============================================================
	/**
	 * Funci�n para obtener el tama�o total de la lista.
	 * @return Devuelve el n�mero total de elementos reservados.
	 * @see getNumero(), getIndice()
	 */
	int getTotal (void) const
	{
		return this->total;
	}

	/**
	 * Funci�n para obtener el n�mero de elementos actual de la lista.
	 * @return Devuelve el n�mero de elementos actual de la lista.
	 * @see getTotal(), getIndice()
	 */
	int getNumero (void) const
	{
		return this->numero;
	}

	/**
	 * Funci�n para obtener el �ndice actual en la lista.
	 * @return Devuelve el �ndice actual en la lista.
	 * @see getTotal(), getNumero()
	 */
	int getIndice (void) const
	{
		return this->indice;
	}



	//============================================================
	/**
	 * Funci�n para obtener un elemento.
	 * @param buscado Elemento al que buscar.
	 * @param dato Elemento devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    bool getElemento (const Tipo & buscado, Tipo & dato)
	{
		ListaNodo<Tipo> * aux = NULL;

		for(aux = this->inicio; aux != NULL; aux = aux->getPosterior())
		{
			if(aux->getDato() == buscado)
			{
				dato = aux->getDato();
				return true;
			}
		}

		return false;
	}

	/**
	 * Funci�n para obtener un elemento.
	 * @param indice Indice al que ir.
	 * @param dato Elemento devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    bool getElemento (int indice, Tipo & dato)
	{
		ListaNodo<Tipo> * aux = NULL;
		int i = 0;

		for(aux = this->inicio; aux != NULL; aux = aux->getPosterior())
		{
			if(i == indice)
			{
				dato = aux->getDato();
				return true;
			}

			++i;
		}

		return false;
	}

	/**
	 * Funci�n para obtener el Elemento actual.
	 * @param dato Elemento devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    bool getElementoIndice (Tipo & dato)
	{
		if(this->actual != NULL)
		{
			dato = this->actual->getDato();
			return true;
		}
		else
		{
			return false;
		}
	}



	//============================================================
	/**
	 * Funci�n para saber si est� cierto elemento.
	 * @param dato Datos del elemento a buscar.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	bool estaElemento (const Tipo & dato)
	{
		Tipo aux;
		return this->getElemento(dato, aux);
	}


	
	//============================================================
	/**
	 * Funci�n para establecer un nuevo valor para el total.
	 * @param total Total m�ximo de nodos que tendremos en la lista.
	 * @return Devuelve true si ha podido cambiar el total.
	 */
    bool setTotal (int total)
	{
		this->total = total;
		return true;
	}

	/**
	 * Funci�n para establecer un nuevo valor para el indice.
	 * @param indice Posici�n en la que nos queremos situar.
	 * @return Devuelve true si ha podido cambiar el indice.
	 */
    bool setIndice (int indice)
	{
		if(indice > -1)
		{
			ListaNodo<Tipo> * aux = NULL;

			for(int i = 0, aux = this->inicio; aux != NULL; ++i, aux = aux->getPosterior())
			{
				if(i == indice)
				{
					this->indice = indice;
					this->actual = aux;

					return true;
				}
			}

			return false;
		}
		else
		{
			this->indice = -1;
			this->actual = NULL;
		}
	}



	//============================================================
	/**
	 * Funci�n que va a agregar un elemento de la lista.
	 * @param dato Elemento que se va a agregar.
	 * @return Devuelve si ha sido agregad o no.
	 * @see borraElemento()
	 */
	bool agregaElemento (const Tipo & dato)
	{
		if(this->modificarElemento(dato))
		{
			return true;
		}
		else
		{
			if((this->total == -1) || (this->numero < this->total))
			{
				ListaNodo<Tipo> * aux = new ListaNodo<Tipo>(dato);
				if(aux == NULL) return false;

				// No hay ning�n nodo en la lista.
				if(this->inicio == NULL)
				{
					this->inicio = aux;
					this->fin    = aux;

					this->numero = 1;
				}
				else
				{
					ListaNodo<Tipo> * upper = this->findUpper(dato);

					// El nodo que vamos a meter est� al final.
					if(upper == NULL)
					{
						this->fin->setPosterior(aux);
						aux->setAnterior(this->fin);
						this->fin = aux;
					}
					// El nodo est� al principio.
					else if(upper == this->inicio)
					{
						this->inicio->setAnterior(aux);
						aux->setPosterior(this->inicio);
						this->inicio = aux;
					}
					// El nodo est� en medio.
					else
					{
						ListaNodo<Tipo> * lower = upper->getAnterior();
						
						lower->setPosterior(aux);
						upper->setAnterior(aux);
					}
					
					this->numero++;
				}

				return true;
			}
			else
			{
				return false;
			}
		}
	}

	/**
	 * Funci�n que va a borrar un elemento de la lista.
	 * @param dato Elemento que se va a borrar.
	 * @return Devuelve si ha sido borrado o no.
	 * @see agregaElemento()
	 */
	bool borraElemento (const Tipo & dato)
	{
		ListaNodo<Tipo> * aux = this->findNode(dato);

		if(aux != NULL)
		{
			ListaNodo<Tipo> * prev = aux->getAnterior();
			ListaNodo<Tipo> * next = aux->getPosterior();


			if(aux == this->inicio) this->inicio = next;
			if(aux == this->fin)    this->fin    = prev;


			if(next != NULL) next->setAnterior(prev);
			if(prev != NULL) prev->setPosterior(next);


			delete aux;

			this->numero--;
			this->indice = -1;
			this->actual = NULL;
		}
		else
		{
			return false;
		}
	}

};


#endif