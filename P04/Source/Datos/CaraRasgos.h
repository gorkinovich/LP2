//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 04 - Grupo 03.
//----------------------------------------------------------------------
#ifndef Datos_CaraRasgosH
#define Datos_CaraRasgosH

#include <string>

/**
 * Número de rasgos que determinan una cara.
 */
const int NUM_RASGOS = 5;

/**
 * Número de posibles valores que puede tomar el tipo del pelo de una cara.
 */
const int NUM_PELO = 4;

/**
 * Número de posibles valores que puede tomar el tipo de los ojos de una cara.
 */
const int NUM_OJOS = 4;

/**
 * Número de posibles valores que puede tomar el tipo de la nariz y orejas de una cara.
 */
const int NUM_NARIZYOREJAS = 4;

/**
 * Número de posibles valores que puede tomar el tipo de la boca de una cara.
 */
const int NUM_BOCA = 4;

/**
 * Número de posibles valores que puede tomar el tipo del mentón de una cara.
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
 * Tipos de metón que pueden aparecer en una cara.
 * El primer valor representa que se desconoce el valor del rasgo.
 */
typedef enum {mentonX = 0, afeitado, barba, perilla} Menton;



/**
 * Strings asociados a los distintos tipos de pelo de una cara.
 * Las cadenas aparecen en el mismo orden que los valroes del enumerado a los
 * que se encuentran asociados.
 * @see Pelo
 */
const std::string STRINGS_PELO[NUM_PELO] = {"desconocido", "largo", "raya", "raso"};

/**
 * Strings asociados a los distintos tipos de ojos de una cara.
 * Las cadenas aparecen en el mismo orden que los valroes del enumerado a los
 * que se encuentran asociados.
 * @see Ojos
 */
const std::string STRINGS_OJOS[NUM_OJOS] = {"desconocido", "redondos", "gafas", "rasgados"};

/**
 * Strings asociados a los distintos tipos de nariz y orejas de una cara.
 * Las cadenas aparecen en el mismo orden que los valroes del enumerado a los
 * que se encuentran asociados.
 * @see NarizYOrejas
 */
const std::string STRINGS_NARIZYOREJAS[NUM_NARIZYOREJAS] = {"desconocido", "gancho", "redonda", "chata"};

/**
 * Strings asociados a los distintos tipos de boca de una cara.
 * Las cadenas aparecen en el mismo orden que los valroes del enumerado a los
 * que se encuentran asociados.
 * @see Boca
 */
const std::string STRINGS_BOCA[NUM_BOCA] = {"desconocido", "larga", "pequeña", "delgada"};

/**
 * Strings asociados a los distintos tipos de mentón de una cara.
 * Las cadenas aparecen en el mismo orden que los valroes del enumerado a los
 * que se encuentran asociados.
 * @see Menton
 */
const std::string STRINGS_MENTON[NUM_MENTON] = {"desconocido", "afeitado", "barba", "perilla"};




/**
 * Da la representación como string del pelo argumento.
 * La función asigna al rasgo unPelo el string de STRINGS_PELO que se encuentra
 * en la misma posición que unPelo en su enumerado.
 * @param unPelo Pelo El rasgo a convertir.
 * @result string La representación como string del rasgo.
 */
std::string getPeloAsString (Pelo unPelo);

/**
 * Obtiene el valor del enumerado del pelo representado por la cadena de caracteres.
 * La función busca el nombre en STRINGS_PELO y en caso de encontrarlo devuelve
 * en unPelo el valor del enumerado que se encuentra en la misma posición que
 * nombre en STRINGS_PELO.
 * @param nombre string El nombre del valor a convertir.
 * @param unPelo Pelo El rasgo que corresponde al nombre.
 * @result bool <UL><LI> true El nombre corresponde a un valor del enumerado Pelo.
 *                  <LI> false e.o.c. (i.e. en otro caso).</UL>
 */
bool getPeloFromString (std::string nombre, Pelo& unPelo);

/**
 * Devuelve la representación gráfica del rasgo como un string.
 * @param unPelo Pelo El rasgo a convertir.
 * @result string La representación gráfica del rasgo.
 */
std::string dibujaPelo (Pelo unPelo);




/**
 * Da la representación como string del ojos argumento.
 * La función asigna al rasgo unosOjos el string de STRINGS_OJOS que se encuentra
 * en la misma posición que unosOjos en su enumerado.
 * @param unosOjos Ojos El rasgo a convertir.
 * @result string La representación como string del rasgo.
 */
std::string getOjosAsString (Ojos unosOjos);

/**
 * Obtiene el valor del enumerado del ojos representado por la cadena de caracteres.
 * La función busca el nombre en STRINGS_OJOS y en caso de encontrarlo devuelve
 * en unosOjos el valor del enumerado que se encuentra en la misma posición que
 * nombre en STRINGS_OJOS.
 * @param nombre string El nombre del valor a convertir.
 * @param unosOjos Ojos El rasgo que corresponde al nombre.
 * @result bool <UL><LI> true El nombre corresponde a un valor del enumerado Ojos.
 *                  <LI> false e.o.c. (i.e. en otro caso).</UL>
 */
bool getOjosFromString (std::string nombre, Ojos & unosOjos);

/**
 * Devuelve la representación gráfica del rasgo como un string.
 * @param unosOjos Ojos El rasgo a convertir.
 * @result string La representación gráfica del rasgo.
 */
std::string dibujaOjos (Ojos unosOjos);




/**
 * Da la representación como string de la nariz y orejas argumento.
 * La función asigna al rasgo unaNarizYOrejas el string de STRINGS_NARIZYOREJAS
 * que se encuentra en la misma posición que unaNarizYOrejas en su enumerado.
 * @param unaNarizYOrejas NarizYOrejas El rasgo a convertir.
 * @result string La representación como string del rasgo.
 */
std::string getNarizYOrejasAsString (NarizYOrejas unaNarizYOrejas);

/**
 * Obtiene el valor del enumerado de la nariz y orejas representado por la cadena de caracteres.
 * La función busca el nombre en STRINGS_NARIZYOREJAS y en caso de encontrarlo devuelve
 * en unaNarizYOrejas el valor del enumerado que se encuentra en la misma posición que
 * nombre en STRINGS_NARIZYOREJAS.
 * @param nombre string El nombre del valor a convertir.
 * @param unaNarizYOrejas NarizYOrejas El rasgo que corresponde al nombre.
 * @result bool <UL><LI> true El nombre corresponde a un valor del enumerado NarizYOrejas.
 *                  <LI> false e.o.c. (i.e. en otro caso).</UL>
 */
bool getNarizYOrejasFromString (std::string nombre, NarizYOrejas & unaNarizYOrejas);

/**
 * Devuelve la representación gráfica del rasgo como un string.
 * @param unaNarizYOrejas NarizYOrejas El rasgo a convertir.
 * @result string La representación gráfica del rasgo.
 */
std::string dibujaNarizYOrejas (NarizYOrejas unaNarizYOrejas);




/**
 * Da la representación como string de la boca argumento.
 * La función asigna al rasgo unaBoca el string de STRINGS_BOCA que se encuentra
 * en la misma posición que unaBoca en su enumerado.
 * @param unaBoca Boca El rasgo a convertir.
 * @result string La representación como string del rasgo.
 */
std::string getBocaAsString (Boca unaBoca);

/**
 * Obtiene el valor del enumerado del boca representado por la cadena de caracteres.
 * La función busca el nombre en STRINGS_BOCA y en caso de encontrarlo devuelve
 * en unaBoca el valor del enumerado que se encuentra en la misma posición que
 * nombre en STRINGS_BOCA.
 * @param nombre string El nombre del valor a convertir.
 * @param unaBoca Boca El rasgo que corresponde al nombre.
 * @result bool <UL><LI> true El nombre corresponde a un valor del enumerado Boca.
 *                  <LI> false e.o.c. (i.e. en otro caso).</UL>
 */
bool getBocaFromString (std::string nombre, Boca & unaBoca);

/**
 * Devuelve la representación gráfica del rasgo como un string.
 * @param unaBoca Boca El rasgo a convertir.
 * @result string La representación gráfica del rasgo.
 */
std::string dibujaBoca (Boca unaBoca);




/**
 * Da la representación como string del mentón argumento.
 * La función asigna al rasgo unMenton el string de STRINGS_MENTON que se encuentra
 * en la misma posición que unMenton en su enumerado.
 * @param unMenton Menton El rasgo a convertir.
 * @result string La representación como string del rasgo.
 */
std::string getMentonAsString (Menton unMenton);

/**
 * Obtiene el valor del enumerado del mentón representado por la cadena de caracteres.
 * La función busca el nombre en STRINGS_MENTON y en caso de encontrarlo devuelve
 * en unMenton el valor del enumerado que se encuentra en la misma posición que
 * nombre en STRINGS_MENTON.
 * @param nombre string El nombre del valor a convertir.
 * @param unMenton Menton El rasgo que corresponde al nombre.
 * @result bool <UL><LI> true El nombre corresponde a un valor del enumerado Menton.
 *                  <LI> false e.o.c. (i.e. en otro caso).</UL>
 */
bool getMentonFromString (std::string nombre, Menton & unMenton);

/**
 * Devuelve la representación gráfica del rasgo como un string.
 * @param unMenton Menton El rasgo a convertir.
 * @result string La representación gráfica del rasgo.
 */
std::string dibujaMenton (Menton unMenton);




/**
 * Convierte un valor introducido desde un RadioGroup en el enumerado.
 * @param value Valor interno del RadioGroup.
 * @result El valor entero convertido al enumerado.
 */
Pelo getPeloFromRadioGroup (int value);

/**
 * Convierte un valor introducido desde un RadioGroup en el enumerado.
 * @param value Valor interno del RadioGroup.
 * @result El valor entero convertido al enumerado.
 */
Ojos getOjosFromRadioGroup (int value);

/**
 * Convierte un valor introducido desde un RadioGroup en el enumerado.
 * @param value Valor interno del RadioGroup.
 * @result El valor entero convertido al enumerado.
 */
NarizYOrejas getNarizYOrejasFromRadioGroup (int value);

/**
 * Convierte un valor introducido desde un RadioGroup en el enumerado.
 * @param value Valor interno del RadioGroup.
 * @result El valor entero convertido al enumerado.
 */
Boca getBocaFromRadioGroup (int value);

/**
 * Convierte un valor introducido desde un RadioGroup en el enumerado.
 * @param value Valor interno del RadioGroup.
 * @result El valor entero convertido al enumerado.
 */
Menton getMentonFromRadioGroup (int value);


#endif
