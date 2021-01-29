//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 02 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "CaraRasgos.h"
#pragma package(smart_init)


string getPeloAsString (Pelo unPelo)
{
    switch (unPelo)
    {
        case largo:
            return STRINGS_PELO[largo];
        case raya:
            return STRINGS_PELO[raya];
        case raso:
            return STRINGS_PELO[raso];
        default:
            return STRINGS_PELO[peloX];
    }
}

bool getPeloFromString (string nombre, Pelo & unPelo)
{
	if(nombre == STRINGS_PELO[largo])
	{
		unPelo = largo;
		return true;
	}
	else if(nombre == STRINGS_PELO[raya])
	{
		unPelo = raya;
		return true;
	}
	else if(nombre == STRINGS_PELO[raso])
	{
		unPelo = raso;
		return true;
	}
	else if(nombre == STRINGS_PELO[peloX])
	{
		unPelo = peloX;
		return true;
	}
	else
	{
		unPelo = peloX;
		return false;
	}
}

string dibujaPelo (Pelo unPelo)
{
    switch (unPelo)
    {
        case largo:
            return "WWWWWWWWW";
        case raya:
            return "\\\\\\//////";
        case raso:
            return "|'''''''|";
        default:
            return "---------";
    }
}


//----------------------------------------------------------------------


string getOjosAsString (Ojos unosOjos)
{
    switch (unosOjos)
    {
        case redondos:
            return STRINGS_OJOS[redondos];
        case gafas:
            return STRINGS_OJOS[gafas];
        case rasgados:
            return STRINGS_OJOS[rasgados];
        default:
            return STRINGS_OJOS[peloX];
    }
}

bool getOjosFromString (string nombre, Ojos & unosOjos)
{
	if(nombre == STRINGS_OJOS[redondos])
	{
		unosOjos = redondos;
		return true;
	}
	else if(nombre == STRINGS_OJOS[gafas])
	{
		unosOjos = gafas;
		return true;
	}
	else if(nombre == STRINGS_OJOS[rasgados])
	{
		unosOjos = rasgados;
		return true;
	}
	else if(nombre == STRINGS_OJOS[ojosX])
	{
		unosOjos = ojosX;
		return true;
	}
	else
	{
		unosOjos = ojosX;
		return false;
	}
}

string dibujaOjos (Ojos unosOjos)
{
    switch (unosOjos)
    {
        case redondos:
            return "|  O O  |";
        case gafas:
            return "|-(. .)-|";
        case rasgados:
            return "|  \\ /  |";
        default:
            return "---------";
    }
}


//----------------------------------------------------------------------


string getNarizYOrejasAsString (NarizYOrejas unaNarizYOrejas)
{
    switch (unaNarizYOrejas)
    {
        case gancho:
            return STRINGS_NARIZYOREJAS[gancho];
        case redonda:
            return STRINGS_NARIZYOREJAS[redonda];
        case chata:
            return STRINGS_NARIZYOREJAS[chata];
        default:
            return STRINGS_NARIZYOREJAS[narizYOrejasX];
    }
}

bool getNarizYOrejasFromString (string nombre, NarizYOrejas & unaNarizYOrejas)
{
	if(nombre == STRINGS_NARIZYOREJAS[gancho])
	{
		unaNarizYOrejas = gancho;
		return true;
	}
	else if(nombre == STRINGS_NARIZYOREJAS[redonda])
	{
		unaNarizYOrejas = redonda;
		return true;
	}
	else if(nombre == STRINGS_NARIZYOREJAS[chata])
	{
		unaNarizYOrejas = chata;
		return true;
	}
	else if(nombre == STRINGS_NARIZYOREJAS[narizYOrejasX])
	{
		unaNarizYOrejas = narizYOrejasX;
		return true;
	}
	else
	{
		unaNarizYOrejas = narizYOrejasX;
		return false;
	}
}

string dibujaNarizYOrejas (NarizYOrejas unaNarizYOrejas)
{
    switch (unaNarizYOrejas)
    {
        case gancho:
            return "@   J   @";
        case redonda:
            return "¿   o   ¿";
        case chata:
            return "<   -   >";
        default:
            return "---------";
    }
}


//----------------------------------------------------------------------


string getBocaAsString (Boca unaBoca)
{
    switch (unaBoca)
    {
        case larga:
            return STRINGS_BOCA[larga];
        case pequenna:
            return STRINGS_BOCA[pequenna];
        case delgada:
            return STRINGS_BOCA[delgada];
        default:
            return STRINGS_BOCA[bocaX];
    }
}

bool getBocaFromString (string nombre, Boca & unaBoca)
{
	if(nombre == STRINGS_BOCA[larga])
	{
		unaBoca = larga;
		return true;
	}
	else if(nombre == STRINGS_BOCA[pequenna])
	{
		unaBoca = pequenna;
		return true;
	}
	else if(nombre == STRINGS_BOCA[delgada])
	{
		unaBoca = delgada;
		return true;
	}
	else if(nombre == STRINGS_BOCA[bocaX])
	{
		unaBoca = bocaX;
		return true;
	}
	else
	{
		unaBoca = bocaX;
		return false;
	}
}

string dibujaBoca (Boca unaBoca)
{
    switch (unaBoca)
    {
        case larga:
            return "|  ===  |";
        case pequenna:
            return "|   -   |";
        case delgada:
            return "|  ---  |";
        default:
            return "---------";
    }
}


//----------------------------------------------------------------------


string getMentonAsString (Menton unMenton)
{
    switch (unMenton)
    {
        case afeitado:
            return STRINGS_MENTON[afeitado];
        case barba:
            return STRINGS_MENTON[barba];
        case perilla:
            return STRINGS_MENTON[perilla];
        default:
            return STRINGS_MENTON[mentonX];
    }
}

bool getMentonFromString (string nombre, Menton & unMenton)
{
	if(nombre == STRINGS_MENTON[afeitado])
	{
		unMenton = afeitado;
		return true;
	}
	else if(nombre == STRINGS_MENTON[barba])
	{
		unMenton = barba;
		return true;
	}
	else if(nombre == STRINGS_MENTON[perilla])
	{
		unMenton = perilla;
		return true;
	}
	else if(nombre == STRINGS_MENTON[mentonX])
	{
		unMenton = mentonX;
		return true;
	}
	else
	{
		unMenton = mentonX;
		return false;
	}
}

string dibujaMenton (Menton unMenton)
{
    switch (unMenton)
    {
        case afeitado:
            return " \\_____/ ";
        case barba:
            return " ####### ";
        case perilla:
            return " \\__#__/ ";
        default:
            return "---------";
    }
}