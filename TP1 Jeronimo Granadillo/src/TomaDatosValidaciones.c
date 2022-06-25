#include "TomaDatosValidaciones.h"
#define EKM 01 // numero de error si no hay un valor mayor a 0 definido en los kilometros, este error indica que la operacion de calcular el precio por kilometro no se realizara.
#define EPG 02 // numero de error si no hay un valor mayor a 0 definido en los precios, este error indica que la operacion de calcular metodos de pago.
#define CONFP 11 //numero de confirmacion, refiere a que se pueden hacer los calculos de medios de pago exitosamente.
#define CONFK 12 //confirma que se efectuara el calculo de precio unitario.
int ValidacionMenu(char mensaje[], int min, int max)
{
	int menuOpciones;
	printf("%s", mensaje);
	scanf("%d", & menuOpciones);
	while(menuOpciones < min || menuOpciones > max)
	{
		printf("¡OPCION INVALIDA! Reingrese: ");
		fflush(stdin);
	    scanf("%d", &menuOpciones);
	}

	return  menuOpciones;
}

int ValidacionKilometros(char mensaje[], int min, int max)
{
	int kilometros;
	printf("%s", mensaje);
	scanf("%d", &kilometros);
	while(kilometros < min || kilometros > max)
	{
		printf("ERROR!, Coloque una distancia coherente entre 100km y 50000km: \n");
		scanf("%d", &kilometros);
	}

	return kilometros;
}

float ValidacionPrecioAerolineas(char mensaje[], int min, int max)
{
	float precioAerolineas;
	printf("%s",mensaje);
	scanf("%f",&precioAerolineas);
	while(precioAerolineas < min || precioAerolineas > max)
	{
		printf("Reeingrese un precio valido: ");
	    scanf("%f",&precioAerolineas);
	}

	return precioAerolineas;
}

float ValidacionPrecioLatam(char mensaje[], int min, int max)
{
	float precioLatam;
		printf("%s",mensaje);
		scanf("%f",&precioLatam);
		while(precioLatam < min || precioLatam > max)
		{
			printf("Reeingrese un precio valido: ");
		    scanf("%f",&precioLatam);
		}

		return precioLatam;
}

int ValidacionMenu2(char mensaje[], int min, int max)
{
	int menuOpciones;
	printf("%s", mensaje);
	scanf("%d", & menuOpciones);
	while(menuOpciones < min || menuOpciones > max)
	{
		printf("¡OPCION INVALIDA! Reingrese: ");
		fflush(stdin);
	    scanf("%d", & menuOpciones);
	}

	return  menuOpciones;
}

void  MensajeDeErrorCalculos(int error, int  aerolinea)
{
	  switch(error)
	  {
	    case 01:
		       if(aerolinea == 1)
		       {
			     printf("NO se podra calcular el precio unitario de Aerolineas Argentinas, Falta ingresar los kilometros\n");
		       }
		       else
		       {
			     printf("NO se podra calcular el precio unitario de Latam, Falta ingresar los kilometros\n");
		       }
	    break;

	    case 02:
	 	 	   if(aerolinea == 1)
	 	 	   {
	 			printf("NO se podra calcular los metodos de pago y el precio unitario de Aerolineas Argentinas, Falta ingresar el precio del pasaje\n");
	 		   }
	 		   else
	 		   {
	 			 printf("NO se podra calcular los metodos de pago y el precio unitario de Latam, Falta ingresar el precio del pasaje\n");
	 		   }
	    break;
	  }
}

int ValidacionCalculoUnitario(int kilometros, int  aerolinea)
{
	int respuesta;
	if(kilometros < 1)
	{
		respuesta = 0;
		MensajeDeErrorCalculos(EKM,aerolinea);
	}
	else
	{

		respuesta = 1;
		MensajeDeConfirmacion(CONFK, aerolinea);
	}

	return respuesta;
}

void ValidacionCalculosPrecio(int numero, int aerolinea)
{
		if(numero < 1)
		{
			MensajeDeErrorCalculos(EPG,aerolinea);
		}
		else
		{
			MensajeDeConfirmacion(CONFP, aerolinea);
		}

}
void MensajeDeConfirmacion(int confirmacion, int aerolinea)
{
	switch(confirmacion)
		{
		  case 11:
			 if(aerolinea == 1)
			 {
				printf("Se Pueden calcular metodos de pago de Aerolineas Argentinas.\n");
			 }
			 else
			 {
				 printf("Se Pueden calcular metodos de pago de Latam.\n");
			 }
		  break;

		  case 12:
		 	if(aerolinea == 1)
		 	{
		 			printf("Hay Km para calcular precio unitario de Aerolineas...\n");
		 	}
		 	else
		 	{
		 			 printf("Hay Km para calcular precio unitario de Latam...\n");
		 	}
		 break;
       }
}




