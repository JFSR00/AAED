/*
 * main.cpp
 *
 *  Created on: 17 jun. 2020
 *      Author: JFSR00
 */

#include <iostream>
#include "cocina.hpp"

using namespace std;

int main(){
	Cocina c1(40);

	c1.anade(Mueble(3.4,1.2));
	c1.anade(Mueble(4.4,1.2));
	c1.anade(Mueble(4.9,1.2));
	c1.anade(Mueble(9.4,1.2));
	c1.anade(Mueble(20,1.2));
	c1.anade(Mueble(30,1.2));
	c1.anade(Mueble(15.4,1.2));
	c1.anade(Mueble(20.5,1.2));
	c1.anade(Mueble(22,1.2));
	cout<<c1<<endl<<endl;
	for(int i=0;i<7;i++){
		c1.mueveMueble(i);
	}
	cout<<c1;
	return 0;
}
