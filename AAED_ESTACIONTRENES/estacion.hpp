/*
 * estacion.hpp
 *
 *  Created on: 16 ene. 2021
 *      Author: JFSR00
 */

#ifndef ESTACION_HPP_
#define ESTACION_HPP_

#include "pila_din.hpp"

typedef int Matricula;

class Estacion{
public:
	Estacion(int =10);

	void llegada(Matricula, int);
	void salida(int);
	void transitoEstacionamiento(Matricula);
	void estacionamientoTransito(Matricula, int);
	int viaDeTren(Matricula);
	Matricula trenEnVia(int);

private:
	bool isViaVacia(int);

	int nVias;
	Matricula *_vias;
	Pila<Matricula> _estacionamiento, _maniobras;
};



#endif /* ESTACION_HPP_ */
