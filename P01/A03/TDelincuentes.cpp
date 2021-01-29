//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 01 - Apartado 03.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "TDelincuentes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//--------------------------------------------------------------------------- 
/**
 * Función que devuelve una lista de delincuentes inicializada.
 */
TContenedorDelincuentes inicializaContenedorDelincuentes (void)
{
    TContenedorDelincuentes aux;

    aux.ultimo = 0;

    return aux;
}
//---------------------------------------------------------------------------  
/**
 * Función que devuelve la última posición libre de la lista.
 * @param contenedor Lista de delincuentes de la que vamos a obtener el dato.
 * @return La última posición libre de la lista.
 */
int getNumero (const TContenedorDelincuentes & contenedor)
{
    return contenedor.ultimo;
}
//--------------------------------------------------------------------------- 
/**
 * Función para obtener la posición de un delincuente.
 * @param contenedor Lista de delincuentes de la que vamos a obtener el dato.
 * @param nombre Nombre del delincuente a buscar.
 * @param indice Posición donde está el delincuente buscado.
 * @return Devuelve si ha sido encontrado o no.
 */
bool getDelincuente (const TContenedorDelincuentes & contenedor, string nombre, int & indice)
{
    for(int i = 0; i < contenedor.ultimo; ++i)
    {
        if(getNombre(contenedor.delincuentes[i]) == nombre)
        {
            indice = i;
            return true;
        }
    }

    return false;
}
//--------------------------------------------------------------------------- 
/**
 * Función para obtener la posición de un delincuente.
 * @param contenedor Lista de delincuentes de la que vamos a obtener el dato.
 * @param cara Cara del delincuente a buscar.
 * @param indice Posición donde está el delincuente buscado.
 * @return Devuelve si ha sido encontrado o no.
 */
bool getDelincuente (const TContenedorDelincuentes & contenedor, TCara cara, int & indice)
{                
    for(int i = 0; i < contenedor.ultimo; ++i)
    {
        if(getCara(contenedor.delincuentes[i]) == cara)
        {
            indice = i;
            return true;
        }
    }

    return false;
}
//---------------------------------------------------------------------------  
/**
 * Función para obtener la posición de un delincuente.
 * @param contenedor Lista de delincuentes de la que vamos a obtener el dato.
 * @param delincuente Datos del delincuente a buscar.
 * @param indice Posición donde está el delincuente buscado.
 * @return Devuelve si ha sido encontrado o no.
 */
bool getDelincuente (const TContenedorDelincuentes & contenedor, TDelincuente delincuente, int & indice)
{
    for(int i = 0; i < contenedor.ultimo; ++i)
    {
        if(contenedor.delincuentes[i] == delincuente)
        {
            indice = i;
            return true;
        }
    }

    return false;
}
//---------------------------------------------------------------------------  
/**
 * Función para obtener un delincuente de una posición dada.
 * @param contenedor Lista de delincuentes de la que vamos a obtener el dato.
 * @param indice Posición que queremos obtener.
 * @param delincuente Los datos del delincuente que queremos obtener.
 * @return Devuelve si ha sido encontrado o no.
 */
bool getDelincuente (const TContenedorDelincuentes & contenedor, int indice, TDelincuente & delincuente)
{
    if(indice < contenedor.ultimo)
    {
        delincuente = contenedor.delincuentes[indice];
        return true;
    }
    else
    {
        return false;
    }
}
//--------------------------------------------------------------------------- 
/**
 * Función que va a agregar un delincuente de la lista.
 * @param contenedor Lista de delincuentes de la que vamos a obtener el dato.
 * @param elemento Delincuente que se va a agregar.
 * @return Devuelve si ha sido agregad o no.
 * @see borraDelincuente()
 */
bool agregaDelincuente (TContenedorDelincuentes & contenedor, TDelincuente elemento)
{
    if(contenedor.ultimo < MAX_TAMANNO)
    {
        int index;

        if(getDelincuente(contenedor, getNombre(elemento), index))
        {
            contenedor.delincuentes[index] = elemento;
        }
        else
        {
            contenedor.delincuentes[contenedor.ultimo] = elemento;
            contenedor.ultimo++;
        }

        return true;
    }

    return false;
}
//---------------------------------------------------------------------------  
/**
 * Función que va a borrar un delincuente de la lista.
 * @param contenedor Lista de delincuentes de la que vamos a obtener el dato.
 * @param elemento Delincuente que se va a borrar.
 * @return Devuelve si ha sido borrado o no.
 * @see agregaDelincuente()
 */
bool borraDelincuente (TContenedorDelincuentes & contenedor, string nombre)
{
    int index;

    if(getDelincuente(contenedor, nombre, index))
    {
        contenedor.ultimo--;

        for(int i = index; i < contenedor.ultimo; ++i)
        {
            contenedor.delincuentes[i] = contenedor.delincuentes[i + 1];
        }

        return true;
    }

    return false;
}
//---------------------------------------------------------------------------
// Fin TDelincuentes.cpp
//---------------------------------------------------------------------------


