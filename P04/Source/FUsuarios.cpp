//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "FUsuarios.h"
#include "Patrones/FactoriaPersonas.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FPersonas"
#pragma resource "*.dfm"
TUsuarios *Usuarios;
//---------------------------------------------------------------------------
__fastcall TUsuarios::TUsuarios(TComponent* Owner)
    : TPersonas(Owner)
{
    this->ficheroLista = ""; 
    this->mnuArchivoGuardar->Enabled = false;
}
//---------------------------------------------------------------------------
__fastcall TUsuarios::TUsuarios(TComponent* Owner, AnsiString ruta)
    : TPersonas(Owner)
{
    this->ficheroLista = ruta;
    this->mnuArchivoGuardar->Enabled = true;
}
//---------------------------------------------------------------------------
void TUsuarios::actualizar (void)
{
    if(this->indice < this->controlador->getNumero())
    {
        this->posicionar(this->indice);
    }
    else
    {
        this->posicionar(this->controlador->getNumero() - 1);
    }
}
//---------------------------------------------------------------------------
void TUsuarios::vacia (void)
{      
	this->TPersonasBasico::vacia();        
    this->TxtPassword->Text = "";
    this->CBAdministrador->Checked = false;
}
//---------------------------------------------------------------------------
Cara * TUsuarios::ObtenerCaraDeCheckButtons (void)
{
    Cara * aux = new CaraClasificada(getPeloFromRadioGroup(this->RBTipoPelo->ItemIndex),
                                     getOjosFromRadioGroup(this->RBTipoOjos->ItemIndex),
                                     getNarizYOrejasFromRadioGroup(this->RBTipoOrejas->ItemIndex),
                                     getBocaFromRadioGroup(this->RBTipoBoca->ItemIndex),
                                     getMentonFromRadioGroup(this->RBTipoMenton->ItemIndex),
                                     this->retinaActual.c_str());
    return aux;
}            
//---------------------------------------------------------------------------
void TUsuarios::dibujaCara (Cara * cara)
{
    Graphics::TBitmap * auxBmp = NULL;
    if(cara->getClassName() == "CaraClasificada")
    {
        CaraClasificada * aux = (CaraClasificada *) cara;
        aux->dibujaSupCara(this->Retrato->Canvas);
        aux->dibujaSupRetina(auxBmp);
        this->Retina->Picture->Bitmap = auxBmp;
    }
    else
    {
        cara->dibujaRetratoRobot(this->Retrato->Canvas);
        cara->dibujaRetina(auxBmp);
        this->Retina->Picture->Bitmap = auxBmp;
    }
}
//---------------------------------------------------------------------------
Persona * TUsuarios::damePersona (void)
{
    Persona * persona = NULL;

    if(this->CBAdministrador->Checked) // Administrador
    {
        persona = FactoriaPersonas::creaUsuario(usuario_administrador);
    }
    else // Policia
    {      
        persona = FactoriaPersonas::creaUsuario(usuario_policia);
    }

    if(persona != NULL)
    {
        Usuario * aux = (Usuario *) persona;
        aux->setID(this->TxtDNI->Text.c_str());
        aux->setNombre(this->TxtNombre->Text.c_str());
        aux->setPassword(this->TxtPassword->Text.c_str());
        aux->setCara((CaraClasificada *) this->ObtenerCaraDeCheckButtons());
    }

    return persona;
}
//---------------------------------------------------------------------------     
void TUsuarios::posicionar (int i)
{
    if((0 <= i) && (i < this->controlador->getNumero()))
    {
        Usuario * aux = NULL;

        if(this->controlador->getPersona(i, (Persona *) aux))
        {                    
            this->indice = i;

            if(aux->getClassName() == "Administrador")
                this->CBAdministrador->Checked = true;
            else
                this->CBAdministrador->Checked = false;

            this->TxtDNI->Text      = aux->getID().c_str();
            this->TxtNombre->Text   = aux->getNombre().c_str();
            this->TxtPassword->Text = aux->getPassword().c_str();

            this->retinaActual = aux->getCara()->getFicheroRetina().c_str();
            if(this->retinaActual != "")
                this->Retina->Picture->Bitmap = aux->getCara()->getImagenRetina();
            else
                this->RetinaFree();

            this->ActualizarCheckButtons(aux->getCara(), true);
            this->actualizarCara();
            MeterNumeroEnLabel(this->LblNumFicha, this->indice);
        }
    }
}
//---------------------------------------------------------------------------
