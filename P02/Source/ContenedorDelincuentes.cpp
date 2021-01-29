//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 02 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "ContenedorDelincuentes.h"
#pragma package(smart_init)


ContenedorDelincuentes::ContenedorDelincuentes ()
{
	this->delincuentes = NULL;

	this->total  = 0;
	this->numero = 0;
	this->indice = 0;
}


ContenedorDelincuentes::ContenedorDelincuentes (int tamanno)
{
	this->delincuentes = new Delincuente[tamanno];

	if(this->delincuentes == NULL)
		this->total  = 0;
	else
		this->total  = tamanno;

	this->numero = 0;
	this->indice = 0;
}


ContenedorDelincuentes::ContenedorDelincuentes (const ContenedorDelincuentes & contenedor)
{
	this->delincuentes = NULL;
	(*this) = contenedor;
}


ContenedorDelincuentes & ContenedorDelincuentes::operator = (const ContenedorDelincuentes & contenedor)
{
	if(this->total >= contenedor.total)
	{
		this->numero = contenedor.numero;
		this->indice = contenedor.indice;

		for(int i = 0; i < contenedor.total; ++i)
		{
			this->delincuentes[i] = contenedor.delincuentes[i];
		}
	}
	else
	{
		if(this->delincuentes != NULL)
		{
			delete [] this->delincuentes;
		}

		this->delincuentes = new Delincuente[contenedor.total];

		if(this->delincuentes == NULL)
		{
			this->total  = 0;
			this->numero = 0;
			this->indice = 0;
		}
		else
		{
			this->total  = contenedor.total;
			this->numero = contenedor.numero;
			this->indice = contenedor.indice;

			for(int i = 0; i < this->total; ++i)
			{
				this->delincuentes[i] = contenedor.delincuentes[i];
			}
		}
	}

	return (*this);
}


ContenedorDelincuentes::~ContenedorDelincuentes ()
{
	if(this->delincuentes != NULL)
	{
		delete [] this->delincuentes;
		this->delincuentes = NULL;
	}

	this->total  = 0;
	this->numero = 0;
	this->indice = 0;
}


int ContenedorDelincuentes::findDelincuente (const string & nombre)
{
	int i, c, j;

	i = 0;
	j = this->numero - 1;

	while(i <= j)
	{
		c = (i + j) / 2;

		if(this->delincuentes[c].getNombre() == nombre)
		{
			return c;
		}
		else
		{
			if(this->delincuentes[c].getNombre() < nombre)
			{
				i = c + 1;
			}
			else
			{
				j = c - 1;
			}
		}
	}

	return -1;
}

    
int ContenedorDelincuentes::findDelincuente (const Cara & cara)
{
	for(int i = 0; i < this->numero; ++i)
	{
		if(this->delincuentes[i].getCara() == cara)
		{
			return i;
		}
	}

	return -1;
}


bool ContenedorDelincuentes::getDelincuente (string nombre, Delincuente & delincuente)
{
	if(this->numero > 0)
	{
		int index = this->findDelincuente(nombre);

		if(index > -1)
		{
			delincuente = this->delincuentes[index];
			return true;
		}
	}

	return false;
}


bool ContenedorDelincuentes::getDelincuente (Cara cara, Delincuente & delincuente)
{     
	for(int i = 0; i < this->numero; ++i)
	{
		if(this->delincuentes[i].getCara() == cara)
		{
			delincuente = this->delincuentes[i];
			return true;
		}
	}

	return false;
}


bool ContenedorDelincuentes::estaDelincuente (const string & nombre)
{
	return (this->findDelincuente(nombre) > -1);
}


bool ContenedorDelincuentes::estaDelincuente (const Delincuente & delincuente)
{
	return (this->findDelincuente(delincuente.getNombre()) > -1);
}


bool ContenedorDelincuentes::agregaDelincuente (const Delincuente & delincuente)
{
   int index = this->findDelincuente(delincuente.getNombre());

   if(index > -1)
	{
		this->delincuentes[index] = delincuente;

      return true;
	}
   else
   {
   	if(this->numero < this->total)
	   {
			index = 0;

            while((index < this->numero) && (this->delincuentes[index] <= delincuente))
                ++index;

            if(index < this->numero)
            {
                for(int i = this->numero; i > index; --i)
                    this->delincuentes[i] = this->delincuentes[i - 1];
            }
                
            this->numero++;

			this->delincuentes[index] = delincuente;
            this->indice = index;

         return true;
		}
	}

	return false;
}


bool ContenedorDelincuentes::borraDelincuente (string & nombre)
{
	if(this->numero > 0)
	{
		int index = this->findDelincuente(nombre);

		if(index > -1)
		{
			this->numero--;

			for(int i = index; i < this->numero; ++i)
			{
				this->delincuentes[i] = this->delincuentes[i + 1];
			}

			return true;
		}
	}

	return false;
}


bool ContenedorDelincuentes::posicionar (int indice)
{
	if((0 <= indice) && (indice < this->numero) && (indice < this->total))
	{
		this->indice = indice;
        return true;
	}
	else
	{
		return false;
	}
}


bool ContenedorDelincuentes::getActual (Delincuente & delincuente)
{
	if((this->total > 0) && (this->numero > 0))
	{
		delincuente = this->delincuentes[this->indice];
		return true;
	}
	else
	{
		return false;
	}
}


bool ContenedorDelincuentes::salvaTXT (const string & salida) const
{
	ofstream file;

	file.open(salida.c_str(), ios::out);
	if(file.is_open())
	{
		for(int i = 0; i < this->numero; ++i)
		{
			if(this->delincuentes[i].salvaTXT(file) == false)
			{
				file.close();
				return false;
			}

            if(i < (this->numero - 1)) file << endl;
		}

		file.close();
		return true;
	}
	else
	{
		return false;
	}
}


bool ContenedorDelincuentes::cargaTXT (const string & entrada)
{
	if(this->total <= 0)
	{
		return false;
	}

	ifstream file;

	file.open(entrada.c_str(), ios::in);
	if(file.is_open())
	{
		Delincuente delincuente;
		this->numero = 0;
        this->indice = 0;
        char zero;

		while(!file.eof())
        {
			if(this->numero < this->total)
			{
				if(delincuente.cargaTXT(file) == false)
				{
					file.close();
					return false;
				}

				this->delincuentes[this->numero] = delincuente;
				this->numero++;

                file.get(zero);
			}
			else
			{
				file.close();
				return false;
			}
		}

		file.close();
		return true;
	}
	else
	{
		return false;
	}
}