//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include <fstream>
#include "Caras_IO.h"
#include "../Datos/Policia.h"
#include "../Datos/Administrador.h"
#include "../Datos/Lector.h"
#include "../Datos/Sonnador.h"
#include "../Datos/LectorConfidente.h"
#include "../Datos/SonnadorConfidente.h"
#pragma package(smart_init)


//----------------------------------------------------------------------
typedef enum
{
	persona_policia            = 0,
	persona_administrador      = 1,
	persona_lector             = 2,
	persona_sonnador           = 3,
	persona_lectorConfidente   = 4,
	persona_sonnadorConfidente = 5
} TPersonas;


//----------------------------------------------------------------------
/**
 * Función para obtener el tipo de un objeto.
 * @param data Objeto del que queremos saber su tipo.
 * @return Tipo del dato pasado a nuestro formato.
 */
TPersonas getTPersonas (const Persona * data)
{
	if(typeid(*data) == typeid(Policia))
	{
		return persona_policia;
	}
	else if(typeid(*data) == typeid(Administrador))
	{
		return persona_administrador;
	}
	else if(typeid(*data) == typeid(Lector))
	{
		return persona_lector;
	}
	else if(typeid(*data) == typeid(Sonnador))
	{
		return persona_sonnador;
	}
	else if(typeid(*data) == typeid(LectorConfidente))
	{
		return persona_lectorConfidente;
	}
	else if(typeid(*data) == typeid(SonnadorConfidente))
	{
		return persona_sonnadorConfidente;
	}
	else
	{
		return persona_policia;
	}
}


//----------------------------------------------------------------------
const int MAX_CARACTERES = 200;
typedef char cadena_io[MAX_CARACTERES];


/**
 * Función para escribir una cadena en un fichero.
 * @param output Flujo de salida hacia el fichero.
 * @param data   Datos que estamos escribiendo.
 */
void EscribirCadena (std::ofstream & output, const std::string & data)
{
	cadena_io aux;
	strcpy(aux, data.c_str());
	output.write(reinterpret_cast<char *> (aux), sizeof(cadena_io));
}


/**
 * Función para leer una cadena de un fichero.
 * @param input Flujo de entrada hacia el contenedor.
 * @param data  Datos que estamos leyendo.
 */
void LeerCadena (std::ifstream & input, std::string & data)
{
	cadena_io aux;
	input.read(reinterpret_cast<char *> (aux), sizeof(cadena_io));
	data = aux;
}


//----------------------------------------------------------------------
/**
 * Función para escribir una persona en un fichero.
 * @param output Flujo de salida hacia el fichero.
 * @param data   Datos que estamos escribiendo.
 */
void EscribirPersona (std::ofstream & output, Persona * data)
{
	EscribirCadena(output, data->getID());
	EscribirCadena(output, data->getNombre());
}


/**
 * Función para escribir un usuario en un fichero.
 * @param output Flujo de salida hacia el fichero.
 * @param data   Datos que estamos escribiendo.
 */
void EscribirUsuario (std::ofstream & output, Usuario * data)
{
	EscribirPersona(output, data);
	EscribirCadena(output, data->getPassword());

	CaraClasificada * aux = (CaraClasificada *) data->getCara();
	output << aux;
}


/**
 * Función para escribir un delincuente común en un fichero.
 * @param output Flujo de salida hacia el fichero.
 * @param data   Datos que estamos escribiendo.
 */
void EscribirDelincuente (std::ofstream & output, Delincuente * data)
{
	EscribirPersona(output, data);


	ListaOrdenada<Delitos> * auxCometidos = data->getDelitosCometidos();
	ListaOrdenada<std::string> * auxConcretos = data->getDelitosConcretos();


	int i, auxenum, total;
	Delitos auxDelitos;

	total = auxCometidos->getNumero();
	output.write(reinterpret_cast<char *> (&total), sizeof(int));

	for(i = 0; i < total; ++i)
	{
		auxCometidos->getElemento(i, auxDelitos);
		auxenum = (int) auxDelitos.getDelito();
		output.write(reinterpret_cast<char *> (&auxenum), sizeof(int));
	}


	std::string auxString;

	total = auxConcretos->getNumero();
	output.write(reinterpret_cast<char *> (&total), sizeof(int));

	for(i = 0; i < total; ++i)
	{
		auxConcretos->getElemento(i, auxString);
		EscribirCadena(output, auxString);
	}
}


/**
 * Función para escribir un delincuente común en un fichero.
 * @param output Flujo de salida hacia el fichero.
 * @param data   Datos que estamos escribiendo.
 */
void EscribirDelincuenteComun (std::ofstream & output, Delincuente * data)
{
	EscribirDelincuente(output, data);

	CaraComun * aux = (CaraComun *) data->getCara();
	output << aux;
}


/**
 * Función para escribir un delincuente confidente en un fichero.
 * @param output Flujo de salida hacia el fichero.
 * @param data   Datos que estamos escribiendo.
 */
void EscribirDelincuenteConfidente (std::ofstream & output, Delincuente * data)
{
	EscribirDelincuente(output, data);

	DelincuenteConfidente * auxdc = (DelincuenteConfidente *) data;
	EscribirCadena(output, auxdc->getSupervisor());

	CaraClasificada * aux = (CaraClasificada *) data->getCara();
	output << aux;
}


//----------------------------------------------------------------------
/**
 * Sobrecarga del operador << para escribir una persona.
 * @param output Flujo de salida hacia el fichero.
 * @param data   Datos que estamos salvando.
 * @return El propio flujo de salida.
 */
std::ofstream & operator << (std::ofstream & output, Persona * data)
{
	TPersonas tipo = getTPersonas(data);
	int auxtipo = (int) tipo;
	output.write(reinterpret_cast<char *> (&auxtipo), sizeof(int));
	
	switch (tipo)
	{
		case persona_policia:
		case persona_administrador:
			EscribirUsuario(output, (Usuario *) data);
			break;
			
		case persona_lector:
		case persona_sonnador:
			EscribirDelincuenteComun(output, (Delincuente *) data);
			break;
			
		case persona_lectorConfidente:
		case persona_sonnadorConfidente:
			EscribirDelincuenteConfidente(output, (Delincuente *) data);
			break;
	}

	return output;
}


//----------------------------------------------------------------------
/**
 * Función leer escribir una persona de un fichero.
 * @param input Flujo de entrada hacia el contenedor.
 * @param data  Datos que estamos leyendo.
 */
void LeerPersona (std::ifstream & input, Persona * data)
{
	std::string aux;

	LeerCadena(input, aux);	data->setID(aux);
	LeerCadena(input, aux); data->setNombre(aux);
}


/**
 * Función leer escribir un usuario de un fichero.
 * @param input Flujo de entrada hacia el contenedor.
 * @param data  Datos que estamos leyendo.
 */
void LeerUsuario (std::ifstream & input, Usuario * data)
{
	LeerPersona(input, data);
	
	std::string aux;
	LeerCadena(input, aux);
	data->setPassword(aux);

	Cara * cara = NULL; input >> cara;
	data->setCara((CaraClasificada *) cara);
}


/**
 * Función para leer un delincuente común de un fichero.
 * @param input Flujo de entrada hacia el contenedor.
 * @param data  Datos que estamos leyendo.
 */
void LeerDelincuente (std::ifstream & input, Delincuente * data)
{
	LeerPersona(input, data);

	ListaOrdenada<Delitos> * auxCometidos = data->getDelitosCometidos();
	ListaOrdenada<std::string> * auxConcretos = data->getDelitosConcretos();


	int i, auxenum, total;
	Delitos auxDelitos;
	input.read(reinterpret_cast<char *> (&total), sizeof(int));
	
	for(i = 0; i < total; ++i)
	{
		input.read(reinterpret_cast<char *> (&auxenum), sizeof(int));
		auxDelitos.setDelito((Delito) auxenum);
		auxCometidos->agregaElemento(auxDelitos);
	}
	

	std::string auxString;
	input.read(reinterpret_cast<char *> (&total), sizeof(int));

	for(i = 0; i < total; ++i)
	{
		LeerCadena(input, auxString);
		auxConcretos->agregaElemento(auxString);
	}
}


/**
 * Función para leer un delincuente común de un fichero.
 * @param input Flujo de entrada hacia el contenedor.
 * @param data  Datos que estamos leyendo.
 */
void LeerDelincuenteComun (std::ifstream & input, Delincuente * data)
{
	LeerDelincuente(input, data);

	Cara * cara = NULL; input >> cara;
	data->setCara((CaraComun *) cara);
}


/**
 * Función para leer un delincuente confidente de un fichero.
 * @param input Flujo de entrada hacia el contenedor.
 * @param data  Datos que estamos leyendo.
 */
void LeerLectorConfidente (std::ifstream & input, LectorConfidente * data)
{
	LeerDelincuente(input, data);

	std::string auxString; LeerCadena(input, auxString);
	data->setSupervisor(auxString);

	Cara * cara = NULL; input >> cara;
	data->setCara((CaraClasificada *) cara);
}


/**
 * Función para leer un delincuente confidente de un fichero.
 * @param input Flujo de entrada hacia el contenedor.
 * @param data  Datos que estamos leyendo.
 */
void LeerSonnadorConfidente (std::ifstream & input, SonnadorConfidente * data)
{
	LeerDelincuente(input, data);

	std::string auxString; LeerCadena(input, auxString);
	data->setSupervisor(auxString);

	Cara * cara = NULL; input >> cara;
	data->setCara((CaraClasificada *) cara);
}


//----------------------------------------------------------------------
/**
 * Sobrecarga del operador >> para cargar una persona.
 * @param input Flujo de entrada hacia el contenedor.
 * @param data  Datos que estamos cargando.
 * @return El propio flujo de entrada.
 */
std::ifstream & operator >> (std::ifstream & input, Persona *& data)
{
	int auxtipo;
	input.read(reinterpret_cast<char *> (&auxtipo), sizeof(int));
	if(input.eof()) return input;

	TPersonas tipo = (TPersonas) auxtipo;
	
	switch (tipo)
	{
		case persona_policia:
			data = new Policia();
			LeerUsuario(input, (Usuario *) data);
			break;

		case persona_administrador:
			data = new Administrador();
			LeerUsuario(input, (Usuario *) data);
			break;
			
		case persona_lector:
			data = new Lector();
			LeerDelincuenteComun(input, (Delincuente *) data);
			break;

		case persona_sonnador:
			data = new Sonnador();
			LeerDelincuenteComun(input, (Delincuente *) data);
			break;
			
		case persona_lectorConfidente:
			data = new LectorConfidente();
			LeerLectorConfidente(input, (LectorConfidente *) data);
			break;

		case persona_sonnadorConfidente:
			data = new SonnadorConfidente();
			LeerSonnadorConfidente(input, (SonnadorConfidente *) data);
			break;
	}

	return input;
}