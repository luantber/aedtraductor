#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "NodoL.h"


using namespace std;
template<class T>
class List
{
    public:
        List(): m_phead(0){}
        virtual ~List(){};
        bool list_find(T d,Nodo<T>**&p);
        bool list_add(T d);
        bool list_delete(T d);
        List<T> list_get_interseccion(List<T> otro);
        void list_imprimir();
    protected:
    private:
        Nodo<T>* m_phead;

};

template<class T>
bool List<T>::list_find(T d,Nodo<T>**&p){
    p=&m_phead;
    while(*p){
        if(d==(*p)->m_dato) return true;
        else if(d<(*p)->m_dato) return false;
        p=&((*p)->m_psig);
    }
    return false;
}

// metodos para añadir y borrar

template<class T>
bool List<T>::list_add(T d){
    Nodo<T>**q;
    if(list_find(d,q)) return false;
    Nodo<T>*nuevo= new Nodo<T>(d);
    nuevo->m_psig=(*q);
    *q=nuevo;

    return true;


}

template<class T>
bool List<T>::list_delete(T d){
    Nodo<T>**q;
    if(!list_find(d,q)) return false;
    Nodo<T>**temp=q;
    *q=(*q)->m_psig;
    delete *temp;
    return true;
}

//-----------------imprimir

template<class T>
void List<T>::list_imprimir(){
    Nodo<T>**temp=&m_phead;
    while(*temp){
        cout<<(*temp)->m_dato<<endl;
        temp=&((*temp)->m_psig);
    }
}

//-----------------interseccion
/*
template<class T>
List<T> List<T>::list_get_interseccion(List<T> otro){
    List<T> nuevo;
    Nodo<T>**ite=&otro.m_phead;
    while(*ite){
        if()

        ite=&((*ite)->m_psig);
    }
}
*/
#endif // LIST_H
