//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 01 - Apartado 03.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "TCara.h"
#include "TDelincuente.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//--------------------------------------------------------------------------- 
/**
 * Crea un delincuente nuevo inicializado.
 * @param nombre Nombre del delincuente.
 * @param delitos Delitos del delincuente.
 * @param cara Cara del delincuente.
 * @return Devuelve el delincuente ya creado.
 */
TDelincuente inicializaDelincuente (string nombre, string delitos, TCara cara)
{
    TDelincuente delincuente;

    delincuente.nombre  = nombre;
    delincuente.delitos = delitos;
    delincuente.cara    = inicializaCara(getPelo(cara), getOjos(cara),
                                         getNarizYOrejas(cara), getBoca(cara));

    return delincuente;
}
//--------------------------------------------------------------------------- 
/**
 * Función que devuelve el nombre del delincuente.
 * @param delincuente Delincuente del que vamos a obtener los datos.
 * @return Devuelve el nombre del delincuente.
 * @see getDelitos(), getCara()
 */
string getNombre (TDelincuente delincuente)
{
    return delincuente.nombre;
}
//--------------------------------------------------------------------------- 
/**
 * Función que devuelve los delitos del delincuente.
 * @param delincuente Delincuente del que vamos a obtener los datos.
 * @return Devuelve los delitos del delincuente.
 * @see getNombre(), getCara()
 */
string getDelitos (TDelincuente delincuente)
{
    return delincuente.delitos;
}
//--------------------------------------------------------------------------- 
/**
 * Función que devuelve la cara del delincuente.
 * @param delincuente Delincuente del que vamos a obtener los datos.
 * @return Devuelve la cara del delincuente.
 * @see getNombre(), getDelitos()
 */
TCara getCara (TDelincuente delincuente)
{
    return delincuente.cara;
}
//--------------------------------------------------------------------------- 
/**
 * Función que cambia el nombre del delincuente.
 * @param delincuente Delincuente del que vamos a obtener los datos.
 * @param nombre Nombre del delincuente.
 * @see setDelitos(), setCara()
 */
void setNombre (TDelincuente delincuente, string nombre)
{
    delincuente.nombre = nombre;
}
//--------------------------------------------------------------------------- 
/**
 * Función que cambia los delitos del delincuente.
 * @param delincuente Delincuente del que vamos a obtener los datos.
 * @param delitos Delitos del delincuente.
 * @see setNombre(), setCara()
 */
void setDelitos (TDelincuente delincuente, string delitos)
{
    delincuente.delitos = delitos;
}
//---------------------------------------------------------------------------
/**
 * Función que cambia la cara del delincuente.
 * @param delincuente Delincuente del que vamos a obtener los datos.
 * @param cara Cara del delincuente.
 * @see setNombre(), setDelitos()
 */
void setCara (TDelincuente delincuente, TCara cara)
{
    delincuente.cara = cara;
}
//--------------------------------------------------------------------------- 
/**
 * Sobrecarga del operador == para TDelincuente.
 */
bool operator == (TDelincuente delincuente1, TDelincuente delincuente2)
{
    return delincuente1.nombre == delincuente2.nombre;
}
//--------------------------------------------------------------------------- 
/**
 * Función que indica si un delincuente es parecido a otro.
 * @param delincuente Delincuente del que vamos a obtener los datos.
 * @param cara Cara con la que queremos comparar el delincuente.
 * @return Devuelve si tiene la cara igual o no.
 */
bool parecido (TDelincuente delincuente, TCara cara)
{
    return (delincuente.cara == cara);
}
//---------------------------------------------------------------------------
// Fin TDelincuente.cpp
//---------------------------------------------------------------------------







