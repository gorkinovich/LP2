//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef IO_Caras_IOH
#define IO_Caras_IOH

#include "../Datos/Cara.h"


/**
 * Sobrecarga del operador << para escribir una cara.
 * @param output Flujo de salida hacia el fichero.
 * @param data   Datos que estamos salvando.
 * @return El propio flujo de salida.
 */
std::ofstream & operator << (std::ofstream & output, Cara * data);


/**
 * Sobrecarga del operador >> para cargar una cara.
 * @param input Flujo de entrada hacia el contenedor.
 * @param data  Datos que estamos cargando.
 * @return El propio flujo de entrada.
 */
std::ifstream & operator >> (std::ifstream & input, Cara *& data);


#endif