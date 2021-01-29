//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Patrones_ControladorPersonasH
#define Patrones_ControladorPersonasH

#include "../Estructuras/ContenedorPersonas.h"
#include "../FPersonasBasico.h"
#include "Controlador.h"


const int MAX_VISTAS = 10;


/**
 * Clase para controlar el modelo de la aplicación.
 */
class ControladorPersonas : public Controlador
{
private:
	ContenedorPersonas ** modelo;
	TPersonasBasico * vistas[MAX_VISTAS];
	int vistasID[MAX_VISTAS];
	bool vistasAbiertas[MAX_VISTAS];
	int numvistas;

public:
	/**
	 * Constructor de la clase.
	 */
	ControladorPersonas ();

	/**
	 * Destructor de la clase.
	 */
	~ControladorPersonas ();



	//============================================================
	/**
	 * Función para registrar una vista.
	 * @param unaVista Vista a registrar.
	 * @param numVista Número de identificación.
	 * @return Devuelve si se ha registrado.
	 */
	bool registrarVista (TPersonasBasico * unaVista, int & numVista);

	/**
	 * Función para borrar una vista.
	 * @param numVista Vista a borrar.
	 */
	void borrarVista (int numVista);

	/**
	 * Función para borrar las vistas que ya no se usan.
	 */
	void limpiarVistas (void);

	/**
	 * Función para indicar que una vista está abierta.
	 * @param numVista Numero identificador de la vista.
	 */
	virtual void vistaAbierta (int numVista);
	
	/**
	 * Función para indicar que una vista está cerrada.
	 * @param numVista Numero identificador de la vista.
	 */
	virtual void vistaCerrada (int numVista);

	/**
	 * Función para registrar un modelo.
	 * @param unModelo Modelo a registrar.
	 */
	void registrarModelo (ContenedorPersonas ** unModelo);

	/**
	 * Función para actualizar las vistas.
	 */
	void actualizarVistas (void);

	/**
	 * Función para cargar un fichero.
	 */
    virtual bool cargar (std::string ruta);
	
	/**
	 * Función para salvar un fichero.
	 */
    virtual bool salvar (std::string ruta);


	//============================================================
	/**
	 * Función para obtener el tamaño total de la base de datos.
	 * @return Devuelve el número total de elementos reservados.
	 * @see getNumero(), getIndice()
	 */
	virtual int getTotal (void) const;

	/**
	 * Función para obtener la posición del primer elemento libre.
	 * @return Devuelve la posición del primer elemento libre.
	 * @see getTotal(), getIndice()
	 */
	virtual int getNumero (void) const;

	/**
	 * Función para obtener el índice actual en la base de datos.
	 * @return Devuelve el índice actual en la base de datos.
	 * @see getTotal(), getNumero()
	 */
	virtual int getIndice (void) const;


	
	//============================================================
	/**
	 * Función para establecer un nuevo valor para el total.
	 * @param total Total máximo de nodos que tendremos en el arbol.
	 * @return Devuelve true si ha podido cambiar el total.
	 */
    virtual bool setTotal (int total);

	/**
	 * Función para establecer un nuevo valor para el indice.
	 * @param indice Posición en la que nos queremos situar.
	 * @return Devuelve true si ha podido cambiar el indice.
	 */
    virtual bool setIndice (int indice);



	//============================================================
	/**
	 * Función para obtener una persona.
	 * @param buscado Persona al que buscar.
	 * @param dato Persona devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getPersona (const Persona & buscado, Persona *& dato);
                     
	/**
	 * Función para obtener una persona.
	 * @param id ID que buscar.
	 * @param dato Persona devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getPersona (std::string id, Persona *& dato);
       
	/**
	 * Función para obtener una persona.
	 * @param cara Cara que buscar.
	 * @param dato Persona devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getPersona (const Cara & cara, Persona *& dato);
       
	/**
	 * Función para obtener una persona.
	 * @param indice Indice al que ir.
	 * @param dato Persona devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getPersona (int indice, Persona *& dato);



	//============================================================
	/**
	 * Función para obtener la persona actual.
	 * @param dato Persona devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getPersonaIndice (Persona *& dato);



	//============================================================
	/**
	 * Función para saber si está cierta persona.
	 * @param persona Datos de la persona a buscar.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	virtual bool estaPersona (const Persona & persona);
         
	/**
	 * Función para saber si está cierta persona.
	 * @param id ID de la persona a buscar.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	virtual bool estaPersona (std::string id);



	//============================================================
	/**
	 * Función que va a agregar una persona de la lista.
	 * @param persona Persona que se va a agregar.
	 * @return Devuelve si ha sido agregad o no.
	 * @see borraPersona()
	 */
	virtual bool agregaPersona (const Persona & persona);

	/**
	 * Función que va a borrar una persona de la lista.
	 * @param persona Persona que se va a borrar.
	 * @return Devuelve si ha sido borrado o no.
	 * @see agregaPersona()
	 */
	virtual bool borraPersona (const Persona & persona);



	//============================================================
	/**
	 * Función que nos indica si el árbol está vacio o no.
	 * @return Devuelve si el árbol está vacio o no.
	 */
	virtual bool vacia (void);
	
	/**
	 * Función para borrar el contenedor.
	 */
	virtual bool nuevo (void);

};

#endif