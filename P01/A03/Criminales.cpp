//---------------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 01 - Apartado 03.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("Criminales.res");
USEFORM("FBusqueda.cpp", Busqueda);
USEUNIT("Util.cpp");
USEFORM("FDelincuentes.cpp", Delincuentes);
USEUNIT("TCara.cpp");
USEUNIT("TDelincuente.cpp");
USEUNIT("TDelincuentes.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TDelincuentes), &Delincuentes);
         Application->CreateForm(__classid(TBusqueda), &Busqueda);
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
