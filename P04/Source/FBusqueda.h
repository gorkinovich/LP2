//---------------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 04 - Grupo 03.
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
#include "Datos/CaraComun.h"
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
    TRadioGroup *RBTipoMenton;
    TLabel *LblRetina;
    TEdit *TxtRetina;
    void __fastcall CmdCancelClick(TObject *Sender);
    void __fastcall CmdOKClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall RBTipoPeloClick(TObject *Sender);
    void __fastcall RBTipoOjosClick(TObject *Sender);
    void __fastcall RBTipoBocaClick(TObject *Sender);
    void __fastcall RBTipoOrejasClick(TObject *Sender);
    void __fastcall RBTipoMentonClick(TObject *Sender);
    
private:	// User declarations
    /// Cara elegida del formulario de b�squeda.
    CaraComun caraElegida;

public:		// User declarations
    __fastcall TBusqueda(TComponent* Owner);
                                      
    /**
     * Funci�n para actualizar la cara mostrada en el memo del formulario.
     */
    void actualizarCara (void);

    /**
     * Funci�n para devolver la cara elegida en el formulario.
     * @return La cara elegida.
     */
    CaraComun * dameCara (void);
};
//---------------------------------------------------------------------------
extern PACKAGE TBusqueda *Busqueda;
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
// Fin FBusqueda.h
//---------------------------------------------------------------------------
