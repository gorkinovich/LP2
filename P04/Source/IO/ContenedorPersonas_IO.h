//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef IO_ContenedorPersonas_IOH
#define IO_ContenedorPersonas_IOH

#include "../Estructuras/ContenedorPersonas.h"


/**
 * Función para escribir un contenedor de personas.
 * @param salida Nombre del fichero de salida.
 * @param data   Datos que estamos salvando.
 * @return Si se ha logrado escribir el fichero.
 */
bool write (std::string salida, ContenedorPersonas * data);


/**
 * Función para cargar un contenedor de personas.
 * @param entrada Nombre del fichero de entrada.
 * @param data    Datos que estamos cargando.
 * @return Si se ha logrado leer el fichero.
 */
bool read (std::string entrada, ContenedorPersonas *& data);


#endif