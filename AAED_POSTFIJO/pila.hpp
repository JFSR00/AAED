//
//  pila.hpp
//  Cadena Inversa 2
//
//  Created by Guillermo Girón García on 25/11/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#ifndef PILA_HPP_
#define PILA_HPP_

#include <cassert>

template <typename T>
class Pila
{
    struct nodo
    {
        T elto;
        nodo *sig;
        nodo (const T &e, nodo *p = 0) : elto(e), sig(p)
        {}
    };

    nodo *tope_;

    void copiar(const Pila <T> &P);

public:
    Pila(); //Constructor
    Pila( const Pila <T> &P); //Constructor de copia
    Pila <T> &operator = (const Pila <T> &P); //Asignacion
    bool vacia() const;
    const T &tope() const;
    void pop();
    void push(const T &x);
    ~Pila(); //Destructor
};

template <typename T>
inline Pila<T>::Pila() : tope_(0)
{}

template <typename T>
Pila<T> ::Pila(const Pila<T> &P) : tope_(0)
{
    copiar(P);
}

template <typename T>
Pila<T> &Pila<T>::operator=(const Pila<T> &P)
{
    if(this != &P)
    {
        //Evitar autoasignacion
        this -> ~Pila();
        copiar(P);
    }

    return *this;
}

template <typename  T>
inline bool Pila<T>::vacia() const
{
    return (!tope_);
}

template <typename T>
inline const T &Pila<T>::tope()const
{
    assert(!vacia());
    return tope_ -> elto;
}

template <typename T>
inline void  Pila<T>::pop()
{
    assert(!vacia());
    nodo *p = tope_;
    tope_ = p -> sig;
    delete p;
}

template <typename T>
inline void Pila<T>::push(const T &x)
{
    tope_ = new nodo(x, tope_);
}

//Destructor de pila vacia

template <typename T>
Pila<T> ::~Pila()
{
    nodo *p;

    while (tope_)
    {
        p = tope_ -> sig;
        delete tope_;
        tope_ = p;
    }
}

//Metodo privado

template <typename T>
void Pila<T>::copiar(const Pila<T> &P)
{
    if (!P.vacia())
    {
        tope_ = new nodo(P.tope()); //copiar el primer elemento

        //Copiar el resto de elementos hasta el fondo de la pila

        nodo *p = tope_; //recorre la pila destino
        nodo* q = P.tope_ -> sig; //2º nodo, recorre la pila origen

        while (q)
        {
            p -> sig = new nodo(q -> elto);
            p = p -> sig;
            q = q -> sig;
        }
    }
}

#endif /* PILA_HPP_ */
