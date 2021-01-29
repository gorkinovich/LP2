//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 01 - Apartado 01.
//----------------------------------------------------------------------
#pragma hdrstop
#include <iostream>
using namespace std;

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
            return "¨   o   ¨";
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

#pragma argsused
int main (int argc, char* argv[])
{
    char opcion = 'y';
    int seleccion;
    string pelo;
    string ojos;
    string narizOrejas;
    string boca;

    while (opcion == 'y')
    {
        cout << "Seleccione el pelo con un numero de 0 a 2: ";
        cin >> seleccion;
        pelo = damePelo(seleccion);
        cout << "Seleccione los ojos con un numero de 0 a 2: ";
        cin >> seleccion;
        ojos = dameOjos(seleccion);
        cout << "Seleccione las orejas y nariz con un numero de 0 a 2: ";
        cin >> seleccion;
        narizOrejas = dameOrejasYNariz(seleccion);
        cout << "Seleccione la boca con un número de 0 a 2: ";
        cin >> seleccion;
        boca = dameBoca(seleccion);
        cout << endl;

        // Decidir si continuar
        cout << pelo << endl << ojos << endl << narizOrejas;
        cout << endl << boca << endl << " \\_____/" << "\n\n";
        cout << "Quiere continuar (y/n): ";
        cin >> opcion;
        cout << endl;
    }
    return 0;
}
