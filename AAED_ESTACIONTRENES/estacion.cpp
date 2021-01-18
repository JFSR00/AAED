/*
 * estacion.cpp
 *
 *  Created on: 16 ene. 2021
 *      Author: JFSR00
 */

#include "pila_din.hpp"
#include "estacion.hpp"

Estacion::Estacion(int n):_vias(new Matricula[n]), nVias(n){}

void Estacion::llegada(Matricula tren, int via){
	if(isViaVacia(via)){
		_vias[via] = tren;
	}
}

void Estacion::salida(int via){
	_vias[via] = 0;
}

void Estacion::transitoEstacionamiento(Matricula tren){
	salida(viaDeTren(tren));
	_estacionamiento.push(tren);
}

void Estacion::estacionamientoTransito(Matricula tren, int via){
	bool fin=false;
	if(isViaVacia(via)){
		while(!_estacionamiento.vacia() && !fin){
			if(_estacionamiento.top() == tren){
				llegada(_estacionamiento.top(), via);
				_estacionamiento.pop();
				fin = true;
			}else{
				_maniobras.push(_estacionamiento.top());
				_estacionamiento.pop();
			}
		}
		while(!_maniobras.vacia()){
			_estacionamiento.push(_maniobras.top());
			_maniobras.pop();
		}
	}
}

int Estacion::viaDeTren(Matricula tren){
	for(int i=0; i<nVias; i++){
		if(_vias[i] == tren){
			return i;
		}
	}
	return -1;
}

Matricula Estacion::trenEnVia(int via){
	return _vias[via];
}

bool Estacion::isViaVacia(int via){
	return (_vias[via] == 0);
}

/*
Ejercicio 2 septiembre, parte 1 (1,2 puntos)
Una estación ferroviaria se compone de N vías para el tránsito de trenes (sólo puede haber un tren en cada una),
una vía muerta para estacionamiento de trenes sin salida inmediata y otra vía muerta de maniobras que se utilizará
sólo para el movimiento de trenes dentro de la estación cuando sea necesario (ambas, supuestamente, de capacidad
ilimitada). Los trenes que circulan por la estación se identifican mediante un código de tren.
a) (1,2 puntos) Especifica el TAD Estación con las siguientes operaciones:
X	Crear una estación de N vías de tránsito.
X	Llegada de un tren concreto a una vía libre dada.
X	Salida de la estación del tren situado en una vía dada.
X	Llevar un determinado tren desde una vía de tránsito a la vía de estacionamiento.
X	Llevar un tren determinado desde la vía de estacionamiento a una de las vías de tránsito.
X	Vía en la que se encuentra un tren.
X	Código del tren situado en una vía de tránsito.
*/
