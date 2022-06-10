/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[20];
	char codigoVuelo[10];
	char estado[20];
}Passenger;

typedef struct
{
	int id;
	char tipo[20];
}pTipo;

typedef struct
{
    int id;
    char estado[20];
}pEstado;

/// @brief Asigna una posicion de memoria en el heap a un pasajero/s y ademas inicializa los campos del pasajero en 0
/// @return devuelve la nueva posicion de memoria del pasajero, es decir devuleve una variable puntero de tipo Passenger
Passenger* Passenger_new();

/// @brief Se encarga de cargar un nuevo apsajero en el heap, y ademas asignarle un "valor distinto de 0 o NULL" a los campos del pasajero
/// @param id
/// @param nombre
/// @param apellido
/// @param precio
/// @param codigo
/// @param tipo
/// @param estado
/// @return retorna el pasajero ya cargado y con sus campos completos
Passenger* Passenger_newParametros(char* id,char* nombre,char* apellido,char* precio,char* codigo,char* tipo,char* estado);

/// @brief Harcodea un array de tipo "pEstado" y otra de tipo "pTipo"
/// @param estado array de tipo pEstado
/// @param tipo array de tipo pTipo
void HardCode_Estado_Tipo(pEstado* estado, pTipo* tipo);

/// @brief Abre un archivo y toma el valor del ultimo id existente y le suma 1 para asi devolver un nuevo id
/// @return
int GenerarId(LinkedList* pArrayListPassenger);

/// @brief Define el tipo de estado del pasajero
/// @param estadoPasajero
/// @param estado
/// @param sizeE
void DefinirEstado(char* estadoPasajero,pEstado* estado,int sizeE);

/// @brief Define el tipo de pasajero
/// @param tipoPasajero
/// @param tipo
/// @param sizeT
void DefinirTipo(char* tipoPasajero,pTipo* tipo,int sizeT);

/// @brief Ordena por id la lista de pasajeros
/// @param pArrayListPassenger
/// @param order
/// @return
int OrdenarPorId(LinkedList* pArrayListPassenger, int order);

/// @brief Compara el id de un pasajero con el de otro
/// @param PasajeroI
/// @param PasajeroJ
/// @return
int ComparaId(void* PasajeroI, void* PasajeroJ);

/// @brief Ordena la lista segun el parametro elegido
/// @param pArrayListPassenger
/// @param order
/// @param option
/// @return
int OrdenarPorParametros(LinkedList* pArrayListPassenger, int order, int option);
//COMPARACIONES//
/// @brief Compara dos pasajeros segun un criterio, el criterio es el nombre de la funcion
/// @param PasajeroI
/// @param PasajeroJ
/// @return
int ComparaPorPrecio(void* PasajeroI, void* PasajeroJ);
int CompararPorEstado(void* PasajeroI, void* PasajeroJ);
int CompararPorTipo(void* PasajeroI, void* PasajeroJ);
int CompararPorNombre(void* PasajeroI, void* PasajeroJ);

/// @brief Agrega un pasajero
/// @param id
/// @param nombre
/// @param apellido
/// @param tipoPasajero
/// @param codigoVuelo
/// @param estadoPasajero
/// @param precio
/// @param pArrayListPassenger
/// @return
int AddPassenger(int id, char*nombre, char*apellido, char*tipoPasajero, char*codigoVuelo, char*estadoPasajero, float precio,LinkedList* pArrayListPassenger);


/// @brief Elimina un pasajero
///
/// @param this
void Passenger_delete(Passenger* this);


/// @brief Muestra un pasajero
///
/// @param pasajero
void Passenger_print(Passenger* pasajero);



// set///

/// @brief  Funciones set, se encargan de designarle un valor a un campo en espesifico del pasajero, Passenger refiere a la estructura pasajeros
/// y el array refiere al dato auxiliar a cargar en el campo de la estructura que indica el nombre de la funcion, EN el caso de ID se trasnforma el char a int y en Precio de char a flotante
///
/// @param Passenger* this Se le pasa el pasajero (posicion de memoria de un pasajero)
/// @param Char* se le pasa el dato auxiliar a cargar en el campod deseado,
/// @return isOk = 0 si la operacion salio mal, isOk = 1 si salio bien
int Passenger_setId(Passenger* this,char* id);
int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_setEstado(Passenger* this,char* estadoPasajero);
int Passenger_setPrecio(Passenger* this,char* precio);

/// @brief Esta variable pide la posicion de memoria del pasajero y las variables auxiliares a la cuales se les quiere cargara el valor de uno de los campos del pasajero
/// para realizar la operacion llama a las demas funciones set, Esta funcion ayuda a ordenar el codigo.
/// @param pasajero
/// @param id
/// @param nombre
/// @param apellido
/// @param tipoPasajero
/// @param codigoVuelo
/// @param estadoPasajero
/// @param precio
/// @return isOk = 0 si la operacion salio mal, isOk = 1 si salio bien
int SetterPassenger(Passenger* pasajero, char*id, char*nombre, char*apellido, char*tipoPasajero, char*codigoVuelo, char*estadoPasajero, char* precio);


//get//
/// @brief  Funciones get, se encargan de tomar el valor de un campo espesifico de un pasajero para pasarlo a una variable auxiliar del mismo tipo
/// @param Passenger* this Se le pasa el pasajero (posicion de memoria de un pasajero)
/// @param Char*/int*/float* se pasa la variable auxiliar en donde se quiere albergar los valores del campo espesifico de un pasajero
/// @return isOk = 0 si la operacion salio mal, isOk = 1 si salio bien
int Passenger_getId(Passenger* this,int* id);
int Passenger_getNombre(Passenger* this,char* nombre);
int Passenger_getApellido(Passenger* this,char* apellido);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getEstado(Passenger* this,char* estadoPasajero);
int Passenger_getPrecio(Passenger* this,float* precio);

/// @brief Esta variable pide todas las variables auxiliares y el pasajero a cual quiere cargarle los datos de esas variables auxiliares, y llama a las funciones que hacen dicha accion
/// simplemente es una funcion que ayuda a que el codigo sea mas ordenado
/// @param pasajero
/// @param id
/// @param nombre
/// @param apellido
/// @param tipoPasajero
/// @param codigoVuelo
/// @param estadoPasajero
/// @param precio
/// @return isOk = 0 si la operacion salio mal, isOk = 1 si salio bien
int GetterPassenger(Passenger* pasajero, int*id, char*nombre, char*apellido, char*tipoPasajero, char*codigoVuelo, char*estadoPasajero, float* precio);

//Funciones Print lista//
void CabeceraPrintLista();
void PiePrintLista();

#endif /* PASSENGER_H_ */
