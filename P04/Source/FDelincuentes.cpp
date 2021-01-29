//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "FDelincuentes.h"
#include "FAcceso.h"
#include "Patrones/FactoriaPersonas.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FPersonas"
#pragma resource "*.dfm"
TDelincuentes *Delincuentes;
//---------------------------------------------------------------------------
__fastcall TDelincuentes::TDelincuentes(TComponent* Owner)
    : TPersonas(Owner)
{            
    this->ficheroLista = "";
    this->mnuArchivoGuardar->Enabled = false;
}                
//---------------------------------------------------------------------------
__fastcall TDelincuentes::TDelincuentes(TComponent* Owner, AnsiString ruta)
    : TPersonas(Owner)
{
    this->ficheroLista = ruta;
    this->mnuArchivoGuardar->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TDelincuentes::mnuConfidentesClick(TObject *Sender)
{
    Acceso->InvocaConfidentes();
}              
//---------------------------------------------------------------------------
void TDelincuentes::actualizar (void)
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
void TDelincuentes::vacia (void)
{
	this->TPersonasBasico::vacia();
    this->TxtDelitos->Text = "";
    this->TxtSupervisor->Text = "";
    this->CBConfidente->Checked = false;
    this->CLBDelitos->Checked[0] = false;
    this->CLBDelitos->Checked[1] = false;
}
//---------------------------------------------------------------------------
Cara * TDelincuentes::ObtenerCaraDeCheckButtons (void)
{
    Cara * aux = NULL;

    if(this->CBConfidente->Checked)
    {
        aux = new CaraClasificada(getPeloFromRadioGroup(this->RBTipoPelo->ItemIndex),
                                  getOjosFromRadioGroup(this->RBTipoOjos->ItemIndex),
                                  getNarizYOrejasFromRadioGroup(this->RBTipoOrejas->ItemIndex),
                                  getBocaFromRadioGroup(this->RBTipoBoca->ItemIndex),
                                  getMentonFromRadioGroup(this->RBTipoMenton->ItemIndex),
                                  this->retinaActual.c_str());
    }
    else
    {
        aux = new CaraComun(getPeloFromRadioGroup(this->RBTipoPelo->ItemIndex),
                            getOjosFromRadioGroup(this->RBTipoOjos->ItemIndex),
                            getNarizYOrejasFromRadioGroup(this->RBTipoOrejas->ItemIndex),
                            getBocaFromRadioGroup(this->RBTipoBoca->ItemIndex),
                            getMentonFromRadioGroup(this->RBTipoMenton->ItemIndex),
                            this->retinaActual.c_str());
    }

    return aux;
}
//---------------------------------------------------------------------------
Persona * TDelincuentes::damePersona (void)
{            
    Persona * persona = NULL;

    if(this->CBConfidente->Checked) // Confidentes
    {
        if(this->CLBDelitos->Checked[1]) // Sonnador
        {
            persona = FactoriaPersonas::creaDelincuente(delincuente_sonnadorConfidente);
        }
        else // Lector
        {
            persona = FactoriaPersonas::creaDelincuente(delincuente_lectorConfidente);
        }
    }
    else // Comunes
    {
        if(this->CLBDelitos->Checked[1]) // Sonnador
        {
            persona = FactoriaPersonas::creaDelincuente(delincuente_sonnador);
        }
        else // Lector
        {
            persona = FactoriaPersonas::creaDelincuente(delincuente_lector);
        }

        if(persona != NULL)
        {
            DelincuenteConfidente * delcon = (DelincuenteConfidente *) persona;
            delcon->setSupervisor(this->TxtSupervisor->Text.c_str());
        }
    }

    if(persona != NULL)
    {
        Delincuente * aux = (Delincuente *) persona;
        aux->setID(this->TxtDNI->Text.c_str());
        aux->setNombre(this->TxtNombre->Text.c_str());

	    ListaOrdenada<Delitos> * auxCometidos = aux->getDelitosCometidos();
    	ListaOrdenada<std::string> * auxConcretos = aux->getDelitosConcretos();


    	Delitos auxDelitos;

        if(this->CLBDelitos->Checked[0])
        {
            auxDelitos.setDelito(lectura);
            auxCometidos->agregaElemento(auxDelitos);
        }

        if(this->CLBDelitos->Checked[1])
        {
            auxDelitos.setDelito(anhelo);
            auxCometidos->agregaElemento(auxDelitos);
        }


    	for(int i = 0; i < this->TxtDelitos->Lines->Count; ++i)
	    {
            auxConcretos->agregaElemento(this->TxtDelitos->Lines->Strings[i].c_str());
	    }


        aux->setCara((CaraComun *) this->ObtenerCaraDeCheckButtons());
    }
    
    return persona;
}
//--------------------------------------------------------------------------- 
void TDelincuentes::posicionar (int i)
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
            if(aux->getCara()->getClassName() == "CaraClasificada")
            {          
                this->RetinaFree();
            }
            else
            {
                if(this->retinaActual != "")
                    this->Retina->Picture->Bitmap = aux->getCara()->getImagenRetina();
                else
                    this->RetinaFree();
            }

            this->ActualizarCheckButtons(aux->getCara());
            this->actualizarCara();
            MeterNumeroEnLabel(this->LblNumFicha, this->indice);
        }
    }
}
//---------------------------------------------------------------------------

