#ifndef ARBOL_H
#define ARBOL_H

#include "nodo.h"

template <class T>
class Arbol
{
public:
    Arbol() {
        mp_root=0;
    }
    Nodo<T> * mp_root;
    bool find(T,Nodo<T>**&);
    bool insertarb(T);

};

//Find Doble Puntero
template<class T>
bool Arbol<T>::find(T d, Nodo<T>**& p)
{
    p = &mp_root;
    while (*p)
    {
        if ((*p)->dato == d) return true;
        p = &((*p)->mp_son[((*p)->dato < d)]);
    }
    return false;
}

template<class T>
bool Arbol<T>::insertarb(T d)
{
    Nodo<T> ** q;
    if (find(d, q)) return false;
    * q = new Nodo<T>(d);
    return true;
}

#endif // ARBOL_H
