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

int calcula(const char*,const char*);
int buscaValor(const char*,char);

int main(){
	cout<<calcula("CBA-/","A3B5C6");
	return 0;
}

int calcula(const char* exp, const char* var){
	Pila<int> res;
	int i=0;
	while(i<(int)strlen(exp)){
		if(exp[i]!='+'&&exp[i]!='-'&&exp[i]!='*'&&exp[i]!='/'){
			res.push(buscaValor(var,exp[i]));
		}else{
			int a=0,b=0;
			b=res.tope();
			res.pop();
			a=res.tope();
			res.pop();
			switch(exp[i]){
			case '+':
				res.push(a+b);
				break;
			case '-':
				res.push(a-b);
				break;
			case '*':
				res.push(a*b);
				break;
			case '/':
				res.push(a/b);
				break;
			default:
				break;
			}
		}
		i++;
	}
	return res.tope();
}

int buscaValor(const char* l, char v){
	Pila<int> datos;
	int valor=0;
	for(int i=0;i<(int)strlen(l);i++){
		if(l[i]==v){
			int j=1,cont=0;
			while(isdigit(l[i+j])&&(i+j)<(int)strlen(l)){
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
