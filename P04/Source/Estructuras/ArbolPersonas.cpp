//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "ArbolPersonas.h"
#pragma package(smart_init)

//**********************************************************************
// Constructores.
//**********************************************************************

ArbolPersonas::ArbolPersonas ()
{
    this->Inicializar();
}

//----------------------------------------------------------------------

ArbolPersonas::ArbolPersonas (int total)
{
    this->Inicializar();
    this->setTotal(total);
}
       
//----------------------------------------------------------------------

void ArbolPersonas::Inicializar (void)
{     
	this->raiz   = NULL;
	this->actual = NULL;

	this->total  = -1;
	this->numero =  0;
	this->indice = -1;
}

//----------------------------------------------------------------------

ArbolPersonas::ArbolPersonas (const ArbolPersonas & contenedor)
{
	(*this) = contenedor;
}
 
//**********************************************************************
// Operador copia.
//**********************************************************************

ArbolPersonas & ArbolPersonas::operator = (const ArbolPersonas & contenedor)
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

ArbolPersonas::~ArbolPersonas ()
{
    this->BorrarArbol(this->raiz);
    this->Inicializar();
}

//**********************************************************************
// Función para copiar un arbol a otro.
//**********************************************************************

Nodo * ArbolPersonas::CopiarArbol (Nodo * fuente)
{
    if(fuente != NULL)
    {
        Nodo * destino = new Nodo();     
        destino->setIzq(this->CopiarArbol(fuente->getIzq()));
        destino->setDer(this->CopiarArbol(fuente->getDer()));
        destino->setDato(&fuente->getDato()->clone());

        return destino;
    }
    else
    {
        return NULL;
    }
}
     
//**********************************************************************
// Función para borrar el arbol.
//**********************************************************************

void ArbolPersonas::BorrarArbol (Nodo * nodo)
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

int ArbolPersonas::getTotal (void) const
{
	return this->total;
}
   
//----------------------------------------------------------------------

int ArbolPersonas::getNumero (void) const
{
	return this->numero;
}
   
//----------------------------------------------------------------------

int ArbolPersonas::getIndice (void) const
{
	return this->indice;
}
  
//**********************************************************************
// Funciones para buscar personas.
//**********************************************************************

Persona * ArbolPersonas::buscarPersona (Nodo * nodo, const Persona & clave)
{
    if(nodo != NULL)
    {
        Persona * aux = nodo->getDato();

        if(*aux == clave)
            return aux;
        else if(clave <= *aux)
            return this->buscarPersona(nodo->getIzq(), clave);
        else
            return this->buscarPersona(nodo->getDer(), clave);
    }
    else
    {
        return NULL;
    }
}  
    
//----------------------------------------------------------------------

Persona * ArbolPersonas::buscarID (Nodo * nodo, const std::string & clave)
{
    if(nodo != NULL)
    {
        Persona * aux = nodo->getDato();

        if(aux->getID() == clave)
            return aux;
        else
        {
            aux = this->buscarID(nodo->getIzq(), clave);
            if(aux != NULL)
                return aux;
            else
                return this->buscarID(nodo->getDer(), clave);
        }
    }
    else
    {
        return NULL;
    }
}
   
//----------------------------------------------------------------------

Persona * ArbolPersonas::buscarCara (Nodo * nodo, const Cara & clave)
{
    if(nodo != NULL)
    {         
        Persona * aux = nodo->getDato();

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
// Funciones para obtener un persona.
//**********************************************************************

bool ArbolPersonas::getPersona (const Persona & buscado, Persona *& dato)
{
    Persona * aux = this->buscarPersona(this->raiz, buscado);
	dato = aux;
    return (aux != NULL);
}
   
//----------------------------------------------------------------------

bool ArbolPersonas::getPersona (std::string id, Persona *& dato)
{
    Persona * aux = this->buscarID(this->raiz, id);
	dato = aux;
    return (aux != NULL);
}
     
//----------------------------------------------------------------------

bool ArbolPersonas::getPersona (const Cara & cara, Persona *& dato)
{
    Persona * aux = this->buscarCara(this->raiz, cara);
	dato = aux;
    return (aux != NULL);
}
   
//----------------------------------------------------------------------

Persona * ArbolPersonas::buscarPorIndice (Nodo * nodo, int & i)
{
    if(nodo != NULL)
    {           
        Persona * aux = this->buscarPorIndice(nodo->getIzq(), i);  
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

bool ArbolPersonas::getPersona (int indice, Persona *& dato)
{
    Persona * aux = this->buscarPorIndice(this->raiz, indice);
	dato = aux;
    return (aux != NULL);
}
            
//----------------------------------------------------------------------

bool ArbolPersonas::getPersonaIndice (Persona *& dato)
{
    if(this->actual != NULL)
    {
        Persona * aux = this->actual->getDato();
		dato = aux;
        return (aux != NULL);
    }
    else
        return false;
}
          
//**********************************************************************
// Funciones para agregar un persona.
//**********************************************************************

Nodo * ArbolPersonas::AgregarNodo (Nodo * nodo, Nodo * nuevo)
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

bool ArbolPersonas::PosicionarEnNodo (Nodo * nodo, Nodo * clave)
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

bool ArbolPersonas::agregaPersona (const Persona & persona)
{
    if(this->estaPersona(persona))
    {
        Nodo * nodo = this->buscarNodo(this->raiz, persona);
        *(nodo->getDato()) = persona;

        return true;
    }
    else
    {
        if((this->getTotal() >= 0) && (this->getTotal() <= this->getNumero()))
            return false;

        Nodo * nuevo = new Nodo();

        if(nuevo != NULL)
        {
			nuevo->setDato(&persona.clone());

            if(nuevo->getDato() == NULL)
            {
                delete nuevo;
                return false;
            }

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
// Funciones para borrar un persona.
//**********************************************************************

Nodo * ArbolPersonas::buscarNodo (Nodo * nodo, const Persona & clave)
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

Nodo * ArbolPersonas::buscarNodoPadre (Nodo * nodo, Nodo * clave)
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

bool ArbolPersonas::borraPersona (const Persona & persona)
{
    Nodo * nodo = this->buscarNodo(this->raiz, persona);

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

Nodo * ArbolPersonas::buscarNodo (Nodo * nodo, int & i)
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

bool ArbolPersonas::setIndice (int indice)
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
  
bool ArbolPersonas::setTotal (int total)
{ 
    this->total = total;
    return true;
}
    
//----------------------------------------------------------------------

bool ArbolPersonas::setNumero (int numero)
{
    this->numero = numero;
    return true;
}
      
//**********************************************************************
// Funciones para saber si está un persona.
//**********************************************************************

bool ArbolPersonas::estaPersona (const Persona & persona)
{
	return (this->buscarPersona(this->raiz, persona) != NULL);
}

//----------------------------------------------------------------------

bool ArbolPersonas::estaPersona (const std::string id)
{
	return (this->buscarID(this->raiz, id) != NULL);
}

//**********************************************************************
// Función para saber si está el arbol vacio.
//**********************************************************************

bool ArbolPersonas::vacia (void)
{
	return (this->raiz == NULL);
}

//----------------------------------------------------------------------

bool ArbolPersonas::nuevo (void)
{
    this->BorrarArbol(this->raiz);
    this->Inicializar();
	return true;
}