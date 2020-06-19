/*
 * simbolo.hpp
 *
 *  Created on: 19 jun. 2020
 *      Author: JFSR00
 */

#include <ostream>
#include "cola_din_circ.hpp"

enum Direccion{ARB,ABJ,IZQ,DCH};

class Simbolo{
public:
	Simbolo();
	Simbolo(Simbolo&&);
	explicit Simbolo(int,Cola<Direccion>);

	void anadeTrazo(Direccion);
	void deshaceNtrazos(int);
	Simbolo simetriaX();
	Simbolo simetriaY();
	Simbolo simetriaXY();

	friend std::ostream& operator <<(std::ostream&, Simbolo&);

private:
	int nTrazos_;
	Cola<Direccion> simbolo_;
};

std::ostream& operator <<(std::ostream&, Simbolo&);
std::ostream& operator <<(std::ostream&, Simbolo&&);
