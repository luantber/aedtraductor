#ifndef NODOARBOL_H
#define NODOARBOL_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

template<class T>
class nodoarbol{
	public:
		nodoarbol<T>* m_pSon[2];
		T m_dato;
		nodoarbol<T>(T d){
			m_dato = d;
			m_pSon[0] = m_pSon[1] = NULL;
		}

        void borrarRecursivo(nodoarbol * temp){
            if (temp->m_pSon[0]) borrarRecursivo(temp->m_pSon[0]);
            if (temp->m_pSon[1]) borrarRecursivo(temp->m_pSon[1]);
            delete(temp);
        }

        ~nodoarbol(){

        }
};

#endif
