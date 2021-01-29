//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "Delincuente.h"
#pragma package(smart_init)


Delincuente::Delincuente ()
{
    this->delitosCometidos = new ListaOrdenada<Delitos>();
    this->delitosConcretos = new ListaOrdenada<std::string>();
}


Delincuente::Delincuente (std::string id, std::string nombre, CaraComun * cara,
						  ListaOrdenada<Delitos> * cometidos,
						  ListaOrdenada<std::string> * concretos)
	: Persona (id, nombre, cara)
{
    this->delitosCometidos = cometidos;
    this->delitosConcretos = concretos;
}


Delincuente::Delincuente (const Delincuente & obj)
{
	this->CopyFrom(obj);
}


Delincuente::~Delincuente ()
{
    if(this->delitosCometidos != NULL)
        delete this->delitosCometidos;
	
    if(this->delitosConcretos != NULL)
        delete this->delitosConcretos;
}


void Delincuente::CopyFrom (const Delincuente & obj)
{
	*(this->delitosCometidos) = *(obj.delitosCometidos);
	*(this->delitosConcretos) = *(obj.delitosConcretos);

	this->Persona::CopyFrom(obj);
}


Persona & Delincuente::operator = (const Persona & obj)
{
	this->CopyFrom((Delincuente &) obj);
	return (*this);
}


Delincuente & Delincuente::operator = (const Delincuente & obj)
{
	this->CopyFrom(obj);
    return (*this);
}


bool Delincuente::estaDelitosCometidos (const Delito unDelito) const
{
	Delitos aux(unDelito);

	return this->delitosCometidos->estaElemento(aux);
}


ListaOrdenada<Delitos> * Delincuente::getDelitosCometidos (void)
{
	return this->delitosCometidos;
}


ListaOrdenada<std::string> * Delincuente::getDelitosConcretos (void)
{
	return this->delitosConcretos;
}


void Delincuente::setDelitosCometidos (ListaOrdenada<Delitos> * delitos)
{
    if(this->delitosCometidos != NULL)
        delete this->delitosCometidos;

	this->delitosCometidos = delitos;
}


void Delincuente::setDelitosConcretos (ListaOrdenada<std::string> * delitos)
{
    if(this->delitosConcretos != NULL)
        delete this->delitosConcretos;

	this->delitosConcretos = delitos;
}


void Delincuente::setCara (CaraComun * cara)
{
	this->Persona::setCara(cara);
}