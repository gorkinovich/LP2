//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 03 - Grupo 03.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("Criminales.res");
USEFORM("Source\FBusqueda.cpp", Busqueda);
USEUNIT("Source\Delincuente.cpp");
USEUNIT("Source\Cara.cpp");
USEUNIT("Source\CaraRasgos.cpp");
USEUNIT("Source\ContenedorDelincuentes.cpp");
USEUNIT("Source\ArbolDelincuentes.cpp");
USEUNIT("Source\CaraComun.cpp");
USEUNIT("Source\CaraConfidente.cpp");
USEUNIT("Source\DelincuenteComun.cpp");
USEUNIT("Source\DelincuenteConfidente.cpp");
USEUNIT("Source\Nodo.cpp");
USEFORM("Source\FTodosDelincuentes.cpp", TodosDelincuentes);
USEFORM("Source\FConfidentes.cpp", Confidentes);
USEFORM("Source\FDelincuentes.cpp", Delincuentes);
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
