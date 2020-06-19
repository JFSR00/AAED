/*
 * main.cpp
 *
 *  Created on: 18 jun. 2020
 *      Author: JFSR00
 */

#include <iostream>
#include "consultorio.hpp"

using namespace std;

int main(){
	Medico m0,m2(2),m5(5);
	Paciente p0,p1("Rodolfo Eustaquio", "González Vázquez", "47473434Z"),p2("Ramira", "Sánchez Quiñones", "78789898X"),
			p3("Joseph", "Goebbels", "99999999Z");
	Consultorio c1;
	c1.alta(m0);
	cout<<c1<<endl;
	c1.alta(m2);
	c1.alta(m5);
	cout<<c1<<endl;
	c1.anadePaciente(m0,p0);
	c1.anadePaciente(m2,p1);
	c1.anadePaciente(m2,p2);
	c1.anadePaciente(m5,p3);
	cout<<c1<<endl;
	c1.atenderPaciente(m2);
	cout<<c1<<endl;
	c1.atenderPaciente(m0);
	cout<<c1<<endl;
	c1.baja(m2);
	cout<<c1<<endl;
	cout<<"Siguiente paciente del médico 5:\n\t"<<c1.siguientePaciente(m5).nom_<<"\n\t"
	<<c1.siguientePaciente(m5).ape_<<"\n\t"<<c1.siguientePaciente(m5).dni_<<endl;
	return 0;
}
