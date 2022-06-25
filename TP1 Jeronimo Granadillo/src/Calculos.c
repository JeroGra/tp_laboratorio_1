#include "TomaDatosValidaciones.h"
#include "Calculos.h"

float PrecioTarjetaDebito(float numero, int descuento, int aerolinea)
{
	float resultado;
	float operacion;
	ValidacionCalculosPrecio(numero,aerolinea);
	operacion = numero*descuento/100;
    resultado = numero-operacion;

	return resultado;
}

float PrecioTarjetaCredito(float numero, int interes)
{
	float resultado;
	float operacion;

	operacion = numero*interes/100;
	resultado = numero+operacion;

	return resultado;
}

float PrecioConBitcoin(float numero, float bitcoin)
{
	float resultado;

    resultado= numero/bitcoin;

	return resultado;
}

float PrecioUnitario(float numero, int kilometros, int  aerolinea)
{
	float resultado;
	int validacion;
	validacion = ValidacionCalculoUnitario(kilometros, aerolinea);
	if(validacion == 1)
	{
		resultado = numero/kilometros ;
	}


	return resultado;
}

float DiferenciaPrecio(float precioAerolineas, float precioLatam)
{
	float resultado;

	 if(precioAerolineas > precioLatam)
	 {
		 resultado = precioAerolineas-precioLatam;
	 }
	 else
	 {
		 resultado = precioLatam-precioAerolineas;
	 }

	return resultado;
}
