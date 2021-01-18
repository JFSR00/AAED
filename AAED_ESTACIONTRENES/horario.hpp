/*
 * horario.hpp
 *
 *  Created on: 18 ene. 2021
 *      Author: JFSR00
 */

#ifndef HORARIO_HPP_
#define HORARIO_HPP_

#include "cola_din_circ.hpp"
#include "estacion.hpp"

typedef enum{LLEGADA, SALIDA} Operacion;

typedef struct{
	Tren _tren;
	Operacion _op;
	int _via, _h, _m;
}Instancia;

class Horario{
public:
	Horario(Cola<Instancia>,Estacion);

	Estacion estadoHora(int, int);

private:
	Estacion _estacionBkup;
	Cola<Instancia> _horario, _aux;

};

/*
 * NOTA DEL DESARROLLADOR: Me he equivocado, ya que no pedian que el horario almacenase la estacion,
 * 						   pero igualmente, solo seria adaptar este codigo un poco, por lo demas diria
 * 						   que es correcto. El horario se podria definir como:
 *
 * 						   typedef Cola<Instancia> Horario;
 *
 * 						   El resto seria modificar el metodo "estadoHora(int, int)" para que fuese una
 * 						   funcion independiente de la clase.
 *
Asumiendo que ya disponemos de la implementaci�n del TAD Estaci�n, el objetivo de nuestro problema es averiguar
el estado de la estaci�n (qu� trenes se encuentran en qu� v�as) a una hora determinada, a partir de la informaci�n
relativa al horado de salidas y llegadas de trenes a una estaci�n un d�a cualquiera.
b) (0,4 puntos) Dise�a y define una estructura de datos adecuada para almacenar la informaci�n relativa al horario
				de salidas y llegadas de trenes.
c) (2,4 puntos) Dada una estaci�n y la informaci�n relativa al horario de trenes (en orden creciente de horas y
				minutos) un d�a cualquiera, implementa una funci�n que devuelva el estado de la estaci�n a una
				hora determinada. Por simplificar el problema, se supone que todos los trenes que parten de la
				estaci�n est�n en alguna v�a, bien porque han efectuado su llegada previamente o bien porque se
				encontraban en la estaci�n desde el principio del d�a.

Nota: Es absolutamente necesario definir todos los tipos de datos implicados en la resoluci�n del problema (excepto
el tipo Estaci�n), as� como los prototipos de las operaciones utilizadas de los TADs conocidos que se utilicen.
*/

#endif /* HORARIO_HPP_ */
