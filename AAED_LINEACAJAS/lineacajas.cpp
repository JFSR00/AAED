/*
 * lineacajas.cpp
 *
 *  Created on: 20 jun. 2020
 *      Author: Juan Francisco
 */

#include <cassert>
#include "lineacajas.hpp"

void LineaCajas::abrirCaja(int idCaja, int idCajero){
	assert(!(idCaja>=50||idCaja<0));
	linea[idCaja].setCajero(idCajero);
}

double LineaCajas::cerrarCaja(int idCaja){
	assert(!(idCaja>=50||idCaja<0));
	linea[idCaja].setAbierta(false);
	return linea[idCaja].getFacturacion();
}

void LineaCajas::cobrarCliente(int idCaja, Cliente cl){
	assert(!(idCaja>=50||idCaja<0));
	assert(!linea[idCaja].isAbierta());
	linea[idCaja].setFacturacion(linea[idCaja].getFacturacion()+cl.getImporte());
}

double LineaCajas::cambiaTurno(Caja* turno){
	double facturacion=cerrarCajas();

	delete linea;
	linea=turno;

	return facturacion;
}

double LineaCajas::cerrarCajas(){
	double facturacion=0;
	for(int i=0;i<50;i++){
		facturacion+=cerrarCaja(i);
	}
	return facturacion;
}

std::ostream& operator <<(std::ostream& os, LineaCajas& l){
	for(int i=0;i<50;i++){
		if(l.linea[i].isAbierta()){
			os<<"Caja "<<i<<":\n\tCajero: "<<l.linea[i].getCajero()<<"\n\tFacturación: "<<l.linea[i].getFacturacion()<<std::endl;
		}
	}
	return os;
}

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
x	- Crear una línea de cajas cerrada.
x	- Abrir una caja determinada.
x	- Cerrar una caja determinada y devolver la facturación realizada en ella desde la última
	  vez que se abrió.
x	- Cobrar a un cliente el importe de su compra en una caja.
x	- Cambiar el turno de trabajo y devolver la recaudación total que hay en las cajas en
	  el momento del cambio. En esta operación puede que el total de cajas, así como las
	  cajas concretas de uno y otro turno no coincidan.
x	- Cerrar todas las cajas y devolver la recaudación total que hay en ellas en el momento
	  del cierre.
b) Realiza la implementación del TAD LíneaCajas, teniendo en cuenta lo siguiente:
x	- El tiempo de ejecución de cerrar una caja, cobrar una compra y sustituir a un cajero
	  debe ser constante.
x	- Justifica razonadamente la estructura de datos elegida en términos de eficiencia en
	  tiempo y espacio.

Justificación:
	Originalmente planee usar una lista pseudo-dinámica, pero en ese caso no sería posible cumplir con
	el requisito de los tiempos de ejecución estáticos para cerrar, cobrar o sutituir, a menos de que
	tomara ventaja por el conocimiento de la implementación. En el caso de que tomara ventaja de dicho
	conocimiento, el programa dejaría de funcionar si cambiara a una lista enlazada, por lo que he
	descartado el uso de las implementaciones del TAD Lista y he optado por hacer uso de un vector de
	objetos Caja, lo cual me permite cumplir con todos los requisitos del enunciado. En espacio diría
	que es tan eficiente como si hubiera usado la el TAD Lista implementado de forma pseudo-estática,
	pero en tiempo, esta implementación es más eficiente debido a que los tiempos de ejecución de los
	métodos antes mencionados es constante.
 */
