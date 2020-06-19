/*
 * simbolo.cpp
 *
 *  Created on: 19 jun. 2020
 *      Author: JFSR00
 */

#include <cassert>
#include "simbolo.hpp"

Simbolo::Simbolo():nTrazos_(0){}

Simbolo::Simbolo(Simbolo&& s):nTrazos_(s.nTrazos_), simbolo_(s.simbolo_){}

Simbolo::Simbolo(int n, Cola<Direccion> c):nTrazos_(n), simbolo_(c){}

void Simbolo::anadeTrazo(Direccion d){
	simbolo_.push(d);
	nTrazos_++;
}

void Simbolo::deshaceNtrazos(int n){
	assert(n<=nTrazos_);

	Cola<Direccion> aux;
	for(int i=0;i<nTrazos_-n;i++){
		aux.push(simbolo_.frente());
		simbolo_.pop();
	}
	simbolo_=aux;
	nTrazos_=nTrazos_-n;
}

Simbolo Simbolo::simetriaX(){
	Cola<Direccion> res, aux=simbolo_;

	while(!aux.vacia()){
		switch(aux.frente()){
		case Direccion::ARB:
			res.push(Direccion::ABJ);
			break;
		case Direccion::ABJ:
			res.push(Direccion::ARB);
			break;
		default:
			res.push(aux.frente());
			break;
		}
		aux.pop();
	}

	return Simbolo(nTrazos_,res);
}

Simbolo Simbolo::simetriaY(){
	Cola<Direccion> res, aux=simbolo_;

	while(!aux.vacia()){
		switch(aux.frente()){
		case Direccion::IZQ:
			res.push(Direccion::DCH);
			break;
		case Direccion::DCH:
			res.push(Direccion::IZQ);
			break;
		default:
			res.push(aux.frente());
			break;
		}
		aux.pop();
	}

	return Simbolo(nTrazos_,res);
}

Simbolo Simbolo::simetriaXY(){
	return simetriaX().simetriaY();
}

std::ostream& operator <<(std::ostream& os, Simbolo& s){
	Cola<Direccion> aux=s.simbolo_;
	while(!aux.vacia()){
		switch(aux.frente()){
		case Direccion::ARB:
			os<<"ARRIBA\n";
			break;
		case Direccion::ABJ:
			os<<"ABAJO\n";
			break;
		case Direccion::IZQ:
			os<<"IZQUIERDA\n";
			break;
		case Direccion::DCH:
			os<<"DERECHA\n";
			break;
		default:
			break;
		}
		aux.pop();
	}
	os<<s.nTrazos_<<std::endl;
	return os;
}

std::ostream& operator <<(std::ostream& os, Simbolo&& s){
	return operator <<(os,s);
}
/*
El TAD S�mbolo se usa para representar s�mbolos trazados con l�neas rectas. Un S�mbolo es una
sucesi�n de Trazos, un trazo es una l�nea recta que puede tener sentido a izquierda, derecha,
arriba o abajo. El TAD s�mbolo tiene que permitir realizar las siguientes operaciones con un
s�mbolo:
x	- crear un s�mbolo vac�o
x	- a�adir un trazo al final de un s�mbolo
x	- deshacer los �ltimos n trazos
x	- tambi�n debe permitir realizar operaciones que devuelvan el s�mbolo sim�trico
	  respecto al eje X, Y y XY.
 */
