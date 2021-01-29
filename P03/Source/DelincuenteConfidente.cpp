//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 03 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "DelincuenteConfidente.h" 
#include "CaraConfidente.h"
#pragma package(smart_init)


DelincuenteConfidente::DelincuenteConfidente () : Delincuente ()
{                     
    this->setCara(new CaraConfidente());
    this->supervisor = "";
}


DelincuenteConfidente::DelincuenteConfidente (string dni, string nombre,
                            string delitos, string supervisor, Cara * cara)
    : Delincuente (dni, nombre, delitos, cara)
{  
    this->supervisor = supervisor;
}


DelincuenteConfidente::~DelincuenteConfidente ()
{
} 


Delincuente & DelincuenteConfidente::operator = (const Delincuente & delincuente)
{ 
	this->supervisor = ((DelincuenteConfidente &) delincuente).supervisor;
    this->Delincuente::operator =(delincuente);

    return (*this);
}


string DelincuenteConfidente::getClassName (void) const
{
    return "DelincuenteConfidente";
}


string DelincuenteConfidente::getSupervisor (void) const
{
	return this->supervisor;
}


void DelincuenteConfidente::setSupervisor (string supervisor)
{
	this->supervisor = supervisor;
}


bool DelincuenteConfidente::salvaTXT (ofstream & salida) const
{                          
	salida << this->getClassName().c_str() << endl;
	salida << "Delincuente.nombre=" << this->getNombre() << endl;
	salida << "Delincuente.dni=" << this->getDNI() << endl;
	salida << "Delincuente.supervisor=" << this->supervisor << endl;
	salida << "Delincuente.delitos=" << this->getDelitos() << endl;

	return this->getCara()->salvaTXT(salida);
}


bool DelincuenteConfidente::cargaTXT (ifstream & entrada)
{
	char aux[256];
	char * tipo, * contenido;
          
    for(int i = 0; i < 4; ++i)
    {
    	entrada.getline(aux, 256);
	    if(entrada.eof()) return false;

        tipo = strchr(aux, '.') + 1;
        contenido = strchr(aux, '=') + 1;

        switch(tipo[1])
        {  
        case 'o':
            this->setNombre(contenido);
            break;

        case 'n':
            this->setDNI(contenido);
            break;

        case 'u':
            this->supervisor = contenido;
            break;

        case 'e':
            this->setDelitos(contenido);
            break;
        }
    }

	return this->getCara()->cargaTXT(entrada);
}
