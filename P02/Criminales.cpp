//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 02 - Grupo 03.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("Criminales.res");
USEFORM("Source\FBusqueda.cpp", Busqueda);
USEFORM("Source\FDelincuentes.cpp", Delincuentes);
USEUNIT("Source\Delincuente.cpp");
USEUNIT("Source\Cara.cpp");
USEUNIT("Source\CaraRasgos.cpp");
USEUNIT("Source\ContenedorDelincuentes.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->CreateForm(__classid(TDelincuentes), &Delincuentes);
       Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
// Fin Criminales.cpp
//---------------------------------------------------------------------------
