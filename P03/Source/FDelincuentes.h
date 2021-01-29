//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 03 - Grupo 03.
//---------------------------------------------------------------------------
#ifndef FDelincuentesH
#define FDelincuentesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "FTodosDelincuentes.h"
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TDelincuentes : public TTodosDelincuentes
{
__published:	// IDE-managed Components
    TMenuItem *mnuArchivoNuevo;
    TMenuItem *mnuArchivoN1;
    TMenuItem *mnuArchivoAbrir;
    TMenuItem *mnuArchivoGuardar;
    TMenuItem *mnuArchivoGuardarComo;
    TMenuItem *mnuArchivoN2;
    TMenuItem *mnuBBDD;
    TMenuItem *mnuBBDDNuevo;
    TMenuItem *mnuBBDDN1;
    TMenuItem *mnuBBDDAgregar;
    TMenuItem *mnuBBDDBorrar;
    TMenuItem *mnuBBDDModificar;
    TMenuItem *mnuBBDDBuscar;
    TMenuItem *mnuConfidentes;
    TOpenDialog *OpenDlg;
    TSaveDialog *SaveDlg;
    void __fastcall mnuArchivoNuevoClick(TObject *Sender);
    void __fastcall mnuArchivoAbrirClick(TObject *Sender);
    void __fastcall mnuArchivoGuardarClick(TObject *Sender);
    void __fastcall mnuArchivoGuardarComoClick(TObject *Sender);
    void __fastcall mnuBBDDNuevoClick(TObject *Sender);
    void __fastcall mnuBBDDAgregarClick(TObject *Sender);
    void __fastcall mnuBBDDBorrarClick(TObject *Sender);
    void __fastcall mnuBBDDModificarClick(TObject *Sender);
    void __fastcall mnuBBDDBuscarClick(TObject *Sender);
    void __fastcall mnuConfidentesClick(TObject *Sender);
private:	// User declarations
    AnsiString ficheroLista;

public:		// User declarations
    __fastcall TDelincuentes(TComponent* Owner); 
    virtual __fastcall ~TDelincuentes();
};
//---------------------------------------------------------------------------
extern PACKAGE TDelincuentes *Delincuentes;
//---------------------------------------------------------------------------
#endif
