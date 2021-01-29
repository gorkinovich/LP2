//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 03 - Grupo 03.
//----------------------------------------------------------------------
#ifndef ContenedorDelincuentesH
#define ContenedorDelincuentesH

#include "Delincuente.h"


class ContenedorDelincuentes
{
public:
        ContenedorDelincuentes () {}
        virtual ~ContenedorDelincuentes() {}
        
        // Accesores
        virtual int getTotal() const = 0;
        virtual int getNumero() const = 0;
        virtual int getIndice() const = 0;
        virtual bool getDelincuente(const Delincuente& buscado, Delincuente*& dato) = 0;
        virtual bool getDelincuente(string dni, Delincuente*& dato) = 0;
        virtual bool getDelincuente(const Cara& cara, Delincuente*& dato) = 0;
        virtual bool getDelincuente(int indice, Delincuente*& dato) = 0;
        virtual bool getDelincuenteIndice(Delincuente*& dato) = 0;

        // Modificadores.
        virtual bool setIndice(int indice) = 0;
        virtual bool agregaDelincuente(const Delincuente& delincuente) = 0;
        virtual bool borraDelincuente(const Delincuente& delincuente) = 0;

        // Consultas
        virtual bool estaDelincuente(const Delincuente& delincuente) = 0;
        virtual bool estaDelincuente(string dni) = 0;
        virtual bool estaDelincuente(const Cara& cara) = 0;

        // Guarda el contenedor en el archivo de texto salida.
        virtual bool salvaTxt(string salida) const = 0;

        // Carga el contenedor a partir de los datos almacenados en el archivo entrada.
        virtual bool cargaTxt(string entrada) = 0;

protected:
        virtual bool setTotal(int total) = 0;
        virtual bool setNumero(int numero) = 0;
};
//---------------------------------------------------------------------------
#endif
