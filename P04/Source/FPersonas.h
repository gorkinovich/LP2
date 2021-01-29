//---------------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 04 - Grupo 03.
//---------------------------------------------------------------------------
#ifndef FPersonasH
#define FPersonasH
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
#include "FPersonasBasico.h"
//---------------------------------------------------------------------------
class TPersonas : public TPersonasBasico
{
__published:	// IDE-managed Components
    TButton *CmdAnyadir;
    TButton *CmdEliminar;
    TButton *CmdModificar;
    TButton *CmdNuevo;
    TOpenDialog *OpenDlg;
    TSaveDialog *SaveDlg;
    TMenuItem *mnuArchivoNuevo;
    TMenuItem *mnuArchivoN1;
    TMenuItem *mnuArchivoAbrir;
    TMenuItem *mnuArchivoGuardar;
    TMenuItem *mnuArchivoGuardarComo;
    TMenuItem *mnuArchivoN2;
    TMenuItem *mnuBBDD;
    TMenuItem *mnuBBDDNueva;
    TMenuItem *mnuBBDDN1;
    TMenuItem *mnuBBDDNuevo;
    TMenuItem *mnuBBDDAnyadir;
    TMenuItem *mnuBBDDModificar;
    TMenuItem *mnuBBDDEliminar;
    TMenuItem *mnuBBDDBuscar;
    void __fastcall CmdNuevoClick(TObject *Sender);
    void __fastcall CmdModificarClick(TObject *Sender);
    void __fastcall CmdEliminarClick(TObject *Sender);
    void __fastcall CmdAnyadirClick(TObject *Sender);
    void __fastcall mnuArchivoNuevoClick(TObject *Sender);
    void __fastcall mnuArchivoAbrirClick(TObject *Sender);
    void __fastcall mnuArchivoGuardarClick(TObject *Sender);
    void __fastcall mnuArchivoGuardarComoClick(TObject *Sender);
    void __fastcall mnuBBDDNuevaClick(TObject *Sender);
    void __fastcall mnuBBDDNuevoClick(TObject *Sender);
    void __fastcall mnuBBDDAnyadirClick(TObject *Sender);
    void __fastcall mnuBBDDModificarClick(TObject *Sender);
    void __fastcall mnuBBDDEliminarClick(TObject *Sender);
    void __fastcall mnuBBDDBuscarClick(TObject *Sender);
protected:	// User declarations
    AnsiString ficheroLista;

	//============================================================
    /**
     * Funci�n para vaciar el contenido del formulario.
     */
    virtual void vacia (void);

    /**
     * Funci�n que recoge del formulario la cara que est� seleccionada.
     * @return La cara que est� elegida.
     */
    virtual Cara * ObtenerCaraDeCheckButtons (void) = 0;



	//============================================================
    /**
     * Funci�n que recoge del formulario los datos que formar�n la persona
     * que estamos creando o modificando.
     * @return Devuelve la persona modificada.
     */
    virtual Persona * damePersona (void) = 0;

    /**
     * Funci�n que carga en el formulario los datos de una posici�n dada de la
     * lista de delincuentes que tenemos almacenados.
     * @param i N�mero de delincuente dentro de la lista.
     */
    virtual void posicionar (int index) = 0;



	//============================================================
    /**
     * Funci�n que agrega un delincuente a la lista del programa.
     * @param delincuente Delincuente que queremos agregar.
     * @see modificarDelincuente(), borrarDelincuente()
     */
    void agregarPersona (Persona * persona);

    /**
     * Funci�n que modifica un delincuente en la lista del programa.
     * @param delincuente Delincuente que queremos modificar.
     * @see agregarDelincuente(), borrarDelincuente()
     */
    void modificarPersona (Persona * persona);

    /**
     * Funci�n que borra un delincuente en la lista del programa.
     * @param delincuente Delincuente que queremos borrar.
     * @see agregarDelincuente(), modificarDelincuente()
     */
    void borrarPersona (Persona * persona);


public:		// User declarations
    __fastcall TPersonas(TComponent* Owner);

    /**
     * Funci�n para actualizar la vista.
     */
    virtual void actualizar (void) = 0;
};
//---------------------------------------------------------------------------
extern PACKAGE TPersonas *Personas;
//---------------------------------------------------------------------------
#endif
