//---------------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 02 - Grupo 03.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "FBusqueda.h"
#include "CaraRasgos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBusqueda *Busqueda;
//---------------------------------------------------------------------------
__fastcall TBusqueda::TBusqueda(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
/**
 * Funci�n para actualizar la cara mostrada en el memo del formulario.
 */
void __fastcall TBusqueda::actualizarCara (void)
{
    string pelo        = dibujaPelo((Pelo) ((this->RBTipoPelo->ItemIndex + 1) % 4));
    string ojos        = dibujaOjos((Ojos) ((this->RBTipoOjos->ItemIndex + 1) % 4));
    string narizOrejas = dibujaNarizYOrejas((NarizYOrejas) ((this->RBTipoOrejas->ItemIndex + 1) % 4));
    string boca        = dibujaBoca((Boca) ((this->RBTipoBoca->ItemIndex + 1) % 4));
    string menton      = dibujaMenton((Menton) ((this->RBTipoMenton->ItemIndex + 1) % 4));

    //-----------------------------------------------------------------------
    // Actualizamos el cuadro de texto con el retrato.
    //-----------------------------------------------------------------------
    this->Retrato->Lines->Clear();
    this->Retrato->Lines->Add(pelo.c_str());
    this->Retrato->Lines->Add(ojos.c_str());
    this->Retrato->Lines->Add(narizOrejas.c_str());
    this->Retrato->Lines->Add(boca.c_str());
    this->Retrato->Lines->Add(menton.c_str());
}
//---------------------------------------------------------------------------
/**
 * Funci�n para devolver la cara elegida en el formulario.
 * @return La cara elegida.
 */
Cara __fastcall TBusqueda::dameCara (void)
{
    return this->caraElegida;
}
//---------------------------------------------------------------------------
/**
 * Funci�n que se ejecuta cuando se muestra el formulario.
 * @param Sender Objeto que llama al m�todo.
 * @return actualizarCara()
 */
void __fastcall TBusqueda::FormShow(TObject *Sender)
{
    this->caraElegida = Cara();

    this->actualizarCara();
}
//---------------------------------------------------------------------------
/**
 * Funci�n para aceptar la cara formada.
 * @param Sender Objeto que llama al m�todo.
 * @see CmdCancelClick()
 */
void __fastcall TBusqueda::CmdOKClick(TObject *Sender)
{
    this->caraElegida = Cara((Pelo) ((this->RBTipoPelo->ItemIndex + 1) % 4),
                             (Ojos) ((this->RBTipoOjos->ItemIndex + 1) % 4),
                             (NarizYOrejas) ((this->RBTipoOrejas->ItemIndex + 1) % 4),
                             (Boca) ((this->RBTipoBoca->ItemIndex + 1) % 4),
                             (Menton) ((this->RBTipoMenton->ItemIndex + 1) % 4));

    this->Close();
}
//---------------------------------------------------------------------------
/**
 * Funci�n para cancelar la busqueda.
 * @param Sender Objeto que llama al m�todo.
 * @see CmdOKClick()
 */
void __fastcall TBusqueda::CmdCancelClick(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------
/**
 * Funci�n que se ejecuta al cambiar el tipo de pelo.
 * @param Sender Objeto que llama al m�todo.
 */
void __fastcall TBusqueda::RBTipoPeloClick(TObject *Sender)
{
    this->actualizarCara();
}
//---------------------------------------------------------------------------
/**
 * Funci�n que se ejecuta al cambiar el tipo de ojos.
 * @param Sender Objeto que llama al m�todo.
 */
void __fastcall TBusqueda::RBTipoOjosClick(TObject *Sender)
{
    this->actualizarCara();
} 
//---------------------------------------------------------------------------
/**
 * Funci�n que se ejecuta al cambiar el tipo de nariz y orejas.
 * @param Sender Objeto que llama al m�todo.
 */
void __fastcall TBusqueda::RBTipoOrejasClick(TObject *Sender)
{
    this->actualizarCara();
}
//---------------------------------------------------------------------------
/**
 * Funci�n que se ejecuta al cambiar el tipo de boca.
 * @param Sender Objeto que llama al m�todo.
 */
void __fastcall TBusqueda::RBTipoBocaClick(TObject *Sender)
{
    this->actualizarCara();
}
//---------------------------------------------------------------------------  
/**
 * Funci�n que se ejecuta al cambiar el tipo de ment�n.
 * @param Sender Objeto que llama al m�todo.
 */
void __fastcall TBusqueda::RBTipoMentonClick(TObject *Sender)
{
    this->actualizarCara();
}
//---------------------------------------------------------------------------
// Fin FBusqueda.cpp
//---------------------------------------------------------------------------
