/*
 * main.cpp
 *
 *  Created on: 23 jun. 2020
 *      Author: JFSR00
 */

#include <iostream>
#include "pila_din.hpp"

using namespace std;

class tCubo{
public:
	tCubo(int t=0,bool p=true):tam_(t),pos_(p){};

	int getTamano() const {return tam_;};
	bool isAbajo() const {return pos_;};
	void darVuelta(){pos_=!pos_;};

private:
	int tam_;
	bool pos_;
};

Pila<tCubo> juego(Pila<tCubo>);
int tamMax(Pila<tCubo>);

int main(){
	return 0;
}

Pila<tCubo> juego(Pila<tCubo> P){
	Pila<tCubo> res, aux;
	tCubo cubo;
	int tMax=tamMax(P);

	while(!P.vacia()||!aux.vacia()){
		if(P.vacia()||aux.vacia()){
			if(aux.vacia()){
				while(P.top().getTamano()!=tMax){
					aux.push(P.top());
					P.pop();
				}
				cubo=P.top();
				P.pop();
			}else{
				while(aux.top().getTamano()!=tMax){
					P.push(P.top());
					aux.pop();
				}
				cubo=aux.top();
				aux.pop();
			}

			res.push(cubo);
		}// El programa está terminado en papel
	}

	return res;
}

int tamMax(Pila<tCubo> P){
	int max=0;

	while(!P.vacia()){
		if(P.top().getTamano()>max){
			max=P.top().getTamano();
		}
		P.pop();
	}
	return max;
}
