/*
 * cocina.cpp
 *
 *  Created on: 17 jun. 2020
 *      Author: JFSR00
 */

#include "cocina.hpp"

Mueble::Mueble(double p, double a):pos_(p), ancho_(a){}

Cocina::Cocina(double l):longitud_(l), nMuebles_(0){if(longitud_<=0){throw "ERROR";}};

bool Cocina::puedeColocar(Mueble &m){
	bool res=false;
	if(nMuebles_==0){res=true;}
	else{
		if((m.ancho_+m.pos_)>longitud_){res=false;}
		else{
			Lista<Mueble>::posicion p=muebles_.primera();
			res=true;
			while(p!=muebles_.fin() && res==true){
				if((m.ancho_+m.pos_)>muebles_.elemento(p).pos_ && (muebles_.elemento(p).pos_+muebles_.elemento(p).ancho_)>m.pos_){
					res=false;
				}
				p=muebles_.siguiente(p);
			}
		}
	}
	return res;
}

void Cocina::añade(Mueble& m){
	if(puedeColocar(m)){
		if(nMuebles_==0){
			muebles_.insertar(m,muebles_.fin());
		}else{
			Lista<Mueble>::posicion p=muebles_.primera();
			while(p!=muebles_.fin()){
				if(muebles_.elemento(p).pos_>m.pos_){
					muebles_.insertar(m,p);
				}
				p=muebles_.siguiente(p);
			}
		}
		nMuebles_++;
	}
}

Mueble Cocina::muebleIesimo(int i){
	Lista<Mueble>::posicion p=muebles_.primera();
	for(int j=0;j<i;j++){
		p=muebles_.siguiente(p);
	}
	return muebles_.elemento(p);
}

void Cocina::eliminaMuebleIesimo(int i){
	Lista<Mueble>::posicion p=muebles_.primera();
	for(int j=0;j<i;j++){
		p=muebles_.siguiente(p);
	}
	muebles_.eliminar(p);
	nMuebles_--;
}

void Cocina::mueveMueble(int i){
	Mueble aux;
	double posAux_=0;
	if(i!=0){posAux_=muebleIesimo(i-1).pos_+muebleIesimo(i-1).ancho_;}
	aux=muebleIesimo(i);
	aux.pos_=posAux_;
	eliminaMuebleIesimo(i);
	añade(aux);
}

/*
Una empresa de muebles de cocina necesita un TAD para representar el conjunto de muebles colocados
en la pared de una cocina. Una cocina se crea con una longitud positiva, y un mueble colocado en la pared
se identifica con el par formado por su posición (distancia desde su lateral izquierdo al extremo izquierdo
de la pared) y su anchura (la profundidad y altura no tienen interés, pues son iguales para todos los muebles).
El TAD debe soportar las siguientes operaciones:

x	- Crear una cocina vacía con una longitud dada.
x	- Determinar si un mueble de una cierta anchura puede colocarse en una posición dada.
x	- Añadir un mueble de una determinada longitud a una posición dada.
x	- Devolver el mueble i-ésimo de la cocina empezando a contar por la izquierda.
x	- Eliminar el mueble i-ésimo de la cocina, si existe.
x	- Mover el mueble i-ésimo de la cocina (si existe) hacia la izquierda, hasta que se junte con el mueble
	  (i - 1) ésimo o el extremo izquierdo de la pared.
x	- Destruir la cocina.

Se pide:
	a) Especificar el TAD Cocina (30 %).
	b) Diseñar una estructura de datos adecuada para representar el TAD Cocina (10 %).
	c) Implementar las operaciones anteriormente descritas (60 %).
 */
