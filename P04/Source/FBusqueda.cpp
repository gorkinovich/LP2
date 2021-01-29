//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "FBusqueda.h"
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
 * Función para actualizar la cara mostrada en el memo del formulario.
 */
void TBusqueda::actualizarCara (void)
{
    std::string pelo        = dibujaPelo(getPeloFromRadioGroup(this->RBTipoPelo->ItemIndex));
    std::string ojos        = dibujaOjos(getOjosFromRadioGroup(this->RBTipoOjos->ItemIndex));
    std::string narizOrejas = dibujaNarizYOrejas(getNarizYOrejasFromRadioGroup(this->RBTipoOrejas->ItemIndex));
    std::string boca        = dibujaBoca(getBocaFromRadioGroup(this->RBTipoBoca->ItemIndex));
    std::string menton      = dibujaMenton(getMentonFromRadioGroup(this->RBTipoMenton->ItemIndex));

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
 * Función para devolver la cara elegida en el formulario.
 * @return La cara elegida.
 */
CaraComun * TBusqueda::dameCara (void)
{
    return &(this->caraElegida);
}
//---------------------------------------------------------------------------
/**
 * Función que se ejecuta cuando se muestra el formulario.
 * @param Sender Objeto que llama al método.
 * @return actualizarCara()
 */
void __fastcall TBusqueda::FormShow(TObject *Sender)
{
    this->caraElegida = CaraComun();

    this->actualizarCara();
}
//---------------------------------------------------------------------------
/**
 * Función para aceptar la cara formada.
 * @param Sender Objeto que llama al método.
 * @see CmdCancelClick()
 */
void __fastcall TBusqueda::CmdOKClick(TObject *Sender)
{
    this->caraElegida = CaraComun(getPeloFromRadioGroup(this->RBTipoPelo->ItemIndex),
                                  getOjosFromRadioGroup(this->RBTipoOjos->ItemIndex),
                                  getNarizYOrejasFromRadioGroup(this->RBTipoOrejas->ItemIndex),
                                  getBocaFromRadioGroup(this->RBTipoBoca->ItemIndex),
                                  getMentonFromRadioGroup(this->RBTipoMenton->ItemIndex),
                                  this->TxtRetina->Text.c_str()); 

    this->Close();
}
//---------------------------------------------------------------------------
/**
 * Función para cancelar la busqueda.
 * @param Sender Objeto que llama al método.
 * @see CmdOKClick()
 */
void __fastcall TBusqueda::CmdCancelClick(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------
/**
 * Función que se ejecuta al cambiar el tipo de pelo.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TBusqueda::RBTipoPeloClick(TObject *Sender)
{
    this->actualizarCara();
}
//---------------------------------------------------------------------------
/**
 * Función que se ejecuta al cambiar el tipo de ojos.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TBusqueda::RBTipoOjosClick(TObject *Sender)
{
    this->actualizarCara();
} 
//---------------------------------------------------------------------------
/**
 * Función que se ejecuta al cambiar el tipo de nariz y orejas.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TBusqueda::RBTipoOrejasClick(TObject *Sender)
{
    this->actualizarCara();
}
//---------------------------------------------------------------------------
/**
 * Función que se ejecuta al cambiar el tipo de boca.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TBusqueda::RBTipoBocaClick(TObject *Sender)
{
    this->actualizarCara();
}
//---------------------------------------------------------------------------  
/**
 * Función que se ejecuta al cambiar el tipo de mentón.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TBusqueda::RBTipoMentonClick(TObject *Sender)
{
    this->actualizarCara();
}
//---------------------------------------------------------------------------
// Fin FBusqueda.cpp
//---------------------------------------------------------------------------
