#include "LinkedList.h"
#include "Passenger.h"
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger,pEstado* estado,int sizeE,pTipo* tipo,int sizeT);
int controller_editPassenger(LinkedList* pArrayListPassenger,pEstado* estado,int sizeE,pTipo* tipo,int sizeT);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
int BuscarIdPasajero(LinkedList* pArrayListPassenger,Passenger* pasajeroAux);
int obtenerIndicePasajero(LinkedList* pArrayListPassenger,Passenger* pasajeroAux,int len, int idAux);

