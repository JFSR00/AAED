/*
 * estacion.hpp
 *
 *  Created on: 16 ene. 2021
 *      Author: JFSR00
 */

#ifndef ESTACION_HPP_
#define ESTACION_HPP_

#include "pila_din.hpp"

typedef int Tren;

class Estacion{
public:
	Estacion(int =10);
	Estacion(Estacion&);
	Estacion& operator =(const Estacion&);

	void llegada(Tren, int);
	void salida(int);
	void transitoEstacionamiento(Tren);
	void estacionamientoTransito(Tren, int);
	int viaDeTren(Tren);
	Tren trenEnVia(int);

private:
	bool isViaVacia(int);

	int nVias;
	Tren *_vias;
	Pila<Tren> _estacionamiento, _maniobras;
};



#endif /* ESTACION_HPP_ */
