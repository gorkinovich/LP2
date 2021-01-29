//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 01 - Apartado 03.
//---------------------------------------------------------------------------
#ifndef TCaraH
#define TCaraH
//---------------------------------------------------------------------------
// Librerías usadas por TCara.
//---------------------------------------------------------------------------
#include <iostream>
using namespace std;
//---------------------------------------------------------------------------
// Tipo TCara.
//---------------------------------------------------------------------------
/// Tipo que almacena los datos de una cara.
typedef struct
{
    int pelo; /**< Pelo seleccionado de la cara. */
    int ojos; /**< Ojos seleccionados de la cara. */
    int narizYOrejas; /**< Nariz y orejas seleccionadas de la cara. */
    int boca; /**< Boca seleccionada de la cara. */
} TCara;
//---------------------------------------------------------------------------
// Funciones para manejar el tipo TCara.
//---------------------------------------------------------------------------
TCara  inicializaCara (int pelo, int ojos, int nariz, int boca);
string dameCara       (TCara cara);
bool   operator ==    (TCara cara1, TCara cara2);

int getBoca         (TCara cara);
int getOjos         (TCara cara);
int getNarizYOrejas (TCara cara);
int getPelo         (TCara cara);
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
// Fin TCara.h
//---------------------------------------------------------------------------