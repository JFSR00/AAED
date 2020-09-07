/*
 * main.cpp
 *
 *  Created on: 7 sept. 2020
 *      Author: JFSR00
 */

#include <iostream>
#include "cronometro.h"

const int N = 5;

using namespace std;

bool simetrica(int M[N][N], int n){
	bool b = true;
	int i = 0;
	while (b && i < n){
		int j = i + 1;
		while (b && j < n){
			b = (M[i][j ] == M[j][i]);
			++j;
		}
		++i;
	}
	return b;
}

int main(){
	return 0;
}
