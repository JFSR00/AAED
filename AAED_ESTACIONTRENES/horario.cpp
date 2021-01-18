/*
 * horario.cpp
 *
 *  Created on: 18 ene. 2021
 *      Author: JFSR00
 */

#include "horario.hpp"

Horario::Horario(Cola<Instancia> hor, Estacion est):_estacionBkup(est), _horario(hor){}

Estacion Horario::estadoHora(int h, int m){
	Estacion res = _estacionBkup;

	while(!_horario.vacia() && (_horario.frente()._h < h || (_horario.frente()._h == h && _horario.frente()._m <= m))){
		switch(_horario.frente()._op){
		case LLEGADA:
			res.llegada(_horario.frente()._tren, _horario.frente()._via);
			break;
		case SALIDA:
			res.salida(_horario.frente()._via);
			break;
		}

		_aux.push(_horario.frente());
		_horario.pop();
	}

	while(!_horario.vacia()){
		_aux.push(_horario.frente());
		_horario.pop();
	}

	while(!_aux.vacia()){
		_horario.push(_aux.frente());
		_aux.pop();
	}

	return res;
}

