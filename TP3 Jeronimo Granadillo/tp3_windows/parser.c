#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "controller.h"
#include "input.h"


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int respuesta = -1;
	int retorno;
	//int contadorRetornosPositivos = 0;
	Passenger* nuevoPasajero;
	char id[20];
	char nombre[30];
	char apellido[30];
	char precio[10];
	char tipo[20];
	char codigo[10];
	char estado[20];
	int cantidad = 0;

	if(pFile != NULL)
	{
		cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigo,tipo,estado);
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigo,tipo,estado);
			if(cantidad == 7)
			{
				nuevoPasajero = Passenger_newParametros(id,nombre,apellido,precio,codigo,tipo,estado);
				if(nuevoPasajero != NULL)
				{
					retorno = ll_add(pArrayListPassenger,nuevoPasajero);
					retorno = retorno+0;
				}
				else
				{
					Passenger_delete(nuevoPasajero);
				}
			}
		}
          if(retorno == 0)
          {
        		respuesta = 1;
          }
	}
    return respuesta;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* nuevoPasajero = NULL;
	int respuesta = 0;
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		while(!feof(pFile))
		{
			nuevoPasajero = Passenger_new();
			if(nuevoPasajero != NULL)
			{
				if(fread(nuevoPasajero,sizeof(Passenger),1,pFile)!= 0)
				{
					ll_add(pArrayListPassenger,nuevoPasajero);
					respuesta = 1;
				}
			}
	    }
    }
    return respuesta;
}
