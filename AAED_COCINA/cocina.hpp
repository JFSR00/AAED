/*
 * cocina.hpp
 *
 *  Created on: 17 jun. 2020
 *      Author: JFSR00
 */

#ifndef COCINA_HPP_
#define COCINA_HPP_

#include <ostream>
#include "lista_doble.hpp"

struct Mueble{
	double pos_, ancho_;
	Mueble(double =0,double =0);
};

class Cocina{
public:
	// Constructor y destructor
	Cocina(double);
	~Cocina(){};

	// Métodos
	bool puedeColocar(Mueble&);
	void anade(Mueble);
	Mueble muebleIesimo(int);
	void eliminaMuebleIesimo(int);
	void mueveMueble(int);

	// He sobrecargado el operador de inserción para poder hacer más fácilmente pruebas del funcionamiento
	friend std::ostream& operator <<(std::ostream&,Cocina&);

private:
	double longitud_;
	int nMuebles_;
	Lista<Mueble> muebles_;
};

std::ostream& operator <<(std::ostream&,Cocina&);

#endif /* COCINA_HPP_ */
