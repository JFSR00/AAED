/*
 * main.cpp
 *
 *  Created on: 7 sept. 2020
 *      Author: JFSR00
 */

#include <iostream>
#include <algorithm>
#include "cronometro.h"

using namespace std;

bool simetrica(int **M, int n){
	bool b = true;
	int i = 0;
	while (b && i < n){
		int j = i + 1;
		while (b && j < n){
			b = (M[i][j] == M[j][i]);
			++j;
		}
		++i;
	}
	return b;
}

/*
Implemente un programa para analizar experimentalmente el tiempo de ejecución de la función
anterior en el caso peor, utilizando un esquema adaptativo de medida indirecta. El programa
tomará medidas para matrices de orden 50 hasta 1 000 en incrementos de 50. Se asume que la
resolución del cronómetro es 0,01s. y que el error relativo máximo admitido es 0,1%.
 */

int main(){
	for(int n=50;n<=1000;n+=50){
		//int M[n][n], T[n][n];

		// Variables para la medición de tiempo
		cronometro c;
		long int r = 0;
		const double e_abs = 0.01, // Máximo error absoluto cometido.
					e_rel = 0.01; // Máximo error relativo aceptado.

		// Creación de los arrays bidimensionales
		int **M,**T;
		M = new int *[n];
		for(int i=0;i<n;i++)
		    M[i] = new int[n];
		T = new int *[n];
		for(int i=0;i<n;i++)
		    T[i] = new int[n];

		// Creación de una matriz simétrica - Creamos una matriz simétrica porque es el peor caso
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				M[i][j]=j;
				T[j][i]=j;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				M[i][j]+=T[j][i];
			}
		}

		// Medición del tiempo de ejecución
		c.activar();
		do{
			simetrica(M,n);
			r++;
		}while(c.tiempo()<e_abs/e_rel+e_abs);
		c.parar();
		double t=c.tiempo()/r;

		cout<<"Tiempo para N = "<<n<<": "<<t<<" ms"<<endl;
	}
	return 0;
}
