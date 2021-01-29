//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 01 - Apartado 03.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "TCara.h"
#include "Util.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
/**
 * Función que crea una cara ya inicializada.
 * @param pelo Tipo de pelo de la cara.
 * @param ojos Tipo de ojos de la cara.
 * @param nariz Tipo de nariz y orejas de la cara.
 * @param boca Tipo de boca de la cara.
 * @return Devuelve una boca ya inicializada.
 */
TCara inicializaCara (int pelo, int ojos, int nariz, int boca)
{
    TCara cara;

    cara.pelo         = pelo;
    cara.ojos         = ojos;
    cara.narizYOrejas = nariz;
    cara.boca         = boca;

    return cara;
}
//---------------------------------------------------------------------------
/**
 * Función que pasándole una cara nos devuelve la "imagen" que forma.
 * @param cara Cara de la que vamos a devolver la representación.
 * @return Devuelve una cadena que representa la cara.
 */
string dameCara (TCara cara)
{
    string aux;

    aux =  damePelo(cara.pelo);
    aux += "\r\n";
    aux += dameOjos(cara.ojos);
    aux += "\r\n";
    aux += dameOrejasYNariz(cara.narizYOrejas);
    aux += "\r\n";
    aux += dameBoca(cara.boca);
    aux += "\r\n";
    aux += " \\_____/";

    return aux;
}
//---------------------------------------------------------------------------
/**
 * Sobrecarga del operador == para TCara.
 */
bool operator == (TCara cara1, TCara cara2)
{
    if((cara1.boca == cara2.boca) &&
       (cara1.ojos == cara2.ojos) &&
       (cara1.narizYOrejas == cara2.narizYOrejas) &&
       (cara1.pelo == cara2.pelo))
        return true;
    else
        return false;
}
//--------------------------------------------------------------------------- 
/**
 * Función para obtener la boca de la cara indicada.
 * @param cara Cara de la que queremos obtener la propiedad.
 * @return Devuelve la boca de la cara.
 * @see getOjos(), getNarizYOrejas(), getPelo()
 */
int getBoca (TCara cara)
{
    return cara.boca;
}
//--------------------------------------------------------------------------- 
/**
 * Función para obtener los ojos de la cara indicada.
 * @param cara Cara de la que queremos obtener la propiedad.
 * @return Devuelve los ojos de la cara.
 * @see getBoca(), getNarizYOrejas(), getPelo()
 */
int getOjos (TCara cara)
{
    return cara.ojos;
}
//--------------------------------------------------------------------------- 
/**
 * Función para obtener la nariz y las orejas de la cara indicada.
 * @param cara Cara de la que queremos obtener la propiedad.
 * @return Devuelve la nariz y las orejas de la cara.
 * @see getBoca(), getOjos(), getPelo()
 */
int getNarizYOrejas (TCara cara)
{
    return cara.narizYOrejas;
}
//--------------------------------------------------------------------------- 
/**
 * Función para obtener el pelo de la cara indicada.
 * @param cara Cara de la que queremos obtener la propiedad.
 * @return Devuelve el pelo de la cara.
 * @see getBoca(), getOjos(), getNarizYOrejas()
 */
int getPelo (TCara cara)
{
    return cara.pelo;
}
//---------------------------------------------------------------------------
// Fin TCara.cpp
//---------------------------------------------------------------------------