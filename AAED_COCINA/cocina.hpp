/*
 * cocina.hpp
 *
 *  Created on: 17 jun. 2020
 *      Author: JFSR00
 */

#ifndef COCINA_HPP_
#define COCINA_HPP_

#include "lista_doble.hpp"

typedef struct Mueble{
	double pos_, ancho_;
	Mueble(double,double);
};

class Cocina{
public:
	// Constructor y destructor
	Cocina(double);
	~Cocina(){};

	// Métodos
	bool puedeColocar(Mueble&);
	void añade(Mueble&);
	Mueble muebleIesimo(int);
	void eliminaMuebleIesimo(int);
	void mueveMueble(int);

private:
	double longitud_;
	int nMuebles_;
	Lista<Mueble> muebles_;
};

#endif /* COCINA_HPP_ */
