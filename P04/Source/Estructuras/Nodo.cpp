//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "Nodo.h"
#pragma package(smart_init)


Nodo::Nodo ()
{
    this->dato = NULL;
    this->izq  = NULL;
    this->der  = NULL;
}


Nodo::Nodo (Persona * dato)
{   
    this->dato = dato;
    this->izq  = NULL;
    this->der  = NULL;
}


Nodo::~Nodo ()
{
    if(this->dato != NULL)
        delete this->dato;
        
    this->izq = NULL;
    this->der = NULL;
}


Persona * Nodo::getDato (void)
{
    return this->dato;
}


Nodo * Nodo::getIzq (void)
{  
    return this->izq;
}


Nodo * Nodo::getDer (void)
{   
    return this->der;
}
             

void Nodo::setDato (Persona * dato)
{
    this->dato = dato;
}


void Nodo::setIzq (Nodo * anterior)
{
    this->izq = anterior;
}


void Nodo::setDer (Nodo * posterior)
{
    this->der = posterior;
}