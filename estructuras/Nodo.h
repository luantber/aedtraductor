#ifndef NODO_H
#define NODO_H
#include <iostream>



template<class T>
class List;

template<class T>
class Cola;

template<class T>
class Nodo
{
    public:
        Nodo(T d): m_dato(d), m_psig(0) {}
        virtual ~Nodo(){}
    protected:
    private:
        T m_dato;
        Nodo<T>*m_psig;

    friend class List<T>;
    friend class Cola<T>;

};

#endif // NODO_H
