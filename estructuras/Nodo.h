#ifndef NODO_H
#define NODO_H
#include <iostream>

class MainWindow;

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
        void borrar_r(Nodo<T>*p){
            if(!p) return;
            borrar_r(p->m_psig);
            delete p;
        }
    protected:
    private:
        T m_dato;
        Nodo<T>*m_psig;

    friend class List<T>;
    friend class Cola<T>;
    friend class MainWindow;
};

#endif // NODO_H
