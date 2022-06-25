/*
 ============================================================================
 Name        : TP1.c
 Author      : Jeronimo Granadillo
 Copyright   : Your copyright notice
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "TomaDatosValidaciones.h"
#include "Calculos.h"
#define MIN 0
#define MAX 10000000
#define DES 10 //Porcentaje de descuento al pagar con tarjeta de debito
#define IN 25 //Porcentaje de interes al pagar con tarjeta de credito
#define BTC 4606954.55 // Valor de 1 bitcoin en pesos argentinos
#define AERO 1 //AERO = aerolineas su char es A
#define LATAM 2 //LATAM = latam su char es L

int main(void) {
	setbuf(stdout, NULL);
	int menuOpciones;
	int kilometrosActuales = 0;
	float precioAerolineas = 0;
	float precioLatam = 0;
	int opcionMenu2;
	float calculoDebitoAerolineas = 0;
	float calculoDebitoLatam = 0;
	float calculoCreditoAerolineas = 0;
	float calculoCreditoLatam = 0;
	float calculoBitcoinAerolineas = 0;
	float calculoBitcoinLatam = 0;
	float calculoPrecioUnitarioAerolineas = 0;
	float calculoPrecioUnitarioLatam = 0;
	float calculoDiferenciaPrecio = 0;
	do{
		printf("\nMENU DE OPCIONES PRINCIPAL\n");
		printf("1-*Ingresar kilometros (Actuales: %dkm)*\n",kilometrosActuales);
		printf("2-*Ingresar Precio de Vuelos (Actuales, Aerolineas Argentinas: $%.2f, Latam: $%.2f)*\n", precioAerolineas, precioLatam);
		printf("3-*Calcular Costos*\n");
		printf("4-*Informar Resultados*\n");
		printf("5-*Carga Forzada de Datos*\n");
		printf("6-*Salir*\n");

		menuOpciones =ValidacionMenu("",1,6);
		switch(menuOpciones)
		{
		  case 1:
			kilometrosActuales = ValidacionKilometros("Coloque los kilometros: \n", 100, 50000);
		  break;

		  case 2:

			  do {
				 printf("\nMENU DE OPCIONES\n");
				 printf("1-Colocar precio de Aerolineas Argentinas (Actual: $%.2f)\n",precioAerolineas);
			     printf("2-Colocar precio de Latam (Actual: $%.2f)\n",precioLatam);
			     printf("3-Salir\n");

                 opcionMenu2 =ValidacionMenu2("",1,3);
                  switch(opcionMenu2)
                  {
                    case 1:
                    	precioAerolineas = ValidacionPrecioAerolineas("Ingrese costo del vuelo de Aerolineas Argentinas: ", MIN, MAX);
				    break;

                    case 2:
                    	 precioLatam = ValidacionPrecioLatam("Ingrese costo del vuelo de Latam: ", MIN, MAX);
                	break;
                  }

			  }while(opcionMenu2 != 3 );

	      break;

		  case 3:
			      printf("Calculando costos...\n");
			      calculoDebitoAerolineas = PrecioTarjetaDebito(precioAerolineas, DES, AERO);
			      calculoDebitoLatam =  PrecioTarjetaDebito(precioLatam, DES, LATAM);
			      calculoCreditoAerolineas = PrecioTarjetaCredito(precioAerolineas,IN);
				  calculoCreditoLatam = PrecioTarjetaCredito(precioLatam,IN);
				  calculoBitcoinAerolineas = PrecioConBitcoin(precioAerolineas, BTC);
				  calculoBitcoinLatam = PrecioConBitcoin(precioLatam, BTC);
				  calculoPrecioUnitarioAerolineas = PrecioUnitario(precioAerolineas,kilometrosActuales, AERO);
				  calculoPrecioUnitarioLatam = PrecioUnitario(precioLatam,kilometrosActuales, LATAM);
				  calculoDiferenciaPrecio = DiferenciaPrecio(precioAerolineas,precioLatam);
	      break;

		  case 4:
			  printf("RESULTADOS\n");

			  printf("Aerolienas Argentinas:\n");
			  printf("a) Precio con tarjeta de debito: $%.2f\n",calculoDebitoAerolineas);
			  printf("b) Precio con tarjeta de credito: $%.2f\n",calculoCreditoAerolineas);
			  printf("c) Precio pagando con Bitcoin: %f BTC\n", calculoBitcoinAerolineas);
			  printf("d) Precio unitario: $%.2f\n",calculoPrecioUnitarioAerolineas);

			  printf("\nLatam: \n");
			  printf("a) Precio con tarjeta de debito: $%.2f\n",calculoDebitoLatam);
			  printf("b) Precio con tarjeta de credito: $%.2f\n",calculoCreditoLatam);
			  printf("c) Precio pagando con Bitcoin: %f BTC\n",calculoBitcoinLatam);
			  printf("d) Precio unitario: $%.2f\n",calculoPrecioUnitarioLatam);

			  printf("\nLa diferencia de precios es: $%.2f\n",calculoDiferenciaPrecio);
		  break;

		  case 5:
			  precioAerolineas = 162965;
			  precioLatam = 159339 ;
			  kilometrosActuales = 7090;

			  calculoDebitoAerolineas = PrecioTarjetaDebito(precioAerolineas, DES, AERO);
			  calculoDebitoLatam =  PrecioTarjetaDebito(precioLatam, DES, LATAM);
 			  calculoCreditoAerolineas = PrecioTarjetaCredito(precioAerolineas,IN);
			  calculoCreditoLatam = PrecioTarjetaCredito(precioLatam,IN);
			  calculoBitcoinAerolineas = PrecioConBitcoin(precioAerolineas, BTC);
			  calculoBitcoinLatam = PrecioConBitcoin(precioLatam, BTC);
			  calculoPrecioUnitarioAerolineas = PrecioUnitario(precioAerolineas,kilometrosActuales, AERO);
			  calculoPrecioUnitarioLatam = PrecioUnitario(precioLatam,kilometrosActuales, LATAM);
			  calculoDiferenciaPrecio = DiferenciaPrecio(precioAerolineas,precioLatam);
			 printf("\nCARGA FORZADA DE DATOS RESULTADOS:\n");
			 printf("\nKMs ingresados: %dKm\n", kilometrosActuales);

			 printf("\nPrecio Aerolienas Argentinas: $%.2f\n",precioAerolineas);
			 printf("a) Precio con tarjeta de debito: $%.2f\n",calculoDebitoAerolineas);
			 printf("b) Precio con tarjeta de credito: $%.2f\n",calculoCreditoAerolineas);
			 printf("c) Precio pagando con Bitcoin: %f BTC\n", calculoBitcoinAerolineas);
			 printf("d) Precio unitario: $%.2f\n",calculoPrecioUnitarioAerolineas);

			 printf("\nPrecio Latam: $%.2f \n", precioLatam);
			 printf("a) Precio con tarjeta de debito: $%.2f\n",calculoDebitoLatam);
			 printf("b) Precio con tarjeta de credito: $%.2f\n",calculoCreditoLatam);
			 printf("c) Precio pagando con Bitcoin: %f BTC\n",calculoBitcoinLatam);
			 printf("d) Precio unitario: $%.2f\n",calculoPrecioUnitarioLatam);

			 printf("\nLa diferencia de precios es: $%.2f\n",calculoDiferenciaPrecio);
		  break;

		  case 6:
			  printf("GRACIAS POR UTILIZAR ESTE PROGRAMA");
		  break;
		}

	}while(menuOpciones != 6);


	return EXIT_SUCCESS;
}


