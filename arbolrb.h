#ifndef ARBOLRB_H
#define ARBOLRB_H

#include "arbol.h"
using namespace std;

template <class T>
class ArbolAVL:public Arbol<T>
{
public:
    ArbolAVL() {}
    void insertar(T d);
    void insertarRB(T ,Nodo<T>*&,bool&);
    void rs(Nodo<T>*&,bool);
    void rd(Nodo<T>*&,bool);
};




#endif // ARBOLRB_H

