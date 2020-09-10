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
	Pila<tCubo> ej1,res;
	ej1.push(tCubo(1,true));
	ej1.push(tCubo(3,false));
	ej1.push(tCubo(5,false));
	ej1.push(tCubo(4,true));
	ej1.push(tCubo(2,false));

	res=juego(ej1);

	while(!res.vacia()){
		cout<<res.top().getTamano()<<"\t"<<boolalpha<<res.top().isAbajo()<<endl;
		res.pop();
	}

	return 0;
}

Pila<tCubo> juego(Pila<tCubo> P){
	Pila<tCubo> res, aux;
	tCubo cubo;
	int tMax = 0;

	while(!P.vacia()){
		tMax = tamMax(P);

		while(P.top().getTamano()!=tMax){
			aux.push(P.top());
			P.pop();
		}
		cubo=P.top();
		P.pop();

		if(!cubo.isAbajo()){cubo.darVuelta();}
		res.push(cubo);

		while(!aux.vacia()){
			P.push(aux.top());
			aux.pop();
		}
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
