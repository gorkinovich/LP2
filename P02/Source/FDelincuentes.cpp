//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 02 - Grupo 03.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "FDelincuentes.h"
#include "FBusqueda.h"
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
Delincuente __fastcall TDelincuentes::dameDelincuente (void)
{
    Cara aux;

    this->ObtenerCaraDeCheckButtons(aux);

    return Delincuente(this->TxtNombre->Text.c_str(),
                       this->TxtDelitos->Text.c_str(), aux);
}
//--------------------------------------------------------------------------- 
/**
 * Función que recoge del formulario la cara que está seleccionada.
 * @param cara Cara que vamos a devolver. 
 * @see ActualizarCheckButtons()
 */
void TDelincuentes::ObtenerCaraDeCheckButtons (Cara & cara)
{
    cara =  Cara((Pelo) ((this->RBTipoPelo->ItemIndex + 1) % 4),
                 (Ojos) ((this->RBTipoOjos->ItemIndex + 1) % 4),
                 (NarizYOrejas) ((this->RBTipoOrejas->ItemIndex + 1) % 4),
                 (Boca) ((this->RBTipoBoca->ItemIndex + 1) % 4),
                 (Menton) ((this->RBTipoMenton->ItemIndex + 1) % 4));
}
//--------------------------------------------------------------------------- 
/**
 * Función que actualiza el formulario en base a una cara ya formada.
 * @param cara Cara que va a servir para actualizar los datos.
 * @see ObtenerCaraDeCheckButtons()
 */
void TDelincuentes::ActualizarCheckButtons (const Cara & cara)
{
    this->RBTipoPelo->ItemIndex   = ((int) cara.getPelo()) - 1;
    this->RBTipoOjos->ItemIndex   = ((int) cara.getOjos()) - 1;
    this->RBTipoOrejas->ItemIndex = ((int) cara.getNarizYOrejas()) - 1;
    this->RBTipoBoca->ItemIndex   = ((int) cara.getBoca()) - 1;
    this->RBTipoMenton->ItemIndex = ((int) cara.getMenton()) - 1;
}
//--------------------------------------------------------------------------- 
/**
 * Función que carga en el formulario los datos de una posición dada de la
 * lista de delincuentes que tenemos almacenados.
 * @param i Número de delincuente dentro de la lista.
 */
void __fastcall TDelincuentes::posicionar (int i)
{
    if(this->almacen->posicionar(i))
    {
        Delincuente aux;

        this->almacen->getActual(aux);

        this->TxtNombre->Text  = aux.getNombre().c_str();
        this->TxtDelitos->Text = aux.getDelitos().c_str();
        this->Retrato->Lines->Clear();
        this->Retrato->Lines->Add(dibujaPelo(aux.getCara().getPelo()).c_str()); 
        this->Retrato->Lines->Add(dibujaOjos(aux.getCara().getOjos()).c_str());
        this->Retrato->Lines->Add(dibujaNarizYOrejas(aux.getCara().getNarizYOrejas()).c_str());
        this->Retrato->Lines->Add(dibujaBoca(aux.getCara().getBoca()).c_str());
        this->Retrato->Lines->Add(dibujaMenton(aux.getCara().getMenton()).c_str());

        this->ActualizarCheckButtons(aux.getCara());

        MeterNumeroEnLabel(this->LblNumFicha, this->almacen->getIndice());
    }
}
//--------------------------------------------------------------------------- 
/**
 * Función para actualizar la cara mostrada en el memo del formulario.
 */
void __fastcall TDelincuentes::actualizarCara (void)
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
void __fastcall TDelincuentes::agregarDelincuente (Delincuente & delincuente)
{
    if(!this->almacen->estaDelincuente(delincuente.getNombre()))
    {
        if(!this->almacen->agregaDelincuente(delincuente))
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
void __fastcall TDelincuentes::modificarDelincuente (Delincuente & delincuente)
{
    if(this->almacen->estaDelincuente(delincuente.getNombre()))
    {
        if(!this->almacen->agregaDelincuente(delincuente))
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
/**
 * Función que borra un delincuente en la lista del programa.
 * @param delincuente Delincuente que queremos borrar.
 * @see agregarDelincuente(), modificarDelincuente()
 */
void __fastcall TDelincuentes::borrarDelincuente (Delincuente & delincuente)
{
    if(!this->almacen->borraDelincuente(delincuente.getNombre()))
    {
        if(this->almacen->getNumero() > 0)
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
    if(this->almacen->getIndice() > 0)
        this->posicionar(this->almacen->getIndice() - 1);
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
    this->posicionar(this->almacen->getIndice() + 1);
}
//--------------------------------------------------------------------------- 
/**
 * Función que agrega el delincuente formado a la lista.
 * @param Sender Objeto que llama al método.
 * @see CmdBorrarClick(), CmdModificarClick(), CmdBuscarClick()
 */
void __fastcall TDelincuentes::CmdAgregarClick(TObject *Sender)
{
    Delincuente aux = this->dameDelincuente();

    this->agregarDelincuente(aux);
    this->posicionar(this->almacen->getIndice());
}
//--------------------------------------------------------------------------- 
/**
 * Función que borra el delincuente formado a la lista.
 * @param Sender Objeto que llama al método.
 * @see CmdAgregarClick(), CmdModificarClick(), CmdBuscarClick()
 */
void __fastcall TDelincuentes::CmdBorrarClick(TObject *Sender)
{
    Delincuente aux = this->dameDelincuente();

    this->borrarDelincuente(aux);

    if(this->almacen->getNumero() > 0)
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
    Delincuente aux = this->dameDelincuente();

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
    TBusqueda * busqueda = new TBusqueda(this);
    busqueda->ShowModal();

    Cara cara = busqueda->dameCara();

    if((cara.getPelo() != peloX) && (cara.getOjos() != ojosX) &&
       (cara.getNarizYOrejas() != narizYOrejasX) && (cara.getBoca() != bocaX) &&
        (cara.getMenton() != mentonX))
    {
        int indice = this->almacen->findDelincuente(cara);

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
 * Función que reinicia la base de datos de delincuentes.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TDelincuentes::CmdReiniciarClick(TObject *Sender)
{
    if(this->almacen != NULL)
        delete this->almacen;

    AnsiString respuesta = InputBox("Tamaño de la base de datos",
             "Cuantos elementos desea que tenga la base de datos: ", "1000");

    this->almacen = new ContenedorDelincuentes(respuesta.ToInt());
    if(this->almacen == NULL)
    {
        MessageBox(Application->Handle, "No se ha podido obtener memoria para la base de datos.",
                   "Memoria insuficiente", MB_ICONWARNING);
        Application->Terminate();
    }

    this->vacia();
    MeterNumeroEnLabel(this->LblNumFicha, 0);
}
//---------------------------------------------------------------------------    
/**
 * Función que carga la base de datos de delincuentes.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TDelincuentes::CmdCargarClick(TObject *Sender)
{
    if(this->almacen->cargaTXT("delincuentes.dat"))
    {
        MessageBox(Application->Handle, "La base de datos ha sido cargada.",
                   "Cargando el fichero", 0);
        this->posicionar(0);
    }
    else
    {
        MessageBox(Application->Handle, "Error al cargar la base de datos.",
                   "Cargando el fichero", MB_ICONWARNING);
    }
}
//---------------------------------------------------------------------------    
/**
 * Función que salva la base de datos de delincuentes.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TDelincuentes::CmdSalvarClick(TObject *Sender)
{
    if(this->almacen->salvaTXT("delincuentes.dat"))
    {
        MessageBox(Application->Handle, "La base de datos ha sido salvada.",
                   "Salvando el fichero", 0);
    }
    else
    {
        MessageBox(Application->Handle, "Error al salvar la base de datos.",
                   "Salvando el fichero", MB_ICONWARNING);
    }
}
//---------------------------------------------------------------------------
/**
 * Función que se ejecuta al destruir el formulario.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TDelincuentes::FormDestroy(TObject *Sender)
{
    if(this->almacen != NULL)
    {
        delete this->almacen;
    }
}
//---------------------------------------------------------------------------
/**
 * Función que se ejecuta al mostrar el formulario.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TDelincuentes::FormShow(TObject *Sender)
{
    AnsiString respuesta = InputBox("Tamaño de la base de datos",
             "Cuantos elementos desea que tenga la base de datos: ", "1000");

    this->almacen = new ContenedorDelincuentes(respuesta.ToInt());
    if(this->almacen == NULL)
    {
        MessageBox(Application->Handle, "No se ha podido obtener memoria para la base de datos.",
                   "Memoria insuficiente", MB_ICONWARNING);    
        Application->Terminate();
    }
    else
    {
        this->posicionar(0);

        this->actualizarCara();
        MeterNumeroEnLabel(this->LblNumFicha, this->almacen->getIndice());
    }
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
 * Función que se ejecuta al cambiar el tipo de nariz y orejas.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TDelincuentes::RBTipoOrejasClick(TObject *Sender)
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
 * Función que se ejecuta al cambiar el tipo de mentón.
 * @param Sender Objeto que llama al método.
 */
void __fastcall TDelincuentes::RBTipoMetonClick(TObject *Sender)
{
    this->actualizarCara();
}
//---------------------------------------------------------------------------
// Fin FDelincuentes.cpp
//---------------------------------------------------------------------------

