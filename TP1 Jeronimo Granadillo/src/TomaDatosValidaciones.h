#ifndef TOMADATOSVALIDACIONES_H_
#define TOMADATOSVALIDACIONES_H_
#include <stdio.h>
#include <stdlib.h>

/// @brief Valida que las opciones ingresadas en el menu principal sean existentes.
/// @param mensaje Da un mensaje en donde pide colocar una de las opciones dadas en el menu principal, luego se toma el mensaje y se pasa a un numero entero.(1,2 ,3,4,5 o 6)
/// @param min se establece un minimo numero para validar las opciones, este numero es la OPCION 1
/// @param max se establece un maximo numero para validar las opciones, este numero es la OPCION 6
/// @return devuelve el entero validado para luego compararlo en el switch y entrar a las opciones.
int ValidacionMenu(char mensaje[],int min,int max );


/// @brief Valida los kilometros ingresados, para luego hacer las operaciones con dichos kilometros
/// @param mensaje Da un mensaje donde pide ingresar los Kilometros, se toma el numero del mensaje y se pasa a entero.
/// @param min se establece un minimo de kilometros para  validarlos
/// @param max se establece un maximo de kilometros para validarlos
/// @return devuleve un entero (Kilometros) validado.
int ValidacionKilometros(char mensaje[], int min, int max);

/// @brief Valida el precio de Aerolineas Argentinas, para luego poder hacer los calculos.
/// @param mensaje pide un mensaje donde se ingresara un numero, luego toma el numero del mensaje y lo pasa a flotante
/// @param min se establece un numero minimo en el precio del pasaje
/// @param max se establece un numero maximo en el precio del pasaje
/// @return devuelve el precio ya validado en forma de flotante
float ValidacionPrecioAerolineas(char mensaje[], int min, int max);

/// @brief Valida el precio de Latam, para luego poder hacer los calculos.
/// @param mensaje pide un mensaje donde se ingresara un numero, luego toma el numero del mensaje y lo pasa a flotante
/// @param min se establece un numero minimo en el precio del pasaje
/// @param max se establece un numero maximo en el precio del pasaje
/// @return devuelve el precio ya validado en forma de flotante
float ValidacionPrecioLatam(char mensaje[], int min, int max);

/// @brief Valida que las opciones ingresadas en el menu de ingreso de precios sean existentes.
/// @param mensaje Da un mensaje en donde pide colocar una de las opciones dadas en el menu principal, luego se toma el mensaje y se pasa a un numero entero.(1,2 o 3)
/// @param min se establece un minimo numero para validar las opciones, este numero es la OPCION 1
/// @param max se establece un maximo numero para validar las opciones, este numero es la OPCION 3
/// @return devuelve el entero validado para luego compararlo en el switch y entrar a las opciones.
int ValidacionMenu2(char mensaje[],int min,int max );

/// @brief Valida si es posible calcular el precio unitario
/// @param kilometros toma los kilometros enviados desde la funcion (PrecioUnitario) y los compara en un if si son menores a 1.
/// @param aerolinea toma el numero correspondiente a la arolinea (AERO = 1, LATAM = 2)
/// @return devuelve 1 (si es posible hacer el calculo), 0 (si no lo es). al devolver 1 se efectua el calculo.
int ValidacionCalculoUnitario(int kilometros, int  aerolinea);

/// @brief Se encarga de mostrar mensajes de error al querer hacer calculos con datos vacios (por ejemplo Kms= 0 o precio de pasajes = 0)
/// @param error toma el codigo de error enviado desde la funcion que la llama(ejemplo: EPG(nombre de error) = 02(valor)  hace referencia a que falta ingresar un valor mayor a 0 en los pasajes)
/// @param aerolinea toma el numero correspondiente a la arolinea (AERO = 1, LATAM = 2)
void MensajeDeErrorCalculos(int error, int  aerolinea);

/// @brief Valida si es posible calcular los metodos de pago
/// @param numero recibe un numero que luego comparar si es menor a 1, en caso de que sea menor llama a la funcion MensajeDeErrorCalculos y en caso de que sea mayor llama a MensajeDeConfirmacion
/// @param aerolinea toma el numero correspondiente a la arolinea (AERO = 1, LATAM = 2)
void ValidacionCalculosPrecio(int numero, int aerolinea);

/// @brief Se encarga de mostrar que es posible realizar los calculos requeridos.
/// @param confirmacion recibe el codigo de confirmacion que contiene un valor (ejemplo CONFK = 12 que hace referencia a que existe un valor mayor a 1 en los kilometros para poder realizar la operacion)
/// @param aerolinea toma el numero correspondiente a la arolinea (AERO = 1, LATAM = 2)
void MensajeDeConfirmacion(int confirmacion, int aerolinea);
#endif /* TOMADATOSVALIDACIONES_H_ */
