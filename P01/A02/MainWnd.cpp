//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 01 - Apartado 02.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "MainWnd.h"
#include "Util.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CmdGenerarCara_OnClick(TObject *Sender)
{
    string pelo        = damePelo(this->RBTipoPelo->ItemIndex);
    string ojos        = dameOjos(this->RBTipoOjos->ItemIndex);
    string narizOrejas = dameOrejasYNariz(this->RBTipoBoca->ItemIndex);
    string boca        = dameBoca(this->RBTipoOrejas->ItemIndex);

    //-----------------------------------------------------------------------
    // Actualizamos el cuadro de texto con el retrato.
    //-----------------------------------------------------------------------
    MainForm->Retrato->Lines->Clear();
    MainForm->Retrato->Lines->Add(pelo.c_str());
    MainForm->Retrato->Lines->Add(ojos.c_str());
    MainForm->Retrato->Lines->Add(narizOrejas.c_str());
    MainForm->Retrato->Lines->Add(boca.c_str());
    MainForm->Retrato->Lines->Add(" \\_____/");
}
//---------------------------------------------------------------------------
// Fin MainWnd.cpp
//---------------------------------------------------------------------------