#ifndef CALCULOS_H_
#define CALCULOS_H_
#include <stdlib.h>

/// @brief Calcula el precio del pasaje si se pagara con tarjeta de debito, toma el precio bruto, y le aplica un descuento
/// @param numero recibe el precio bruto, varia segun la aerolinea
/// @param descuento recibe el descuento, en este caso se define como un 10%
/// @param aerolinea recibe el codigo de la aerolinea LATAM o AERO, este codigo le sirve para al llamar a las validaciones pasarlo ya que estas lo requieren.
/// @return devuelve un flotante con el precio final que se ofrece al pagar con tarjeta de debito
float PrecioTarjetaDebito(float numero, int descuento,  int aerolinea);

/// @brief Calcula el precio del pasaje si se pagara con tarjeta de credito, toma el precio bruto y le aplica intereses.
/// @param numero recibe el precio bruto, varia segun la aerolinea.
/// @param interes recibe la tasa de interes, en este caso es de 25%
/// @return devuelve un flotante con el precio final que se ofrece al pagar con tarjeta de credito
float PrecioTarjetaCredito(float numero, int interes);

/// @brief Pasa el precio bruto del pasaje al valor de bitcoin, para poder saber cuantos bitcoins hay que pagar para obtener el pasaje
/// @param numero recibe el precio bruto, varia segun la aerolinea.
/// @param Bitcoin recibe el precio de Bitcoin, este precio se encuentra definido en BTC asi que puede ser cambiado cuando se desee actualizar el precio del bitcoin.
/// @return devuelve un flotante con el precio final pasado a Bitcoin que se ofrece al pagar con Bitcoins
float PrecioConBitcoin(float numero, float Bitcoin);

/// @brief Calcula el precio bruto por kilometros, es decir precio por kilometro.
/// @param numero recibe el precio bruto del pasaje, varia segun aerolinea
/// @param kilometros recibe los kilometros colocados.
/// @param aerolinea recibe el codigo de la aerolinea LATAM o AERO, este codigo le sirve para al llamar a las validaciones pasarlo ya que estas lo requieren.
/// @return devuleve un flotante que hace referencia al pecio unitaio, (precio por kilometro)
float PrecioUnitario(float numero, int kilometros, int  aerolinea);

/// @brief Calcula el precio o valor diferencial entre los precios brutos de las aerolineas
/// @param precioAerolineas recibe el pecio buto de Aerolineas Argentinas
/// @param precioLatam recibe el precio bruto de Latam
/// @return devuelve un flotante que hace referencia al diferencial de precio entre las dos aerolineas.
float DiferenciaPrecio(float precioAerolineas, float precioLatam);

#endif /* CALCULOS_H_ */
