#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "input.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    LinkedList* listaPasajeros = ll_newLinkedList();
    pTipo tipoPasajero[3];
    pEstado estadoPasajero[4];
    int retorno;
    int option;
    int banderaCargaTexto = 0;
    int SeCargoUnaVez = 0;
    int banderaCargaBinario = 0;
    int SeGuardoBinario = 0;
    int SeGuardoTexto = 0;

    HardCode_Estado_Tipo(estadoPasajero,tipoPasajero);
    do{
    	option = getInt("\n|                                          MENU                                          |\n"
    			          "|________________________________________________________________________________________|\n"
						  "|1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).            |\n"
						  "|2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).          |\n"
						  "|3. Alta de pasajero.                                                                    |\n"
						  "|4. Modificar datos de pasajero.                                                         |\n"
						  "|5. Baja de pasajero.                                                                    |\n"
						  "|6. Listar pasajeros.                                                                    |\n"
						  "|7. Ordenar pasajeros.                                                                   |\n"
						  "|8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).              |\n"
						  "|9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).            |\n"
						  "|10. Salir.                                                                              |\n"
						  "|________________________________________________________________________________________|\n"
						  "|----------------------------->>>Seleccione una opcion<<<--------------------------------|\n",1,10);
		switch(option)
		{
			    case 1:
			    if(banderaCargaBinario == 0 && SeCargoUnaVez == 0)
			    {
			    	retorno = controller_loadFromText("data.csv",listaPasajeros);
					if(retorno == 1)
					{
                       printf("\n|-->Los datos del archivo data.csv fueron cargados en memoria.\n");
                       banderaCargaTexto = 1;
                       SeCargoUnaVez = 1;
					}
					else
					{
                       printf("\n|-->Ocurrio un error al cargar los datos.\n");
					}
			    }
			    else
			    {
			    	printf("\n|-->Accion denegada Ya se realizo una carga de datos.\n");
			    }
				break;
			    case 2:
			    	if(banderaCargaTexto == 0 && SeCargoUnaVez == 0)
			    	{
			    		retorno = controller_loadFromBinary("data.bin",listaPasajeros);
						if(retorno == 1)
						{
						   printf("\n|-->Los datos del archivo data.csv fueron cargados en memoria.\n");
						   banderaCargaBinario = 1;
						   SeCargoUnaVez = 1;
						}
						else
						{
						   printf("\n|-->Ocurrio un error al cargar los datos.\n");
						}
			    	}
			    	else
			    	{
			    		printf("\n|-->Accion denegada Ya se realizo una carga de datos desde la lista.\n");
			    	}

                break;
			    case 3:
			    	retorno = controller_addPassenger(listaPasajeros,estadoPasajero,4,tipoPasajero,3);
			    	if(retorno == 1)
			    	{
			    		printf("\n|-->Pasajero Caragado.\n");
			    	}
			    	else
					{
						printf("\n|-->Operacion cancelada.\n");
					}
			    break;
			    case 4:
			    	if(!ll_isEmpty(listaPasajeros))
			         {
			    		OrdenarPorId(listaPasajeros,1);
			    		retorno = controller_editPassenger(listaPasajeros,estadoPasajero,4,tipoPasajero,3);
			    	   if(retorno == 1)
						{
			    		   printf("\n|-->Pasajero Caragado.\n");
						}
			         }
			    	else
			    	{
			    		printf("\n|-->No hay datos para modificar.\n");
			    	}
			   	break;
			    case 5:
			    	if(!ll_isEmpty(listaPasajeros))
			    	{
			    		OrdenarPorId(listaPasajeros,1);
			    		retorno = controller_removePassenger(listaPasajeros);
			    		if(retorno == 1)
			    		{
			    			printf("\n|-->Pasajero eliminado.\n");
			    		}
			    		else
			    		{
			    			printf("\n|-->Ocurrio un error.\n");
			    		}
			    	}
			    	else
			    	{
			    		printf("\n|-->No hay datos para eliminar.\n");
			    	}
			   	break;
				case 6:
					if(!ll_isEmpty(listaPasajeros))
					{
						controller_ListPassenger(listaPasajeros);
					}
					else
					{
						printf("\n|-->No hay datos para Mostrar.\n");
					}
				break;
				case 7:
					if(!ll_isEmpty(listaPasajeros))
					{
						controller_sortPassenger(listaPasajeros);
					}
					else
					{
						printf("\n|-->No hay datos para Mostrar.\n");
					}
				break;
				case 8:
					if(SeCargoUnaVez == 1)
					{
						OrdenarPorId(listaPasajeros,1);
						retorno = controller_saveAsText("data.csv",listaPasajeros);
						if(retorno == 1)
						{
							SeGuardoTexto = 1;
							printf("\n|-->Guardado correctamente.\n");
						}
						else
						{
							printf("\n|-->Ocurrio un error.\n");
						}
					}
					else
					{
						if(getInt("\n|--->ERROR!<---|Para poder guardar los datos debes como minimo cargar una lista |\n"
								    "|______________|________________________________________________________________|\n"
							        "|Deseas cargar una lista ahora?                                                  \n"
							        "|1.Si \n"
							        "|2.No \n"
							        "|----------------------------->Seleccione una opcion<---------------------------|\n",1,2) == 1)
						{
							if(controller_loadFromText("data.csv",listaPasajeros)==1)
							{
								SeCargoUnaVez = 1;
								banderaCargaTexto = 1;
								OrdenarPorId(listaPasajeros,1);
								if(controller_saveAsText("data.csv",listaPasajeros)==1)
								{
									SeGuardoTexto = 1;
									printf("\n|-->Datos Cargados y Guaradados.\n");
								}
							}
						}
					}
				break;
				case 9:
					if(SeCargoUnaVez == 1)
					{
						OrdenarPorId(listaPasajeros,1);
						retorno = controller_saveAsBinary("data.bin",listaPasajeros);
						if(retorno == 1)
						{
							SeGuardoBinario = 1;
							printf("\n|-->Guardado correctamente.\n");
						}
						else
						{
							printf("\n|-->Ocurrio un error.\n");
						}
					}
					else
					{
					    if(getInt("\n|--->ERROR!<---|Para poder guardar los datos debes como minimo cargar una lista |\n"
							    "|______________|________________________________________________________________|\n"
						        "|Deseas cargar una lista ahora?                                                      \n"
						        "|1.Si \n"
						        "|2.No \n"
						        "|---------------------------->Seleccione una opcion<----------------------------|\n",1,2) == 1)
						{
							if(controller_loadFromText("data.csv",listaPasajeros)==1)
							{
								SeCargoUnaVez = 1;
								banderaCargaTexto = 1;
								OrdenarPorId(listaPasajeros,1);
								if(controller_saveAsBinary("data.bin",listaPasajeros)==1)
								{
									SeGuardoBinario = 1;
									printf("\n|-->Datos Cargados y Guaradados.");
								}
							}
						}
					}

				break;
				case 10:
					while( SeGuardoBinario == 0 || SeGuardoTexto == 0)
					{
					  if(getInt("\n|--->ATENCION!<---|Para salir debes guardar los datos en el archivo de Texto 'data.csv' y en el archivo Binario 'data.bin' |\n"
							      "|__________________________________________________________________________________________________________________________|\n"
							      "|Desea guardar los datos ahora?\n"
							      "|1.Si\n"
							      "|2.No\n"
							      "|------------------------------------------------>Seleccione una opcion<---------------------------------------------------|\n",1,2) == 1)
					  {
						  if(SeCargoUnaVez == 0)
						  {
							  if(controller_loadFromText("data.csv",listaPasajeros)==1)
								{
								  SeCargoUnaVez = 1;
								  banderaCargaTexto = 1;
								  OrdenarPorId(listaPasajeros,1);
								  if((controller_saveAsBinary("data.bin",listaPasajeros)==1) && (controller_saveAsText("data.csv",listaPasajeros)==1))
								  {
										SeGuardoBinario = 1;
										SeGuardoTexto = 1;
										printf("\n|-->Datos Cargados y Guaradados");
										break;
								 }
								}
						  }
						  else
						  {
							  OrdenarPorId(listaPasajeros,1);
							  if(controller_saveAsBinary("data.bin",listaPasajeros)==1 && controller_saveAsText("data.csv",listaPasajeros)==1)
								  {
										SeGuardoBinario = 1;
										SeGuardoTexto = 1;
										printf("\n|-->Datos Cargados y Guaradados");
										break;
								 }
						  }
					  }
					  else
					  {
						  option = 10;
						  break;
					  }
					}
					if(option == 10)
					{
						printf("\n|--> Hasta luego <--|\n");
					}
				break;
		}
	}while(option != 10);
    return 0;
}

