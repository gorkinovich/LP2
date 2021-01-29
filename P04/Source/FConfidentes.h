//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//---------------------------------------------------------------------------
#ifndef FConfidentesH
#define FConfidentesH
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
#include "FPersonasBasico.h"
//---------------------------------------------------------------------------
class TConfidentes : public TPersonasBasico
{
__published:	// IDE-managed Components
    TLabel *LblSupervisor;
    TEdit *TxtSupervisor;
    TCheckBox *CBConfidente;
    TLabel *LblDelitos;
    TMemo *TxtDelitos;
    TCheckListBox *CLBDelitos;
    void __fastcall RetinaClick(TObject *Sender);
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

    /**
     * Función para actualizar la cara mostrada en el formulario.
     */
    virtual void dibujaCara (Cara * cara);



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
    __fastcall TConfidentes(TComponent* Owner);    

    /**
     * Función para actualizar la vista.
     */
    virtual void actualizar (void);
};
//---------------------------------------------------------------------------
extern PACKAGE TConfidentes *Confidentes;
//---------------------------------------------------------------------------
#endif
