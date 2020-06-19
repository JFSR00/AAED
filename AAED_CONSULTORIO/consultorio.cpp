/*
 * consultorio.cpp
 *
 *  Created on: 18 jun. 2020
 *      Author: JFSR00
 */

#include "consultorio.hpp"

Paciente::Paciente(std::string n, std::string a, std::string d):nom_(n), ape_(a), dni_(d){}

Medico::Medico(int id):id_(id){}

Medico::Medico(const Medico& m):id_(m.id_){
	listaEspera_=m.listaEspera_;
}

bool Medico::operator ==(const Medico& m){
	return id_==m.id_;
}

void Consultorio::alta(const Medico& m){
	medicos_.insertar(m,medicos_.fin());
}

void Consultorio::baja(const Medico& m){
	medicos_.eliminar(medicos_.buscar(m));
}

void Consultorio::anadePaciente(const Medico& m, Paciente p){
	medicos_.elemento(medicos_.buscar(m)).listaEspera_.push(p);
}

Paciente Consultorio::siguientePaciente(const Medico& m){
	return medicos_.elemento(medicos_.buscar(m)).listaEspera_.frente();
}

void Consultorio::atenderPaciente(const Medico& m){
	medicos_.elemento(medicos_.buscar(m)).listaEspera_.pop();
}

bool Consultorio::tienePaciente(const Medico& m){
	return !medicos_.elemento(medicos_.buscar(m)).listaEspera_.vacia();
}

std::ostream& operator <<(std::ostream& os, Consultorio& c){
	Lista<Medico>::posicion p=c.medicos_.primera();
	while(p!=c.medicos_.fin()){
		os<<"M�dico "<<c.medicos_.elemento(p).id_<<":\n\t";
		if(c.tienePaciente(c.medicos_.elemento(p))){
			os<<"Paciente siguiente: "<<c.medicos_.elemento(p).listaEspera_.frente().nom_<<" "
			<<c.medicos_.elemento(p).listaEspera_.frente().ape_<<" DNI: "
			<<c.medicos_.elemento(p).listaEspera_.frente().dni_<<std::endl;
		}else{
			os<<"Sin pacientes\n";
		}
		p=c.medicos_.siguiente(p);
	}
	return os;
}

/*
La direcci�n de un hospital quiere informatizar su consultorio m�dico que est� en constante
crecimiento por medio de un sistema que permita realizar al menos las siguientes operaciones

x	- Generar un consultorio vac�o sin ninguna informaci�n.
x	- Dar de alta un nuevo m�dico.
x	- Dar de baja un m�dico.
x	- Poner a un paciente en la lista de espera de un m�dico.
x	- Consultar al paciente que le toque el turno para ser atendido por un m�dico.
x	- Atender al paciente que le toque por parte de un m�dico.
x	- Comprobar si un m�dico determinado tiene o no pacientes en espera.

a) Realice la especificaci�n del TAD.
b) Dise�e una estructura de datos adecuada para representar el TAD e implemente las
   operaciones anteriores.
 */
