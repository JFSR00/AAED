/*
 * lineacajas.hpp
 *
 *  Created on: 20 jun. 2020
 *      Author: Juan Francisco
 */

#ifndef LINEACAJAS_HPP_
#define LINEACAJAS_HPP_

#include "listaPseudo.hpp"

struct Cliente{
	double importe;
	Cliente(double i=0):importe(i){};
};

class Caja{
public:
	Caja(int n=0,int id=0,double f=0):nCaja(n),idCajero(id),fact(f){};

	int getCaja(){return nCaja;};
	int getCajero(){return idCajero;};
	double getFacturacion(){return fact;};

	void setCaja(int n){nCaja=n;};
	void setCajero(int id){idCajero=id;};
	void setFacturacion(double f){fact=f;};

	bool operator ==(const Caja& c){return nCaja==c.nCaja;};

private:
	int nCaja, idCajero;
	double fact;
};

class LineaCajas{
public:
	LineaCajas() = default;
	void abrirCaja(Caja);
	double cerrarCaja(Caja);

private:
	Lista<Caja> linea{50};
};

#endif /* LINEACAJAS_HPP_ */

/*
Un hipermercado dispone para el pago de las compras de 50 cajas numeradas de 1 a 50. El
número de cajas que permanecen abiertas a lo largo del día es variable, de tal forma que en cada
momento hay entre 10 y 50 cajas en funcionamiento, dependiendo de la afluencia de clientes
(en las horas y fechas punta hay más cajas abiertas que en los momentos de menor clientela),
aunque la media es de 48 cajas abiertas. El horario de venta se cubre con dos turnos de trabajo
al día y en cada turno se supone que hay suficientes cajeros para atender la demanda máxima
que se pueda producir y además algunos suplentes para sustituir a los que necesitan descansar.
Para cada caja hay que almacenar el número de caja, el identificador del cajero (tres dígitos)
y la facturación realizada desde el comienzo del turno de trabajo.

a) Escribe la especificación del TAD LíneaCajas con las siguientes operaciones:
	- Crear una línea de cajas cerrada.
	- Abrir una caja determinada.
	- Cerrar una caja determinada y devolver la facturación realizada en ella desde la última
	  vez que se abrió.
	- Cobrar a un cliente el importe de su compra en una caja.
	- Cambiar el turno de trabajo y devolver la recaudación total que hay en las cajas en
	  el momento del cambio. En esta operación puede que el total de cajas, así como las
	  cajas concretas de uno y otro turno no coincidan.
	- Cerrar todas las cajas y devolver la recaudación total que hay en ellas en el momento
	  del cierre.
b) Realiza la implementación del TAD LíneaCajas, teniendo en cuenta lo siguiente:
	- El tiempo de ejecución de cerrar una caja, cobrar una compra y sustituir a un cajero
	  debe ser constante.
	- Justifica razonadamente la estructura de datos elegida en términos de eficiencia en
	  tiempo y espacio.
 */
