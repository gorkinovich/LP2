//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 03 - Grupo 03.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "FTodosDelincuentes.h"
#include "FBusqueda.h"              
#include "DelincuenteComun.h"
#include "DelincuenteConfidente.h"         
#include "CaraComun.h"
#include "CaraConfidente.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTodosDelincuentes *TodosDelincuentes;
//---------------------------------------------------------------------------
/**
 * Función que mete en una etiqueta un número como texto de esta.
 * @param lbl Equiqueta que modificar.
 * @param numero Número que se va a mostrar en la etiqueta.
 */
void MeterNumeroEnLabel (TLabel * lbl, int numero)
{
    lbl->Caption = lbl->Caption.sprintf("%d", numero + 1);
}
//---------------------------------------------------------------------------
__fastcall TTodosDelincuentes::TTodosDelincuentes(TComponent* Owner)
    : TForm(Owner)
{
    this->delincuentes = new ArbolDelincuentes();
}   
//---------------------------------------------------------------------------
__fastcall TTodosDelincuentes::TTodosDelincuentes(TComponent* Owner,
                                    ContenedorDelincuentes * delincuentes)
    : TForm(Owner)
{
    this->delincuentes = delincuentes;
}
//---------------------------------------------------------------------------
__fastcall TTodosDelincuentes::~TTodosDelincuentes ()
{     
    if(this->delincuentes != NULL)
    {
        delete this->delincuentes;
    }
}
//---------------------------------------------------------------------------
Delincuente * __fastcall TTodosDelincuentes::dameDelincuente (void)
{
    Delincuente * aux = NULL;
    Cara * auxc = this->ObtenerCaraDeCheckButtons();

    if(auxc != NULL)
    {
        if(this->CBConfidente->Checked)
        {
            aux = new DelincuenteConfidente(this->TxtDNI->Text.c_str(),
                                            this->TxtNombre->Text.c_str(),
                                            this->TxtDelitos->Text.c_str(),
                                            this->TxtSupervisor->Text.c_str(),
                                            auxc);
        }
        else
        {
            aux = new DelincuenteComun(this->TxtDNI->Text.c_str(),
                                       this->TxtNombre->Text.c_str(),
                                       this->TxtDelitos->Text.c_str(),
                                       auxc);
        }

        if(aux == NULL)
        {
            delete auxc;
        }
    }
    
    return aux;
}
//---------------------------------------------------------------------------
Cara * TTodosDelincuentes::ObtenerCaraDeCheckButtons (void)
{               
    Cara * aux = NULL;

    if(this->CBConfidente->Checked)
    {
        aux = new CaraConfidente(getPeloFromRadioGroup(this->RBTipoPelo->ItemIndex),
                                 getOjosFromRadioGroup(this->RBTipoOjos->ItemIndex),
                                 getNarizYOrejasFromRadioGroup(this->RBTipoOrejas->ItemIndex),
                                 getBocaFromRadioGroup(this->RBTipoBoca->ItemIndex),
                                 getMentonFromRadioGroup(this->RBTipoMenton->ItemIndex));
    }
    else
    {
        aux = new CaraComun(getPeloFromRadioGroup(this->RBTipoPelo->ItemIndex),
                            getOjosFromRadioGroup(this->RBTipoOjos->ItemIndex),
                            getNarizYOrejasFromRadioGroup(this->RBTipoOrejas->ItemIndex),
                            getBocaFromRadioGroup(this->RBTipoBoca->ItemIndex),
                            getMentonFromRadioGroup(this->RBTipoMenton->ItemIndex));
    }

    return aux;
}
//---------------------------------------------------------------------------
void TTodosDelincuentes::ActualizarCheckButtons (const Cara * cara)
{
    if(cara->getClassName() == "CaraConfidente")
    {
        this->RBTipoPelo->ItemIndex   = -1;
        this->RBTipoOjos->ItemIndex   = -1;
        this->RBTipoOrejas->ItemIndex = -1;
        this->RBTipoBoca->ItemIndex   = -1;
        this->RBTipoMenton->ItemIndex = -1;
    }
    else
    {
        this->RBTipoPelo->ItemIndex   = ((int) cara->getPelo()) - 1;
        this->RBTipoOjos->ItemIndex   = ((int) cara->getOjos()) - 1;
        this->RBTipoOrejas->ItemIndex = ((int) cara->getNarizYOrejas()) - 1;
        this->RBTipoBoca->ItemIndex   = ((int) cara->getBoca()) - 1;
        this->RBTipoMenton->ItemIndex = ((int) cara->getMenton()) - 1;
    }
}
//---------------------------------------------------------------------------
void __fastcall TTodosDelincuentes::posicionar (int i)
{
    if(this->delincuentes->setIndice(i))
    {
        Delincuente * aux = NULL;

        if(this->delincuentes->getDelincuenteIndice(aux))
        {
            if(aux->getClassName() == "DelincuenteConfidente")
            {
                DelincuenteConfidente * auxdc = (DelincuenteConfidente *) aux;

                this->CBConfidente->Checked = true;
                this->TxtSupervisor->Text = auxdc->getSupervisor().c_str();
            }
            else
            {
                this->CBConfidente->Checked = false;
                this->TxtSupervisor->Text = "";
            }

            this->TxtDNI->Text     = aux->getDNI().c_str();
            this->TxtNombre->Text  = aux->getNombre().c_str();
            this->TxtDelitos->Text = aux->getDelitos().c_str();

            this->ActualizarCheckButtons(aux->getCara());
            this->actualizarCara();

            MeterNumeroEnLabel(this->LblNumFicha, this->delincuentes->getIndice());
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TTodosDelincuentes::actualizarCara (void)
{
    if(this->delincuentes->getIndice() == -1)
    {
        this->actualizarCaraPorRadioGroups();
    }
    else
    {       
        this->Retrato->Canvas->Brush->Color = clWhite;
        this->Retrato->Canvas->FillRect(Rect(0, 0, this->Retrato->Width,
                                             this->Retrato->Height));

        Delincuente * aux = NULL;

        if(this->delincuentes->getDelincuenteIndice(aux))
        {
            this->dibujaCara(aux->getCara());
        }
    }
}                                       
//---------------------------------------------------------------------------
void __fastcall TTodosDelincuentes::dibujaCara (Cara * cara)
{
    cara->dibuja(this->Retrato->Canvas);
}
//---------------------------------------------------------------------------
void __fastcall TTodosDelincuentes::actualizarCaraPorRadioGroups (void)
{
    this->Retrato->Canvas->Brush->Color = clWhite;
    this->Retrato->Canvas->FillRect(Rect(0, 0, this->Retrato->Width, this->Retrato->Height));

    string pelo        = dibujaPelo(getPeloFromRadioGroup(this->RBTipoPelo->ItemIndex));
    string ojos        = dibujaOjos(getOjosFromRadioGroup(this->RBTipoOjos->ItemIndex));
    string narizOrejas = dibujaNarizYOrejas(getNarizYOrejasFromRadioGroup(this->RBTipoOrejas->ItemIndex));
    string boca        = dibujaBoca(getBocaFromRadioGroup(this->RBTipoBoca->ItemIndex));
    string menton      = dibujaMenton(getMentonFromRadioGroup(this->RBTipoMenton->ItemIndex));

    this->Retrato->Canvas->Font->Name = "Courier New";
    this->Retrato->Canvas->Font->Size = 16;
    this->Retrato->Canvas->TextOutA(0, 0,  pelo.c_str());
    this->Retrato->Canvas->TextOutA(0, 24, ojos.c_str());
    this->Retrato->Canvas->TextOutA(0, 48, narizOrejas.c_str());
    this->Retrato->Canvas->TextOutA(0, 72, boca.c_str());
    this->Retrato->Canvas->TextOutA(0, 96, menton.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TTodosDelincuentes::vacia (void)
{
    this->delincuentes->setIndice(-1);
                                
    this->TxtDNI->Text          = "";
    this->TxtNombre->Text       = "";
    this->TxtDelitos->Text      = "";
    this->TxtSupervisor->Text   = "";
    this->CBConfidente->Checked = false;

    this->RBTipoPelo->ItemIndex   = -1;
    this->RBTipoOjos->ItemIndex   = -1;
    this->RBTipoOrejas->ItemIndex = -1;
    this->RBTipoBoca->ItemIndex   = -1;
    this->RBTipoMenton->ItemIndex = -1;

    this->actualizarCara();
}
//---------------------------------------------------------------------------
void __fastcall TTodosDelincuentes::agregarDelincuente (Delincuente * delincuente)
{
    if(!this->delincuentes->estaDelincuente(*delincuente))
    {
        if(!this->delincuentes->agregaDelincuente(*delincuente))
        {
            MessageBox(Application->Handle, "No se ha podido agregar el delincuente.",
                       "Fallo al agregar", MB_ICONWARNING);
        }
    }
    else
    {
        MessageBox(Application->Handle, "El criminal ya existe, por lo que debería modificarlo.",
                   "Registro ya existente", MB_ICONWARNING);
    }
}
//---------------------------------------------------------------------------
void __fastcall TTodosDelincuentes::modificarDelincuente (Delincuente * delincuente)
{
    if(this->delincuentes->estaDelincuente(*delincuente))
    {
        if(!this->delincuentes->agregaDelincuente(*delincuente))
            MessageBox(Application->Handle, "No se ha podido actualizar el delincuente.",
                       "Error al actualizar", MB_ICONWARNING);
    }
    else
    {   
        MessageBox(Application->Handle, "El criminal no existe, por lo que debería agregarlo.",
                   "Registro inexistente", MB_ICONWARNING);
    }
}
//---------------------------------------------------------------------------
void __fastcall TTodosDelincuentes::borrarDelincuente (Delincuente * delincuente)
{
    if(!this->delincuentes->borraDelincuente(*delincuente))
    {
        if(this->delincuentes->getNumero() > 0)
            MessageBox(Application->Handle, "El registro que intenta borrar no existe.",
                       "Registro inexistente", MB_ICONWARNING);
        else
            MessageBox(Application->Handle, "La base de datos de criminales está vacía.",
                       "Base de datos vacía", MB_ICONWARNING);
    }
    else
    {
        if(this->delincuentes->getNumero() > 0)
            this->CmdAntClick(this);
        else
            this->vacia();
    }
}
//---------------------------------------------------------------------------  
/**
 * Función que pasa al anterior delincuente de la lista.
 * @param Sender Objeto que llama al método.
 * @see CmdSigClick()
 */
void __fastcall TTodosDelincuentes::CmdAntClick(TObject *Sender)
{
    if(this->delincuentes->getIndice() > 0)
        this->posicionar(this->delincuentes->getIndice() - 1);
}
//--------------------------------------------------------------------------- 
/**
 * Función que pasa al siguiente delincuente de la lista.
 * @param Sender Objeto que llama al método.
 * @see CmdAntClick()
 */
void __fastcall TTodosDelincuentes::CmdSigClick(TObject *Sender)
{
    this->posicionar(this->delincuentes->getIndice() + 1);
}
//---------------------------------------------------------------------------   
/**
 * Función que crea un nuevo delincuente.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TTodosDelincuentes::CmdNuevoClick(TObject *Sender)
{
    this->vacia();
}
//---------------------------------------------------------------------------
/**
 * Función que agrega el delincuente formado a la lista.
 * @param Sender Objeto que llama al método.
 * @see CmdBorrarClick(), CmdModificarClick(), CmdBuscarClick()
 */
void __fastcall TTodosDelincuentes::CmdAgregarClick(TObject *Sender)
{
    Delincuente * aux = this->dameDelincuente();

    this->agregarDelincuente(aux);
    this->posicionar(this->delincuentes->getIndice());  

    delete aux;
}
//--------------------------------------------------------------------------- 
/**
 * Función que borra el delincuente formado a la lista.
 * @param Sender Objeto que llama al método.
 * @see CmdAgregarClick(), CmdModificarClick(), CmdBuscarClick()
 */
void __fastcall TTodosDelincuentes::CmdBorrarClick(TObject *Sender)
{
    Delincuente * aux = this->dameDelincuente();

    this->borrarDelincuente(aux);

    if(this->delincuentes->getNumero() > 0)
        this->CmdAntClick(NULL);
    else
        this->vacia();       

    delete aux;
}
//--------------------------------------------------------------------------- 
/**
 * Función que modifica el delincuente formado a la lista.
 * @param Sender Objeto que llama al método.
 * @see CmdAgregarClick(), CmdBorrarClick(), CmdBuscarClick()
 */
void __fastcall TTodosDelincuentes::CmdModificarClick(TObject *Sender)
{
    Delincuente * aux = this->dameDelincuente();

    this->modificarDelincuente(aux);   
    this->posicionar(this->delincuentes->getIndice());

    delete aux;
}
//---------------------------------------------------------------------------
/**
 * Función que busca un delincuente en la lista.
 * @param Sender Objeto que llama al método.
 * @see CmdAgregarClick(), CmdBorrarClick(), CmdModificarClick()
 */
void __fastcall TTodosDelincuentes::CmdBuscarClick(TObject *Sender)
{
    TBusqueda * busqueda = new TBusqueda(this);

    busqueda->ShowModal();
    Cara * cara = busqueda->dameCara();

    if((cara->getPelo() != peloX) && (cara->getOjos() != ojosX) &&
       (cara->getNarizYOrejas() != narizYOrejasX) && (cara->getBoca() != bocaX) &&
       (cara->getMenton() != mentonX))
    {
        Delincuente * aux = NULL;
        int indice = -1;

        for(int i = 0; (i < this->delincuentes->getNumero()) && (indice == -1); ++i)
        {
            if(this->delincuentes->getDelincuente(i, aux))
            {
                if(aux->parecido(*cara))
                {
                    indice = i;
                }
            }
        }

        if(indice > -1)
        {
            this->posicionar(indice);
        }
        else
        {
            MessageBox(Application->Handle, "La cara que busca no ha podido ser encontrada.",
                       "Busqueda sin resultados", MB_ICONWARNING);
        }
    }

    delete busqueda;
}
//---------------------------------------------------------------------------
/**
 * Función que se ejecuta al mostrar el formulario.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TTodosDelincuentes::FormShow(TObject *Sender)
{          
    this->Retrato->Canvas->Brush->Color = clWhite;
    this->Retrato->Canvas->FillRect(Rect(0, 0, this->Retrato->Width, this->Retrato->Height));
}
//---------------------------------------------------------------------------
/**
 * Función que se ejecuta al cambiar el tipo de pelo.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TTodosDelincuentes::RBTipoPeloClick(TObject *Sender)
{
    this->actualizarCaraPorRadioGroups();
}
//--------------------------------------------------------------------------- 
/**
 * Función que se ejecuta al cambiar el tipo de ojos.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TTodosDelincuentes::RBTipoOjosClick(TObject *Sender)
{
    this->actualizarCaraPorRadioGroups();
}              
//---------------------------------------------------------------------------  
/**
 * Función que se ejecuta al cambiar el tipo de nariz y orejas.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TTodosDelincuentes::RBTipoOrejasClick(TObject *Sender)
{
    this->actualizarCaraPorRadioGroups();
}
//---------------------------------------------------------------------------  
/**
 * Función que se ejecuta al cambiar el tipo de boca.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TTodosDelincuentes::RBTipoBocaClick(TObject *Sender)
{
    this->actualizarCaraPorRadioGroups();
} 
//---------------------------------------------------------------------------  
/**
 * Función que se ejecuta al cambiar el tipo de mentón.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TTodosDelincuentes::RBTipoMetonClick(TObject *Sender)
{
    this->actualizarCaraPorRadioGroups();
}
//---------------------------------------------------------------------------   
/**
 * Función que ordena el fin de la aplicación.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TTodosDelincuentes::mnuArchivoSalirClick(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------
// Fin FTodosDelincuentes.cpp
//---------------------------------------------------------------------------
