#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPasajeros.h"
#include "Input.h"
#define LIMIT 2000 //Limite de pasajeros
#define SALIR 6
#define P 3
#define E 3

int main(void) {
	setbuf(stdout,NULL);
	Passenger listaPasajeros[LIMIT];
	eTipoPasajero tipoPasajero[P] ={{NORMAL,"ESTANDAR"},{BUSINESS,"BUSINESS"},{ROYAL,"ROYAL"}};
	eEstadoVuelo estado[E] = {{ACTIVO,"ACTIVO"},{EN_TRAMITE,"EN TRAMITE"},{FINALIZADO,"CONCLUIDO"}};
	int opcionMenu;
    int retorno;
    int inicializacion;

    inicializacion = initPassenger(listaPasajeros,LIMIT);
    if(inicializacion == 0)
    {
    	printf("Se inicializaron en TRUE isEmpty de la estructura Passengers");
    }

	do{
	 opcionMenu = getIntMasIntentos("\nMENU DE OPCIONES\n1.Cargar Pasajero/a\n2.Modificar Pasajero/a\n3.Eliminar Pasajero/a\n4.Informar\n5.Carga forzada\n6.Salir\nElija una opcion: \n",1,6,3,0);
	 switch(opcionMenu)
	 {
	 case 1:
         retorno =  addPassenger(listaPasajeros,LIMIT,tipoPasajero,P,estado,E);
         switch(retorno)
         {
         case -1:
        	 printf("No Hay espacio para cargar pasajeros");
         break;

         case -2:
        	 printf("Se cancelo la operacion");
         break;

         default:
        	 printf("Operacion realizada con exito");
         break;
         }
     break;

	 case 2:
		retorno = ModifyPassenger(listaPasajeros,LIMIT,tipoPasajero,P,estado,E);
		switch(retorno)
		{
		case -1:
			printf("No hay pasajeros dados de alta\n");
		break;
		case -2:
		    printf("Se cancelo la operacion");
	    break;
		}

	 break;

	 case 3:
        retorno = RemovePassenger(listaPasajeros,LIMIT,tipoPasajero,P,estado,E);
        switch(retorno)
		{
		case -1:
			printf("No hay pasajeros dados de alta\n");
		break;
		case -2:
			printf("Se cancelo la operacion");
		break;
		}
	 break;

	 case 4:
		retorno =VerificarExistencia(listaPasajeros, LIMIT);
		if(retorno == -1)
		{
			printf("No hay pasajeros dados de alta\n");
		}
		else
		{
		  SubMenuOpcionCuatro(listaPasajeros,LIMIT,tipoPasajero,P,estado,E);
		}
	 break;

	 case 5:
		 Hradcode(listaPasajeros);
		 printf("Datos forzados cargados\n");
	 break;
	 case 6:
         printf("Hasta luego.");
	 break;
	 }
	}while(opcionMenu != SALIR);
	return EXIT_SUCCESS;
}
