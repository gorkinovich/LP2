//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 01 - Apartado 03.
//---------------------------------------------------------------------------
#ifndef TDelincuentesH
#define TDelincuentesH
//---------------------------------------------------------------------------
// Librerías usadas por TContenedorDelincuentes.
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
    int ultimo; /**< Última posición libre. */
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
