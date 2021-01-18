/*
 * estacion.cpp
 *
 *  Created on: 16 ene. 2021
 *      Author: JFSR00
 */

#include <cstring>
#include "pila_din.hpp"
#include "estacion.hpp"

Estacion::Estacion(int n):_vias(new Tren[n]), nVias(n){}

Estacion::Estacion(Estacion& cpy):_vias(new Tren[cpy.nVias]), nVias(cpy.nVias){
	memcpy(_vias, cpy._vias, sizeof(Tren)*cpy.nVias);
	_estacionamiento = cpy._estacionamiento;
	_maniobras = cpy._maniobras;
}

Estacion& Estacion::operator =(const Estacion& est){
	this->nVias = est.nVias;

	delete[] this->_vias;
	this->_vias = new Tren[this->nVias];
	memcpy(this->_vias, est._vias, sizeof(Tren)*this->nVias);

	this->_estacionamiento = est._estacionamiento;
	this->_maniobras = est._maniobras;

	return this;
}

void Estacion::llegada(Tren tren, int via){
	if(isViaVacia(via)){
		_vias[via] = tren;
	}
}

void Estacion::salida(int via){
	_vias[via] = 0;
}

void Estacion::transitoEstacionamiento(Tren tren){
	salida(viaDeTren(tren));
	_estacionamiento.push(tren);
}

void Estacion::estacionamientoTransito(Tren tren, int via){
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

int Estacion::viaDeTren(Tren tren){
	for(int i=0; i<nVias; i++){
		if(_vias[i] == tren){
			return i;
		}
	}
	return -1;
}

Tren Estacion::trenEnVia(int via){
	return _vias[via];
}

bool Estacion::isViaVacia(int via){
	return (_vias[via] == 0);
}

/*
Ejercicio 2 septiembre, parte 1 (1,2 puntos)
Una estaci�n ferroviaria se compone de N v�as para el tr�nsito de trenes (s�lo puede haber un tren en cada una),
una v�a muerta para estacionamiento de trenes sin salida inmediata y otra v�a muerta de maniobras que se utilizar�
s�lo para el movimiento de trenes dentro de la estaci�n cuando sea necesario (ambas, supuestamente, de capacidad
ilimitada). Los trenes que circulan por la estaci�n se identifican mediante un c�digo de tren.
a) (1,2 puntos) Especifica el TAD Estaci�n con las siguientes operaciones:
X	Crear una estaci�n de N v�as de tr�nsito.
X	Llegada de un tren concreto a una v�a libre dada.
X	Salida de la estaci�n del tren situado en una v�a dada.
X	Llevar un determinado tren desde una v�a de tr�nsito a la v�a de estacionamiento.
X	Llevar un tren determinado desde la v�a de estacionamiento a una de las v�as de tr�nsito.
X	V�a en la que se encuentra un tren.
X	C�digo del tren situado en una v�a de tr�nsito.
*/
