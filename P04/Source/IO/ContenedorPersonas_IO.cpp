//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include <fstream>
#include "Personas_IO.h"
#include "ContenedorPersonas_IO.h"
#include "../Estructuras/ArbolPersonas.h"
#pragma package(smart_init)


//----------------------------------------------------------------------
/**
 * Sobrecarga del operador << para escribir un contenedor de personas.
 * @param output Flujo de salida hacia el fichero.
 * @param data   Datos que estamos salvando.
 * @return El propio flujo de salida.
 */
std::ofstream & operator << (std::ofstream & output, ContenedorPersonas * data)
{
	int i, total;
	Persona * aux;
	
	total = data->getNumero();

	for(i = 0; i < total; ++i)
	{
		data->getPersona(i, aux);
		output << aux;
	}

	return output;
}


//----------------------------------------------------------------------
/**
 * Sobrecarga del operador >> para cargar un contenedor de personas.
 * @param input Flujo de entrada hacia el contenedor.
 * @param data  Datos que estamos cargando.
 * @return El propio flujo de entrada.
 */
std::ifstream & operator >> (std::ifstream & input, ContenedorPersonas *& data)
{
	Persona * aux;
	data = new ArbolPersonas();

	if(data != NULL)
	{
		while(!input.eof())
		{
			aux = NULL;
			input >> aux;
			if(aux != NULL)
			{
				data->agregaPersona(*aux);
				delete aux;
			}
		}
	}

	return input;
}


//----------------------------------------------------------------------
/**
 * Función para escribir un contenedor de personas.
 * @param salida Nombre del fichero de salida.
 * @param data   Datos que estamos salvando.
 * @return Si se ha logrado escribir el fichero.
 */
bool write (std::string salida, ContenedorPersonas * data)
{
	std::ofstream output;

	output.open(salida.c_str(), std::ios::binary | std::ios::out);
	if(output.is_open())
	{
		output << data;
		output.close();
		return true;
	}
	else
	{   
		output.close();
		return false;
	}
}


//----------------------------------------------------------------------
/**
 * Función para cargar un contenedor de personas.
 * @param entrada Nombre del fichero de entrada.
 * @param data    Datos que estamos cargando.
 * @return Si se ha logrado leer el fichero.
 */
bool read (std::string entrada, ContenedorPersonas *& data)
{
	std::ifstream input;

	data = NULL;

	input.open(entrada.c_str(), std::ios::binary | std::ios::in);
	if(input.is_open())
	{
		input >> data;
		input.close();
		return true;
	}
	else
	{                 
		input.close();
		return false;
	}
}