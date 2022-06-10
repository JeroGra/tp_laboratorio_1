#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "input.h"
Passenger* Passenger_newParametros(char* id,char* nombre,char* apellido,char* precio,char* codigo,char* tipo,char* estado)
{
	Passenger* pasajero = NULL;
	pasajero = Passenger_new();
	if(pasajero != NULL)
	{
           SetterPassenger(pasajero,id,nombre,apellido,tipo,codigo,estado,precio);
	}
	return pasajero;
}
Passenger* Passenger_new()
{
	Passenger* indice = (Passenger*) malloc(sizeof(Passenger)*1);
	if(indice != NULL)
	{
		indice->id = 0;
		indice->precio = 0;
		strcpy(indice->nombre,"");
		strcpy(indice->apellido,"");
		strcpy(indice->codigoVuelo,"");
		strcpy(indice->tipoPasajero,"");
		strcpy(indice->estado,"");
	}
	return indice;
}
void Passenger_delete(Passenger* this)
{
  if(this != NULL)
  {
	  free(this);
	  this = NULL;

  }
}
void HardCode_Estado_Tipo(pEstado* estado, pTipo* tipo)
{
	pEstado estadoAux[4]={{1,"En Horario"},{2,"Demorado"},{3,"Aterrizado"},{4,"En Vuelo"}};
	pTipo tipoAux[3]={{1,"EconomyClass"},{2,"ExecutiveClass"},{3,"FirstClass"}};

	for(int i = 0;i<4;i++)
	{
		estado[i] = estadoAux[i];
	}
	for(int i = 0;i<3;i++)
	{
		tipo[i] = tipoAux[i];
	}

}
int GenerarId(LinkedList* pArrayListPassenger)
{
	int nuevoId;
	FILE* pArchivo;
	char id[2000];
	pArchivo = fopen("idRegister.csv","r");
	if(pArchivo != NULL)
	{
		while(!feof(pArchivo))
		{
			fscanf(pArchivo,"%[^\n]\n",id);
			nuevoId = atoi(id);
		}
	}
	nuevoId++;
	fclose(pArchivo);
	return nuevoId;
}
void DefinirEstado(char* estadoPasajero,pEstado* estado,int sizeE)
{
	int indiceE;
	printf("ESTADOS\n");
	for(int i = 0;i<sizeE;i++)
	{
		printf("%d.%-5s\n",estado[i].id, estado[i].estado);
	}
	indiceE = getInt("Seleccione una opcion\n",1,4);
	for(int i = 0;i<sizeE;i++)
	{
		if(indiceE == estado[i].id)
		{
		    strcpy(estadoPasajero,estado[i].estado);
		    break;
		}

	}
}
void DefinirTipo(char* tipoPasajero,pTipo* tipo,int sizeT)
{
	int indiceT;
	printf("TIPOS DE PASAJEROS\n");
	for(int i = 0;i<sizeT;i++)
	{
		printf("%d.%-5s\n",tipo[i].id, tipo[i].tipo);
	}
	indiceT = getInt("Seleccione una opcion\n",1,3);
	for(int i = 0;i<sizeT;i++)
	{
		if(indiceT == tipo[i].id)
		{
		    strcpy(tipoPasajero,tipo[i].tipo);
		    break;
		}
	}
}
//////////////////// Setters //////////////////////////////////
int Passenger_setId(Passenger* this,char* id)
{
	int isOk = 0;
	if(this != NULL)
	{
		this->id = atoi(id);
		isOk = 1;
	}
	return isOk;
}
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int isOk = 0;
	if(this != NULL)
	{
		strcpy(this->nombre,nombre);
		isOk = 1;
	}
	return isOk;
}
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int isOk = 0;
	if(this != NULL)
	{
		strcpy(this->apellido,apellido);
		isOk = 1;
	}
	return isOk;
}
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int isOk = 0;
	if(this != NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		isOk = 1;
	}
	return isOk;
}
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int isOk = 0;
	if(this != NULL)
	{
		strcpy(this->tipoPasajero,tipoPasajero);
		isOk = 1;
	}
	return isOk;
}
int Passenger_setEstado(Passenger* this,char* estadoPasajero)
{
	int isOk = 0;
	if(this != NULL)
	{
		strcpy(this->estado,estadoPasajero);
		isOk = 1;
	}
	return isOk;
}
int Passenger_setPrecio(Passenger* this,char* precio)
{
	int isOk = 0;
	if(this != NULL)
	{
		this->precio = atof(precio);
		isOk = 1;
	}
	return isOk;
}
int SetterPassenger(Passenger* pasajero, char*id, char*nombre, char*apellido, char*tipoPasajero, char*codigoVuelo, char*estadoPasajero, char* precio)
{
	int isOk = 0;
	if(Passenger_setId(pasajero,id)==1)
	{
		if(Passenger_setNombre(pasajero,nombre)==1)
		{
			if(Passenger_setApellido(pasajero,apellido)==1)
			{
				if(Passenger_setCodigoVuelo(pasajero,codigoVuelo)==1)
				{
					if(Passenger_setTipoPasajero(pasajero,tipoPasajero)==1)
					{
						if(Passenger_setEstado(pasajero,estadoPasajero)==1)
						{
							if(Passenger_setPrecio(pasajero,precio)==1)
							{
								isOk = 1;
							}
						}
					}
				}
			}
		}
	}
	return isOk;
}
int AddPassenger(int id, char*nombre, char*apellido, char*tipoPasajero, char*codigoVuelo, char*estadoPasajero, float precio,LinkedList* pArrayListPassenger)
{
	Passenger* pasajero;
	FILE* pArchivo;
	pasajero = Passenger_new();
	int retorno;
	int isOk = 0;
	if(id > 0 && nombre != NULL && apellido != NULL && tipoPasajero != NULL && codigoVuelo != NULL && estadoPasajero != NULL && precio > 0 && pasajero!=NULL)
	{
		pasajero->id = id;
		pasajero->precio = precio;
		Passenger_setNombre(pasajero,nombre);
		Passenger_setApellido(pasajero,apellido);
		Passenger_setCodigoVuelo(pasajero,codigoVuelo);
		Passenger_setTipoPasajero(pasajero,tipoPasajero);
		Passenger_setEstado(pasajero,estadoPasajero);
		CabeceraPrintLista();
		Passenger_print(pasajero);

		printf("inicialice los campos\n");
		retorno = getInt("Desea cargar este pasajero?\n"
					   "1.Si\n"
					   "2.No\n",1,2);
		if(retorno==1)
		{
			ll_add(pArrayListPassenger,pasajero);
			isOk = 1;
			pArchivo = fopen("idRegister.csv","w");
			if(pArchivo != NULL)
			{

					fprintf(pArchivo,"%d\n",id);
			}
			fclose(pArchivo);
		}
		else
		{
			Passenger_delete(pasajero);
		}
	}
	return isOk;
}


////////////////// Getters //////////////////////////////////
int Passenger_getId(Passenger* this,int* id)
{
   int isOk = 0;
   if(this != NULL && id != NULL)
   {
	   *id = this->id;
	   isOk = 1;
   }
   return isOk;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	   int isOk = 0;
	   if(this != NULL && nombre != NULL)
	   {
		   strcpy(nombre,this->nombre);
		   isOk = 1;
	   }
	   return isOk;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	   int isOk = 0;
	   if(this != NULL && apellido != NULL)
	   {
		   strcpy(apellido,this->apellido);
		   isOk = 1;
	   }
	   return isOk;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	   int isOk = 0;
	   if(this != NULL && codigoVuelo != NULL)
	   {
		   strcpy(codigoVuelo,this->codigoVuelo);
		   isOk = 1;
	   }
	   return isOk;
}
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	   int isOk = 0;
	   if(this != NULL && tipoPasajero != NULL)
	   {
		   strcpy(tipoPasajero,this->tipoPasajero);
		   isOk = 1;
	   }
	   return isOk;
}
int Passenger_getEstado(Passenger* this,char* estadoPasajero)
{
	   int isOk = 0;
	   if(this != NULL && estadoPasajero != NULL)
	   {
		   strcpy(estadoPasajero,this->estado);
		   isOk = 1;
	   }
	   return isOk;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	   int isOk = 0;
	   if(this != NULL && precio != NULL)
	   {
		   *precio = this->precio;
		   isOk = 1;
	   }
	   return isOk;
}
int GetterPassenger(Passenger* pasajero, int*id, char*nombre, char*apellido, char*tipoPasajero, char*codigoVuelo, char*estadoPasajero, float* precio)
{
	int isOk = 0;
	if(Passenger_getId(pasajero,id)==1)
	{
		if(Passenger_getNombre(pasajero,nombre)==1)
		{
			if(Passenger_getApellido(pasajero,apellido)==1)
			{
				if(Passenger_getCodigoVuelo(pasajero,codigoVuelo)==1)
				{
					if(Passenger_getTipoPasajero(pasajero,tipoPasajero)==1)
					{
						if(Passenger_getEstado(pasajero,estadoPasajero)==1)
						{
							if(Passenger_getPrecio(pasajero,precio)==1)
							{
								isOk = 1;
							}
						}
					}
				}
			}
		}
	}
	return isOk;

}



//////////////// Print /////////////////////////////////////
void Passenger_print(Passenger* pasajero)
{
	int id;
	char nombre[50];
	char apellido[50];
	char tipoPasajero[20];
	char codigoVuelo[10];
	char estadoPasajero[20];
	int isOk;
	float precio;

    isOk = GetterPassenger(pasajero,&id,nombre,apellido,tipoPasajero,codigoVuelo,estadoPasajero,&precio);

	if(isOk==1)
	{
	printf("|%-5d\t|%-20s\t|%-20s\t|%-8.2f\t|%-15s\t|%-15s\t|%-10s\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoPasajero);
	}
}
int OrdenarPorId(LinkedList* pArrayListPassenger, int order)
{
	int respuesta = -1;
	if(pArrayListPassenger != NULL)
	{
		if(!ll_sort(pArrayListPassenger,ComparaId,order))
		{
			respuesta = 1;
        }
	}
	return respuesta;
}
int OrdenarPorParametros(LinkedList* pArrayListPassenger, int order, int option)
{
	int respuesta = -1;
	if(pArrayListPassenger != NULL)
	{
		switch(option)
		{
		case 1:
			if(!ll_sort(pArrayListPassenger,CompararPorNombre,order))
			{
				respuesta = 1;
			}
		break;
		case 2:
			if(!ll_sort(pArrayListPassenger,CompararPorTipo,order))
			{
				respuesta = 1;
			}
		break;
		case 3:
			if(!ll_sort(pArrayListPassenger,CompararPorEstado,order))
			{
				respuesta = 1;
			}
		break;
		case 4:
			if(!ll_sort(pArrayListPassenger,ComparaPorPrecio,order))
			{
				respuesta = 1;
			}
		break;

		}

	}
	return respuesta;
}
 int CompararPorNombre(void* PasajeroI, void* PasajeroJ)
{
	int respuesta = 0;
	Passenger* pI = NULL;
	Passenger* pJ = NULL;
	char nI[128];
	char nJ[128];
	if(PasajeroI != NULL && PasajeroJ != NULL)
	{
		pI = (Passenger*) PasajeroI;
		pJ = (Passenger*) PasajeroJ;
		if((Passenger_getNombre(pI,nI)) == 1 && (Passenger_getNombre(pJ,nJ)) == 1)
		{
			respuesta = strcmp(nI,nJ);
		}
	}
	return respuesta;
}
int CompararPorTipo(void* PasajeroI, void* PasajeroJ)
{
	int respuesta = 0;
	Passenger* pI = NULL;
	Passenger* pJ = NULL;
	char tI[128];
	char tJ[128];
	if(PasajeroI != NULL && PasajeroJ != NULL)
	{
		pI = (Passenger*) PasajeroI;
		pJ = (Passenger*) PasajeroJ;
		if((Passenger_getTipoPasajero(pI,tI)) == 1 && (Passenger_getTipoPasajero(pJ,tJ)) == 1)
		{
			respuesta = strcmp(tI,tJ);
		}
	}
	return respuesta;
}
int CompararPorEstado(void* PasajeroI, void* PasajeroJ)
{
	int respuesta = 0;
	Passenger* pI = NULL;
	Passenger* pJ = NULL;
	char eI[128];
	char eJ[128];
	if(PasajeroI != NULL && PasajeroJ != NULL)
	{
		pI = (Passenger*) PasajeroI;
		pJ = (Passenger*) PasajeroJ;
		if((Passenger_getEstado(pI,eI)) == 1 && (Passenger_getEstado(pJ,eJ)) == 1)
		{
			respuesta = strcmp(eI,eJ);
		}
	}
	return respuesta;
}
int ComparaPorPrecio(void* PasajeroI, void* PasajeroJ)
{
	int respuesta = 0;
	Passenger* pI = NULL;
	Passenger* pJ = NULL;
	float precioI;
	float precioJ;
	if(PasajeroI != NULL && PasajeroJ != NULL)
	{
		pI = (Passenger*) PasajeroI;
		pJ = (Passenger*) PasajeroJ;
		if((Passenger_getPrecio(pI,&precioI)) == 1 && (Passenger_getPrecio(pJ,&precioJ)) == 1)
		{
			if(precioI > precioJ)
			{
				respuesta = 1;
			}
			else
			{
				if(precioI < precioJ)
				{
					respuesta = -1;
				}
			}
		}
	}
	return respuesta;
}
int ComparaId(void* PasajeroI, void* PasajeroJ)
{
	int respuesta = 0;
	Passenger* pI = NULL;
	Passenger* pJ = NULL;
	int idI;
	int idJ;
	if(PasajeroI != NULL && PasajeroJ != NULL)
	{
		pI = (Passenger*) PasajeroI;
		pJ = (Passenger*) PasajeroJ;
		if((Passenger_getId(pI,&idI)) == 1 && (Passenger_getId(pJ,&idJ)) == 1)
		{
			if(idI > idJ)
			{
				respuesta = 1;
			}
			else
			{
				if(idI < idJ)
				{
					respuesta = -1;
				}
			}
		}
	}
	return respuesta;
}

void CabeceraPrintLista()
{
	printf("|ID  \t|Nombre              \t|Apellido            \t|Precio       \t|Codigo de Vuelo    \t|Tipo de Pasajero   \t|Estado de Pasajero       \n"
					   "|_______|_______________________|_______________________|_______________|_______________________|_______________________|________________________|\n");
}
void PiePrintLista()
{
	printf("|_______|_______________________|_______________________|_______________|_______________________|_______________________|________________________|\n");
}
