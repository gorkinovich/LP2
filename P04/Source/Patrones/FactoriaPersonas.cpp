//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "FactoriaPersonas.h"
#pragma package(smart_init)


Usuario * FactoriaPersonas::creaUsuario (TipoUsuario tipo)
{
	switch(tipo)
	{
	case usuario_policia:       return new Policia();
	case usuario_administrador: return new Administrador();
	}

	return NULL;
}


Delincuente * FactoriaPersonas::creaDelincuente (TipoDelincuente tipo)
{
	switch(tipo)
	{
	case delincuente_lector:             return new Lector();
	case delincuente_sonnador:           return new Sonnador();
	case delincuente_lectorConfidente:   return new LectorConfidente();
	case delincuente_sonnadorConfidente: return new SonnadorConfidente();
	}

	return NULL;
}