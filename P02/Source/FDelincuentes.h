//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 02 - Grupo 03.
//---------------------------------------------------------------------------
#ifndef FDelincuentesH
#define FDelincuentesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
#include "ContenedorDelincuentes.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TDelincuentes : public TForm
{
__published:	// IDE-managed Components
    TMemo *Retrato;
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
    TButton *CmdReiniciar;
    TButton *CmdCargar;
    TButton *CmdSalvar;
    void __fastcall CmdAntClick(TObject *Sender);
    void __fastcall CmdSigClick(TObject *Sender);
    void __fastcall CmdAgregarClick(TObject *Sender);
    void __fastcall CmdBorrarClick(TObject *Sender);
    void __fastcall CmdModificarClick(TObject *Sender);
    void __fastcall CmdBuscarClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall RBTipoPeloClick(TObject *Sender);
    void __fastcall RBTipoOjosClick(TObject *Sender);
    void __fastcall RBTipoBocaClick(TObject *Sender);
    void __fastcall RBTipoOrejasClick(TObject *Sender);
    void __fastcall CmdReiniciarClick(TObject *Sender);
    void __fastcall RBTipoMetonClick(TObject *Sender);
    void __fastcall CmdCargarClick(TObject *Sender);
    void __fastcall CmdSalvarClick(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
    /// Lista con los delincuentes.
    ContenedorDelincuentes * almacen;

    void ActualizarCheckButtons (const Cara & cara);
    void ObtenerCaraDeCheckButtons (Cara & cara);

public:		// User declarations
    __fastcall TDelincuentes(TComponent* Owner);

    Delincuente __fastcall dameDelincuente (void);
    void __fastcall posicionar (int index);
    void __fastcall actualizarCara (void);
    void __fastcall vacia (void);
    void __fastcall agregarDelincuente (Delincuente & delincuente);
    void __fastcall modificarDelincuente (Delincuente & delincuente);
    void __fastcall borrarDelincuente (Delincuente & delincuente);
};
//---------------------------------------------------------------------------
extern PACKAGE TDelincuentes *Delincuentes;
//---------------------------------------------------------------------------
#endif             
//---------------------------------------------------------------------------
// Fin FDelincuentes.h
//---------------------------------------------------------------------------