//----------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Patrones_ControladorPersonasH
#define Patrones_ControladorPersonasH

#include "../Estructuras/ContenedorPersonas.h"
#include "../FPersonasBasico.h"
#include "Controlador.h"


const int MAX_VISTAS = 10;


/**
 * Clase para controlar el modelo de la aplicaci�n.
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
	 * Funci�n para registrar una vista.
	 * @param unaVista Vista a registrar.
	 * @param numVista N�mero de identificaci�n.
	 * @return Devuelve si se ha registrado.
	 */
	bool registrarVista (TPersonasBasico * unaVista, int & numVista);

	/**
	 * Funci�n para borrar una vista.
	 * @param numVista Vista a borrar.
	 */
	void borrarVista (int numVista);

	/**
	 * Funci�n para borrar las vistas que ya no se usan.
	 */
	void limpiarVistas (void);

	/**
	 * Funci�n para indicar que una vista est� abierta.
	 * @param numVista Numero identificador de la vista.
	 */
	virtual void vistaAbierta (int numVista);
	
	/**
	 * Funci�n para indicar que una vista est� cerrada.
	 * @param numVista Numero identificador de la vista.
	 */
	virtual void vistaCerrada (int numVista);

	/**
	 * Funci�n para registrar un modelo.
	 * @param unModelo Modelo a registrar.
	 */
	void registrarModelo (ContenedorPersonas ** unModelo);

	/**
	 * Funci�n para actualizar las vistas.
	 */
	void actualizarVistas (void);

	/**
	 * Funci�n para cargar un fichero.
	 */
    virtual bool cargar (std::string ruta);
	
	/**
	 * Funci�n para salvar un fichero.
	 */
    virtual bool salvar (std::string ruta);


	//============================================================
	/**
	 * Funci�n para obtener el tama�o total de la base de datos.
	 * @return Devuelve el n�mero total de elementos reservados.
	 * @see getNumero(), getIndice()
	 */
	virtual int getTotal (void) const;

	/**
	 * Funci�n para obtener la posici�n del primer elemento libre.
	 * @return Devuelve la posici�n del primer elemento libre.
	 * @see getTotal(), getIndice()
	 */
	virtual int getNumero (void) const;

	/**
	 * Funci�n para obtener el �ndice actual en la base de datos.
	 * @return Devuelve el �ndice actual en la base de datos.
	 * @see getTotal(), getNumero()
	 */
	virtual int getIndice (void) const;


	
	//============================================================
	/**
	 * Funci�n para establecer un nuevo valor para el total.
	 * @param total Total m�ximo de nodos que tendremos en el arbol.
	 * @return Devuelve true si ha podido cambiar el total.
	 */
    virtual bool setTotal (int total);

	/**
	 * Funci�n para establecer un nuevo valor para el indice.
	 * @param indice Posici�n en la que nos queremos situar.
	 * @return Devuelve true si ha podido cambiar el indice.
	 */
    virtual bool setIndice (int indice);



	//============================================================
	/**
	 * Funci�n para obtener una persona.
	 * @param buscado Persona al que buscar.
	 * @param dato Persona devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getPersona (const Persona & buscado, Persona *& dato);
                     
	/**
	 * Funci�n para obtener una persona.
	 * @param id ID que buscar.
	 * @param dato Persona devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getPersona (std::string id, Persona *& dato);
       
	/**
	 * Funci�n para obtener una persona.
	 * @param cara Cara que buscar.
	 * @param dato Persona devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getPersona (const Cara & cara, Persona *& dato);
       
	/**
	 * Funci�n para obtener una persona.
	 * @param indice Indice al que ir.
	 * @param dato Persona devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getPersona (int indice, Persona *& dato);



	//============================================================
	/**
	 * Funci�n para obtener la persona actual.
	 * @param dato Persona devuelto.
	 * @return Devuelve si ha sido encontrado o no.
	 */
    virtual bool getPersonaIndice (Persona *& dato);



	//============================================================
	/**
	 * Funci�n para saber si est� cierta persona.
	 * @param persona Datos de la persona a buscar.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	virtual bool estaPersona (const Persona & persona);
         
	/**
	 * Funci�n para saber si est� cierta persona.
	 * @param id ID de la persona a buscar.
	 * @return Devuelve si ha sido encontrado o no.
	 */
	virtual bool estaPersona (std::string id);



	//============================================================
	/**
	 * Funci�n que va a agregar una persona de la lista.
	 * @param persona Persona que se va a agregar.
	 * @return Devuelve si ha sido agregad o no.
	 * @see borraPersona()
	 */
	virtual bool agregaPersona (const Persona & persona);

	/**
	 * Funci�n que va a borrar una persona de la lista.
	 * @param persona Persona que se va a borrar.
	 * @return Devuelve si ha sido borrado o no.
	 * @see agregaPersona()
	 */
	virtual bool borraPersona (const Persona & persona);



	//============================================================
	/**
	 * Funci�n que nos indica si el �rbol est� vacio o no.
	 * @return Devuelve si el �rbol est� vacio o no.
	 */
	virtual bool vacia (void);
	
	/**
	 * Funci�n para borrar el contenedor.
	 */
	virtual bool nuevo (void);

};

#endif