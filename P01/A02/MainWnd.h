//---------------------------------------------------------------------------

#ifndef MainWndH
#define MainWndH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
    TMemo *Retrato;
    TButton *CmdGenerarCara;
    TRadioGroup *RBTipoPelo;
    TRadioGroup *RBTipoOjos;
    TRadioGroup *RBTipoBoca;
    TRadioGroup *RBTipoOrejas;
    void __fastcall CmdGenerarCara_OnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
