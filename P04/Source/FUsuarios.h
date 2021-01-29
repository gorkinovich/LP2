//---------------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 04 - Grupo 03.
//---------------------------------------------------------------------------
#ifndef FUsuariosH
#define FUsuariosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ExtDlgs.hpp>
#include <Menus.hpp>     
//---------------------------------------------------------------------------
#include "FPersonas.h"
//---------------------------------------------------------------------------
class TUsuarios : public TPersonas
{
__published:	// IDE-managed Components
    TLabel *LblPassword;
    TEdit *TxtPassword;
    TCheckBox *CBAdministrador;
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

    /**
     * Funci�n para actualizar la cara mostrada en el formulario.
     */
    virtual void dibujaCara (Cara * cara);



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
    __fastcall TUsuarios(TComponent* Owner);
    __fastcall TUsuarios(TComponent* Owner, AnsiString ruta);

    /**
     * Funci�n para actualizar la vista.
     */
    virtual void actualizar (void);
};
//---------------------------------------------------------------------------
extern PACKAGE TUsuarios *Usuarios;
//---------------------------------------------------------------------------
#endif
