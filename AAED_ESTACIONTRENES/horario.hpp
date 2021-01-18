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
Asumiendo que ya disponemos de la implementación del TAD Estación, el objetivo de nuestro problema es averiguar
el estado de la estación (qué trenes se encuentran en qué vías) a una hora determinada, a partir de la información
relativa al horado de salidas y llegadas de trenes a una estación un día cualquiera.
b) (0,4 puntos) Diseña y define una estructura de datos adecuada para almacenar la información relativa al horario
				de salidas y llegadas de trenes.
c) (2,4 puntos) Dada una estación y la información relativa al horario de trenes (en orden creciente de horas y
				minutos) un día cualquiera, implementa una función que devuelva el estado de la estación a una
				hora determinada. Por simplificar el problema, se supone que todos los trenes que parten de la
				estación están en alguna vía, bien porque han efectuado su llegada previamente o bien porque se
				encontraban en la estación desde el principio del día.

Nota: Es absolutamente necesario definir todos los tipos de datos implicados en la resolución del problema (excepto
el tipo Estación), así como los prototipos de las operaciones utilizadas de los TADs conocidos que se utilicen.
*/

#endif /* HORARIO_HPP_ */
