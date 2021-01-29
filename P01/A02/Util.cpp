//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 01 - Apartado 02.
//----------------------------------------------------------------------
#include "Util.h"

// Devuelve una cadena con el pelo seleccionado
// Valores reconocidos en tipo:0,1,2
string damePelo (int tipo)
{
    switch (tipo)
    {
        case 0:
            return "WWWWWWWWW";
        case 1:
            return "\\\\\\//////";
        case 2:
            return "|'''''''|";
        default:
            return "----------";
    }
}

// Devuelve una cadena con los ojos seleccionados
// Valores reconocidos en tipo:0,1,2
string dameOjos (int tipo)
{
    switch (tipo)
    {
        case 0:
            return "|  O O  |";
        case 1:
            return "|-(. .)-|";
        case 2:
            return "|  \\ /  |";
        default:
            return "----------";
    }
}

// Devuelve una cadena con las orejas y nariz seleccionadas
// Valores reconocidos en tipo:0,1,2
string dameOrejasYNariz (int tipo)
{
    switch (tipo)
    {
        case 0:
            return "@   J   @";
        case 1:
            return "¿   o   ¿";
        case 2:
            return "<   -   >";
        default:
            return "----------";
    }
}

// Devuelve una cadena con la boca seleccionada
// Valores reconocidos en tipo:0,1,2
string dameBoca (int tipo)
{
    switch (tipo)
    {
        case 0:
            return "|  ===  |";
        case 1:
            return "|   -   |";
        case 2:
            return "|  ---  |";
        default:
            return "----------";
    }
}
//---------------------------------------------------------------------------
// Fin Util.cpp
//---------------------------------------------------------------------------