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
		os<<"Médico "<<c.medicos_.elemento(p).id_<<":\n\t";
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
La dirección de un hospital quiere informatizar su consultorio médico que está en constante
crecimiento por medio de un sistema que permita realizar al menos las siguientes operaciones

x	- Generar un consultorio vacío sin ninguna información.
x	- Dar de alta un nuevo médico.
x	- Dar de baja un médico.
x	- Poner a un paciente en la lista de espera de un médico.
x	- Consultar al paciente que le toque el turno para ser atendido por un médico.
x	- Atender al paciente que le toque por parte de un médico.
x	- Comprobar si un médico determinado tiene o no pacientes en espera.

a) Realice la especificación del TAD.
b) Diseñe una estructura de datos adecuada para representar el TAD e implemente las
   operaciones anteriores.
 */
