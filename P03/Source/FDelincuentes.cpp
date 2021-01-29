//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 03 - Grupo 03.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "FDelincuentes.h"
#include "FConfidentes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FTodosDelincuentes"
#pragma resource "*.dfm"
TDelincuentes *Delincuentes;
//---------------------------------------------------------------------------
__fastcall TDelincuentes::TDelincuentes(TComponent* Owner)
    : TTodosDelincuentes(Owner)
{
    this->ficheroLista = "";
    this->mnuArchivoGuardar->Enabled = false;
}
//---------------------------------------------------------------------------
__fastcall TDelincuentes::~TDelincuentes()
{
}
//---------------------------------------------------------------------------
void __fastcall TDelincuentes::mnuArchivoNuevoClick(TObject *Sender)
{
    if(this->delincuentes != NULL)
        delete this->delincuentes;

    this->delincuentes = new ArbolDelincuentes();

    this->ficheroLista = "";
    this->mnuArchivoGuardar->Enabled = false;
    this->vacia();

    if(this->delincuentes == NULL)
        MessageBox(Application->Handle, "No se ha podido reservar memoria para la base de datos.",
                   "Fallo al crear una nueva base de datos", MB_ICONWARNING);
}
//---------------------------------------------------------------------------
void __fastcall TDelincuentes::mnuArchivoAbrirClick(TObject *Sender)
{
    if(this->OpenDlg->Execute())
    {
        if(!this->delincuentes->cargaTxt(this->OpenDlg->FileName.c_str()))
        {
            MessageBox(Application->Handle, "No se ha podido cargar el fichero.",
                   "Fallo al cargar el fichero", MB_ICONWARNING);
            this->vacia();
        }
        else
        {                 
            this->posicionar(0);   
            this->ficheroLista = this->OpenDlg->FileName;
            this->mnuArchivoGuardar->Enabled = true;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TDelincuentes::mnuArchivoGuardarClick(TObject *Sender)
{
    if(this->ficheroLista != "")
    {   
        if(!this->delincuentes->salvaTxt(this->ficheroLista.c_str()))
        {    
            MessageBox(Application->Handle, "No se ha podido salvar el fichero.",
                   "Fallo al salvar el fichero", MB_ICONWARNING);
        }
    }
    else
    {
        this->mnuArchivoGuardarComoClick(Sender);
    }
}
//---------------------------------------------------------------------------
void __fastcall TDelincuentes::mnuArchivoGuardarComoClick(TObject *Sender)
{
    if(this->SaveDlg->Execute())
    {
        if(!this->delincuentes->salvaTxt(this->SaveDlg->FileName.c_str()))
        {    
            MessageBox(Application->Handle, "No se ha podido salvar el fichero.",
                   "Fallo al salvar el fichero", MB_ICONWARNING);
        }
        this->ficheroLista = this->SaveDlg->FileName;
        this->mnuArchivoGuardar->Enabled = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TDelincuentes::mnuBBDDNuevoClick(TObject *Sender)
{
    this->CmdNuevoClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TDelincuentes::mnuBBDDAgregarClick(TObject *Sender)
{
    this->CmdAgregarClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TDelincuentes::mnuBBDDBorrarClick(TObject *Sender)
{
    this->CmdBorrarClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TDelincuentes::mnuBBDDModificarClick(TObject *Sender)
{
    this->CmdModificarClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TDelincuentes::mnuBBDDBuscarClick(TObject *Sender)
{
    this->CmdBuscarClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TDelincuentes::mnuConfidentesClick(TObject *Sender)
{
    TConfidentes * confidentes = new TConfidentes(this, this->delincuentes);

    if(confidentes != NULL)
    {
        confidentes->ShowModal();
        delete confidentes;
        this->posicionar(0);
    }
}
//---------------------------------------------------------------------------

