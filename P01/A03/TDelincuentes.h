//---------------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 01 - Apartado 03.
//---------------------------------------------------------------------------
#ifndef TDelincuentesH
#define TDelincuentesH
//---------------------------------------------------------------------------
// Librer�as usadas por TContenedorDelincuentes.
//---------------------------------------------------------------------------
#include "TDelincuente.h"
//---------------------------------------------------------------------------
// Constantes.
//---------------------------------------------------------------------------
const int MAX_TAMANNO = 100;
//---------------------------------------------------------------------------
// Tipo TContenedorDelincuentes.
//---------------------------------------------------------------------------
/// Tipo para almacenar una lista de delincuentes.
typedef struct
{
    TDelincuente delincuentes[MAX_TAMANNO]; /**< Lista de delincuentes. */
    int ultimo; /**< �ltima posici�n libre. */
} TContenedorDelincuentes;
//---------------------------------------------------------------------------
// Funciones para manejar el tipo TContenedorDelincuentes.
//---------------------------------------------------------------------------
TContenedorDelincuentes inicializaContenedorDelincuentes (void);

int  getNumero      (const TContenedorDelincuentes & contenedor);
bool getDelincuente (const TContenedorDelincuentes & contenedor, string nombre, int & indice);
bool getDelincuente (const TContenedorDelincuentes & contenedor, TCara cara, int & indice);
bool getDelincuente (const TContenedorDelincuentes & contenedor, TDelincuente delincuente, int & indice);
bool getDelincuente (const TContenedorDelincuentes & contenedor, int indice, TDelincuente & delincuente);

bool agregaDelincuente (TContenedorDelincuentes & contenedor, TDelincuente elemento);
bool borraDelincuente  (TContenedorDelincuentes & contenedor, string nombre);
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
// Fin TDelincuentes.h
//---------------------------------------------------------------------------
