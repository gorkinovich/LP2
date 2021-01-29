//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "FPersonasBasico.h"
#include "FBusqueda.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPersonasBasico *PersonasBasico;
//***************************************************************************
__fastcall TPersonasBasico::TPersonasBasico(TComponent* Owner)
    : TForm(Owner)
{
    this->controlador  = NULL;
    this->vistaID      = -1;  
    this->indice       = -1;
    this->retinaActual = "";
}
//***************************************************************************
void TPersonasBasico::registrarControlador (Controlador * unControlador)
{
    this->controlador = unControlador;
}
//---------------------------------------------------------------------------
void TPersonasBasico::setVistaID (int vistaID)
{
    this->vistaID = vistaID;
}
//***************************************************************************
void TPersonasBasico::MeterNumeroEnLabel (TLabel * lbl, int numero)
{
    lbl->Caption = lbl->Caption.sprintf("%d", numero + 1);
}     
//---------------------------------------------------------------------------
void TPersonasBasico::PaintCanvasWhite (TCanvas * canvas, int w, int h)
{     
    canvas->Brush->Color = clWhite;
    canvas->FillRect(Rect(0, 0, w, h));
}        
//---------------------------------------------------------------------------
void TPersonasBasico::RetinaFree (void)
{
    this->Retina->Picture->Bitmap->Width = this->Retina->Width;
    this->Retina->Picture->Bitmap->Height = this->Retina->Height;
    this->PaintCanvasWhite(this->Retina->Picture->Bitmap->Canvas,
                           this->Retina->Width, this->Retina->Height);
}
//---------------------------------------------------------------------------
void TPersonasBasico::vacia (void)
{
    this->indice = -1;
    this->retinaActual = "";

    this->TxtDNI->Text          = "";
    this->TxtNombre->Text       = "";

    this->RBTipoPelo->ItemIndex   = -1;
    this->RBTipoOjos->ItemIndex   = -1;
    this->RBTipoOrejas->ItemIndex = -1;
    this->RBTipoBoca->ItemIndex   = -1;
    this->RBTipoMenton->ItemIndex = -1;

    this->RetinaFree();
    this->actualizarCaraPorRadioGroups();
}
//***************************************************************************
// Eventos del formulario.
//*************************************************************************** 
/**
 * Función que pasa al anterior delincuente de la lista.
 */
void __fastcall TPersonasBasico::CmdAntClick(TObject *Sender)
{
    if(this->indice > 0)
        this->posicionar(this->indice - 1);
}
//--------------------------------------------------------------------------- 
/**
 * Función que pasa al siguiente delincuente de la lista.
 */
void __fastcall TPersonasBasico::CmdSigClick(TObject *Sender)
{
	if(this->indice < (this->controlador->getNumero() - 1))
		this->posicionar(this->indice + 1);
}
//---------------------------------------------------------------------------
/**
 * Función que busca un delincuente en la lista.
 */
void __fastcall TPersonasBasico::CmdBuscarClick(TObject *Sender)
{
    TBusqueda * busqueda = new TBusqueda(this);

    busqueda->ShowModal();
    Cara * cara = busqueda->dameCara();

    if(!cara->vacia())
    {        
        Persona * aux = NULL;
        int auxIndice = -1;

        for(int i = 0; (i < this->controlador->getNumero()) && (auxIndice == -1); ++i)
        {
            if(this->controlador->getPersona(i, aux))
            {
                if(aux->getCara()->parecida(*cara))
                {
                    auxIndice = i;
                }
            }
        }

        if(auxIndice > -1)
        {
            this->posicionar(auxIndice);
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
 */
void __fastcall TPersonasBasico::FormShow(TObject *Sender)
{
    this->PaintCanvasWhite(this->Retrato->Canvas, this->Retrato->Width,
                           this->Retrato->Height);
    this->PaintCanvasWhite(this->Retina->Canvas, this->Retina->Width,
                           this->Retina->Height);

    this->OpenPicDlg->InitialDir = "./Images/";

    this->controlador->vistaAbierta(this->vistaID);
}
//---------------------------------------------------------------------------
/**
 * Función que se ejecuta al cerrar el formulario.
 */
void __fastcall TPersonasBasico::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    this->controlador->vistaCerrada(this->vistaID);
}
//---------------------------------------------------------------------------
/**
 * Función que ordena el fin de la aplicación.
 */
void __fastcall TPersonasBasico::mnuArchivoSalirClick(TObject *Sender)
{
    this->Close();
}
//--------------------------------------------------------------------------- 
/**
 * Función que cambia la imagen de la retina.
 */
void __fastcall TPersonasBasico::RetinaClick(TObject *Sender)
{
    if(this->OpenPicDlg->Execute())
    {
        this->retinaActual = this->OpenPicDlg->FileName;
        this->Retina->Picture->LoadFromFile(this->retinaActual);
    }
}
//***************************************************************************
// RadioGroups.
//***************************************************************************
void TPersonasBasico::actualizarCara (void)
{
    if(this->indice == -1)
    {
        this->actualizarCaraPorRadioGroups();
    }
    else
    {       
        this->PaintCanvasWhite(this->Retrato->Canvas, this->Retrato->Width,
                               this->Retrato->Height);
                               
        Persona * aux = NULL;

        if(this->controlador->getPersona(this->indice, aux))
        {
            this->dibujaCara(aux->getCara());
        }
    }
}
//---------------------------------------------------------------------------
void TPersonasBasico::dibujaCara (Cara * cara)
{
    cara->dibujaRetratoRobot(this->Retrato->Canvas);
    Graphics::TBitmap * auxBmp = NULL;
    cara->dibujaRetina(auxBmp);
    this->Retina->Picture->Bitmap = auxBmp;
}
//***************************************************************************
void TPersonasBasico::ActualizarCheckButtons (const Cara * cara, bool admin)
{
    if((cara->getClassName() == "CaraClasificada") && (!admin))
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
void TPersonasBasico::actualizarCaraPorRadioGroups (void)
{                     
    this->PaintCanvasWhite(this->Retrato->Canvas, this->Retrato->Width,
                           this->Retrato->Height);

    std::string pelo        = dibujaPelo(getPeloFromRadioGroup(this->RBTipoPelo->ItemIndex));
    std::string ojos        = dibujaOjos(getOjosFromRadioGroup(this->RBTipoOjos->ItemIndex));
    std::string narizOrejas = dibujaNarizYOrejas(getNarizYOrejasFromRadioGroup(this->RBTipoOrejas->ItemIndex));
    std::string boca        = dibujaBoca(getBocaFromRadioGroup(this->RBTipoBoca->ItemIndex));
    std::string menton      = dibujaMenton(getMentonFromRadioGroup(this->RBTipoMenton->ItemIndex));

    this->Retrato->Canvas->Font->Name = "Courier New";
    this->Retrato->Canvas->Font->Size = 16;
    this->Retrato->Canvas->TextOutA(0, 0,  pelo.c_str());
    this->Retrato->Canvas->TextOutA(0, 24, ojos.c_str());
    this->Retrato->Canvas->TextOutA(0, 48, narizOrejas.c_str());
    this->Retrato->Canvas->TextOutA(0, 72, boca.c_str());
    this->Retrato->Canvas->TextOutA(0, 96, menton.c_str());
}
//***************************************************************************
/**
 * Función que se ejecuta al cambiar el tipo de pelo.
 */
void __fastcall TPersonasBasico::RBTipoPeloClick(TObject *Sender)
{
    this->actualizarCaraPorRadioGroups();
}
//---------------------------------------------------------------------------
/**
 * Función que se ejecuta al cambiar el tipo de ojos.
 */
void __fastcall TPersonasBasico::RBTipoOjosClick(TObject *Sender)
{
    this->actualizarCaraPorRadioGroups();
}
//---------------------------------------------------------------------------  
/**
 * Función que se ejecuta al cambiar el tipo de nariz y orejas.
 */
void __fastcall TPersonasBasico::RBTipoOrejasClick(TObject *Sender)
{
    this->actualizarCaraPorRadioGroups();
}
//---------------------------------------------------------------------------
/**
 * Función que se ejecuta al cambiar el tipo de boca.
 */
void __fastcall TPersonasBasico::RBTipoBocaClick(TObject *Sender)
{
    this->actualizarCaraPorRadioGroups();
}
//---------------------------------------------------------------------------
/**
 * Función que se ejecuta al cambiar el tipo de mentón.
 */
void __fastcall TPersonasBasico::RBTipoMetonClick(TObject *Sender)
{
    this->actualizarCaraPorRadioGroups();
}
//---------------------------------------------------------------------------
// Fin FPersonasBasico.cpp
//---------------------------------------------------------------------------
