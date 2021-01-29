//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 03 - Grupo 03.
//---------------------------------------------------------------------------
#ifndef FTodosDelincuentesH
#define FTodosDelincuentesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
#include "ArbolDelincuentes.h"
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TTodosDelincuentes : public TForm
{
__published:	// IDE-managed Components
    TLabel *LblFicha;
    TLabel *LblNumFicha;
    TButton *CmdAgregar;
    TButton *CmdBorrar;
    TButton *CmdModificar;
    TButton *CmdBuscar;
    TButton *CmdAnt;
    TButton *CmdSig;
    TLabel *LblNombre;
    TLabel *LblDelitos;
    TEdit *TxtNombre;
    TMemo *TxtDelitos;
    TRadioGroup *RBTipoPelo;
    TRadioGroup *RBTipoOjos;
    TRadioGroup *RBTipoBoca;
    TRadioGroup *RBTipoOrejas;
    TRadioGroup *RBTipoMenton;
    TMainMenu *MenuPrincipal;
    TMenuItem *mnuArchivo;
    TMenuItem *mnuArchivoSalir;
    TButton *CmdNuevo;
    TLabel *LblDNI;
    TEdit *TxtDNI;
    TLabel *LblSupervisor;
    TEdit *TxtSupervisor;
    TCheckBox *CBConfidente;
    TImage *Retrato;
    void __fastcall CmdAntClick(TObject *Sender);
    void __fastcall CmdSigClick(TObject *Sender);
    void __fastcall CmdNuevoClick(TObject *Sender);
    void __fastcall CmdAgregarClick(TObject *Sender);
    void __fastcall CmdBorrarClick(TObject *Sender);
    void __fastcall CmdModificarClick(TObject *Sender);
    void __fastcall CmdBuscarClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall RBTipoPeloClick(TObject *Sender);
    void __fastcall RBTipoOjosClick(TObject *Sender);
    void __fastcall RBTipoBocaClick(TObject *Sender);
    void __fastcall RBTipoOrejasClick(TObject *Sender);
    void __fastcall RBTipoMetonClick(TObject *Sender);
    void __fastcall mnuArchivoSalirClick(TObject *Sender);
protected:	// User declarations
    ContenedorDelincuentes * delincuentes;


    /**
     * Función que actualiza el formulario en base a una cara ya formada.
     * @param cara Cara que va a servir para actualizar los datos.
     * @see ObtenerCaraDeCheckButtons()
     */
    void ActualizarCheckButtons (const Cara * cara);
    
    /**
     * Función que recoge del formulario la cara que está seleccionada.
     * @return La cara que está elegida.
     * @see ActualizarCheckButtons()
     */
    Cara * ObtenerCaraDeCheckButtons (void);  


    /**
     * Función que recoge del formulario los datos que formarán el delincuente
     * que estamos creando o modificando.
     * @return Devuelve el delincuente modificado.
     */
    Delincuente * __fastcall dameDelincuente (void);
                               
    /**
     * Función que carga en el formulario los datos de una posición dada de la
     * lista de delincuentes que tenemos almacenados.
     * @param i Número de delincuente dentro de la lista.
     */
    void __fastcall posicionar (int index);

    /**
     * Función para actualizar la cara mostrada en el formulario.
     */
    void __fastcall actualizarCara (void);
    
    /**
     * Función para generar un delincuente "vacio" en el formulario.
     */
    void __fastcall vacia (void);
    
    /**
     * Función que agrega un delincuente a la lista del programa.
     * @param delincuente Delincuente que queremos agregar.
     * @see modificarDelincuente(), borrarDelincuente()
     */
    void __fastcall agregarDelincuente (Delincuente * delincuente);

    /**
     * Función que modifica un delincuente en la lista del programa.
     * @param delincuente Delincuente que queremos modificar.
     * @see agregarDelincuente(), borrarDelincuente()
     */
    void __fastcall modificarDelincuente (Delincuente * delincuente);
    
    /**
     * Función que borra un delincuente en la lista del programa.
     * @param delincuente Delincuente que queremos borrar.
     * @see agregarDelincuente(), modificarDelincuente()
     */
    void __fastcall borrarDelincuente (Delincuente * delincuente);

           
    /**
     * Función para actualizar la cara mostrada en el formulario.
     */
    virtual void __fastcall dibujaCara (Cara * cara);
    
    /**
     * Función para actualizar la cara mostrada en el formulario.
     */
    void __fastcall actualizarCaraPorRadioGroups (void);

public:		// User declarations
    __fastcall TTodosDelincuentes(TComponent* Owner);
    __fastcall TTodosDelincuentes(TComponent* Owner, ContenedorDelincuentes * delincuentes);
    virtual __fastcall ~TTodosDelincuentes();
};
//---------------------------------------------------------------------------
extern PACKAGE TTodosDelincuentes *TodosDelincuentes;
//---------------------------------------------------------------------------
#endif             
//---------------------------------------------------------------------------
// Fin FTodosDelincuentes.h
//---------------------------------------------------------------------------