//----------------------------------------------------------------------
// Gorka Su�rez Garc�a - Ing. Tec. Inf. de Gesti�n 2� B.
// Pr�ctica 02 - Grupo 03.
//----------------------------------------------------------------------
#ifndef CaraRasgosH
#define CaraRasgosH

#include <iostream>
#include <string>
using namespace std;

/**
 * N�mero de rasgos que determinan una cara.
 */
const int NUM_RASGOS = 5;

/**
 * N�mero de posibles valores que puede tomar el tipo del pelo de una cara.
 */
const int NUM_PELO = 4;

/**
 * N�mero de posibles valores que puede tomar el tipo de los ojos de una cara.
 */
const int NUM_OJOS = 4;

/**
 * N�mero de posibles valores que puede tomar el tipo de la nariz y orejas de una cara.
 */
const int NUM_NARIZYOREJAS = 4;

/**
 * N�mero de posibles valores que puede tomar el tipo de la boca de una cara.
 */
const int NUM_BOCA = 4;

/**
 * N�mero de posibles valores que puede tomar el tipo del ment�n de una cara.
 */
const int NUM_MENTON = 4;



/**
 * Tipos de pelo que pueden aparecer en una cara.
 * El primer valor representa que se desconoce el valor del rasgo.
 */
typedef enum {peloX = 0, largo, raya, raso} Pelo;

/**
 * Tipos de ojos que pueden aparecer en una cara.
 * El primer valor representa que se desconoce el valor del rasgo.
 */
typedef enum {ojosX = 0, redondos, gafas, rasgados} Ojos;

/**
 * Tipos de nariz y orejas que pueden aparecer en una cara.
 * El primer valor representa que se desconoce el valor del rasgo.
 */
typedef enum {narizYOrejasX = 0, gancho, redonda, chata} NarizYOrejas;

/**
 * Tipos de boca que pueden aparecer en una cara.
 * El primer valor representa que se desconoce el valor del rasgo.
 */
typedef enum {bocaX = 0, larga, pequenna, delgada} Boca;

/**
 * Tipos de met�n que pueden aparecer en una cara.
 * El primer valor representa que se desconoce el valor del rasgo.
 */
typedef enum {mentonX = 0, afeitado, barba, perilla} Menton;



/**
 * Strings asociados a los distintos tipos de pelo de una cara.
 * Las cadenas aparecen en el mismo orden que los valroes del enumerado a los
 * que se encuentran asociados.
 * @see Pelo
 */
const string STRINGS_PELO[NUM_PELO] = {"desconocido", "largo", "raya", "raso"};

/**
 * Strings asociados a los distintos tipos de ojos de una cara.
 * Las cadenas aparecen en el mismo orden que los valroes del enumerado a los
 * que se encuentran asociados.
 * @see Ojos
 */
const string STRINGS_OJOS[NUM_OJOS] = {"desconocido", "redondos", "gafas", "rasgados"};

/**
 * Strings asociados a los distintos tipos de nariz y orejas de una cara.
 * Las cadenas aparecen en el mismo orden que los valroes del enumerado a los
 * que se encuentran asociados.
 * @see NarizYOrejas
 */
const string STRINGS_NARIZYOREJAS[NUM_NARIZYOREJAS] = {"desconocido", "gancho", "redonda", "chata"};

/**
 * Strings asociados a los distintos tipos de boca de una cara.
 * Las cadenas aparecen en el mismo orden que los valroes del enumerado a los
 * que se encuentran asociados.
 * @see Boca
 */
const string STRINGS_BOCA[NUM_BOCA] = {"desconocido", "larga", "peque�a", "delgada"};

/**
 * Strings asociados a los distintos tipos de ment�n de una cara.
 * Las cadenas aparecen en el mismo orden que los valroes del enumerado a los
 * que se encuentran asociados.
 * @see Menton
 */
const string STRINGS_MENTON[NUM_MENTON] = {"desconocido", "afeitado", "barba", "perilla"};




/**
 * Da la representaci�n como string del pelo argumento.
 * La funci�n asigna al rasgo unPelo el string de STRINGS_PELO que se encuentra
 * en la misma posici�n que unPelo en su enumerado.
 * @param unPelo Pelo El rasgo a convertir.
 * @result string La representaci�n como string del rasgo.
 */
string getPeloAsString (Pelo unPelo);

/**
 * Obtiene el valor del enumerado del pelo representado por la cadena de caracteres.
 * La funci�n busca el nombre en STRINGS_PELO y en caso de encontrarlo devuelve
 * en unPelo el valor del enumerado que se encuentra en la misma posici�n que
 * nombre en STRINGS_PELO.
 * @param nombre string El nombre del valor a convertir.
 * @param unPelo Pelo El rasgo que corresponde al nombre.
 * @result bool <UL><LI> true El nombre corresponde a un valor del enumerado Pelo.
 *                  <LI> false e.o.c. (i.e. en otro caso).</UL>
 */
bool getPeloFromString (string nombre, Pelo& unPelo);

/**
 * Devuelve la representaci�n gr�fica del rasgo como un string.
 * @param unPelo Pelo El rasgo a convertir.
 * @result string La representaci�n gr�fica del rasgo.
 */
string dibujaPelo (Pelo unPelo);




/**
 * Da la representaci�n como string del ojos argumento.
 * La funci�n asigna al rasgo unosOjos el string de STRINGS_OJOS que se encuentra
 * en la misma posici�n que unosOjos en su enumerado.
 * @param unosOjos Ojos El rasgo a convertir.
 * @result string La representaci�n como string del rasgo.
 */
string getOjosAsString (Ojos unosOjos);

/**
 * Obtiene el valor del enumerado del ojos representado por la cadena de caracteres.
 * La funci�n busca el nombre en STRINGS_OJOS y en caso de encontrarlo devuelve
 * en unosOjos el valor del enumerado que se encuentra en la misma posici�n que
 * nombre en STRINGS_OJOS.
 * @param nombre string El nombre del valor a convertir.
 * @param unosOjos Ojos El rasgo que corresponde al nombre.
 * @result bool <UL><LI> true El nombre corresponde a un valor del enumerado Ojos.
 *                  <LI> false e.o.c. (i.e. en otro caso).</UL>
 */
bool getOjosFromString (string nombre, Ojos & unosOjos);

/**
 * Devuelve la representaci�n gr�fica del rasgo como un string.
 * @param unosOjos Ojos El rasgo a convertir.
 * @result string La representaci�n gr�fica del rasgo.
 */
string dibujaOjos (Ojos unosOjos);




/**
 * Da la representaci�n como string de la nariz y orejas argumento.
 * La funci�n asigna al rasgo unaNarizYOrejas el string de STRINGS_NARIZYOREJAS
 * que se encuentra en la misma posici�n que unaNarizYOrejas en su enumerado.
 * @param unaNarizYOrejas NarizYOrejas El rasgo a convertir.
 * @result string La representaci�n como string del rasgo.
 */
string getNarizYOrejasAsString (NarizYOrejas unaNarizYOrejas);

/**
 * Obtiene el valor del enumerado de la nariz y orejas representado por la cadena de caracteres.
 * La funci�n busca el nombre en STRINGS_NARIZYOREJAS y en caso de encontrarlo devuelve
 * en unaNarizYOrejas el valor del enumerado que se encuentra en la misma posici�n que
 * nombre en STRINGS_NARIZYOREJAS.
 * @param nombre string El nombre del valor a convertir.
 * @param unaNarizYOrejas NarizYOrejas El rasgo que corresponde al nombre.
 * @result bool <UL><LI> true El nombre corresponde a un valor del enumerado NarizYOrejas.
 *                  <LI> false e.o.c. (i.e. en otro caso).</UL>
 */
bool getNarizYOrejasFromString (string nombre, NarizYOrejas & unaNarizYOrejas);

/**
 * Devuelve la representaci�n gr�fica del rasgo como un string.
 * @param unaNarizYOrejas NarizYOrejas El rasgo a convertir.
 * @result string La representaci�n gr�fica del rasgo.
 */
string dibujaNarizYOrejas (NarizYOrejas unaNarizYOrejas);




/**
 * Da la representaci�n como string de la boca argumento.
 * La funci�n asigna al rasgo unaBoca el string de STRINGS_BOCA que se encuentra
 * en la misma posici�n que unaBoca en su enumerado.
 * @param unaBoca Boca El rasgo a convertir.
 * @result string La representaci�n como string del rasgo.
 */
string getBocaAsString (Boca unaBoca);

/**
 * Obtiene el valor del enumerado del boca representado por la cadena de caracteres.
 * La funci�n busca el nombre en STRINGS_BOCA y en caso de encontrarlo devuelve
 * en unaBoca el valor del enumerado que se encuentra en la misma posici�n que
 * nombre en STRINGS_BOCA.
 * @param nombre string El nombre del valor a convertir.
 * @param unaBoca Boca El rasgo que corresponde al nombre.
 * @result bool <UL><LI> true El nombre corresponde a un valor del enumerado Boca.
 *                  <LI> false e.o.c. (i.e. en otro caso).</UL>
 */
bool getBocaFromString (string nombre, Boca & unaBoca);

/**
 * Devuelve la representaci�n gr�fica del rasgo como un string.
 * @param unaBoca Boca El rasgo a convertir.
 * @result string La representaci�n gr�fica del rasgo.
 */
string dibujaBoca (Boca unaBoca);




/**
 * Da la representaci�n como string del ment�n argumento.
 * La funci�n asigna al rasgo unMenton el string de STRINGS_MENTON que se encuentra
 * en la misma posici�n que unMenton en su enumerado.
 * @param unMenton Menton El rasgo a convertir.
 * @result string La representaci�n como string del rasgo.
 */
string getMentonAsString (Menton unMenton);

/**
 * Obtiene el valor del enumerado del ment�n representado por la cadena de caracteres.
 * La funci�n busca el nombre en STRINGS_MENTON y en caso de encontrarlo devuelve
 * en unMenton el valor del enumerado que se encuentra en la misma posici�n que
 * nombre en STRINGS_MENTON.
 * @param nombre string El nombre del valor a convertir.
 * @param unMenton Menton El rasgo que corresponde al nombre.
 * @result bool <UL><LI> true El nombre corresponde a un valor del enumerado Menton.
 *                  <LI> false e.o.c. (i.e. en otro caso).</UL>
 */
bool getMentonFromString (string nombre, Menton & unMenton);

/**
 * Devuelve la representaci�n gr�fica del rasgo como un string.
 * @param unMenton Menton El rasgo a convertir.
 * @result string La representaci�n gr�fica del rasgo.
 */
string dibujaMenton (Menton unMenton);



#endif
