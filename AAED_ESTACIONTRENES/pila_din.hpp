/*
 * pila_din.hpp
 *
 *  Created on: 18 nov. 2019
 *      Author: JFSR00
 */

#ifndef PILA_DIN_HPP_
#define PILA_DIN_HPP_
#include <cassert>

template<typename T> class Pila{
public:
	Pila();
	Pila(Pila<T>&);
	Pila<T>& operator =(const Pila<T>&);
	void push(T);
	void pop();
	const T& top() const;
	const bool vacia() const;
	~Pila();

private:
	struct nodo{
		T elem;
		nodo *sig;
		nodo(T e,nodo *s=0):elem(e),sig(s){}
	};

	nodo *tope;

	void copiar(const Pila<T>&);
};

template<typename T>
Pila<T>::Pila():tope(0){}

template<typename T>
Pila<T>::Pila(Pila<T>& p):
tope(0)
{
	copiar(p);
}

template<typename T>
Pila<T>& Pila<T>::operator =(const Pila<T>& p)
{
	if(this!=&p)
	{
		this->~Pila();
		copiar(p);
	}
	return *this;
}

template<typename T>
void Pila<T>::push(T num)
{
	tope=new nodo(num,tope);
}

template<typename T>
void Pila<T>::pop()
{
	assert(!vacia());
	nodo *aux=tope;
	tope=aux->sig;
	delete aux;
}

template<typename T>
inline const T& Pila<T>::top() const
{
	assert(!vacia());
	return tope->elem;
}

template<typename T>
inline const bool Pila<T>::vacia() const
{
	return (!tope);
}

template<typename T>
Pila<T>::~Pila()
{
	while(tope)
	{
		Pila<T>::pop();
	}
}

template<typename T>
void Pila<T>::copiar(const Pila<T>& P)
{
	if(!P.Pila<T>::vacia())
	{
		tope=new nodo(P.top());
		nodo* p = tope;
		nodo* q = P.tope->sig;
		while(q)
		{
			p->sig = new nodo(q->elem);
			p = p->sig;
			q = q->sig;
		}
	}
}

#endif /* PILA_DIN_HPP_ */
