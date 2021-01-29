//----------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Datos_DelincuenteH
#define Datos_DelincuenteH

#include "Persona.h"
#include "Delitos.h"
#include "CaraComun.h"
#include "../Estructuras/ListaOrdenada.h"

//template class ListaOrdenada<Delitos>;
//template class ListaOrdenada<std::string>;

/**
 * Clase para almacenar los datos referentes a un delincuente.
 */
class Delincuente : public Persona
{
private:
	ListaOrdenada<Delitos>     * delitosCometidos;
	ListaOrdenada<std::string> * delitosConcretos;


protected:
	/**
	 * Funci�n para copiar de un objeto.
	 * @param obj Objeto que queremos copiar.
	 */
	void CopyFrom (const Delincuente & obj);


public:
	/**
	 * Constructor que crea un delincuente ya inicializado.
	 */
	Delincuente ();

	/**
	 * Constructor que crea un delincuente ya inicializado.
	 * @param id        ID del delincuente.
	 * @param nombre    Nombre del delincuente.
	 * @param cara      Cara del delincuente.
	 * @param cometidos Delitos cometidos del delincuente.
	 * @param concretos Delitos concretos del delincuente.
	 */
	Delincuente (std::string id, std::string nombre, CaraComun * cara,
				 ListaOrdenada<Delitos> * cometidos,
				 ListaOrdenada<std::string> * concretos);

	/**
	 * Constructor copia.
	 * @param obj Delincuente que queremos copiar.
	 */
	Delincuente (const Delincuente & obj);

	/**
	 * Destructor de la clase.
	 */
    virtual ~Delincuente ();

	/**
	 * Sobrecarga del operador =.
	 */
	virtual Persona & operator = (const Persona & obj);

	/**
	 * Sobrecarga del operador =.
	 */
	Delincuente & operator = (const Delincuente & obj);

	/**
	 * Funci�n para hacer una copia del objeto.
	 * @return La copia del objeto actual.
	 */
	virtual Persona & clone (void) const = 0;

	/**
	 * Funci�n para obtener el tipo de la clase actual.
	 * @return Devuelve el tipo de la clase.
	 */
    virtual std::string getClassName (void) const = 0;

	/**
	 * Funci�n para saber si est� un delito o no en el delincuente.
	 * @param unDelito Delito que estamos buscando en el delincuente.
	 * @return Devuelve si se ha encontrado ese delito o no.
	 */
	bool estaDelitosCometidos (const Delito unDelito) const;

	/**
	 * Funci�n para obtener los delitos del delincuente indicado.
	 * @return Devuelve los delitos del delincuente indicado.
	 */
	ListaOrdenada<Delitos> * getDelitosCometidos (void);

	/**
	 * Funci�n para obtener los delitos del delincuente indicado.
	 * @return Devuelve los delitos del delincuente indicado.
	 */
	ListaOrdenada<std::string> * getDelitosConcretos (void);

	/**
	 * Funci�n para establecer los delitos del delincuente indicado.
	 * @param delitos Delitos del delincuente.
	 */
	void setDelitosCometidos (ListaOrdenada<Delitos> * delitos);

	/**
	 * Funci�n para establecer los delitos del delincuente indicado.
	 * @param delitos Delitos del delincuente.
	 */
	void setDelitosConcretos (ListaOrdenada<std::string> * delitos);

	/**
	 * Funci�n para establecer la cara del delincuente indicado.
	 * @param cara Cara de la persona indicada.
	 */
	void setCara (CaraComun * cara);

};


#endif