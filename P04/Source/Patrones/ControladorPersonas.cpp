//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "ControladorPersonas.h"
#include "../IO/ContenedorPersonas_IO.h"
#pragma package(smart_init)


ControladorPersonas::ControladorPersonas ()
{
	this->modelo    = NULL;
	this->numvistas = 0;

	for(int i = 0; i < MAX_VISTAS; ++i)
	{
		this->vistas[i]         = NULL;
		this->vistasID[i]       = 0;
		this->vistasAbiertas[i] = false;
	}
}


ControladorPersonas::~ControladorPersonas ()
{
	for(int i = 0; i < this->numvistas; ++i)
	{
		this->vistas[i]->Close();
		delete this->vistas[i];
	}
}


bool ControladorPersonas::registrarVista (TPersonasBasico * unaVista, int & numVista)
{
	static int ultimoID = 0;

	if(this->numvistas < MAX_VISTAS)
	{
		numVista = ultimoID;
		this->vistas[this->numvistas]   = unaVista;
		this->vistasID[this->numvistas] = numVista;
		this->numvistas++;
		return true;
	}
	else
	{
		return false;
	}
}


void ControladorPersonas::borrarVista (int numVista)
{
	bool exit = false;

	for(int i = 0; (i < this->numvistas) && (!exit); ++i)
	{
		if(this->vistasID[i] == numVista)
		{
			delete this->vistas[i];
			this->numvistas--;

			if(i < this->numvistas)
			{
				this->vistas[i]   = this->vistas[this->numvistas];
				this->vistasID[i] = this->vistasID[this->numvistas];
			}

			exit = true;
		}
	}
}


void ControladorPersonas::limpiarVistas (void)
{
	for(int i = 0; i < this->numvistas; )
	{
		if(!this->vistasAbiertas[i])
		{
			delete this->vistas[i];
			this->numvistas--;

			if(i < this->numvistas)
			{
				this->vistas[i]   = this->vistas[this->numvistas];
				this->vistasID[i] = this->vistasID[this->numvistas];
			}
		}
		else
		{
			++i;
		}
	}
}


void ControladorPersonas::vistaAbierta (int numVista)
{
	bool exit = false;

	for(int i = 0; (i < this->numvistas) && (!exit); ++i)
	{
		if(this->vistasID[i] == numVista)
		{
			this->vistasAbiertas[i] = true;
			exit = true;
		}
	}
}


void ControladorPersonas::vistaCerrada (int numVista)
{
	bool exit = false;

	for(int i = 0; (i < this->numvistas) && (!exit); ++i)
	{
		if(this->vistasID[i] == numVista)
		{
			this->vistasAbiertas[i] = false;
			exit = true;
		}
	}
}


void ControladorPersonas::registrarModelo (ContenedorPersonas ** unModelo)
{
	this->modelo = unModelo;
}


void ControladorPersonas::actualizarVistas (void)
{
	for(int i = 0; i < this->numvistas; i++)
	{
		this->vistas[i]->actualizar();
	}
}


bool ControladorPersonas::cargar (std::string ruta)
{
	ContenedorPersonas * aux = NULL;

	if(read(ruta, aux))
	{	
		ContenedorPersonas * victima = (*this->modelo);
		(*this->modelo) = aux;
		delete victima;
		this->actualizarVistas();
		return true;
	}
	else
	{
		return false;
	}
}


bool ControladorPersonas::salvar (std::string ruta)
{
    return write(ruta, (*this->modelo));
}


int ControladorPersonas::getTotal (void) const
{
	return (*this->modelo)->getTotal();
}


int ControladorPersonas::getNumero (void) const
{
	return (*this->modelo)->getNumero();
}


int ControladorPersonas::getIndice (void) const
{
	return (*this->modelo)->getIndice();
}


bool ControladorPersonas::setTotal (int total)
{
	bool result = (*this->modelo)->setTotal(total);
	this->actualizarVistas();
	return result;
}


bool ControladorPersonas::setIndice (int indice)
{
	bool result = (*this->modelo)->setIndice(indice);
	this->actualizarVistas();
	return result;
}


bool ControladorPersonas::getPersona (const Persona & buscado, Persona *& dato)
{
	return (*this->modelo)->getPersona(buscado, dato);
}


bool ControladorPersonas::getPersona (std::string id, Persona *& dato)
{
	return (*this->modelo)->getPersona(id, dato);
}


bool ControladorPersonas::getPersona (const Cara & cara, Persona *& dato)
{
	return (*this->modelo)->getPersona(cara, dato);
}


bool ControladorPersonas::getPersona (int indice, Persona *& dato)
{
	return (*this->modelo)->getPersona(indice, dato);
}


bool ControladorPersonas::getPersonaIndice (Persona *& dato)
{
	return (*this->modelo)->getPersonaIndice(dato);
}


bool ControladorPersonas::estaPersona (const Persona & persona)
{
	return (*this->modelo)->estaPersona(persona);
}


bool ControladorPersonas::estaPersona (std::string id)
{
	return (*this->modelo)->estaPersona(id);
}


bool ControladorPersonas::agregaPersona (const Persona & persona)
{
	bool result = (*this->modelo)->agregaPersona(persona);
	this->actualizarVistas();
	return result;
}


bool ControladorPersonas::borraPersona (const Persona & persona)
{
	bool result = (*this->modelo)->borraPersona(persona);
	this->actualizarVistas();
	return result;
}


bool ControladorPersonas::vacia (void)
{
	bool result = (*this->modelo)->vacia();
	this->actualizarVistas();
	return result;
}


bool ControladorPersonas::nuevo (void)
{
	bool result = (*this->modelo)->nuevo();
	this->actualizarVistas();
	return result;
}