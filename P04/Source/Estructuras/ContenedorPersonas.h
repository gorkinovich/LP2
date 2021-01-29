//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Estructuras_ContenedorPersonasH
#define Estructuras_ContenedorPersonasH

#include "../Datos/Persona.h"


class ContenedorPersonas
{
public:
        ContenedorPersonas () {}
        virtual ~ContenedorPersonas() {}
        

        virtual int getTotal  (void) const = 0;
        virtual int getNumero (void) const = 0;
        virtual int getIndice (void) const = 0;


        virtual bool setTotal  (int total) = 0;
        virtual bool setIndice (int indice) = 0;


		virtual bool getPersona (const Persona & buscado, Persona *& dato) = 0;
		virtual bool getPersona (std::string id, Persona *& dato) = 0;
		virtual bool getPersona (const Cara & cara, Persona *& dato) = 0;
		virtual bool getPersona (int indice, Persona *& dato) = 0;
		

		virtual bool getPersonaIndice (Persona *& dato) = 0;


        virtual bool estaPersona (const Persona & persona) = 0;
        virtual bool estaPersona (std::string id) = 0;


        virtual bool agregaPersona (const Persona & persona) = 0;
        virtual bool borraPersona  (const Persona & persona) = 0;


		virtual bool vacia (void) = 0;
		virtual bool nuevo (void) = 0;


protected:
        virtual bool setNumero(int numero) = 0;
};
//---------------------------------------------------------------------------
#endif
