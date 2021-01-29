//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//---------------------------------------------------------------------------
#ifndef FPersonasBasicoH
#define FPersonasBasicoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
#include "Datos/Persona.h"
#include "Patrones/Vista.h"
//E2278 Multiple base classes not supported for VCL classes.
//---------------------------------------------------------------------------
class TPersonasBasico : public TForm //, public Vista
{
__published:	// IDE-managed Components
    TLabel *LblFicha;
    TLabel *LblNumFicha;
    TButton *CmdBuscar;
    TButton *CmdAnt;
    TButton *CmdSig;
    TLabel *LblNombre;
    TEdit *TxtNombre;
    TRadioGroup *RBTipoPelo;
    TRadioGroup *RBTipoOjos;
    TRadioGroup *RBTipoBoca;
    TRadioGroup *RBTipoOrejas;
    TRadioGroup *RBTipoMenton;
    TMainMenu *MenuPrincipal;
    TMenuItem *mnuArchivo;
    TMenuItem *mnuArchivoSalir;
    TLabel *LblDNI;
    TEdit *TxtDNI;
    TImage *Retrato;
    TImage *Retina;
    TOpenPictureDialog *OpenPicDlg;
    void __fastcall CmdAntClick(TObject *Sender);
    void __fastcall CmdSigClick(TObject *Sender);
    void __fastcall CmdBuscarClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall RBTipoPeloClick(TObject *Sender);
    void __fastcall RBTipoOjosClick(TObject *Sender);
    void __fastcall RBTipoBocaClick(TObject *Sender);
    void __fastcall RBTipoOrejasClick(TObject *Sender);
    void __fastcall RBTipoMetonClick(TObject *Sender);
    void __fastcall mnuArchivoSalirClick(TObject *Sender);
    void __fastcall RetinaClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
protected:	// User declarations
    Controlador * controlador;
    int vistaID;
     
    int indice;
    AnsiString retinaActual;


    /**
     * Función para pintar un canvas en blanco.
     */
    void PaintCanvasWhite (TCanvas * canvas, int w, int h);
         
    /**
     * Función para pintar un canvas en blanco.
     */
    void RetinaFree (void);


	//============================================================
    /**
     * Función que mete en una etiqueta un número como texto de esta.
     * @param lbl Equiqueta que modificar.
     * @param numero Número que se va a mostrar en la etiqueta.
     */
    void MeterNumeroEnLabel (TLabel * lbl, int numero);

    /**
     * Función para vaciar el contenido del formulario.
     */
    virtual void vacia (void);



	//============================================================
    /**
     * Función que actualiza el formulario en base a una cara ya formada.
     * @param cara Cara que va a servir para actualizar los datos.
     + @param admin Indica si el formulario tiene privilegios para ver confidentes.
     */
    void ActualizarCheckButtons (const Cara * cara, bool admin = false);
    
    /**
     * Función para actualizar la cara mostrada en el formulario.
     */
    void actualizarCaraPorRadioGroups (void);

    /**
     * Función que recoge del formulario la cara que está seleccionada.
     * @return La cara que está elegida.
     */
    virtual Cara * ObtenerCaraDeCheckButtons (void) = 0;



	//============================================================
    /**
     * Función para actualizar la cara mostrada en el formulario.
     */
    void actualizarCara (void);

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
    virtual Persona * damePersona (void) = 0;

    /**
     * Función que carga en el formulario los datos de una posición dada de la
     * lista de delincuentes que tenemos almacenados.
     * @param index Número de delincuente dentro de la lista.
     */
    virtual void posicionar (int index) = 0;



public:		// User declarations
    __fastcall TPersonasBasico(TComponent* Owner);

    /**
     * Función para actualizar la vista.
     */
    virtual void actualizar (void) = 0;

    /**
     * Función para registrar un controlador. 
     * @param controlador Controlador que queremos registrar.
     */
    virtual void registrarControlador (Controlador * unControlador);

    /**
     * Función para cambiar el ID de la vista.
     * @param vistaID ID de la vista.
     */
    void setVistaID (int vistaID);
       
    /**
     * Función cambiar el número de indice del contenedor.
     * @param index Número de persona dentro de la lista.
     */
    void setIndice (int index)
    {
        this->posicionar(index);
    }
};
//---------------------------------------------------------------------------
extern PACKAGE TPersonasBasico *PersonasBasico;
//---------------------------------------------------------------------------
#endif             
//---------------------------------------------------------------------------
// Fin FPersonasBasico.h
//---------------------------------------------------------------------------
