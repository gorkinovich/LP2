//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 02 - Grupo 03.
//----------------------------------------------------------------------
#ifndef ContenedorDelincuentesH
#define ContenedorDelincuentesH


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Delincuente.h"


/**
 * Clase para almacenar la base de datos de delincuentes.
 */
class ContenedorDelincuentes
{
protected:
	Delincuente * delincuentes;
	int total;  // Tamaño total del array.
	int numero; // Posición del primer elemento libre en el array.
	int indice; // Posición actual de consulta en la base de datos.

public:
	/**
	 * Constructor que crea un contenedor ya inicializado.
	 */
	ContenedorDelincuentes ();

	/**
	 * Constructor que crea un contenedor ya inicializado.
	 * @param tamanno Tamaño del array.
	 */
	ContenedorDelincuentes (int tamanno);

	/**
	 * Constructor copia que crea un contenedor ya inicializado.
	 * @param tamanno Tamaño del array.
	 */
	ContenedorDelincuentes (const ContenedorDelincuentes & contenedor);

	/**
	 * Sobrecarga del operador == para Delincuente.
	 */
	ContenedorDelincuentes & operator = (const ContenedorDelincuentes & contenedor);

	/**
	 * Destructor que libera un contenedor.
	 */
	~ContenedorDelincuentes ();

	/**
	 * Función para obtener el tamaño total de la base de datos.
	 * @return Devuelve el número total de elementos reservados.
	 * @see getNumero(), getIndice()
	 */
	int getTotal (void) const
	{
		return this->total;
	}

	/**
	 * Función para obtener la posición del primer elemento libre.
	 * @return Devuelve la posición del primer elemento libre.
	 * @see getTotal(), getIndice()
	 */
	int getNumero (void) const
	{
		return this->numero;
	}

	/**
	 * Función para obtener el índice actual en la base de datos.
	 * @return Devuelve el índice actual en la base de datos.
	 * @see getTotal(), getNumero()
	 */
	int getIndice (void) const
	{
		return this->indice;
	}
         
	/**
	 * Función para obtener la posición de un delincuente por su nombre.
	 * @param nombre Nombre del delincuente a buscar.
	 * @return Devuelve -1 si no ha sido encontrado.
	 */
	int findDelincuente (const string & nombre);
          
	/**
	 * Función para obtener la posición de un delincuente por su nombre.
	 * @param cara Cara del delincuente a buscar.
	 * @return Devuelve -1 si no ha sido encontrado.
	 */
	int findDelincuente (const Cara & cara);

	/**
	 * Función para obtener un delincuente por su nombre.
	 * @param nombre Nombre del delincuente a buscar.
	 * @param delincuente Variable en la que vamos a recibir los datos.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	bool getDelincuente (string nombre, Delincuente & delincuente);

	/**
	 * Función para obtener un delincuente por su cara.
	 * @param cara Cara del delincuente a buscar.
	 * @param delincuente Variable en la que vamos a recibir los datos.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	bool getDelincuente (Cara cara, Delincuente & delincuente);

	/**
	 * Función para saber si está cierto delincuente.
	 * @param nombre Nombre del delincuente a buscar.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	bool estaDelincuente (const string & nombre);

	/**
	 * Función para saber si está cierto delincuente.
	 * @param delincuente Datos del delincuente a buscar.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	bool estaDelincuente (const Delincuente & delincuente);

	/**
	 * Función que va a agregar un delincuente de la lista.
	 * @param elemento Delincuente que se va a agregar.
	 * @return Devuelve si ha sido agregad o no.
	 * @see borraDelincuente()
	 */
	bool agregaDelincuente (const Delincuente & delincuente);

	/**
	 * Función que va a borrar un delincuente de la lista.
	 * @param elemento Delincuente que se va a borrar.
	 * @return Devuelve si ha sido borrado o no.
	 * @see agregaDelincuente()
	 */
	bool borraDelincuente (string & nombre);

	/**
	 * Función para establecer un nuevo valor para el indice.
	 * @param indice Posición en la que nos queremos situar.
	 * @return Devuelve true si ha podido cambiar el indice.
	 */
	bool posicionar (int indice);

	/**
	 * Función que nos devuelve el delincuente de la posición actual.
	 * @param delincuente Variable en la que vamos a recibir los datos.
	 * @return Devuelve true si ha podido leer el delincuente.
	 */
	bool getActual (Delincuente & delincuente);

	/**
	 * Salva el delincuente en un fichero de texto.
	 * @param salida Ruta del fichero de salida.
	 * @return Devuelve true si todo ha ido bien.
	 */
	bool salvaTXT (const string & salida) const;
	
	/**
	 * Carga el delincuente de un fichero de texto.
	 * @param entrada Ruta del fichero de entrada.
	 * @return Devuelve true si todo ha ido bien.
	 */
	bool cargaTXT (const string & entrada);
};


#endif