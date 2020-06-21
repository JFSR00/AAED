/*
 * main.cpp
 *
 *  Created on: 20 jun. 2020
 *      Author: Juan Francisco
 */

#include <iostream>
#include "lineacajas.hpp"

using namespace std;

void iniCaja(Caja&, int, double, bool);

int main(){
	Cliente aux;
	Caja l1[50];
	LineaCajas linea;
	iniCaja(l1[0],0,45.54,true);
	iniCaja(l1[23],34,4.5,true);
	iniCaja(l1[2],45,5.6,true);
	iniCaja(l1[31],47,67.48,true);

	linea.abrirCaja(1,23);
	linea.abrirCaja(21,32);
	linea.abrirCaja(32,69);
	linea.abrirCaja(7,54);
	linea.abrirCaja(15,9);

	aux.setImporte(53.43);
	linea.cobrarCliente(1,aux);
	aux.setImporte(3.3);
	linea.cobrarCliente(21,aux);
	aux.setImporte(5.4);
	linea.cobrarCliente(32,aux);
	aux.setImporte(76.12);
	linea.cobrarCliente(7,aux);
	aux.setImporte(9.99);
	linea.cobrarCliente(15,aux);

	cout<<linea<<endl;

	linea.cambiaTurno(l1);

	cout<<linea<<endl;

	aux.setImporte(5.98);
	linea.cobrarCliente(31,aux);

	cout<<linea<<endl;

	cout<<linea.cerrarCajas()<<endl<<linea;

//	aux.setImporte(5.98);
//	linea.cobrarCliente(31,aux);

	return 0;
}

void iniCaja(Caja& caja, int id, double f, bool st){
	caja.setCajero(id);
	caja.setFacturacion(f);
	caja.setAbierta(st);
}
