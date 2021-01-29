//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
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
    /// Cara elegida del formulario de búsqueda.
    CaraComun caraElegida;

public:		// User declarations
    __fastcall TBusqueda(TComponent* Owner);
                                      
    /**
     * Función para actualizar la cara mostrada en el memo del formulario.
     */
    void actualizarCara (void);

    /**
     * Función para devolver la cara elegida en el formulario.
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
