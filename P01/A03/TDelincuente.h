//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 01 - Apartado 03.
//---------------------------------------------------------------------------
#ifndef TDelincuenteH
#define TDelincuenteH
//---------------------------------------------------------------------------
// Librerías usadas por TDelincuente.
//---------------------------------------------------------------------------
#include "TCara.h"
//---------------------------------------------------------------------------
// Tipo TDelincuente.
//---------------------------------------------------------------------------
/// Tipo para almacenar los datos de un delincuente.
typedef struct
{
    string nombre; /**< Nombre del delincuente. */
    string delitos; /**< Delitos del delincuente. */
    TCara cara; /**< Cara del delincuente. */
} TDelincuente;
//---------------------------------------------------------------------------
// Funciones para manejar el tipo TDelincuente.
//---------------------------------------------------------------------------
TDelincuente inicializaDelincuente (string nombre, string delitos, TCara cara);

string getNombre  (TDelincuente delincuente);
string getDelitos (TDelincuente delincuente);
TCara  getCara    (TDelincuente delincuente);

void setNombre  (TDelincuente delincuente, string nombre);
void setDelitos (TDelincuente delincuente, string delitos);
void setCara    (TDelincuente delincuente, TCara cara);

bool operator == (TDelincuente delincuente1, TDelincuente delincuente2);
bool parecido    (TDelincuente delincuente, TCara cara);
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
// Fin TDelincuente.h
//---------------------------------------------------------------------------
