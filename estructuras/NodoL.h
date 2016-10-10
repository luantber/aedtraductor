#ifndef NODO_H
#define NODO_H
#include <iostream>

class MainWindow;



template<class T>
class Nodo
{
    public:

        Nodo();
        Nodo(T d): m_dato(d), m_psig(0){}
        T get_dato(){return this->m_dato;}
        virtual ~Nodo(){}
    protected:
    private:
        T m_dato;
        Nodo<T>* m_psig;
    friend class List<T>;
    friend class ListCircular<T>;
    friend class MainWindow;
};

#endif // NODO_H
