#include "ArrayPasajeros.h"
#include "Input.h"


Passenger DarAlta(Passenger* listaPasajeros,int size,eTipoPasajero* estadoPasajero, int sizeTipo,eEstadoVuelo* estadoVuelo, int sizeV)
{
	Passenger pasajero;
	pasajero.id = GeneradorId(listaPasajeros,size);

    getString(pasajero.name,"Ingrese el nombre del pasajero/a: \n",51);
    TrasnsformarNombres(pasajero.name);

    getString(pasajero.lastname,"Ingrese el apellido del pasajero/a: \n",51);
    TrasnsformarNombres(pasajero.lastname);

    pasajero.price = getFloat("Coloque el precio del pasaje: \n",99,200000);// precio en usd

    getString(pasajero.flycode,"Ingrese el codigo de vuelo del pasajero/a: \n",10);
    strlwr(pasajero.flycode);

    pasajero.typePassenger = TipoDePasajero(estadoPasajero,sizeTipo);

    pasajero.status = EstadoDePasajero(estadoVuelo,sizeV);

    pasajero.isEmpty = FALSE;

	return pasajero;

}
int initPassenger(Passenger listaPasajeros[],int size)
{
	int respuesta = TRUE;
	for(int i = 0; i<size;i++)
	{
	   listaPasajeros[i].isEmpty = 0;
	   listaPasajeros[i].id = 0;
	}
	return respuesta;
}

int BuscarEspacioLibre(Passenger* listaPasajeros,int size)
{
	int respuesta = FALSE;
	for(int i = 0; i<size;i++)
	{
	  if(listaPasajeros[i].isEmpty == TRUE)
	  {
		  respuesta = i;
	  }
	}
	return respuesta;
}
int VerificarExistencia(Passenger listaPasajeros[],int size)
{
	int respuesta = FALSE;
		for(int i = 0; i<size;i++)
		{
		  if(listaPasajeros[i].isEmpty == FALSE)
		  {
			  respuesta = i;
			  break;
		  }
		}
	return respuesta;
}

int GeneradorId(Passenger listaPasajeros[],int size)
{
	int nuevoId = 0;
	OrdenarPorIdMayor(listaPasajeros,size);
	nuevoId = listaPasajeros[0].id + 1;
    return nuevoId;
}

void Hradcode(Passenger listaPasajeros[])
{
  Passenger auxiliar[5]={{100,"Pablo","Zarcia",5000,"dsasd",BUSINESS,ACTIVO,FALSE},{2,"Maria","Martinez",3500,"eadaw",NORMAL,EN_TRAMITE,FALSE},{30,"Ana","Hernandez",10000,"agrjg",ROYAL,FINALIZADO,FALSE},{50,"Tomas","Amaria",3500,"uyuiy",NORMAL,FINALIZADO,FALSE},{20,"Alan","Mercedes",4500,"ejkiq",BUSINESS,ACTIVO,FALSE}};
  for(int i = 0; i<5;i++)
  {
	  listaPasajeros[i] = auxiliar[i];
  }
}

void OrdenarPorIdMayor(Passenger listaPasajeros[],int size)
{
	Passenger auxiliar;

		for(int i = 0; i < size-1; i++)
		{
			for(int j = i+1; j < size;j++)
			{
				if(listaPasajeros[i].id < listaPasajeros[j].id)
				{
					auxiliar = listaPasajeros[i];
					listaPasajeros[i] = listaPasajeros[j];
					listaPasajeros[j] = auxiliar;
				}
			}
		}
}

void OrdenarPorIdTipo(eTipoPasajero estadoPasajero[], int sizeTipo)
{
	eTipoPasajero auxiliar;

		for(int i = 0; i < sizeTipo-1; i++)
		{
			for(int j = i+1; j < sizeTipo;j++)
			{
				if(estadoPasajero[i].idTipo > estadoPasajero[j].idTipo)
				{
					auxiliar = estadoPasajero[i];
					estadoPasajero[i] = estadoPasajero[j];
					estadoPasajero[j] = auxiliar;
				}
			}
		}
}

int SortPassenger(Passenger* listaPasajeros, int size)
{
	int respuesta;
	Passenger auxiliar;
		for(int i = 0; i < size-1; i++)
			{
				for(int j = i+1; j < size;j++)
				{
					if(listaPasajeros[i].isEmpty == FALSE && strcmp(listaPasajeros[i].lastname,listaPasajeros[j].lastname)>0)
					{
						auxiliar = listaPasajeros[i];
						listaPasajeros[i] = listaPasajeros[j];
						listaPasajeros[j] = auxiliar;
					}
					else
					{
						if(strcmp(listaPasajeros[i].lastname,listaPasajeros[j].lastname)==0)
						{
							if(listaPasajeros[i].isEmpty == FALSE && listaPasajeros[i].status < listaPasajeros[j].status)
							{
								auxiliar = listaPasajeros[i];
								listaPasajeros[i] = listaPasajeros[j];
								listaPasajeros[j] = auxiliar;
							}
						}
					}
				}
			}
		respuesta = 0;
    return respuesta;
}
int SortPassengerByCode(Passenger* listaPasajeros,int size,eTipoPasajero* estadoPasajero, int sizeTipo,eEstadoVuelo* estadoVuelo, int sizeV)
{
	int respuesta;
	Passenger auxiliar;
		for(int i = 0; i < size-1; i++)
			{
				for(int j = i+1; j < size;j++)
				{
					if(listaPasajeros[i].isEmpty == FALSE &&  strcmp(listaPasajeros[i].flycode,listaPasajeros[j].flycode)>0)
					{
						auxiliar = listaPasajeros[i];
						listaPasajeros[i] = listaPasajeros[j];
						listaPasajeros[j] = auxiliar;
					}
				}
			}
		for(int i = 0; i<size;i++)
		{
			for(int j = 0; j<sizeTipo;j++)
			{
				for(int z = 0; z<sizeV;z++)
				{
					if(listaPasajeros[i].isEmpty == FALSE && estadoPasajero[j].idTipo == listaPasajeros[i].typePassenger && listaPasajeros[i].status == ACTIVO &&listaPasajeros[i].status == estadoVuelo[z].id)
					{
						PrintPassenger(listaPasajeros[i],estadoPasajero[j],estadoVuelo[z]);
					}
				}
			}
		}


		respuesta = 0;
    return respuesta;
}

int addPassenger(Passenger* listaPasajeros,int size,eTipoPasajero* estadoPasajero, int sizeTipo,eEstadoVuelo* estadoVuelo, int sizeV)
{
	int respuesta;
	respuesta = BuscarEspacioLibre(listaPasajeros, size);
	if(respuesta != -1)
	{
		switch(getIntMasIntentos("\n1.Realizar Operacion\n2.Cancelar Operacion\nElija una opcion: \n", 1, 2,3,0))
		{
		case 1:
			listaPasajeros[respuesta] = DarAlta(listaPasajeros,size,estadoPasajero,sizeTipo,estadoVuelo,sizeV);
		break;
		case 2:
			 respuesta = -2;
		break;
		}
	}
	return respuesta;
}

int TipoDePasajero(eTipoPasajero estadoPasajero[], int sizeTipo)
{
   int tipoPasajero;
   OrdenarPorIdTipo(estadoPasajero,sizeTipo);
   MostrarListaTipoPasajero(estadoPasajero,sizeTipo);
   tipoPasajero = getInt("Ingrese una opcion: \n",estadoPasajero[0].idTipo,estadoPasajero[sizeTipo-1].idTipo);
   return tipoPasajero;
}
int EstadoDePasajero(eEstadoVuelo estadoVuelo[], int sizeV)
{
   int tipoPasajero;
   OrdenarPorIdEstado(estadoVuelo,sizeV);
   MostrarListaEstado(estadoVuelo,sizeV);
   tipoPasajero = getInt("Ingrese una opcion: \n",estadoVuelo[0].id,estadoVuelo[sizeV-1].id);
   return tipoPasajero;
}
void OrdenarPorIdEstado(eEstadoVuelo estadoVuelo[], int sizeV)
{
	eEstadoVuelo auxiliar;

		for(int i = 0; i < sizeV-1; i++)
		{
			for(int j = i+1; j < sizeV;j++)
			{
				if(estadoVuelo[i].id > estadoVuelo[j].id)
				{
					auxiliar = estadoVuelo[i];
					estadoVuelo[i] = estadoVuelo[j];
					estadoVuelo[j] = auxiliar;
				}
			}
		}
}
void MostrarListaEstado(eEstadoVuelo estadoVuelo[], int sizeV)
{
 for(int i = 0; i<sizeV;i++)
 {
	 printf("ID:%d - Estado: %s \n",estadoVuelo[i].id,estadoVuelo[i].estado);
 }
}
void MostrarListaTipoPasajero(eTipoPasajero estadoPasajero[], int sizeTipo)
{
 for(int i = 0; i<sizeTipo;i++)
 {
	 printf("ID:%d - Estado: %s \n",estadoPasajero[i].idTipo,estadoPasajero[i].estado);
 }
}
int ModifyPassenger(Passenger* listaPasajeros,int size,eTipoPasajero* estadoPasajero, int sizeTipo,eEstadoVuelo* estadoVuelo, int sizeV)
{
	int respuesta;
	respuesta = VerificarExistencia(listaPasajeros, size);
	int menuOpciones;
	int idPassenger;
	if(respuesta != -1)
	{
		switch(getIntMasIntentos("\n1.Realizar Operacion\n2.Cancelar Operacion\nElija una opcion: \n", 1, 2,3,2))
		{
		case 1:
			idPassenger = FindPassengerById(listaPasajeros,size,estadoPasajero,sizeTipo,estadoVuelo,sizeV);
			do{
			menuOpciones =getIntMasIntentos("Que desea modificar?\n1.Nombre\n2.Apellido\n3.Codigo de vuelo\n4.Tipo de pasajero\n5.Precio de vuelo\n6.Salir\n",1,6,3,0);
				switch(menuOpciones)
				{
				case 1:
					getString(listaPasajeros[idPassenger].name,"Ingrese el nombre del pasajero/a: \n",51);
					TrasnsformarNombres(listaPasajeros[idPassenger].name);
					printf("Cambio de nombre realizado\n");
				break;
				case 2:
					getString(listaPasajeros[idPassenger].lastname,"Ingrese el apellido del pasajero/a: \n",51);
					TrasnsformarNombres(listaPasajeros[idPassenger].lastname);
					printf("Cambio de apellido realizado\n");
				break;
				case 3:
					 getString(listaPasajeros[idPassenger].flycode,"Ingrese el codigo de vuelo del pasajero/a: \n",10);
					 strlwr(listaPasajeros[idPassenger].flycode);
					 printf("Cambio de codigo de vuelo realizado\n");
				break;
				case 4:
					listaPasajeros[idPassenger].typePassenger = TipoDePasajero(estadoPasajero,sizeTipo);
				break;
				case 5:
					listaPasajeros[idPassenger].price = getFloat("Coloque el precio del pasaje: \n",99,200000);
				break;
				}
			}while(menuOpciones!=6);
		break;
		case 2:
			 respuesta = -2;
		break;
		}
	}
	return respuesta;
}
int RemovePassenger(Passenger* listaPasajeros,int size,eTipoPasajero* estadoPasajero, int sizeTipo,eEstadoVuelo* estadoVuelo, int sizeV)
{
	int respuesta;
	int idPassenger;
	respuesta = VerificarExistencia(listaPasajeros, size);
	if(respuesta != -1)
	{
		switch(getIntMasIntentos("\n1.Realizar Operacion\n2.Cancelar Operacion\nElija una opcion: \n", 1, 2,3,2))
		{
		case 1:
			idPassenger = FindPassengerById(listaPasajeros,size,estadoPasajero,sizeTipo,estadoVuelo,sizeV);
			listaPasajeros[idPassenger].isEmpty = TRUE;
			printf("Pasajero eliminado con exito\n");
		break;
		case 2:
			 respuesta = -2;
		break;
		}
	}
	return respuesta;
}
int FindPassengerById(Passenger* listaPasajeros,int size,eTipoPasajero* estadoPasajero, int sizeTipo,eEstadoVuelo* estadoVuelo, int sizeV)
{
	int respuesta;
	int existencia = FALSE;
	int i;
	PassengerList(listaPasajeros,size,estadoPasajero,sizeTipo,estadoVuelo,sizeV);
	respuesta = getInt("Elija el id del pasajero existente: \n",0,size-1);
	for(i = 0; i<size;i++)
	{
	  if(listaPasajeros[i].isEmpty == FALSE && respuesta == listaPasajeros[i].id)
	  {
		  existencia = TRUE;
		  break;
	  }
	}
    if(existencia == FALSE )
    {
		 while(existencia != TRUE)
		 {
			printf("ERROR\n");
			PassengerList(listaPasajeros,size,estadoPasajero,sizeTipo,estadoVuelo,sizeV);
			respuesta = getInt("elija de vuelta: \n",0,size-1);
			for(i = 0; i<size;i++)
			{
			  if(listaPasajeros[i].isEmpty == FALSE && respuesta == listaPasajeros[i].id)
			  {
				  existencia = TRUE;
				  break;
			  }
			}
		}
    }

	return i;
}
void PassengerList(Passenger listaPasajeros[],int size,eTipoPasajero estadoPasajero[], int sizeTipo,eEstadoVuelo estadoVuelo[], int sizeV)
{
	for(int i = 0;i< size;i++)
	{
		if(listaPasajeros[i].isEmpty == FALSE)
		{
			CompararFkConPk(listaPasajeros[i],estadoPasajero,sizeTipo,estadoVuelo,sizeV);
		}
	}
}
void CompararFkConPk(Passenger listaPasajeros,eTipoPasajero* estadoPasajero, int sizeTipo,eEstadoVuelo* estadoVuelo, int sizeV)
{
	int tipoEsIgual;
	int j;

	for(j = 0; j < sizeTipo; j++)
	{
		if(listaPasajeros.typePassenger == estadoPasajero[j].idTipo)
		{
           tipoEsIgual = 1;
           break;
		}
	}

	if(tipoEsIgual == 1)
	{
		for(int z = 0; z<sizeV; z++)
		{
		   if(listaPasajeros.status == estadoVuelo[z].id)
		   {
			   PrintPassenger(listaPasajeros,estadoPasajero[j],estadoVuelo[z]);
			   break;
		   }
		}
	}

}
void PrintPassenger(Passenger listaPasajeros, eTipoPasajero estadoPasajero, eEstadoVuelo estadoV)
{
  printf("Id: %d - Name: %s - LastName: %s - flycode: %s - Type: %s - Status: %s - flight price: usd%.2f\n",listaPasajeros.id,listaPasajeros.name,listaPasajeros.lastname,listaPasajeros.flycode,estadoPasajero.estado,estadoV.estado,listaPasajeros.price);
}

void OperacionPrecio(Passenger listaPasajeros[],int size,eTipoPasajero estadoPasajero[], int sizeTipo,eEstadoVuelo estadoVuelo[], int sizeV)
{
	float precioTotal = 0;
	float promedio;
	float contadorPasajeros = 0;
	for(int i = 0; i < size; i++)
	{
		if(listaPasajeros[i].isEmpty == FALSE)
		{
		 precioTotal = listaPasajeros[i].price + precioTotal;
		 contadorPasajeros++;
		}
	}
	promedio = precioTotal/contadorPasajeros;
	printf("Precio total adquirido de los pasajes: usd%.2f\nPrecio promedio de los pasajes: usd%.2f\n",precioTotal,promedio);

	printf("Pasajeros con un valor de pasaje superior al promedio\n");
	for(int i = 0; i < size; i++)
	{
		for(int j = 0;j<sizeTipo;j++)
		{
			for(int z = 0;z<sizeV;z++)
			{
				if(listaPasajeros[i].isEmpty == FALSE && listaPasajeros[i].price > promedio && listaPasajeros[i].typePassenger ==  estadoPasajero[j].idTipo && listaPasajeros[i].status == estadoVuelo[z].id)
				{
					PrintPassenger(listaPasajeros[i],estadoPasajero[j],estadoVuelo[z]);
				}
			}
		}
	}

}

void SubMenuOpcionCuatro(Passenger listaPasajeros[],int size,eTipoPasajero estadoPasajero[], int sizeTipo,eEstadoVuelo estadoVuelo[], int sizeV)
{
	int subMenu;
	int retorno;
	do{
		subMenu = getIntMasIntentos("\nMENU DE LISTAS\n1.Lista de pasajeros/as ordenada por apellido y tipo\n2.Precio total de pasajes, promedio y pasajes sobre el promedio\n3.Lista ordenada por codigo de vuelo y estado de vuelo 'ACTIVO'\n4.Volver al menu principal\nElija una opcion: \n",1,4,3,0);
		switch(subMenu)
		{
			case 1:
				retorno = SortPassenger(listaPasajeros,size);
				if(retorno == 0)
				{
					PassengerList(listaPasajeros,size,estadoPasajero,sizeTipo,estadoVuelo,sizeV);
				}
				else
				{
					printf("Ups, algo salio mal T~T\n");
				}
			break;
			case 2:
				  OperacionPrecio(listaPasajeros,size,estadoPasajero,sizeTipo,estadoVuelo,sizeV);
			break;
			case 3:
				retorno = SortPassengerByCode(listaPasajeros,size,estadoPasajero,sizeTipo,estadoVuelo,sizeV);
				if(retorno != 0)
				{
					printf("Ups, algo salio mal T~T\n");
				}
			break;
		}
	}while(subMenu != 4);
}



