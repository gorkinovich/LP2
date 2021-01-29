//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 01 - Apartado 03.
//---------------------------------------------------------------------------
#ifndef FDelincuentesH
#define FDelincuentesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
#include "TDelincuentes.h"
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
    void __fastcall CmdAntClick(TObject *Sender);
    void __fastcall CmdSigClick(TObject *Sender);
    void __fastcall CmdAgregarClick(TObject *Sender);
    void __fastcall CmdBorrarClick(TObject *Sender);
    void __fastcall CmdModificarClick(TObject *Sender);
    void __fastcall CmdBuscarClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall RBTipoPeloClick(TObject *Sender);
    void __fastcall RBTipoOjosClick(TObject *Sender);
    void __fastcall RBTipoBocaClick(TObject *Sender);
    void __fastcall RBTipoOrejasClick(TObject *Sender);
private:	// User declarations
    /// Número identificador del delincuente en TDelincuentes.
    int index;

    /// Lista con los delincuentes.
    TContenedorDelincuentes delincuentes;

    void ActualizarCheckButtons (const TCara & cara);
    void ObtenerCaraDeCheckButtons (TCara & cara);

public:		// User declarations
    __fastcall TDelincuentes(TComponent* Owner);

    TDelincuente __fastcall dameDelincuente (void);
    void __fastcall posicionar (int index);
    void __fastcall actualizarCara (void);
    void __fastcall vacia (void);
    void __fastcall agregarDelincuente (TDelincuente delincuente);
    void __fastcall modificarDelincuente (TDelincuente delincuente);
    void __fastcall borrarDelincuente (TDelincuente delincuente);
};
//---------------------------------------------------------------------------
extern PACKAGE TDelincuentes *Delincuentes;
//---------------------------------------------------------------------------
#endif             
//---------------------------------------------------------------------------
// Fin FDelincuentes.h
//---------------------------------------------------------------------------