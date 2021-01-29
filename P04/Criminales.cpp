//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("Criminales.res");
USEUNIT("Source\Datos\Persona.cpp");
USEUNIT("Source\Datos\Policia.cpp");
USEUNIT("Source\Datos\Usuario.cpp");
USEUNIT("Source\Datos\Administrador.cpp");
USEUNIT("Source\Datos\Cara.cpp");
USEUNIT("Source\Datos\CaraComun.cpp");
USEUNIT("Source\Datos\CaraClasificada.cpp");
USEUNIT("Source\Estructuras\Nodo.cpp");
USEUNIT("Source\Estructuras\ArbolPersonas.cpp");
USEUNIT("Source\Datos\Delincuente.cpp");
USEUNIT("Source\Datos\Lector.cpp");
USEUNIT("Source\Datos\Sonnador.cpp");
USEUNIT("Source\Datos\DelincuenteConfidente.cpp");
USEUNIT("Source\Datos\LectorConfidente.cpp");
USEUNIT("Source\Datos\SonnadorConfidente.cpp");
USEUNIT("Source\Datos\CaraRasgos.cpp");
USEUNIT("Source\IO\Personas_IO.cpp");
USEUNIT("Source\IO\Caras_IO.cpp");
USEUNIT("Source\IO\ContenedorPersonas_IO.cpp");
USEUNIT("Source\Patrones\FactoriaPersonas.cpp");
USEUNIT("Source\Patrones\ControladorPersonas.cpp");
USEFORM("Source\FBusqueda.cpp", Busqueda);
USEFORM("Source\FPersonasBasico.cpp", PersonasBasico);
USEFORM("Source\FPersonas.cpp", Personas);
USEFORM("Source\FConfidentes.cpp", Confidentes);
USEFORM("Source\FUsuarios.cpp", Usuarios);
USEFORM("Source\FDelincuentes.cpp", Delincuentes);
USEFORM("Source\FAcceso.cpp", Acceso);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TAcceso), &Acceso);
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
