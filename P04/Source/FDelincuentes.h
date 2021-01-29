//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//---------------------------------------------------------------------------
#ifndef FDelincuentesH
#define FDelincuentesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ExtDlgs.hpp>
#include <Menus.hpp>
#include <CheckLst.hpp>
//---------------------------------------------------------------------------
#include "FPersonas.h"
//---------------------------------------------------------------------------
class TDelincuentes : public TPersonas
{
__published:	// IDE-managed Components
    TLabel *LblSupervisor;
    TEdit *TxtSupervisor;
    TCheckBox *CBConfidente;
    TLabel *LblDelitos;
    TMemo *TxtDelitos;
    TCheckListBox *CLBDelitos;
    TMenuItem *mnuConfidentes;
    void __fastcall mnuConfidentesClick(TObject *Sender);
protected:	// User declarations  
	//============================================================
    /**
     * Función para vaciar el contenido del formulario.
     */
    virtual void vacia (void);

    /**
     * Función que recoge del formulario la cara que está seleccionada.
     * @return La cara que está elegida.
     */
    virtual Cara * ObtenerCaraDeCheckButtons (void);



	//============================================================
    /**
     * Función que recoge del formulario los datos que formarán la persona
     * que estamos creando o modificando.
     * @return Devuelve la persona modificada.
     */
    virtual Persona * damePersona (void);

    /**
     * Función que carga en el formulario los datos de una posición dada de la
     * lista de delincuentes que tenemos almacenados.
     * @param i Número de delincuente dentro de la lista.
     */
    virtual void posicionar (int index);



public:		// User declarations
    __fastcall TDelincuentes(TComponent* Owner);  
    __fastcall TDelincuentes(TComponent* Owner, AnsiString ruta);

    /**
     * Función para actualizar la vista.
     */
    virtual void actualizar (void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDelincuentes *Delincuentes;
//---------------------------------------------------------------------------
#endif
