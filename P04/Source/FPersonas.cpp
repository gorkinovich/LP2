//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "FPersonas.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FPersonasBasico"
#pragma resource "*.dfm"
TPersonas *Personas;
//***************************************************************************
__fastcall TPersonas::TPersonas(TComponent* Owner)
    : TPersonasBasico(Owner)
{
}
//***************************************************************************
void TPersonas::vacia (void)
{
	this->TPersonasBasico::vacia();
}
//***************************************************************************
void TPersonas::agregarPersona (Persona * persona)
{
    if(!this->controlador->estaPersona(*persona))
    {
        if(!this->controlador->agregaPersona(*persona))
        {
            MessageBox(Application->Handle, "No se ha podido agregar la persona.",
                       "Fallo al agregar", MB_ICONWARNING);
        }

        this->posicionar(this->controlador->getIndice());
    }
    else
    {
        MessageBox(Application->Handle, "La persona ya existe, por lo que debería modificarla.",
                   "Registro ya existente", MB_ICONWARNING);
    }
}
//---------------------------------------------------------------------------
void TPersonas::modificarPersona (Persona * persona)
{
    if(this->controlador->estaPersona(*persona))
    {
        if(!this->controlador->agregaPersona(*persona))
            MessageBox(Application->Handle, "No se ha podido actualizar la persona.",
                       "Error al actualizar", MB_ICONWARNING);
        else
            this->posicionar(this->controlador->getIndice());
    }
    else
    {
        MessageBox(Application->Handle, "La persona no existe, por lo que debería agregarla.",
                   "Registro inexistente", MB_ICONWARNING);
    }
}
//---------------------------------------------------------------------------
void TPersonas::borrarPersona (Persona * persona)
{
    if(!this->controlador->borraPersona(*persona))
    {
        if(this->controlador->getNumero() > 0)
            MessageBox(Application->Handle, "El registro que intenta borrar no existe.",
                       "Registro inexistente", MB_ICONWARNING);
        else
            MessageBox(Application->Handle, "La base de datos de personas está vacía.",
                       "Base de datos vacía", MB_ICONWARNING);
    }
}
//***************************************************************************
/**
 * Función que crea un nuevo delincuente.
 */
void __fastcall TPersonas::CmdNuevoClick(TObject *Sender)
{
    this->vacia();
}
//---------------------------------------------------------------------------    
/**
 * Función que agrega el delincuente formado a la lista.
 */
void __fastcall TPersonas::CmdAnyadirClick(TObject *Sender)
{
    Persona * aux = this->damePersona();
    this->agregarPersona(aux);
    delete aux;
}
//---------------------------------------------------------------------------   
/**
 * Función que modifica el delincuente formado a la lista.
 */
void __fastcall TPersonas::CmdModificarClick(TObject *Sender)
{
    Persona * aux = this->damePersona();
    this->modificarPersona(aux);
    delete aux;
}
//---------------------------------------------------------------------------  
/**
 * Función que borra el delincuente formado a la lista.
 */
void __fastcall TPersonas::CmdEliminarClick(TObject *Sender)
{
    Persona * aux = this->damePersona();
    this->borrarPersona(aux);
    delete aux;
}
//***************************************************************************
void __fastcall TPersonas::mnuArchivoNuevoClick(TObject *Sender)
{
    this->controlador->nuevo();
    this->ficheroLista = "";
    this->mnuArchivoGuardar->Enabled = false;
    this->vacia();
}
//---------------------------------------------------------------------------
void __fastcall TPersonas::mnuArchivoAbrirClick(TObject *Sender)
{
    if(this->OpenDlg->Execute())
    {
        if(!this->controlador->cargar(this->OpenDlg->FileName.c_str()))
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
void __fastcall TPersonas::mnuArchivoGuardarClick(TObject *Sender)
{
    if(this->ficheroLista != "")
    {   
        if(!this->controlador->salvar(this->ficheroLista.c_str()))
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
void __fastcall TPersonas::mnuArchivoGuardarComoClick(TObject *Sender)
{
    if(this->SaveDlg->Execute())
    {
        if(!this->controlador->salvar(this->SaveDlg->FileName.c_str()))
        {    
            MessageBox(Application->Handle, "No se ha podido salvar el fichero.",
                   "Fallo al salvar el fichero", MB_ICONWARNING);
        }
        this->ficheroLista = this->SaveDlg->FileName;
        this->mnuArchivoGuardar->Enabled = true;
    }
}
//***************************************************************************
void __fastcall TPersonas::mnuBBDDNuevaClick(TObject *Sender)
{
    this->mnuArchivoNuevoClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TPersonas::mnuBBDDNuevoClick(TObject *Sender)
{
    this->CmdNuevoClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TPersonas::mnuBBDDAnyadirClick(TObject *Sender)
{
    this->CmdAnyadirClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TPersonas::mnuBBDDModificarClick(TObject *Sender)
{
    this->CmdModificarClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TPersonas::mnuBBDDEliminarClick(TObject *Sender)
{
    this->CmdEliminarClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TPersonas::mnuBBDDBuscarClick(TObject *Sender)
{
    this->CmdBuscarClick(Sender);
}
//---------------------------------------------------------------------------
