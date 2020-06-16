/*
 * main.cpp
 *
 *  Created on: 16 jun. 2020
 *      Author: Juan Francisco
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include "pila.hpp"

using namespace std;

int calcula(char*,char*);
int buscaValor(char*,char);

int main(){
	cout<<buscaValor("A34B7C45D9",'D');
	return 0;
}

int calcula(char* exp, char* var){
	Pila<int> res;
	return 0;
}

int buscaValor(char* l, char v){
	Pila<int> datos;
	int valor=0;
	for(int i=0;i<strlen(l);i++){
		if(l[i]==v){
			int j=1,cont=0;
			while(isdigit(l[i+j])&&(i+j)<strlen(l)){
				datos.push(l[i+j]-'0');
				j++;
			}
			while(j>1){
				valor+=datos.tope()*(pow(10,cont));
				datos.pop();
				cont++;
				j--;
			}
			break;
		}
	}
	return valor;
}
