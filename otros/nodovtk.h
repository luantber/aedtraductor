#ifndef NODOVTK_H
#define NODOVTK_H

#include <string>
#include <vector>
#include <iostream>
#include "par.h"

typedef int cor;
using namespace std;


class NodoVTK
{
public:
    NodoVTK(){

    }

    NodoVTK(cor x, cor y ,int s, vector<Par> h) {
        par = Par(x,y);
        palabra = s;
        hijos = h;
    }
    Par par;
    int palabra;
    vector<Par> hijos;
    void show();

};

#endif

