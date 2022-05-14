#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// @brief recibe un mensaje del cual extrae un entero validad y ademas limita la cantidad de errores
/// @param mensaje mensaje que recibe de donde extraera el entero
/// @param minimo recibe un minimo para validar
/// @param maximo recibe un maximo para validar
/// @param intentos recibe cantidad de intentos que el usuario tendra
/// @param defaultInt recibe un valor default que devolvera en caso de superar el numero de intentos
/// @return devuelve el entero validado
int getIntMasIntentos(char mensaje[], int minimo, int maximo, int intentos,int defaultInt);

/// @brief recibe un mensaje del cual extrae un entero validado
/// @param mensaje mensaje que recibe de donde extraera el entero
/// @param minimo recibe un minimo para validar
/// @param maximo recibe un maximo para validar
/// @return devuelve el entero validado
int getInt(char mensaje[], int minimo, int maximo);

/// @brief Valida una cadena de caracteres
/// @param mensajeRecibido la cadena de caracteres a validar
/// @param maximo maximo de longitud que puede poseer dicha cadena
/// @return devuelve la cadena validada
int ValidacionString(char mensajeRecibido[], int maximo);

/// @brief Se encarga de pasarle un maximo de largo a una cadena de caracteres, esat cadena de caracteres recibira un maximo espesifico relacionado
/// a la cantidad de digitos que puede tener un entero, es principalmente una funcion echa para pasarle un maximo de largo a la funcion de validar cadena
/// asi la cadena que se valida luego se puede pasar a un entero
/// @param maximoNumero
/// @return devuelve el maximo de caracteres que pueden poseer la cadena
int MaximoStringInt(int maximoNumero);

/// @brief recibe un mensaje del cual extrae un dato decimal o flotante validado
/// @param mensaje mensaje de donde extrae le floatnte
/// @param minimo minimo valor a validar para el flotante
/// @param maximo maximo valor a valdiar para el flotante
/// @return devuelve el flotante validado
float getFloat(char mensaje[], int minimo, int maximo);

/// @brief Obtiene de un mensaje una cadena de caracteres
/// @param mensajeCargado variable de tipo array que se pasa por parametro donde se guardara la cadena de caracteres
/// @param mensaje mensaje de donde se extrae dicha cadena
/// @param maximo maximo de longitud que puede poseer la cadena
void getString(char mensajeCargado[], char mensaje[], int maximo);

/// @brief recibe un array donde en teoria alberga un nombre o apellido, convierte  todas las letas de ese array en letras minusculas
/// convierte la letra del indice 0 del array en una letra mayuscula
/// verifica si ubo saltos de linea para apenas encontrar uno pasar a letra mayuscula la proxima letra, esto sirve si se ingresan un doble nombre ej 'PEPE FERNANDO'
/// esta funcion toma el nombre y lo combierte en 'Pepe Fernando'
/// @param modificar es el array de caracteres a modificar
void TrasnsformarNombres(char modificar[]);

#endif /* INPUT_H_ */
