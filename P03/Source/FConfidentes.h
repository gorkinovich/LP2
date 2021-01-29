//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 03 - Grupo 03.
//---------------------------------------------------------------------------
#ifndef FConfidentesH
#define FConfidentesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>      
//---------------------------------------------------------------------------
#include "FTodosDelincuentes.h"
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TConfidentes : public TTodosDelincuentes
{
__published:	// IDE-managed Components
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormShow(TObject *Sender);

protected:	// User declarations         
    /**
     * Función para actualizar la cara mostrada en el formulario.
     */
    virtual void __fastcall dibujaCara (Cara * cara);

public:		// User declarations
    __fastcall TConfidentes(TComponent* Owner, ContenedorDelincuentes * delincuentes);
};
//---------------------------------------------------------------------------
extern PACKAGE TConfidentes *Confidentes;
//---------------------------------------------------------------------------
#endif           
//---------------------------------------------------------------------------
// Fin TConfidentes.h
//---------------------------------------------------------------------------
