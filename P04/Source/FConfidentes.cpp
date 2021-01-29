//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "FConfidentes.h"
#include "Patrones/FactoriaPersonas.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FPersonasBasico"
#pragma resource "*.dfm"
TConfidentes *Confidentes;
//---------------------------------------------------------------------------
__fastcall TConfidentes::TConfidentes(TComponent* Owner)
    : TPersonasBasico(Owner)
{    
}
//---------------------------------------------------------------------------
void __fastcall TConfidentes::RetinaClick(TObject *Sender)
{
    // No hacer nada en este metodo.
}
//---------------------------------------------------------------------------
void TConfidentes::actualizar (void)
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
void TConfidentes::vacia (void)
{
	this->TPersonasBasico::vacia();
    this->TxtDelitos->Text = "";
    this->TxtSupervisor->Text = "";
    this->CBConfidente->Checked = false;
    this->CLBDelitos->Checked[0] = false;
    this->CLBDelitos->Checked[1] = false;
}
//---------------------------------------------------------------------------
Cara * TConfidentes::ObtenerCaraDeCheckButtons (void)
{
    return NULL;
}
//---------------------------------------------------------------------------
void TConfidentes::dibujaCara (Cara * cara)
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
Persona * TConfidentes::damePersona (void)
{
    return NULL;
}
//---------------------------------------------------------------------------
void TConfidentes::posicionar (int i)
{ 
    if((0 <= i) && (i < this->controlador->getNumero()))
    { 
        Delincuente * aux = NULL;

        if(this->controlador->getPersona(i, (Persona *) aux))
        {       
            this->indice = i;
                  
            if((aux->getClassName() == "LectorConfidente") ||
               (aux->getClassName() == "SonnadorConfidente"))
            {
                this->CBConfidente->Checked = true;
                
                DelincuenteConfidente * delcon = (DelincuenteConfidente *) aux;
                this->TxtSupervisor->Text = delcon->getSupervisor().c_str();
            }
            else
            {
                this->CBConfidente->Checked = false;    
                this->TxtSupervisor->Text = "";
            }
                    
            this->TxtDNI->Text    = aux->getID().c_str();
            this->TxtNombre->Text = aux->getNombre().c_str();


	        ListaOrdenada<Delitos> * auxCometidos = aux->getDelitosCometidos();
        	ListaOrdenada<std::string> * auxConcretos = aux->getDelitosConcretos();

            int i;
            Delitos auxDel;
            this->CLBDelitos->Checked[0] = false;
            this->CLBDelitos->Checked[1] = false;
             
            for(i = 0; i < auxCometidos->getNumero(); ++i)
            {
                if(auxCometidos->getElemento(i, auxDel))
                {
                    switch(auxDel.getDelito())
                    {
                    case lectura:
                        this->CLBDelitos->Checked[0] = true;
                        break;

                    case anhelo:
                        this->CLBDelitos->Checked[1] = true;
                        break;
                    }
                }
            }
               
            std::string auxStr;
            this->TxtDelitos->Lines->Clear();

            for(i = 0; i < auxConcretos->getNumero(); ++i)
            {
                if(auxConcretos->getElemento(i, auxStr))
                {
                    this->TxtDelitos->Lines->Add(auxStr.c_str());
                }
            }
                        
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

