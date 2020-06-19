/*
 * main.cpp
 *
 *  Created on: 19 jun. 2020
 *      Author: JFSR00
 */

#include <iostream>
#include "simbolo.hpp"

using namespace std;

int main(){
	Simbolo s1;
	s1.anadeTrazo(Direccion::IZQ);
	s1.anadeTrazo(Direccion::ABJ);
	s1.anadeTrazo(Direccion::ABJ);
	s1.anadeTrazo(Direccion::DCH);
	s1.anadeTrazo(Direccion::ARB);
	s1.anadeTrazo(Direccion::IZQ);
	cout<<s1<<"\nSimetr�a X:\n"<<s1.simetriaX()<<"\nSimetr�a Y:\n"<<s1.simetriaY()<<"\nSimetr�a XY:\n"<<s1.simetriaXY()<<endl;
	s1.deshaceNtrazos(3);
	cout<<s1<<endl;
	s1.anadeTrazo(Direccion::IZQ);
	s1.anadeTrazo(Direccion::ABJ);
	cout<<s1<<endl;
	s1.deshaceNtrazos(6);
	return 0;
}
