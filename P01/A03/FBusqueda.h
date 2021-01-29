//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 01 - Apartado 03.
//---------------------------------------------------------------------------
#ifndef FBusquedaH
#define FBusquedaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
#include "TCara.h"
//---------------------------------------------------------------------------
class TBusqueda : public TForm
{
__published:	// IDE-managed Components
    TMemo *Retrato;
    TButton *CmdOK;
    TButton *CmdCancel;
    TGroupBox *GBCaja;
    TLabel *LblTitulo;
    TRadioGroup *RBTipoOjos;
    TRadioGroup *RBTipoPelo;
    TRadioGroup *RBTipoOrejas;
    TRadioGroup *RBTipoBoca;
    void __fastcall CmdCancelClick(TObject *Sender);
    void __fastcall CmdOKClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall RBTipoPeloClick(TObject *Sender);
    void __fastcall RBTipoOjosClick(TObject *Sender);
    void __fastcall RBTipoBocaClick(TObject *Sender);
    void __fastcall RBTipoOrejasClick(TObject *Sender);
    
private:	// User declarations
    /// Cara elegida del formulario de búsqueda.
    TCara caraElegida;

public:		// User declarations
    __fastcall TBusqueda(TComponent* Owner);

    void __fastcall actualizarCara (void);
    TCara __fastcall dameCara (void);
};
//---------------------------------------------------------------------------
extern PACKAGE TBusqueda *Busqueda;
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
// Fin FBusqueda.h
//---------------------------------------------------------------------------
