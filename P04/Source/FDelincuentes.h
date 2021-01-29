//---------------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 04 - Grupo 03.
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
     * Funci�n para vaciar el contenido del formulario.
     */
    virtual void vacia (void);

    /**
     * Funci�n que recoge del formulario la cara que est� seleccionada.
     * @return La cara que est� elegida.
     */
    virtual Cara * ObtenerCaraDeCheckButtons (void);



	//============================================================
    /**
     * Funci�n que recoge del formulario los datos que formar�n la persona
     * que estamos creando o modificando.
     * @return Devuelve la persona modificada.
     */
    virtual Persona * damePersona (void);

    /**
     * Funci�n que carga en el formulario los datos de una posici�n dada de la
     * lista de delincuentes que tenemos almacenados.
     * @param i N�mero de delincuente dentro de la lista.
     */
    virtual void posicionar (int index);



public:		// User declarations
    __fastcall TDelincuentes(TComponent* Owner);  
    __fastcall TDelincuentes(TComponent* Owner, AnsiString ruta);

    /**
     * Funci�n para actualizar la vista.
     */
    virtual void actualizar (void);
};
//---------------------------------------------------------------------------
extern PACKAGE TDelincuentes *Delincuentes;
//---------------------------------------------------------------------------
#endif
