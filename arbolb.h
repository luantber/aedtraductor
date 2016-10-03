#ifndef ARBOLB_H
#define ARBOLB_H

#include "arbol.h"
template <class T>
class ArbolB:public Arbol<T>
{
public:
    ArbolB() {}
    bool insertar(T d){
        return this->insertarb(d);
    };
    
};



#endif // ARBOLB_H
