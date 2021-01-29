//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Datos_DelitosH
#define Datos_DelitosH


/**
 * Tipo que lista los delitos de menor a mayor gravedad.
 */
typedef enum
{
	lectura = 0,
	anhelo  = 1
} Delito;


/**
 * Clase para almacenar los datos referentes a un delito.
 */
class Delitos
{
private:
	Delito delito;

public:
	/**
	 * Constructor que crea un delito ya inicializada.
	 */
	Delitos ()
	{
		this->delito = lectura;
	}

	/**
	 * Constructor que crea un delito ya inicializada.
	 * @param delito Tipo de delito cometido.
	 */
	Delitos (Delito delito)
	{
		this->delito = delito;
	}

	/**
	 * Constructor copia.
	 */
	Delitos (const Delitos & obj)
	{
		this->delito = obj.delito;
	}

	/**
	 * Destructor de la clase.
	 */
	~Delitos ()
	{
	}

	/**
	 * Sobrecarga del operador =.
	 */
	virtual Delitos & operator = (const Delitos & obj)
	{
		this->delito = obj.delito;
		return (*this);
	}

	/**
	 * Función para hacer una copia del objeto.
	 * @return La copia del objeto actual.
	 */
	virtual Delitos & clone (void) const
	{
		Delitos * aux = new Delitos(this->delito);
		return (*aux);
	}

	/**
	 * Función para estableder el tipo de delito.
	 * @param delito Tipo de delito cometido.
	 */
	void setDelito (Delito delito)
	{
		this->delito = delito;
	}

	/**
	 * Función para obtener el tipo de delito.
	 * @return Devuelve el tipo de delito.
	 */
	Delito getDelito (void)
	{
		return this->delito;
	}

	/**
	 * Sobrecarga del operador <= para Delitos.
	 */
	bool operator <= (const Delitos & op) const
	{
		return this->delito <= op.delito;
	}
	
	/**
	 * Sobrecarga del operador == para Delitos.
	 */
	bool operator == (const Delitos & op) const
	{
		return this->delito == op.delito;
	}

	/**
	 * Sobrecarga del operador <= para Delitos.
	 */
	bool operator <= (const Delito & op) const
	{
		return this->delito <= op;
	}
	
	/**
	 * Sobrecarga del operador == para Delitos.
	 */
	bool operator == (const Delito & op) const
	{
		return this->delito == op;
	}
};


#endif