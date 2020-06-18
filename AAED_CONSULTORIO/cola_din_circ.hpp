/*
 * cola_din_circ.hpp
 *
 *  Created on: 23 nov. 2019
 *      Author: JFSR00
 */

#ifndef COLA_DIN_CIRC_HPP_
#define COLA_DIN_CIRC_HPP_
#include <cassert>

template<typename T> class Cola{
public:
	Cola();
	Cola(Cola<T>&);
	Cola<T>& operator =(const Cola<T>&);
	void push(T);
	void pop();
	const T& frente() const;
	const bool vacia() const;
	~Cola();

private:
	struct nodo{
		T elem;
		nodo *sig;
		nodo(T e,nodo *s=0):elem(e),sig(s){}
	};

	nodo *fin;

	void copiar(const Cola<T>&);
};

template<typename T>
Cola<T>::Cola():fin(0){}

template<typename T>
Cola<T>::Cola(Cola<T>& C):
fin(0)
{
	copiar(C);
}

template<typename T>
inline Cola<T>& Cola<T>::operator =(const Cola<T>& C)
{
	if(this!=&C)
	{
		this->~Cola();
		copiar(C);
	}
	return *this;
}

template<typename T>
void Cola<T>::push(T num)
{
	if(fin)
	{
		fin=fin->sig=new nodo(num,fin->sig);
	}
	else
	{
		fin=new nodo(num);
		fin->sig=fin;
	}
}

template<typename T>
void Cola<T>::pop()
{
	assert(!vacia());
	if(fin==fin->sig)
	{
		delete fin;
		fin=0;
	}
	else
	{
		nodo *aux=fin->sig;
		fin->sig=aux->sig;
		delete aux;
	}
}

template<typename T>
inline const T& Cola<T>::frente() const
{
	assert(!vacia());
	return fin->sig->elem;
}

template<typename T>
inline const bool Cola<T>::vacia() const
{
	return (!fin);
}

template<typename T>
Cola<T>::~Cola()
{
	while(fin)
	{
		Cola<T>::pop();
	}
}

template<typename T>
void Cola<T>::copiar(const Cola<T>& C)
{
	if(!C.Cola<T>::vacia())
	{
		fin=new nodo(C.frente());
		nodo *p=C.fin->sig->sig;
		nodo *aux=fin;
		while(p!=C.fin->sig)
		{
			fin->sig=new nodo(p->elem);
			p=p->sig;
			fin=fin->sig;
		}
		fin->sig=aux;
	}
}

#endif /* COLA_DIN_CIRC_HPP_ */
