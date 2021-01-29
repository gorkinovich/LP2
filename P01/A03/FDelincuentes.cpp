//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 01 - Apartado 03.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "FDelincuentes.h"
#include "FBusqueda.h"
#include "Util.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDelincuentes *Delincuentes;
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
__fastcall TDelincuentes::TDelincuentes(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------  
/**
 * Función que recoge del formulario los datos que formarán el delincuente
 * que estamos creando o modificando.
 * @return Devuelve el delincuente modificado.
 */
TDelincuente __fastcall TDelincuentes::dameDelincuente (void)
{
    TCara aux;

    this->ObtenerCaraDeCheckButtons(aux);

    return inicializaDelincuente(this->TxtNombre->Text.c_str(),
                this->TxtDelitos->Text.c_str(), aux);
}
//--------------------------------------------------------------------------- 
/**
 * Función que recoge del formulario la cara que está seleccionada.
 * @param cara Cara que vamos a devolver. 
 * @see ActualizarCheckButtons()
 */
void TDelincuentes::ObtenerCaraDeCheckButtons (TCara & cara)
{
    cara = inicializaCara(this->RBTipoPelo->ItemIndex,
        this->RBTipoOjos->ItemIndex, this->RBTipoOrejas->ItemIndex,
        this->RBTipoBoca->ItemIndex);
}
//--------------------------------------------------------------------------- 
/**
 * Función que actualiza el formulario en base a una cara ya formada.
 * @param cara Cara que va a servir para actualizar los datos.
 * @see ObtenerCaraDeCheckButtons()
 */
void TDelincuentes::ActualizarCheckButtons (const TCara & cara)
{
    this->RBTipoPelo->ItemIndex   = getPelo(cara);
    this->RBTipoOjos->ItemIndex   = getOjos(cara);
    this->RBTipoBoca->ItemIndex   = getNarizYOrejas(cara);
    this->RBTipoOrejas->ItemIndex = getBoca(cara);
}
//--------------------------------------------------------------------------- 
/**
 * Función que carga en el formulario los datos de una posición dada de la
 * lista de delincuentes que tenemos almacenados.
 * @param i Número de delincuente dentro de la lista.
 */
void __fastcall TDelincuentes::posicionar (int i)
{
    if(i < getNumero(this->delincuentes))
    {
        TDelincuente aux;

        getDelincuente(this->delincuentes, i, aux);

        this->TxtNombre->Text  = (getNombre(aux)).c_str();
        this->TxtDelitos->Text = (getDelitos(aux)).c_str();
        this->Retrato->Text    = dameCara(getCara(aux)).c_str();

        this->ActualizarCheckButtons(getCara(aux));

        this->index = i;
        MeterNumeroEnLabel(this->LblNumFicha, this->index);
    }
}
//--------------------------------------------------------------------------- 
/**
 * Función para actualizar la cara mostrada en el memo del formulario.
 */
void __fastcall TDelincuentes::actualizarCara (void)
{
    string pelo        = damePelo(this->RBTipoPelo->ItemIndex);
    string ojos        = dameOjos(this->RBTipoOjos->ItemIndex);
    string narizOrejas = dameOrejasYNariz(this->RBTipoBoca->ItemIndex);
    string boca        = dameBoca(this->RBTipoOrejas->ItemIndex);

    //-----------------------------------------------------------------------
    // Actualizamos el cuadro de texto con el retrato.
    //-----------------------------------------------------------------------
    this->Retrato->Lines->Clear();
    this->Retrato->Lines->Add(pelo.c_str());
    this->Retrato->Lines->Add(ojos.c_str());
    this->Retrato->Lines->Add(narizOrejas.c_str());
    this->Retrato->Lines->Add(boca.c_str());
    this->Retrato->Lines->Add(" \\_____/");
}
//--------------------------------------------------------------------------- 
/**
 * Función para generar un delincuente "vacio" en el formulario.
 * @see actualizarCara()
 */
void __fastcall TDelincuentes::vacia (void)
{
    this->TxtNombre->Text  = "";
    this->TxtDelitos->Text = "";
    
    this->actualizarCara();
}
//---------------------------------------------------------------------------
/**
 * Función que agrega un delincuente a la lista del programa.
 * @param delincuente Delincuente que queremos agregar.
 * @see modificarDelincuente(), borrarDelincuente()
 */
void __fastcall TDelincuentes::agregarDelincuente (TDelincuente delincuente)
{
    int indice;

    if(!getDelincuente(this->delincuentes, getNombre(delincuente), indice))
    {
        if(!agregaDelincuente(this->delincuentes, delincuente))
            MessageBox(Application->Handle, "No hay espacio en la base de datos.",
                       "Base de datos completa", MB_ICONWARNING);
    }
    else
    {
        MessageBox(Application->Handle, "El criminal ya existe, por lo que debería modificarlo.",
                   "Registro ya existente", MB_ICONWARNING);
    }
}
//---------------------------------------------------------------------------  
/**
 * Función que modifica un delincuente en la lista del programa.
 * @param delincuente Delincuente que queremos modificar.
 * @see agregarDelincuente(), borrarDelincuente()
 */
void __fastcall TDelincuentes::modificarDelincuente (TDelincuente delincuente)
{
    int indice;

    if(getDelincuente(this->delincuentes, getNombre(delincuente), indice))
    {
        this->delincuentes.delincuentes[indice] = delincuente;
    }
    else
    {   
        MessageBox(Application->Handle, "El criminal no existe, por lo que debería agregarlo.",
                   "Registro inexistente", MB_ICONWARNING);
    }
}
//---------------------------------------------------------------------------  
/**
 * Función que borra un delincuente en la lista del programa.
 * @param delincuente Delincuente que queremos borrar.
 * @see agregarDelincuente(), modificarDelincuente()
 */
void __fastcall TDelincuentes::borrarDelincuente (TDelincuente delincuente)
{
    if(!borraDelincuente(this->delincuentes, getNombre(delincuente)))
    {
        if(getNumero(this->delincuentes) > 0)
            MessageBox(Application->Handle, "El registro que intenta borrar no existe.",
                       "Registro inexistente", MB_ICONWARNING);
        else
            MessageBox(Application->Handle, "La base de datos de criminales está vacía.",
                       "Base de datos vacía", MB_ICONWARNING);
    }
}
//---------------------------------------------------------------------------  
/**
 * Función que pasa al anterior delincuente de la lista.
 * @param Sender Objeto que llama al método.
 * @see CmdSigClick()
 */
void __fastcall TDelincuentes::CmdAntClick(TObject *Sender)
{
    if(index > 0)
        this->posicionar(this->index - 1);
    else
        this->posicionar(0);
}
//--------------------------------------------------------------------------- 
/**
 * Función que pasa al siguiente delincuente de la lista.
 * @param Sender Objeto que llama al método.
 * @see CmdAntClick()
 */
void __fastcall TDelincuentes::CmdSigClick(TObject *Sender)
{
    this->posicionar(this->index + 1);
}
//--------------------------------------------------------------------------- 
/**
 * Función que agrega el delincuente formado a la lista.
 * @param Sender Objeto que llama al método.
 * @see CmdBorrarClick(), CmdModificarClick(), CmdBuscarClick()
 */
void __fastcall TDelincuentes::CmdAgregarClick(TObject *Sender)
{
    TDelincuente aux = this->dameDelincuente();

    this->agregarDelincuente(aux);
    this->posicionar(getNumero(this->delincuentes) - 1);
}
//--------------------------------------------------------------------------- 
/**
 * Función que borra el delincuente formado a la lista.
 * @param Sender Objeto que llama al método.
 * @see CmdAgregarClick(), CmdModificarClick(), CmdBuscarClick()
 */
void __fastcall TDelincuentes::CmdBorrarClick(TObject *Sender)
{
    TDelincuente aux = this->dameDelincuente();

    this->borrarDelincuente(aux);

    if(this->delincuentes.ultimo > 0)
        this->CmdAntClick(NULL);
    else
        this->vacia();
}
//--------------------------------------------------------------------------- 
/**
 * Función que modifica el delincuente formado a la lista.
 * @param Sender Objeto que llama al método.
 * @see CmdAgregarClick(), CmdBorrarClick(), CmdBuscarClick()
 */
void __fastcall TDelincuentes::CmdModificarClick(TObject *Sender)
{
    TDelincuente aux = this->dameDelincuente();

    this->modificarDelincuente(aux);
}
//--------------------------------------------------------------------------- 
/**
 * Función que busca un delincuente en la lista.
 * @param Sender Objeto que llama al método.
 * @see CmdAgregarClick(), CmdBorrarClick(), CmdModificarClick()
 */
void __fastcall TDelincuentes::CmdBuscarClick(TObject *Sender)
{
    Busqueda->ShowModal();
    TCara cara = Busqueda->dameCara();

    if((getPelo(cara) != 3) && (getOjos(cara) != 3) &&
       (getNarizYOrejas(cara) != 3) && (getBoca(cara) != 3))
    {
        int indice;

        if(getDelincuente(this->delincuentes, cara, indice))
        {
            this->posicionar(indice);
        }
        else
        {
            MessageBox(Application->Handle, "La cara que busca no ha podido ser encontrada.",
                       "Busqueda sin resultados", MB_ICONWARNING);
        }
    }
}  
//--------------------------------------------------------------------------- 
/**
 * Función que se ejecuta al crear el formulario.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TDelincuentes::FormCreate(TObject *Sender)
{
    FILE * f;

    this->index = 0;
    this->delincuentes = inicializaContenedorDelincuentes();

    f = fopen("delincuentes.dat", "rb");

    if(f != NULL)
    {
        TDelincuente aux;
        char letra;

        while(!feof(f))
        {
            aux.nombre = "";
            do{
                fread(&letra, sizeof(char), 1, f);
                if(letra != 0) aux.nombre += letra;
            }while(letra != 0);

            aux.delitos = "";
            do{
                fread(&letra, sizeof(char), 1, f);
                if(letra != 0) aux.delitos += letra;
            }while(letra != 0);

            fread(&(aux.cara), sizeof(aux.cara), 1, f);

            if(aux.nombre != "")
                this->agregarDelincuente(aux);
        }
    }

    fclose(f);

    this->posicionar(0);
}
//--------------------------------------------------------------------------- 
/**
 * Función que se ejecuta al finalizar la aplicación.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TDelincuentes::FormDestroy(TObject *Sender)
{
    FILE * f;
    char zero = 0;

    f = fopen("delincuentes.dat", "wb");

    if(f != NULL)
    {
        for(int i = 0; i < this->delincuentes.ultimo; ++i)
        {
            fprintf(f, "%s", this->delincuentes.delincuentes[i].nombre.c_str());
            fwrite(&zero, sizeof(char), 1, f);
            fprintf(f, "%s", this->delincuentes.delincuentes[i].delitos.c_str());
            fwrite(&zero, sizeof(char), 1, f);
            fwrite(&(this->delincuentes.delincuentes[i].cara), sizeof(TCara), 1, f);
        }
    }

    fclose(f);
}
//--------------------------------------------------------------------------- 
/**
 * Función que se ejecuta al mostrar el formulario.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TDelincuentes::FormShow(TObject *Sender)
{
    this->actualizarCara();
    MeterNumeroEnLabel(this->LblNumFicha, this->index);
}
//--------------------------------------------------------------------------- 
/**
 * Función que se ejecuta al cambiar el tipo de pelo.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TDelincuentes::RBTipoPeloClick(TObject *Sender)
{
    this->actualizarCara();
}
//--------------------------------------------------------------------------- 
/**
 * Función que se ejecuta al cambiar el tipo de ojos.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TDelincuentes::RBTipoOjosClick(TObject *Sender)
{
    this->actualizarCara();
}
//---------------------------------------------------------------------------  
/**
 * Función que se ejecuta al cambiar el tipo de boca.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TDelincuentes::RBTipoBocaClick(TObject *Sender)
{
    this->actualizarCara();
}
//---------------------------------------------------------------------------  
/**
 * Función que se ejecuta al cambiar el tipo de nariz y orejas.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TDelincuentes::RBTipoOrejasClick(TObject *Sender)
{
    this->actualizarCara();
}
//---------------------------------------------------------------------------
// Fin FDelincuentes.cpp
//---------------------------------------------------------------------------

