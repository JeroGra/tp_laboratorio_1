#include "Controller.h"
#include "parser.h"
#include "Passenger.h"
#include "LinkedList.h"
#include "input.h"
int getIntMasIntentos(char mensaje[], int minimo, int maximo, int intentos,int defaultInt)
{
	int enteroValidado = 0;
	int entero;
	int maximoString;
	char mensajeRecibido[100];
	printf("%s",mensaje);
	fflush(stdin);
	gets(mensajeRecibido);
	maximoString = MaximoStringInt(maximo);
	while(ValidacionString(mensajeRecibido,maximoString)==0)
	{
		intentos--;
		if(intentos < 1)
		{
		   printf("Te quedaste sin intentos\n");
		   enteroValidado = defaultInt;
		   break;
		}
		printf("Error: \n");
		fflush(stdin);
		gets(mensajeRecibido);

	}
	entero = atoi(mensajeRecibido);
	while(entero < minimo || entero > maximo)
	{
		intentos --;
		if(intentos < 1)
		{
		   printf("Te quedaste sin intentos\n");
		   enteroValidado = defaultInt;
		   break;
		}
		printf("Error: \n");
		fflush(stdin);
		gets(mensajeRecibido);

		while(ValidacionString(mensajeRecibido,maximoString)==0)
		{
			intentos --;
			if(intentos < 1)
			{
			   printf("Te quedaste sin intentos\n");
			   enteroValidado = defaultInt;
			   break;
			}
			printf("Error: \n");
			fflush(stdin);
			gets(mensajeRecibido);
		}

	entero = atoi(mensajeRecibido);
	}

	enteroValidado = entero;
	return enteroValidado;
}

int getInt(char mensaje[], int minimo, int maximo)
{
	int enteroValidado = 0;
	int entero;
	int maximoString;
	char mensajeRecibido[10];
	printf("%s",mensaje);
	fflush(stdin);
	gets(mensajeRecibido);
	maximoString = MaximoStringInt(maximo);
	while(ValidacionString(mensajeRecibido,maximoString)==0)
	{
		printf("Error: \n");
		fflush(stdin);
		gets(mensajeRecibido);
	}
	entero = atoi(mensajeRecibido);
	while(entero < minimo || entero > maximo)
	{
		printf("Error: \n");
		fflush(stdin);
		gets(mensajeRecibido);

		while(ValidacionString(mensajeRecibido,maximoString)==0)
		{
			printf("Error: \n");
			fflush(stdin);
			gets(mensajeRecibido);
		}
	entero = atoi(mensajeRecibido);
	}

	enteroValidado = entero;
	return enteroValidado;
}

float getFloat(char mensaje[], int minimo, int maximo)
{
	float flotanteValidado = 0;
	float flotante;
	int maximoString;
	char mensajeRecibido[10];
	printf("%s",mensaje);
	fflush(stdin);
	gets(mensajeRecibido);
	maximoString = MaximoStringInt(maximo);
	while(ValidacionString(mensajeRecibido,maximoString)==0)
	{
		printf("Error: \n");
		fflush(stdin);
		gets(mensajeRecibido);

	}
	flotante = atof(mensajeRecibido);
	while(flotante < minimo || flotante > maximo)
	{
		printf("Error: \n");
		fflush(stdin);
		gets(mensajeRecibido);

		while(ValidacionString(mensajeRecibido,maximoString)==0)
		{
			printf("Error: \n");
			fflush(stdin);
			gets(mensajeRecibido);
		}
	flotante = atoi(mensajeRecibido);
	}

	flotanteValidado = flotante;
	return flotanteValidado;
}

void getString(char mensajeCargado[], char mensaje[], int maximo)
{
	printf("%s",mensaje);
	fflush(stdin);
	gets(mensajeCargado);
	while(ValidacionString(mensajeCargado,maximo)==0)
	{
		printf("Error: \n");
		fflush(stdin);
		gets(mensajeCargado);
	}
}

void TrasnsformarNombres(char modificar[])
{
	int len;
	int espacio;
	int posicion;
	strlwr(modificar);
    len = strlen(modificar);
	for(int i = 0; i < len;i++)
	{
		espacio= isspace(modificar[i]);

		if(espacio == 0)
		{
			posicion++;
		}
		else
		{
			posicion++;
			modificar[i+1] = toupper(modificar[i+1]);
		}
	}
	modificar[0] = toupper(modificar[0]);
}


int ValidacionString(char mensajeRecibido[],int maximo)
{
 int validacion = 0;
 int longitud;
 longitud = strlen(mensajeRecibido);
 if(mensajeRecibido != NULL && longitud > 0 && longitud < maximo)
 {
	 validacion = 1;
 }
 return validacion;
}

int MaximoStringInt(int maximoNumero)
{
	int maximoDeString;
	if(maximoNumero > 0 && maximoNumero < 10)
	{
		maximoDeString = 3;
	}
	else
	{
		if(maximoNumero > 9 && maximoNumero < 100)
		{
			maximoDeString = 4;
		}
		else
		{
			if(maximoNumero > 99 && maximoNumero < 1000)
			{
				maximoDeString = 5;
			}
			else
			{
				if(maximoNumero > 999 && maximoNumero < 10000)
				{
					maximoDeString = 6;
				}
				else
				{
					if(maximoNumero > 9999 && maximoNumero < 100000)
					{
						maximoDeString = 7;
					}
					else
					{
						if(maximoNumero > 99999 && maximoNumero < 10000000)
						{
							maximoDeString = 8;
						}
					}
				}
			}
		}
	}
	return maximoDeString;
}

int ValidarDiaFecha(int mes)
{
	int dia;
	switch(mes)
	{
       case  1 :
	   case  3 :
	   case  5 :
	   case  7 :
	   case  8 :
	   case 10 :
	   case 12 :
          dia = getInt("Coloque el dia: \n",1,31);
	   break;

	   case  4 :
	   case  6 :
	   case  9 :
	   case 11 :
		   dia = getInt("Coloque el dia: \n",1,30);
	   break;

	   case 2:
		   dia = getInt("Coloque el dia: \n",1,28);
	   break;
	}
	return dia;
}
