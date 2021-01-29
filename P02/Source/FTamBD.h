//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 02 - Grupo 03.
//---------------------------------------------------------------------------
#ifndef FTamBDH
#define FTamBDH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TTamBD : public TForm
{
__published:	// IDE-managed Components
    TLabel *LblPregunta;
    TEdit *TxtRespuesta;
    TButton *CmdCancelar;
    TButton *CmdAceptar;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall CmdCancelarClick(TObject *Sender);
    void __fastcall CmdAceptarClick(TObject *Sender);
    void __fastcall TxtRespuestaKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
    __fastcall TTamBD(TComponent* Owner);

    int Respuesta;
};
//---------------------------------------------------------------------------
extern PACKAGE TTamBD *TamBD;
//---------------------------------------------------------------------------
#endif
