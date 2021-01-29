//----------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 03 - Grupo 03.
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
private:
    string dni;
	string nombre;
	string delitos;
	Cara * cara;

protected:
        
	/**
	 * Funci�n para establecer el dni del delincuente indicado.
	 * @param delitos Dni del delincuente.
	 * @see setNombre(), setDelitos(), setCara()
	 */
	void setDNI (string dni);

public:
	/**
	 * Constructor que crea un delincuente ya inicializado.
	 */
	Delincuente ();

	/**
	 * Constructor que crea un delincuente ya inicializado.
	 * @param nombre Nombre del delincuente.
	 * @param delitos Delitos del delincuente.
	 * @param cara Cara del delincuente.
	 */
	Delincuente (string dni, string nombre, string delitos, Cara * cara);

	/**
	 * Destructor de la clase.
	 */
    virtual ~Delincuente ();

	/**
	 * Operador de asignaci�n sobrecargado.
	 */
    virtual Delincuente & operator = (const Delincuente & delincuente);

	/**
	 * Funci�n para obtener el tipo de la clase actual.
	 * @return Devuelve el tipo de la clase.
	 */
    virtual string getClassName (void) const = 0;

	/**
	 * Funci�n para obtener el nombre del delincuente indicado.
	 * @return Devuelve el nombre del delincuente indicado.
	 * @see getDelitos(), getDNI(), getCara()
	 */
	string getNombre (void) const;

	/**
	 * Funci�n para obtener los delitos del delincuente indicado.
	 * @return Devuelve los delitos del delincuente indicado.
	 * @see getNombre(), getDNI(), getCara()
	 */
	string getDelitos (void) const;

	/**
	 * Funci�n para obtener el dni del delincuente indicado.
	 * @return Devuelve el dni del delincuente indicado.
	 * @see getNombre(), getDelitos(), getCara()
	 */
	string getDNI (void) const;

	/**
	 * Funci�n para obtener la cara del delincuente indicado.
	 * @return Devuelve la cara del delincuente indicado.
	 * @see getNombre(), getDelitos(), getDNI()
	 */
	Cara * getCara (void) const;

	/**
	 * Funci�n para establecer el nombre del delincuente indicado.
	 * @param nombre Nombre del delincuente.
	 * @see setDelitos(), setDNI(), setCara()
	 */
	void setNombre (string nombre);

	/**
	 * Funci�n para establecer los delitos del delincuente indicado.
	 * @param delitos Delitos del delincuente.
	 * @see setNombre(), setDNI(), setCara()
	 */
	void setDelitos (string delitos);

	/**
	 * Funci�n para establecer la cara del delincuente indicado.
	 * @param cara Cara del delincuente.
	 * @see setNombre(), setDelitos(), setDNI()
	 */
	void setCara (Cara * cara);

	/**
	 * Sobrecarga del operador == para Delincuente.
	 */
	bool operator == (const Delincuente & delincuente) const;

	/**
	 * Sobrecarga del operador == para Delincuente.
	 */
	bool operator <= (const Delincuente & delincuente) const;

	/**
	 * Funci�n que indica si un delincuente es parecido a otro.
	 * @param delincuente Delincuente del que vamos a obtener los datos.
	 * @param cara Cara con la que queremos comparar el delincuente.
	 * @return Devuelve si tiene la cara igual o no.
	 */
	bool parecido (const Cara & cara) const;

	/**
	 * Salva el delincuente en un fichero de texto.
	 * @param salida Flujo de salida al fichero.
	 * @return Devuelve true si todo ha ido bien.
	 */
	virtual bool salvaTXT (ofstream & salida) const = 0;
	
	/**
	 * Carga el delincuente de un fichero de texto.
	 * @param entrada Flujo de entrada al fichero.
	 * @return Devuelve true si todo ha ido bien.
	 */
	virtual bool cargaTXT (ifstream & entrada) = 0;
};


#endif