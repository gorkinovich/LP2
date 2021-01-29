//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 03 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "DelincuenteComun.h"
#include "CaraComun.h"
#pragma package(smart_init)


DelincuenteComun::DelincuenteComun () : Delincuente ()
{
    this->setCara(new CaraComun());
}


DelincuenteComun::DelincuenteComun (string dni, string nombre,
                                    string delitos, Cara * cara)
    : Delincuente (dni, nombre, delitos, cara)
{
}


DelincuenteComun::~DelincuenteComun ()
{
}


string DelincuenteComun::getClassName (void) const
{
    return "DelincuenteComun";
}


bool DelincuenteComun::salvaTXT (ofstream & salida) const
{                  
	salida << this->getClassName().c_str() << endl;
	salida << "Delincuente.nombre=" << this->getNombre() << endl;
	salida << "Delincuente.dni=" << this->getDNI() << endl;
	salida << "Delincuente.delitos=" << this->getDelitos() << endl;

	return this->getCara()->salvaTXT(salida);
}


bool DelincuenteComun::cargaTXT (ifstream & entrada)
{
	char aux[256];
	char * tipo, * contenido;
         
    for(int i = 0; i < 3; ++i)
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

        case 'e':
            this->setDelitos(contenido);
            break;
        }
    }

	return this->getCara()->cargaTXT(entrada);
}
