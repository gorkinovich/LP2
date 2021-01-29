//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 03 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "ArbolDelincuentes.h"
#include "DelincuenteComun.h"
#include "DelincuenteConfidente.h"
#pragma package(smart_init)

//**********************************************************************
// Constructores.
//**********************************************************************

ArbolDelincuentes::ArbolDelincuentes ()
{
    this->Inicializar();
}

//----------------------------------------------------------------------

ArbolDelincuentes::ArbolDelincuentes (int total)
{
    this->Inicializar();
    this->setTotal(total);
}
       
//----------------------------------------------------------------------

void ArbolDelincuentes::Inicializar (void)
{     
	this->raiz   = NULL;
	this->actual = NULL;

	this->total  = -1;
	this->numero =  0;
	this->indice = -1;
}

//----------------------------------------------------------------------

ArbolDelincuentes::ArbolDelincuentes (const ArbolDelincuentes & contenedor)
{
	(*this) = contenedor;
}
 
//**********************************************************************
// Operador copia.
//**********************************************************************

ArbolDelincuentes & ArbolDelincuentes::operator = (const ArbolDelincuentes & contenedor)
{              
    this->BorrarArbol(this->raiz);

	this->raiz   = NULL;
	this->actual = NULL;


	this->total  = contenedor.total;
	this->numero = contenedor.numero;
	this->indice = contenedor.indice;


	this->raiz = this->CopiarArbol(contenedor.raiz);
	this->actual = this->raiz;

	return (*this);
}

//**********************************************************************
// Destructor.
//**********************************************************************

ArbolDelincuentes::~ArbolDelincuentes ()
{
    this->BorrarArbol(this->raiz);
    this->Inicializar();
}

//**********************************************************************
// Función para copiar un arbol a otro.
//**********************************************************************

Nodo * ArbolDelincuentes::CopiarArbol (Nodo * fuente)
{
    if(fuente != NULL)
    {
        Nodo * fuente = new Nodo();     
        fuente->setIzq(this->CopiarArbol(fuente->getIzq()));
        fuente->setDer(this->CopiarArbol(fuente->getDer()));
        fuente->setDato(fuente->getDato());

        return fuente;
    }
    else
    {
        return NULL;
    }
}
     
//**********************************************************************
// Función para borrar el arbol.
//**********************************************************************

void ArbolDelincuentes::BorrarArbol (Nodo * nodo)
{
    if(nodo != NULL)
    {
        this->BorrarArbol(nodo->getIzq());
        this->BorrarArbol(nodo->getDer());
        delete nodo;
    }
}
   
//**********************************************************************
// Gets.
//**********************************************************************

int ArbolDelincuentes::getTotal (void) const
{
	return this->total;
}
   
//----------------------------------------------------------------------

int ArbolDelincuentes::getNumero (void) const
{
	return this->numero;
}
   
//----------------------------------------------------------------------

int ArbolDelincuentes::getIndice (void) const
{
	return this->indice;
}
  
//**********************************************************************
// Funciones para buscar delincuentes.
//**********************************************************************

Delincuente * ArbolDelincuentes::buscarDelincuente (Nodo * nodo, const Delincuente & clave)
{
    if(nodo != NULL)
    {
        Delincuente * aux = nodo->getDato();

        if(*aux == clave)
            return aux;
        else if(clave <= *aux)
            return this->buscarDelincuente(nodo->getIzq(), clave);
        else
            return this->buscarDelincuente(nodo->getDer(), clave);
    }
    else
    {
        return NULL;
    }
}  
    
//----------------------------------------------------------------------

Delincuente * ArbolDelincuentes::buscarDNI (Nodo * nodo, const string & clave)
{
    if(nodo != NULL)
    {
        Delincuente * aux = nodo->getDato();

        if(aux->getDNI() == clave)
            return aux;
        else
        {
            aux = this->buscarDNI(nodo->getIzq(), clave);
            if(aux != NULL)
                return aux;
            else
                return this->buscarDNI(nodo->getDer(), clave);
        }
    }
    else
    {
        return NULL;
    }
}
   
//----------------------------------------------------------------------

Delincuente * ArbolDelincuentes::buscarCara (Nodo * nodo, const Cara & clave)
{
    if(nodo != NULL)
    {         
        Delincuente * aux = nodo->getDato();

        if(aux->parecido(clave))
            return aux;
        else
        {
            aux = this->buscarCara(nodo->getIzq(), clave);
            if(aux != NULL)
                return aux;
            else
                return this->buscarCara(nodo->getDer(), clave);
        }
    }
    else
    {
        return NULL;
    }
}
   
//**********************************************************************
// Funciones para obtener un delincuente.
//**********************************************************************

bool ArbolDelincuentes::getDelincuente (const Delincuente& buscado, Delincuente*& dato)
{
    dato = this->buscarDelincuente(this->raiz, buscado);        
    return (dato != NULL);
}
   
//----------------------------------------------------------------------

bool ArbolDelincuentes::getDelincuente (string dni, Delincuente*& dato)
{
    dato = this->buscarDNI(this->raiz, dni);
    return (dato != NULL);
}
     
//----------------------------------------------------------------------

bool ArbolDelincuentes::getDelincuente (const Cara& cara, Delincuente*& dato)
{
    dato = this->buscarCara(this->raiz, cara);
    return (dato != NULL);
}
   
//----------------------------------------------------------------------

Delincuente * ArbolDelincuentes::buscarPorIndice (Nodo * nodo, int & i)
{
    if(nodo != NULL)
    {           
        Delincuente * aux = this->buscarPorIndice(nodo->getIzq(), i);  
        if(aux != NULL)
            return aux;
        else
        {   
            if(i == 0)
            {
                return nodo->getDato();
            }
            else
            {     
                i--;
                return this->buscarPorIndice(nodo->getDer(), i);
            }
        }
    }
    else
    {
        return NULL;
    }
}
      
//----------------------------------------------------------------------

bool ArbolDelincuentes::getDelincuente (int indice, Delincuente*& dato)
{
    dato = this->buscarPorIndice(this->raiz, indice);
    return (dato != NULL);
}
            
//----------------------------------------------------------------------

bool ArbolDelincuentes::getDelincuenteIndice (Delincuente*& dato)
{
    if(this->actual != NULL)
    {
        dato = this->actual->getDato();
        return (dato != NULL);
    }
    else
        return false;
}
          
//**********************************************************************
// Funciones para agregar un delincuente.
//**********************************************************************

Nodo * ArbolDelincuentes::AgregarNodo (Nodo * nodo, Nodo * nuevo)
{
    if(nodo == NULL)
    {
        return nuevo;
    }
    else
    {
        if(*(nuevo->getDato()) <= *(nodo->getDato()))
            nodo->setIzq(this->AgregarNodo(nodo->getIzq(), nuevo));
        else
            nodo->setDer(this->AgregarNodo(nodo->getDer(), nuevo));

        return nodo;
    }
}
      
//----------------------------------------------------------------------

bool ArbolDelincuentes::PosicionarEnNodo (Nodo * nodo, Nodo * clave)
{
    if(nodo != NULL)
    {
        if(this->PosicionarEnNodo(nodo->getIzq(), clave))
            return true;
        else
        {    
            this->indice++;

            if(nodo == clave)
            {
                this->actual = nodo;
                return true;
            }
            else
            {
                return this->PosicionarEnNodo(nodo->getDer(), clave);
            }
        }
    }
    else
    {
        return false;
    }
}
     
//----------------------------------------------------------------------

bool ArbolDelincuentes::agregaDelincuente (const Delincuente & delincuente)
{
    if(this->estaDelincuente(delincuente))
    {         
        Nodo * nodo = this->buscarNodo(this->raiz, delincuente);
        *(nodo->getDato()) = delincuente;

        return true;
    }
    else
    {
        if((this->getTotal() >= 0) && (this->getTotal() <= this->getNumero()))
            return false;

        Nodo * nuevo = new Nodo();

        if(nuevo != NULL)
        {
            if(delincuente.getClassName() == "DelincuenteConfidente")
                nuevo->setDato(new DelincuenteConfidente());
            else
                nuevo->setDato(new DelincuenteComun());

            if(nuevo->getDato() == NULL)
            {
                delete nuevo;
                return false;
            }

            *(nuevo->getDato()) = delincuente;

            this->raiz = this->AgregarNodo(this->raiz, nuevo);

            this->setNumero(this->getNumero() + 1);

            this->indice = -1;
            this->PosicionarEnNodo(this->raiz, nuevo);
            return true;
        }
        else
        {
            return false;
        }
    }
}
         
//**********************************************************************
// Funciones para borrar un delincuente.
//**********************************************************************

Nodo * ArbolDelincuentes::buscarNodo (Nodo * nodo, const Delincuente & clave)
{
    if(nodo != NULL)
    {
        if(*(nodo->getDato()) == clave)
            return nodo;
        else if(clave <= *(nodo->getDato()))
            return this->buscarNodo(nodo->getIzq(), clave);
        else
            return this->buscarNodo(nodo->getDer(), clave);
    }
    else
    {
        return NULL;
    }
}
         
//----------------------------------------------------------------------

Nodo * ArbolDelincuentes::buscarNodoPadre (Nodo * nodo, Nodo * clave)
{   
    if(nodo != NULL)
    {
        if((nodo->getIzq() == clave) || (nodo->getDer() == clave))
            return nodo;
        else if(*(clave->getDato()) <= *(nodo->getDato()))
            return this->buscarNodoPadre(nodo->getIzq(), clave);
        else
            return this->buscarNodoPadre(nodo->getDer(), clave);
    }
    else
    {
        return NULL;
    }
}
               
//----------------------------------------------------------------------

bool ArbolDelincuentes::borraDelincuente (const Delincuente & delincuente)
{
    Nodo * nodo = this->buscarNodo(this->raiz, delincuente);

    if(nodo != NULL)
    {
        if(this->raiz != nodo)
        {
            Nodo * padre = this->buscarNodoPadre(this->raiz, nodo);

            if(nodo->getDer() != NULL)
                nodo->setIzq(this->AgregarNodo(nodo->getIzq(), nodo->getDer()));

            if(padre->getIzq() == nodo)
            {
                padre->setIzq(nodo->getIzq());
                delete nodo;
            }
            else if(padre->getDer() == nodo)
            {
                padre->setDer(nodo->getIzq());
                delete nodo;
            }
            else
            {
                return false;
            }
                  
            this->setNumero(this->getNumero() - 1);

            return true;
        }
        else
        {   
            if(nodo->getDer() != NULL)
                nodo->setIzq(this->AgregarNodo(nodo->getIzq(), nodo->getDer()));

            this->raiz = nodo->getIzq();
            delete nodo;

            this->setNumero(this->getNumero() - 1);

            return true;
        }
    }
    else
    {
        return false;
    }
}
           
//**********************************************************************
// Funciones para posicionarse en un nodo.
//**********************************************************************

Nodo * ArbolDelincuentes::buscarNodo (Nodo * nodo, int & i)
{
    if(nodo != NULL)
    {              
        Nodo * aux = this->buscarNodo(nodo->getIzq(), i);
        if(aux != NULL)
            return aux;
        else
        {
            if(i == 0)
            {
                return nodo;
            }
            else
            {     
                i--;
                return this->buscarNodo(nodo->getDer(), i);
            }
        }
    }
    else
    {
        return NULL;
    }
}
   
//----------------------------------------------------------------------

bool ArbolDelincuentes::setIndice (int indice)
{
    if(indice == -1)
    {
        this->actual = NULL;
        this->indice = -1;
        return true;
    }
    else
    {
        int i = indice;
        Nodo * previo = this->actual;

        this->actual = this->buscarNodo(this->raiz, i);

        if(this->actual != NULL)
        {
            this->indice = indice;
            return true;
        }
        else
        {
            this->actual = previo;
            return false;
        }
    }
}

//**********************************************************************
// Sets.
//**********************************************************************
  
bool ArbolDelincuentes::setTotal(int total)
{ 
    this->total = total;
    return true;
}
    
//----------------------------------------------------------------------

bool ArbolDelincuentes::setNumero(int numero)
{
    this->numero = numero;
    return true;
}
      
//**********************************************************************
// Funciones para saber si está un delincuente.
//**********************************************************************

bool ArbolDelincuentes::estaDelincuente (const Delincuente & delincuente)
{
	return (this->buscarDelincuente(this->raiz, delincuente) != NULL);
}
   
//----------------------------------------------------------------------

bool ArbolDelincuentes::estaDelincuente (const string dni)
{
	return (this->buscarDNI(this->raiz, dni) != NULL);
}
    
//----------------------------------------------------------------------

bool ArbolDelincuentes::estaDelincuente (const Cara & cara)
{
	return (this->buscarCara(this->raiz, cara) != NULL);
}
    
//**********************************************************************
// Funciones para salvar y cargar en un txt un árbol.
//**********************************************************************

bool ArbolDelincuentes::salvaNodo (Nodo * nodo, ofstream & salida) const
{
    if(nodo != NULL)
    {
        if(nodo->getDato()->salvaTXT(salida))
        {
            salida << endl;
            
            if(this->salvaNodo(nodo->getIzq(), salida))
                return this->salvaNodo(nodo->getDer(), salida);
            else
                return false;
        }
        else
            return false;
    }
    else
    {
        return true;
    }
}
   
//----------------------------------------------------------------------

bool ArbolDelincuentes::salvaTxt (string salida) const
{
	ofstream file;

	file.open(salida.c_str(), ios::out);
	if(file.is_open())
	{
        if(this->salvaNodo(this->raiz, file))
        {
		    file.close();
		    return true;
        }
        else
        {
		    file.close();
		    return false;
        }
	}
	else
	{
		return false;
	}
}
     
//----------------------------------------------------------------------

bool ArbolDelincuentes::cargaTxt (string entrada)
{
	ifstream file;

	file.open(entrada.c_str(), ios::in);
	if(file.is_open())
	{
        DelincuenteComun auxDelComun;
        DelincuenteConfidente auxDelConfi;
        char zero, aux[256];  
        Delincuente * delincuente = NULL;

        this->BorrarArbol(this->raiz);
        this->Inicializar();

        file.getline(aux, 256);
		while(!file.eof())
        {
            if(auxDelComun.getClassName() == aux)
            {
                delincuente = &auxDelComun;
            }
            else if(auxDelConfi.getClassName() == aux)
            {
                delincuente = &auxDelConfi;
            }
            else
            {
	    	    file.close();
                return false;
            }

            if(delincuente->cargaTXT(file) == false)
            {
                file.close();
                return false;
            }

            this->agregaDelincuente(*delincuente);
            file.getline(aux, 256);
		}

		file.close();
		return true;
	}
	else
	{
		return false;
	}
}
