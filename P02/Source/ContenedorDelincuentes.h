//----------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 02 - Grupo 03.
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
	int total;  // Tama�o total del array.
	int numero; // Posici�n del primer elemento libre en el array.
	int indice; // Posici�n actual de consulta en la base de datos.

public:
	/**
	 * Constructor que crea un contenedor ya inicializado.
	 */
	ContenedorDelincuentes ();

	/**
	 * Constructor que crea un contenedor ya inicializado.
	 * @param tamanno Tama�o del array.
	 */
	ContenedorDelincuentes (int tamanno);

	/**
	 * Constructor copia que crea un contenedor ya inicializado.
	 * @param tamanno Tama�o del array.
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
	 * Funci�n para obtener el tama�o total de la base de datos.
	 * @return Devuelve el n�mero total de elementos reservados.
	 * @see getNumero(), getIndice()
	 */
	int getTotal (void) const
	{
		return this->total;
	}

	/**
	 * Funci�n para obtener la posici�n del primer elemento libre.
	 * @return Devuelve la posici�n del primer elemento libre.
	 * @see getTotal(), getIndice()
	 */
	int getNumero (void) const
	{
		return this->numero;
	}

	/**
	 * Funci�n para obtener el �ndice actual en la base de datos.
	 * @return Devuelve el �ndice actual en la base de datos.
	 * @see getTotal(), getNumero()
	 */
	int getIndice (void) const
	{
		return this->indice;
	}
         
	/**
	 * Funci�n para obtener la posici�n de un delincuente por su nombre.
	 * @param nombre Nombre del delincuente a buscar.
	 * @return Devuelve -1 si no ha sido encontrado.
	 */
	int findDelincuente (const string & nombre);
          
	/**
	 * Funci�n para obtener la posici�n de un delincuente por su nombre.
	 * @param cara Cara del delincuente a buscar.
	 * @return Devuelve -1 si no ha sido encontrado.
	 */
	int findDelincuente (const Cara & cara);

	/**
	 * Funci�n para obtener un delincuente por su nombre.
	 * @param nombre Nombre del delincuente a buscar.
	 * @param delincuente Variable en la que vamos a recibir los datos.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	bool getDelincuente (string nombre, Delincuente & delincuente);

	/**
	 * Funci�n para obtener un delincuente por su cara.
	 * @param cara Cara del delincuente a buscar.
	 * @param delincuente Variable en la que vamos a recibir los datos.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	bool getDelincuente (Cara cara, Delincuente & delincuente);

	/**
	 * Funci�n para saber si est� cierto delincuente.
	 * @param nombre Nombre del delincuente a buscar.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	bool estaDelincuente (const string & nombre);

	/**
	 * Funci�n para saber si est� cierto delincuente.
	 * @param delincuente Datos del delincuente a buscar.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	bool estaDelincuente (const Delincuente & delincuente);

	/**
	 * Funci�n que va a agregar un delincuente de la lista.
	 * @param elemento Delincuente que se va a agregar.
	 * @return Devuelve si ha sido agregad o no.
	 * @see borraDelincuente()
	 */
	bool agregaDelincuente (const Delincuente & delincuente);

	/**
	 * Funci�n que va a borrar un delincuente de la lista.
	 * @param elemento Delincuente que se va a borrar.
	 * @return Devuelve si ha sido borrado o no.
	 * @see agregaDelincuente()
	 */
	bool borraDelincuente (string & nombre);

	/**
	 * Funci�n para establecer un nuevo valor para el indice.
	 * @param indice Posici�n en la que nos queremos situar.
	 * @return Devuelve true si ha podido cambiar el indice.
	 */
	bool posicionar (int indice);

	/**
	 * Funci�n que nos devuelve el delincuente de la posici�n actual.
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