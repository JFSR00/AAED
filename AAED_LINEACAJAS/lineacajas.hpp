/*
 * lineacajas.hpp
 *
 *  Created on: 20 jun. 2020
 *      Author: Juan Francisco
 */

#ifndef LINEACAJAS_HPP_
#define LINEACAJAS_HPP_

#include <ostream>

// En este TAD he implementado la mayoría de funciones en el propio .hpp por no perder tiempo, aunque se que lo correcto
// sería hacerlas inline, tanto para este TAD como para los otros del repositorio, cuyas funciones he implementado en el .cpp

class Cliente{
public:
	Cliente(double i=0):importe(i){};

	double getImporte(){return importe;};
	void setImporte(double i){importe=i;};

private:
	double importe;
};

class Caja{
public:
	Caja(int id=0,double f=0,bool st=false):idCajero(id),fact(f),abierta(st){};

	int getCajero(){return idCajero;};
	double getFacturacion(){return fact;};
	bool isAbierta(){return abierta;};

	void setCajero(int id){idCajero=id;};
	void setFacturacion(double f){fact=f;};
	void setAbierta(bool st){abierta=st;};

private:
	int idCajero;
	double fact;
	bool abierta;
};

class LineaCajas{
public:
	LineaCajas():linea(new Caja[50]){};
	~LineaCajas(){delete linea;};

	void abrirCaja(int,int);
	double cerrarCaja(int);
	void cobrarCliente(int,Cliente);
	double cambiaTurno(Caja*);	// Deconozco qué se debe hacer con las cajas del nuevo turno, asi que recibo las nuevas cajas
	double cerrarCajas();

	friend std::ostream& operator <<(std::ostream&,LineaCajas&);

private:
	Caja *linea;
};

std::ostream& operator <<(std::ostream&,LineaCajas&);

#endif /* LINEACAJAS_HPP_ */
