//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//---------------------------------------------------------------------------
#ifndef FAccesoH
#define FAccesoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
#include "Estructuras/ArbolPersonas.h"
#include "Patrones/ControladorPersonas.h"
//---------------------------------------------------------------------------
class TAcceso : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *Menu;
    TLabel *Label1;
    TEdit *Nombre;
    TLabel *Label2;
    TEdit *Contrasenya;
    TMenuItem *mnuPrincipal;
    TMenuItem *mnuLogin;
    TMenuItem *mnuSep;
    TMenuItem *mnuSalir;
    TButton *Login;
    TButton *Salir;
    void __fastcall LoginClick(TObject *Sender);
    void __fastcall SalirClick(TObject *Sender);
    void __fastcall mnuLoginClick(TObject *Sender);
    void __fastcall mnuSalirClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    
private:	// User declarations
    ArbolPersonas * usuarios;
    ControladorPersonas * controlUsuarios;

    ArbolPersonas * delincuentes;
    ControladorPersonas * controlDelincuentes;


public:		// User declarations
    __fastcall TAcceso(TComponent* Owner);
    __fastcall ~TAcceso();

    void InvocaConfidentes (void);
};
//---------------------------------------------------------------------------
extern PACKAGE TAcceso *Acceso;
//---------------------------------------------------------------------------
#endif
