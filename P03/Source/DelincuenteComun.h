//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 03 - Grupo 03.
//----------------------------------------------------------------------
#ifndef DelincuenteComunH
#define DelincuenteComunH

#include "Delincuente.h"


/**
 * Clase para almacenar los datos referentes a un delincuente.
 */
class DelincuenteComun : public Delincuente
{
public:
	/**
	 * Constructor que crea un delincuente ya inicializado.
	 */
	DelincuenteComun ();

	/**
	 * Constructor que crea un delincuente ya inicializado.
	 * @param nombre Nombre del delincuente.
	 * @param delitos Delitos del delincuente.
	 * @param cara Cara del delincuente.
	 */
	DelincuenteComun (string dni, string nombre, string delitos, Cara * cara);

	/**
	 * Destructor de la clase.
	 */
    virtual ~DelincuenteComun ();

	/**
	 * Función para obtener el tipo de la clase actual.
	 * @return Devuelve el tipo de la clase.
	 */
    virtual string getClassName (void) const;

	/**
	 * Salva el delincuente en un fichero de texto.
	 * @param salida Flujo de salida al fichero.
	 * @return Devuelve true si todo ha ido bien.
	 */
	virtual bool salvaTXT (ofstream & salida) const;

	/**
	 * Carga el delincuente de un fichero de texto.
	 * @param entrada Flujo de entrada al fichero.
	 * @return Devuelve true si todo ha ido bien.
	 */
	virtual bool cargaTXT (ifstream & entrada);
};


#endif