//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 02 - Grupo 03.
//----------------------------------------------------------------------
#ifndef DelincuenteH
#define DelincuenteH


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Cara.h"


/**
 * Clase para almacenar los datos referentes a un delincuente.
 */
class Delincuente
{
protected:
	string nombre;
	string delitos;
	Cara   cara;

public:
	/**
	 * Constructor que crea un delincuente ya inicializado.
	 */
	Delincuente () : cara()
	{
		this->nombre  = "";
		this->delitos = "";
	}

	/**
	 * Constructor que crea un delincuente ya inicializado.
	 * @param nombre Nombre del delincuente.
	 * @param delitos Delitos del delincuente.
	 * @param cara Cara del delincuente.
	 */
	Delincuente (const string & nombre, const string & delitos, const Cara & cara)
	{
		this->nombre  = nombre;
		this->delitos = delitos;
		this->cara    = cara;
	}

	/**
	 * Función para obtener el nombre del delincuente indicado.
	 * @return Devuelve el nombre del delincuente indicado.
	 * @see getDelitos(), getCara()
	 */
	string getNombre (void) const
	{
		return this->nombre;
	}

	/**
	 * Función para obtener los delitos del delincuente indicado.
	 * @return Devuelve los delitos del delincuente indicado.
	 * @see getNombre(), getCara()
	 */
	string getDelitos (void) const
	{
		return this->delitos;
	}

	/**
	 * Función para obtener la cara del delincuente indicado.
	 * @return Devuelve la cara del delincuente indicado.
	 * @see getNombre(), getDelitos()
	 */
	Cara getCara (void) const
	{
		return this->cara;
	}

	/**
	 * Función para establecer el nombre del delincuente indicado.
	 * @param nombre Nombre del delincuente.
	 * @see setDelitos(), setCara()
	 */
	void setNombre (const string & nombre)
	{
		this->nombre = nombre;
	}

	/**
	 * Función para establecer los delitos del delincuente indicado.
	 * @param delitos Delitos del delincuente.
	 * @see setNombre(), setCara()
	 */
	void setDelitos (const string & delitos)
	{
		this->delitos = delitos;
	}

	/**
	 * Función para establecer la cara del delincuente indicado.
	 * @param cara Cara del delincuente.
	 * @see setNombre(), setDelitos()
	 */
	void setCara (const Cara & cara)
	{
		this->cara = cara;
	}

	/**
	 * Sobrecarga del operador == para Delincuente.
	 */
	bool operator == (const Delincuente & delincuente) const
	{
		return this->nombre == delincuente.nombre;
	}

	/**
	 * Sobrecarga del operador == para Delincuente.
	 */
	bool operator <= (const Delincuente & delincuente) const
	{
		return (this->nombre == delincuente.nombre) ||
			   (this->nombre < delincuente.nombre) ;
	}

	/**
	 * Función que indica si un delincuente es parecido a otro.
	 * @param delincuente Delincuente del que vamos a obtener los datos.
	 * @param cara Cara con la que queremos comparar el delincuente.
	 * @return Devuelve si tiene la cara igual o no.
	 */
	bool parecido (const Cara & cara) const
	{
		return (this->cara == cara);
	}

	/**
	 * Salva el delincuente en un fichero de texto.
	 * @param salida Flujo de salida al fichero.
	 * @return Devuelve true si todo ha ido bien.
	 */
	bool salvaTXT (ofstream & salida) const;
	
	/**
	 * Carga el delincuente de un fichero de texto.
	 * @param entrada Flujo de entrada al fichero.
	 * @return Devuelve true si todo ha ido bien.
	 */
	bool cargaTXT (ifstream & entrada);
};


#endif