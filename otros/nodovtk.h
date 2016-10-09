#ifndef NODOVTK_H
#define NODOVTK_H

#include <string>
#include <vector>
#include <iostream>
#include "par.h"

typedef int cor;
using namespace std;

template <class T>
class NodoVTK
{
public:
    NodoVTK(){

    }

    NodoVTK(cor x, cor y ,T s, vector<Par> h) {
        par = Par(x,y);
        palabra = s;
        hijos = h;
    }
    Par par;
    T palabra;
    vector<Par> hijos;
    void show();

};


template <class T>
void NodoVTK<T>::show(){
    cout << par.x << " , " << par.y << endl;
}


#endif

