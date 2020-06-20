//
//  lista.h
//  TAD Lista
//
//  Created by Guillermo Girón García on 13/12/17.
//  Copyright © 2017 Guillermo Girón García. All rights reserved.
//

#ifndef lista_h
#define lista_h

#include <iostream>
#include <cassert>

template <typename T>
class Lista
{
    T *elementos; // vector de elementos
    int Lmax; // tamaño del vector
    int n; // longitud de la lista

    public:

    typedef int posicion;   // posición de un elto

    explicit Lista(size_t TamaMax); // constructor
    Lista(const Lista<T>& l); // ctor. de copia
    Lista<T>& operator =(const Lista<T>& l); // asignación entre listas
    void insertar(const T& x, posicion p);
    void eliminar(posicion p);
    const T& elemento(posicion p) const; // acceso a elto, lectura
    T& elemento(posicion p); // acceso a elto, lectura/escritura
    posicion buscar(const T& x) const; // requiere operador == para el tipo T
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const; // posición después del último
    ~Lista(); // destructor
};

//clase Lista genérica: vector pseudo−estático.
//Una lista de longitud n se almacena en celdas consecutivas del vector, desde 0 hasta n−1.
//La posición de un elemento es el índice de la celda en que se almacena.
//Implementación de operaciones

template <typename T>
inline Lista<T>::Lista(size_t TamaMax) :
 elementos(new T[TamaMax]),
 Lmax(TamaMax),
 n(0)
{}

template <typename T>
Lista<T>::Lista(const Lista<T>& l) :
    elementos(new T[l.Lmax]),
    Lmax(l.Lmax),
    n(l.n)
{
    for (Lista<T>::posicion p = 0; p < n; p++) // copiar el vector
    {
      elementos[p] = l.elementos[p];
    }
}

template <typename T>
Lista<T>& Lista<T>::operator =(const Lista<T>& l)
{
    if (this != &l)
    {
        // evitar autoasignación
        // Destruir el vector y crear uno nuevo si es necesario

        if (Lmax != l.Lmax)
        {
            delete[] elementos;
            Lmax = l.Lmax;
            elementos = new T[Lmax];
        }

        // Copiar el vector

        n=l.n;

        for (Lista<T>::posicion p = 0; p < n; p++)
            elementos[p] = l.elementos[p];
    }
  return *this;
}

template <typename T>
void Lista<T>::insertar(const T& x, Lista<T>::posicion p)
{
    assert(p >= 0 && p <= n); // posición válida
    assert(n < Lmax); // lista no llena

    for (Lista<T>::posicion q = n; q > p; q--)
    {
        // desplazar los eltos. en p, p+1, ...

        elementos[q] = elementos[q-1]; // a la siguiente posición
        elementos[p] = x;
    }

    n++;
}

template <typename T>
void Lista<T>::eliminar(Lista<T>::posicion p)
{
    assert(p >= 0 && p < n); // posición válida

    n--;

    for (Lista<T>::posicion q = p; q < n; q++)
        //desplazar los eltos. en p+1, p+2, ...
        elementos[q] = elementos[q+1]; // a la posición anterior
}

template <typename T> inline
const T& Lista<T>::elemento(Lista<T>::posicion p) const
{
    assert(p >= 0 && p < n); // posición válida
    return elementos[p];
}

template <typename T>
inline T& Lista<T>::elemento(Lista<T>::posicion p)
{
    assert(p >= 0 && p < n); // posición válida
    return elementos[p];
}

template <typename T>
typename Lista<T>::posicion Lista<T>::buscar(const T& x)
const
{
    Lista<T>::posicion q = 0;
    bool encontrado = false;

    while (q < n && !encontrado)
        if (elementos[q] == x)
            encontrado = true;
        else
            q++;

    return q;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::siguiente(Lista<
                                                       T>::posicion p) const
{
    assert(p >= 0 && p < n); // posición válida
    return p+1;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::anterior(Lista<T>::posicion p) const
{
    assert(p > 0 && p <= n); // posición válida
    return p-1;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::primera() const
{ return 0; }

template <typename T>
inline typename Lista<T>::posicion Lista<T>::fin() const
{ return n; }

template <typename T>
inline Lista<T>::~Lista()
{ delete[] elementos; }

#endif /* lista_h */
