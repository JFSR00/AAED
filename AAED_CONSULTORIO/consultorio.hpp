/*
 * consultorio.hpp
 *
 *  Created on: 18 jun. 2020
 *      Author: JFSR00
 */

#ifndef CONSULTORIO_HPP_
#define CONSULTORIO_HPP_

#include <string>
#include <ostream>
#include "lista_doble.hpp"
#include "cola_din_circ.hpp"

struct Paciente{
	std::string nom_,ape_,dni_;
	Paciente(std::string ="NO_NOMBRE",std::string ="NO_APELLIDO",std::string ="0000");
};

struct Medico{
	int id_;
	Cola<Paciente> listaEspera_;

	bool operator ==(const Medico&);

	Medico(int =0);
	Medico(Medico&);
};

class Consultorio{
public:
	Consultorio() = default;

	void alta(const Medico&);
	void baja(const Medico&);
	void anadePaciente(const Medico&,Paciente);
	Paciente siguientePaciente(const Medico&);
	void atenderPaciente(const Medico&);
	bool tienePaciente(const Medico&);

	friend std::ostream& operator <<(std::ostream&, Consultorio&);

private:
	Lista<Medico> medicos_;
};

std::ostream& operator <<(std::ostream&, Consultorio&);

#endif /* CONSULTORIO_HPP_ */
