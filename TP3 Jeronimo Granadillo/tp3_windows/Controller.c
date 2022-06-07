#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "input.h"
#include "Controller.h"



/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int respuesta = -1;
	int retorno;
	FILE* pArchivo;
	if(path != NULL && pArrayListPassenger != NULL)
	{
	 pArchivo = fopen(path,"r");
	 retorno = parser_PassengerFromText(pArchivo,pArrayListPassenger);
	 if(retorno == 1)
	 {
		 respuesta = 1;
	 }
	 fclose(pArchivo);
	}
    return respuesta ;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int respuesta = -1;
	int retorno;
	FILE* pArchivo;
	if(path != NULL && pArrayListPassenger != NULL)
	{
	 pArchivo = fopen(path,"rb");

	 if(pArchivo != NULL)
	 {
		 retorno = parser_PassengerFromBinary(pArchivo,pArrayListPassenger);

		 if(retorno == 1)
		 {
			 respuesta = retorno;
		 }
	 }

	 fclose(pArchivo);
    }
    return respuesta ;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger,pEstado* estado,int sizeE,pTipo* tipo,int sizeT)
{
	int isOk = -1;
	int id;
	char nombre[30];
	char apellido[30];
	float precio;
	char tipoPasajero[50];
	char codigo[10];
	char estadoPasajero[50];

	if(pArrayListPassenger != NULL)
	{
		id = GenerarId(pArrayListPassenger);
		getString(nombre,"Coloque el nombre\n",30);
		TrasnsformarNombres(nombre);
		getString(apellido,"Coloque el apellido\n",30);
		TrasnsformarNombres(apellido);
		getString(codigo,"Coloque el codigo de vuelo\n",10);
		DefinirTipo(tipoPasajero,tipo,sizeT);
		precio = getFloat("Coloque el precio\n",100,100000);
	    DefinirEstado(estadoPasajero,estado,sizeE);
	}
	isOk = AddPassenger(id,nombre,apellido,tipoPasajero,codigo,estadoPasajero,precio,pArrayListPassenger);
    return isOk;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger,pEstado* estado,int sizeE,pTipo* tipo,int sizeT)
{
	int respuesta = 0;
	int indicePAsajero;
	int opcion;
	char nombre[30];
	char apellido[30];
	float precio;
	char tipoPasajero[50];
	char estadoPasajero[50];
	int BanderaCambios = 0;
	Passenger* pasajero = NULL;
	if(pArrayListPassenger != NULL)
	{
		indicePAsajero = BuscarIdPasajero(pArrayListPassenger,pasajero);
		pasajero = ll_get(pArrayListPassenger,indicePAsajero);
		printf("|ID  \t|Nombre              \t|Apellido            \t|Precio       \t|Codigo de Vuelo    \t|Tipo de Pasajero   \t|Estado de Pasajero       \n"
				   "|_______|_______________________|_______________________|_______________|_______________________|_______________________|________________________|\n");
		printf("Este es el pasajero seleccionado para Modificar?\n");
		Passenger_print(pasajero);
	   if(getInt("1.Si\n"
				 "2.No\n"
				 "Seleccione la respuesta: \n",1,2)==1)
	   {
		   do
		   {
			   opcion = getInt("\n|     MENU MODIFICACIONES     |\n"
					             "|_____________________________|\n"
					             "|1.Nombre                     |\n"
					             "|2.Apellido                   |\n"
					             "|3.Tipo de pasajero           |\n"
					             "|4.Estado de pasajero         |\n"
					             "|5.Precio                     |\n"
					             "|6.Salir                      |\n"
					             "|--->Seleccione una opcion<---|\n",1,6);
			   switch(opcion)
			   {
			   case 1:
					getString(nombre,"Coloque el nombre\n",30);
					TrasnsformarNombres(nombre);
					Passenger_setNombre(pasajero,nombre);
					printf("Se realizo el cambio\n");
					BanderaCambios = 1;
			   break;
			   case 2:
				   getString(apellido,"Coloque el apellido\n",30);
				   TrasnsformarNombres(apellido);
				   Passenger_setApellido(pasajero,apellido);
				   printf("Se realizo el cambio\n");
				   BanderaCambios = 1;
			   break;
			   case 3:
				   DefinirTipo(tipoPasajero,tipo,sizeT);
				   Passenger_setTipoPasajero(pasajero,tipoPasajero);
				   printf("Se realizo el cambio\n");
				   BanderaCambios = 1;
			   break;
			   case 4:
				   DefinirEstado(estadoPasajero,estado,sizeE);
				   Passenger_setEstado(pasajero,estadoPasajero);
				   printf("Se realizo el cambio\n");
				   BanderaCambios = 1;
			   break;
			   case 5:
				   precio = getFloat("Coloque el precio\n",100,100000);
				   pasajero->precio = precio;
				   printf("Se realizo el cambio\n");
				   BanderaCambios = 1;
			   break;
			   case 6:
				   if(BanderaCambios == 0)
				   {
					   printf("No se realizaron Cambios");
				   }
				   else
				   {
					   printf("Este es el resultado de los cambios\n");
					   Passenger_print(pasajero);
					   if(getInt("Son correctos?\n"
							     "1.Si\n"
							     "2.No\n",1,2)==2)
					   {
						   if(getInt("Deseas modificarlos devuelta?\n"
									 "1.Si\n"
									 "2.No\n",1,2)==1)
						   {
							   opcion = 0;
						   }
					   }
				   }
			   break;
			   }
		   }while(opcion != 6);
	   }
	   else
	   {
			printf("Se cancelo la operacion\n");
			Passenger_delete(pasajero);
	   }

	}
    return respuesta;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int respuesta = 0;
    int indicePasajero;
    Passenger* pasajero = NULL;

    indicePasajero= BuscarIdPasajero(pArrayListPassenger,pasajero);
	pasajero = ll_get(pArrayListPassenger,indicePasajero);
	printf("|ID  \t|Nombre              \t|Apellido            \t|Precio       \t|Codigo de Vuelo    \t|Tipo de Pasajero   \t|Estado de Pasajero       \n"
			   "|_______|_______________________|_______________________|_______________|_______________________|_______________________|________________________|\n");
	printf("Este es el pasajero seleccionado para eliminar?\n");
	Passenger_print(pasajero);
	if(getInt("1.Si\n"
			  "2.No\n"
			  "Seleccione la respuesta: \n",1,2)==1)
	{
		ll_remove(pArrayListPassenger,indicePasajero);
		respuesta = 1;
	}
	else
	{
		printf("Se cancelo la operacion\n");
	}
    return respuesta;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* pasajero;
	printf("|ID  \t|Nombre              \t|Apellido            \t|Precio       \t|Codigo de Vuelo    \t|Tipo de Pasajero   \t|Estado de Pasajero       \n"
		   "|_______|_______________________|_______________________|_______________|_______________________|_______________________|________________________|\n");
	for(int i = 0; i<ll_len(pArrayListPassenger); i++)
	{
		pasajero = (Passenger*) ll_get(pArrayListPassenger, i);
		Passenger_print(pasajero);
	}
	printf("|_______|_______________________|_______________________|_______________|_______________________|_______________________|________________________|\n");
    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int respuesta = -1;
	int SeOrdeno = 0;
	int option;
	LinkedList* Aux;
	if(pArrayListPassenger != NULL)
	{

		Aux = ll_clone(pArrayListPassenger);
		do{
			option = getInt("\n|          MENU DE ORDENAMIENTOS          |\n"
					          "|_________________________________________|\n"
					          "|1.Ordenar por ID de forma Ascendente.    |\n"
					          "|2.Ordenar por Id de forma Descendente.   |\n"
					          "|3.Ordenar Alfabeticamente.               |\n"
					          "|4.Ordenar por Tipo De Pasajero.          |\n"
					          "|5.Ordenar por Estado De Pasajero.        |\n"
					          "|6.Ordenar por Precio                     |\n"
					          "|7.Salir.                                 |\n"
					          "|--------->Seleccione una opcion<---------|\n",1,7);
			switch(option)
			{
			case 1:
				printf("Cargando...\tEsto puede demorarce unos segundos...\n");
				OrdenarPorId(Aux,1);
				printf("\n\n\nLISTA SEGUN ORDEN ELEGIDO\n");
				controller_ListPassenger(Aux);
				SeOrdeno = 1;
			break;
			case 2:
				printf("Cargando...\tEsto puede demorarce unos segundos...\n");
				OrdenarPorId(Aux,0);
				printf("\n\n\nLISTA SEGUN ORDEN ELEGIDO\n");
				controller_ListPassenger(Aux);
				SeOrdeno = 1;
			break;
			case 3:
				printf("Cargando...\tEsto puede demorarce unos segundos...\n");
				OrdenarPorParametros(Aux,0,1);
				printf("\n\n\nLISTA SEGUN ORDEN ELEGIDO\n");
				controller_ListPassenger(Aux);
				SeOrdeno = 1;
			break;
			case 4:
				printf("Cargando...\tEsto puede demorarce unos segundos...\n");
				OrdenarPorParametros(Aux,1,2);
				printf("\n\n\nLISTA SEGUN ORDEN ELEGIDO\n");
				controller_ListPassenger(Aux);
				SeOrdeno = 1;
			break;
			case 5:
				printf("Cargando...\tEsto puede demorarce unos segundos...\n");
				OrdenarPorParametros(Aux,1,3);
				printf("\n\n\nLISTA SEGUN ORDEN ELEGIDO\n");
				controller_ListPassenger(Aux);
				SeOrdeno = 1;
		    break;
			case 6:
				printf("Cargando...\tEsto puede demorarce unos segundos...\n");
				OrdenarPorParametros(Aux,1,4);
				printf("\n\n\nLISTA SEGUN ORDEN ELEGIDO\n");
				controller_ListPassenger(Aux);
				SeOrdeno = 1;
			break;
			case 7:
				if(SeOrdeno == 1)
				{
					if(getInt("Desea guardar en una lista aparte los datos segun el ultimo ordenamiento?\n"
							  "1.Si\n"
							  "2.No\n",1,2)==1)
					{
						controller_saveAsText("dataNewSort.csv",Aux);
						ll_deleteLinkedList(Aux);
						printf("Volviendo al menu principal...\n");
					}
					else
					{
						ll_deleteLinkedList(Aux);
						printf("Volviendo al menu principal...\n");
					}

				}
			break;
			}

		}while(option != 7);

	}
    return respuesta;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int i;
	int longitud;
	int id;
	char nombre[50];
	char apellido[50];
	char tipoPasajero[20];
	char codigoVuelo[10];
	char estadoPasajero[20];
	float precio;
	int precioEntero;
	FILE* pArchivo;
	Passenger* pasajero = NULL;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path,"w");
		longitud = ll_len(pArrayListPassenger);
		if(pArchivo != NULL && longitud > 0)
		{
			fprintf(pArchivo,"ID,Nombre,Apellido,Precio,Codigo,Tipo,Estado\n");
			for(i = 0; i<longitud;i++)
			{
				pasajero = (Passenger*) ll_get(pArrayListPassenger,i);
				if(pasajero != NULL)
				{
					if(GetterPassenger(pasajero,&id,nombre,apellido,tipoPasajero,codigoVuelo,estadoPasajero,&precio)==1)
					{
						precioEntero =(int)precio;
						fprintf(pArchivo,"%d,%s,%s,%d,%s,%s,%s\n",id,nombre,apellido,precioEntero,codigoVuelo,tipoPasajero,estadoPasajero);
						retorno = 1;
					}
					else
					{
						Passenger_delete(pasajero);
					}
				}
			}
		}
		fclose(pArchivo);
	}
    return retorno;
}


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int longitud;
	FILE* pArchivo;
	Passenger* pasajero = NULL;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path, "wb");
		longitud = ll_len(pArrayListPassenger);
		if(pArchivo != NULL && longitud > 0)
		{
			for(int i = 0; i<longitud;i++)
			{
				pasajero = (Passenger*) ll_get(pArrayListPassenger,i);
				if(pasajero != NULL)
				{
					fwrite(pasajero,sizeof(Passenger),1,pArchivo);
					retorno = 1;
				}
			}
		}
		fclose(pArchivo);
	}
    return retorno;
}

