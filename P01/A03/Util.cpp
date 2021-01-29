//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 01 - Apartado 02.
//----------------------------------------------------------------------
#include "Util.h"

/**
 * Función que devuelve una cadena con el pelo seleccionado.
 * @param tipo Tipo de pelo a obtener.
 * @return Una cadena con el pelo.
 * @see dameOjos(), dameOrejasYNariz(), dameBoca()
 */
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

/**
 * Función que devuelve una cadena con los ojos seleccionados.
 * @param tipo Tipo de ojos a obtener.
 * @return Una cadena con los ojos.
 * @see damePelo(), dameOrejasYNariz(), dameBoca()
 */
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

/**
 * Función que devuelve una cadena con las orejas y nariz seleccionadas.
 * @param tipo Tipo de nariz y orejas a obtener.
 * @return Una cadena con la nariz y las orejas.
 * @see damePelo(), dameOjos(), dameBoca()
 */
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

/**
 * Función que devuelve una cadena con la boca seleccionada.
 * @param tipo Tipo de boca a obtener.
 * @return Una cadena con la boca.
 * @see damePelo(), dameOjos(), dameOrejasYNariz()
 */
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