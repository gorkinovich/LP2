//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 03 - Grupo 03.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "FConfidentes.h"      
#include "DelincuenteComun.h"
#include "DelincuenteConfidente.h"         
#include "CaraComun.h"
#include "CaraConfidente.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FTodosDelincuentes"
#pragma resource "*.dfm"
TConfidentes *Confidentes;
//---------------------------------------------------------------------------
__fastcall TConfidentes::TConfidentes(TComponent* Owner,
                                      ContenedorDelincuentes * delincuentes)
    : TTodosDelincuentes(Owner, delincuentes)
{
}
//---------------------------------------------------------------------------
void __fastcall TConfidentes::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    this->delincuentes = NULL;
}           
//---------------------------------------------------------------------------
void __fastcall TConfidentes::FormShow(TObject *Sender)
{
    this->posicionar(0);
}
//---------------------------------------------------------------------------
/**
 * Función para actualizar la cara mostrada en el memo del formulario.
 */
void __fastcall TConfidentes::dibujaCara (Cara * cara)
{
    if(cara->getClassName() == "CaraConfidente")
    {
        CaraConfidente * auxcc = (CaraConfidente *) cara;
        auxcc->dibujaSupervisor(this->Retrato->Canvas);
    }
    else
    {
        cara->dibuja(this->Retrato->Canvas);
    }
}
//---------------------------------------------------------------------------
// Fin TConfidentes.cpp
//---------------------------------------------------------------------------

