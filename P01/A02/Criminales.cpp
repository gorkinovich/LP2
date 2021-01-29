//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 01 - Apartado 02.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("Criminales.res");
USEFORM("MainWnd.cpp", MainForm);
USEUNIT("Util.cpp");
USE("\\LP2\P01\A02\Util.h", File);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TMainForm), &MainForm);
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
