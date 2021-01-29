//---------------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "FAcceso.h"
#include "FUsuarios.h"
#include "FDelincuentes.h"  
#include "FConfidentes.h"
//---------------------------------------------------------------------------
#include "Datos/Usuario.h"
#include "IO/ContenedorPersonas_IO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAcceso *Acceso;
//---------------------------------------------------------------------------
__fastcall TAcceso::TAcceso(TComponent* Owner)
    : TForm(Owner)
{
    this->usuarios = NULL;
    this->controlUsuarios = NULL;

    this->delincuentes = NULL;
    this->controlDelincuentes = NULL;
}
//---------------------------------------------------------------------------
__fastcall TAcceso::~TAcceso()
{
    if(this->controlUsuarios != NULL)
        delete this->controlUsuarios;

    if(this->controlDelincuentes != NULL)
        delete this->controlDelincuentes;


    if(this->usuarios != NULL)
        delete this->usuarios;

    if(this->delincuentes != NULL)
        delete this->delincuentes;
}
//---------------------------------------------------------------------------
void __fastcall TAcceso::FormCreate(TObject *Sender)
{
    read("./Data/users.bin", (ContenedorPersonas *) this->usuarios);
    read("./Data/outlaws.bin", (ContenedorPersonas *) this->delincuentes);
               
    if(this->usuarios == NULL)
        this->usuarios = new ArbolPersonas();

    if(this->delincuentes == NULL)
        this->delincuentes = new ArbolPersonas();

    this->controlUsuarios = new ControladorPersonas();
    this->controlDelincuentes = new ControladorPersonas();
    
    this->controlUsuarios->registrarModelo((ContenedorPersonas **) &(this->usuarios));
    this->controlDelincuentes->registrarModelo((ContenedorPersonas **) &(this->delincuentes));
}
//--------------------------------------------------------------------------- 
void TAcceso::InvocaConfidentes (void)
{        
    int vistaID;
    
    this->controlDelincuentes->limpiarVistas();

    TConfidentes * auxForm = new TConfidentes(this);
    auxForm->registrarControlador(this->controlDelincuentes);
    this->controlDelincuentes->registrarVista(auxForm, vistaID);
    auxForm->setVistaID(vistaID);
    auxForm->Show();
    auxForm->setIndice(0);
}
//---------------------------------------------------------------------------
void __fastcall TAcceso::LoginClick(TObject *Sender)
{
    int vistaID;

    this->controlUsuarios->limpiarVistas();
    this->controlDelincuentes->limpiarVistas();

    if(this->usuarios->getNumero() > 0)
    {
        Usuario * aux = NULL;
        int i, total = this->usuarios->getNumero();
        std::string nombre = this->Nombre->Text.c_str();
        std::string password = this->Contrasenya->Text.c_str();
        bool salir = false;

        for(i = 0; (i < total) && (!salir); ++i)
        {
            if(this->usuarios->getPersona(i, (Persona *) aux))
            {
                if(aux->getNombre() == nombre)
                {
                    if(aux->getPassword() == password)
                    {
                        if(aux->getClassName() == "Administrador")
                        {
                            TUsuarios * auxForm = new TUsuarios(this, "./Data/users.bin");
                            auxForm->registrarControlador(this->controlUsuarios);
                            this->controlUsuarios->registrarVista(auxForm, vistaID);
                            auxForm->setVistaID(vistaID);
                            auxForm->Show();
                            auxForm->setIndice(0);
                        }
                        else if(aux->getClassName() == "Policia")
                        {
                            TDelincuentes * auxForm = new TDelincuentes(this, "./Data/outlaws.bin");
                            auxForm->registrarControlador(this->controlDelincuentes);
                            this->controlDelincuentes->registrarVista(auxForm, vistaID);
                            auxForm->setVistaID(vistaID);
                            auxForm->Show(); 
                            auxForm->setIndice(0);
                        }
                    }
                    else
                    {
                        MessageBox(Application->Handle, "Contraseña incorrecta.",
                                   "Log-in", MB_ICONWARNING);
                    }
                    salir = true;
                }
            }
        }

        if(!salir)
        {
            MessageBox(Application->Handle, "Usuario incorrecto.",
                       "Log-in", MB_ICONWARNING);
        }
    }
    else
    {
        if((this->Nombre->Text == "yo") && (this->Contrasenya->Text == "yo"))
        {
            TUsuarios * auxForm = new TUsuarios(this, "./Data/users.bin");
            auxForm->registrarControlador(this->controlUsuarios);
            this->controlUsuarios->registrarVista(auxForm, vistaID);
            auxForm->setVistaID(vistaID);
            auxForm->Show();
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TAcceso::SalirClick(TObject *Sender)
{        
    //write("./Data/users.bin", (ContenedorPersonas *) this->usuarios);
    //write("./Data/outlaws.bin", (ContenedorPersonas *) this->delincuentes);
    this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TAcceso::mnuLoginClick(TObject *Sender)
{
    this->LoginClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TAcceso::mnuSalirClick(TObject *Sender)
{
    this->SalirClick(Sender);
}
//---------------------------------------------------------------------------

