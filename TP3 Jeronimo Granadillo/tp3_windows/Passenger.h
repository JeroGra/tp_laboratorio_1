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

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* id,char* nombre,char* apellido,char* precio,char* codigo,char* tipo,char* estado);
void HardCode_Estado_Tipo(pEstado* estado, pTipo* tipo);
int GenerarId(LinkedList* pArrayListPassenger);
void DefinirEstado(char* estadoPasajero,pEstado* estado,int sizeE);
void DefinirTipo(char* tipoPasajero,pTipo* tipo,int sizeT);
int BuscarIdPasajero(LinkedList* pArrayListPassenger,Passenger* pasajeroAux);
int OrdenarPorId(LinkedList* pArrayListPassenger, int order);
int ComparaId(void* PasajeroI, void* PasajeroJ);
int OrdenarPorParametros(LinkedList* pArrayListPassenger, int order, int option);
int ComparaPorPrecio(void* PasajeroI, void* PasajeroJ);
int CompararPorEstado(void* PasajeroI, void* PasajeroJ);
int CompararPorTipo(void* PasajeroI, void* PasajeroJ);
int CompararPorNombre(void* PasajeroI, void* PasajeroJ);

int AddPassenger(int id, char*nombre, char*apellido, char*tipoPasajero, char*codigoVuelo, char*estadoPasajero, float precio,LinkedList* pArrayListPassenger);

int GetterPassenger(Passenger* pasajero, int*id, char*nombre, char*apellido, char*tipoPasajero, char*codigoVuelo, char*estadoPasajero, float* precio);
int SetterPassenger(Passenger* pasajero, char*id, char*nombre, char*apellido, char*tipoPasajero, char*codigoVuelo, char*estadoPasajero, char* precio);

void Passenger_delete(Passenger* this);
void Passenger_print(Passenger* pasajero);

int Passenger_setId(Passenger* this,char* id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setEstado(Passenger* this,char* estadoPasajero);
int Passenger_getEstado(Passenger* this,char* estadoPasajero);

int Passenger_setPrecio(Passenger* this,char* precio);
int Passenger_getPrecio(Passenger* this,float* precio);

#endif /* PASSENGER_H_ */
