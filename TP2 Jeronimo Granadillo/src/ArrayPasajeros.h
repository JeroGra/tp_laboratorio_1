#ifndef ARRAYPASAJEROS_H_
#define ARRAYPASAJEROS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPasajeros.h"
#include "Input.h"
//Estados de vuelo:
#define ACTIVO 1
#define EN_TRAMITE 0
#define FINALIZADO 2
//Esta vacio:
#define TRUE 0
#define FALSE -1
//Tipos de pasajeros:
#define NORMAL 0
#define BUSINESS 1
#define ROYAL 2

typedef struct{
	int id;
	char estado[20];
}eEstadoVuelo;
typedef struct{
	int idTipo;
	char estado[20];
}eTipoPasajero;
typedef struct{
	int id;
	char name[51];
	char lastname[51];
	float price;
	char flycode[10];
	int typePassenger;
	int status;
	int isEmpty;
}Passenger;
/// Hardcodea una lista de pasajeros
/// @param se le pasa como parametro el array listaPsajeros de tipo Passenger
void Hradcode(Passenger listaPasajeros[]);

/// @brief Ordena los id de listaPasajeros de mayor a menor
/// @param se le pasa como parametro el array listaPsajeros de tipo Passenger
/// @param se le pasa el tamaño total del vector/array listaPsajeros
void OrdenarPorIdMayor(Passenger listaPasajeros[],int size);

/// @brief Muestra la lista de Tipos de pasajeros "ROYAL,ESTANDAR...etc"
/// @param se le pasa como parametro el array estadoPasajero de tipo eTipoPasajero
/// @param se le pasa el tamaño total del vector/array estadoPasajero
void MostrarListaTipoPasajero(eTipoPasajero estadoPasajero[], int sizeTipo);

/// @brief Muestra la lista de tipos de estados del vuelo "ACTIVO,EN TRAMITE...etc"
/// @param se le pasa como parametro el array estadoVuelo de tipo eEstadoVuelo
/// @param se le pasa el tamaño total del vector/array estadoVuelo
void MostrarListaEstado(eEstadoVuelo estadoVuelo[], int sizeV);

/// @brief  Ordena Por id las lista de tipos de pasajeros
/// @param se le pasa como parametro el array estadoPasajero de tipo eTipoPasajero
/// @param se le pasa el tamaño total del vector/array estadoPasajero
void OrdenarPorIdTipo(eTipoPasajero estadoPasajero[], int sizeTipo);

/// @brief Muestra toda la informacio de un pasajero dado de alta
/// @param se le pasa como parametro una posicion de el array listaPsajeros de tipo Passenger
/// /// @param se le pasa como parametro una posicion de el array estadoPasajero de tipo eTipoPasajero
/// /// @param se le pasa como parametro una posicion de el array estadoV de tipo eEstadoVuelo
void PrintPassenger(Passenger listaPasajeros,eTipoPasajero estadoPasajero,eEstadoVuelo estadoV);

/// @brief Alberga un submenu de la opcion 4 del menu principal
/// @param se le pasa como parametro el array listaPsajeros de tipo Passenger
/// @param se le pasa el tamaño total del vector/array listaPsajeros
/// @param se le pasa como parametro una posicion de el array estadoPasajero de tipo eTipoPasajero
/// @param se le pasa el tamaño total del vector/array estadoPasajero
/// @param se le pasa como parametro una posicion de el array estadoV de tipo eEstadoVuelo
/// @param se le pasa el tamaño total del vector/array estadoVuelo
void SubMenuOpcionCuatro(Passenger listaPasajeros[],int size,eTipoPasajero estadoPasajero[], int sizeTipo,eEstadoVuelo estadoVuelo[], int sizeV);

/// @brief Operacion que se encarga de obtener el precio total(suma todos los pasajes), promediarlo y por ultimo informa que pasajero/a supera el precio promedio
//// @param se le pasa como parametro el array listaPsajeros de tipo Passenger
/// @param se le pasa el tamaño total del vector/array listaPsajeros
/// @param se le pasa como parametro una posicion de el array estadoPasajero de tipo eTipoPasajero
/// @param se le pasa el tamaño total del vector/array estadoPasajero
/// @param se le pasa como parametro una posicion de el array estadoV de tipo eEstadoVuelo
/// @param se le pasa el tamaño total del vector/array estadoVuelo
void OperacionPrecio(Passenger listaPasajeros[],int size,eTipoPasajero estadoPasajero[], int sizeTipo,eEstadoVuelo estadoVuelo[], int sizeV);

/// @brief Ordena por id los estados de vuelos
/// @param se le pasa como parametro una posicion de el array estadoV de tipo eEstadoVuelo
/// @param se le pasa el tamaño total del vector/array estadoVuelo
void OrdenarPorIdEstado(eEstadoVuelo estadoVuelo[], int sizeV);

/// @brief Compara FK con PK esta operacion reccore la lista de pasajeros, y compara que sus FK sean identicos a los PK de las demas estructuras
/// @param se le pasa como parametro una posicion de el array listaPsajeros de tipo Passenger
/// @param se le pasa como parametro una posicion de el array estadoPasajero de tipo eTipoPasajero
/// @param se le pasa el tamaño total del vector/array estadoPasajero
/// @param se le pasa como parametro una posicion de el array estadoV de tipo eEstadoVuelo
/// @param se le pasa el tamaño total del vector/array estadoVuelo
void CompararFkConPk(Passenger listaPasajeros,eTipoPasajero* estadoPasajero, int sizeTipo,eEstadoVuelo* estadoVuelo, int sizeV);

/// @brief  Esta funcion sirve para cargar el estado de vuelo del pasajero
/// @param se le pasa como parametro una posicion de el array estadoV de tipo eEstadoVuelo
/// @param se le pasa el tamaño total del vector/array estadoVuelo
/// @return retorna el id del estado de vuelo
int EstadoDePasajero(eEstadoVuelo estadoVuelo[], int sizeV);

/// @brief Busca un espacio libre en el array de listaPasajeros y confirma si existe para poder dar de alta un pasajero/a
/// @param se le pasa como parametro el array listaPsajeros de tipo Passenger
/// @param se le pasa el tamaño total del vector/array listaPsajeros
/// @return retorna el idice del primer espacio libre que encontro dentro del array, sino retorna -1 que indica que todos los espacios estan ocupados
int BuscarEspacioLibre(Passenger* listaPasajeros,int size);

/// @brief  Funcion encargada de dar de alta un pasajero en una posicion espesifica del array listaPasajeros
/// @param listaPasajeros
/// @param size
/// @param estadoPasajero
/// @param sizeTipo
/// @param estadoVuelo
/// @param sizeV
/// @return devuelve un dato tipo estructura Passsenger
Passenger DarAlta(Passenger* listaPasajeros,int size,eTipoPasajero* estadoPasajero, int sizeTipo,eEstadoVuelo* estadoVuelo, int sizeV);

/// @brief Despliega una lista de pasajeros dados de ALTA con sus ID para seleccionar un id y valida que exista
/// @param listaPasajeros
/// @param size
/// @param estadoPasajero
/// @param sizeTipo
/// @param estadoVuelo
/// @param sizeV
/// @return retorna el id del pasajero seleccionado y validado
int FindPassengerById(Passenger* listaPasajeros,int size,eTipoPasajero* estadoPasajero, int sizeTipo,eEstadoVuelo* estadoVuelo, int sizeV);

/// @brief Modifica una pasajero, se pide su id para acceder al indice donde alberga y habilita la modificacion de sus datos
/// @param listaPasajeros
/// @param size
/// @param estadoPasajero
/// @param sizeTipo
/// @param estadoVuelo
/// @param sizeV
/// @return retorna si existe un pasajero cargado para poder realizar la operacion
int ModifyPassenger(Passenger* listaPasajeros,int size,eTipoPasajero* estadoPasajero, int sizeTipo,eEstadoVuelo* estadoVuelo, int sizeV);

/// @brief Elimina un pasajero por su id de forma logica
/// @param listaPasajeros
/// @param size
/// @param estadoPasajero
/// @param sizeTipo
/// @param estadoVuelo
/// @param sizeV
/// @return retorna si existe un pasajero cargado para poder realizar la operacion
int RemovePassenger(Passenger* listaPasajeros,int size,eTipoPasajero* estadoPasajero, int sizeTipo,eEstadoVuelo* estadoVuelo, int sizeV);

/// @brief Ordena la lista de pasajeros por su apellido de forma alfabetica, si el apellido es igual ordena por tipo de pasajero
/// @param listaPasajeros
/// @param size
/// @return devuelve si se pudo realizar la operacion
int SortPassenger(Passenger* listaPasajeros, int size);

/// @brief Ordena lista de pasajeros por codigo de vuelo ordenado alfabeticamente y muestra solo los pasajeros que tienen el estado de vuelo ACTIVO
/// @param listaPasajeros
/// @param size
/// @param estadoPasajero
/// @param sizeTipo
/// @param estadoVuelo
/// @param sizeV
/// @return devuelve si se pudo realizar la operacion
int SortPassengerByCode(Passenger* listaPasajeros,int size,eTipoPasajero* estadoPasajero, int sizeTipo,eEstadoVuelo* estadoVuelo, int sizeV);

/// @brief Toma el array listaPasajeros para recorrer sus idices, llama a CompararFkConPk para que esta otra llame PrintPassenger y asi se muestran todos los pasajeros existentes
/// @param listaPasajeros
/// @param size
/// @param estadoPasajero
/// @param sizeTipo
/// @param estadoVuelo
/// @param sizeV
void PassengerList(Passenger listaPasajeros[],int size,eTipoPasajero estadoPasajero[], int sizeTipo,eEstadoVuelo estadoVuelo[], int sizeV);

/// @brief Opcion que se llama desde el main para poder agregar un nuevo psajero/a
/// @param listaPasajeros
/// @param size
/// @param estadoPasajero
/// @param sizeTipo
/// @param estadoVuelo
/// @param sizeV
/// @return retorna si existe la posibilidad de realizar la accion
int addPassenger(Passenger* listaPasajeros,int size,eTipoPasajero* estadoPasajero, int sizeTipo,eEstadoVuelo* estadoVuelo, int sizeV);

/// @brief Genera un id nuevo que no exista, toma el valor del id mayor existente y le suma 1 para asi crear un nuevo ID
/// @param listaPasajeros
/// @param size
/// @return retorna el ID nuevo que se genero
int GeneradorId(Passenger listaPasajeros[],int size);

/// @brief Se encarga de cargar el tipo de pasajero, "ROYAL, ESTANDAR...etc" lo carga en base al campo idTipo De la estructura eTipoPasajero
/// @param estadoPasajero
/// @param sizeTipo
/// @return devuelve el id del tipo de pasajero
int TipoDePasajero(eTipoPasajero estadoPasajero[], int sizeTipo);

/// @brief Verifica si existen espacios ocupados dentro del array listaPasajeros , esto confirma sie existen pasajeros dados de alta
/// @param listaPasajeros
/// @param size
/// @return devuelve el espacio de memoria del primer psajero que se encontro dado de alta, sino devuelve -1 que indica que no existe tal pasajero
int VerificarExistencia(Passenger listaPasajeros[],int size);

/// @brief inicializa los estados de pasajeros isEmpty en TRUE y los id en 0
/// @param listaPasajeros
/// @param size
/// @return retorna un codigo que confirma que se realizo la operacion
int initPassenger(Passenger listaPasajeros[],int size);



#endif /* ARRAYPASAJEROS_H_ */
