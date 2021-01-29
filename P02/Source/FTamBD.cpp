//---------------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 02 - Grupo 03.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "FTamBD.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTamBD *TamBD;
//---------------------------------------------------------------------------
__fastcall TTamBD::TTamBD(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTamBD::FormShow(TObject *Sender)
{
    this->Respuesta = 1000;    
}
//---------------------------------------------------------------------------
void __fastcall TTamBD::CmdCancelarClick(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TTamBD::CmdAceptarClick(TObject *Sender)
{
    this->Respuesta = this->TxtRespuesta->Text.ToInt();
    this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TTamBD::TxtRespuestaKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == 13)
    {
        this->CmdAceptarClick(Sender);
    }
}
//---------------------------------------------------------------------------

