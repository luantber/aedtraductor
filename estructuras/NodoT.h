#ifndef NODOT_H
#define NODOT_H
#include <iostream>


template<class T>
class Binary_tree;

template<class T>
class avl_tree;

template<class T>
class NodoT
{
    public:
        NodoT(){};
        NodoT(T d): m_dato(d), m_pDer(0), m_pIzq(0) {}
        virtual ~NodoT(){};
        NodoT<T>*m_pDer;
        NodoT<T>*m_pIzq;
        T m_dato;
    protected:
    private:


    friend class Binary_tree<T>;
    friend class avl_tree<T>;
};

#endif // NODOT_H
