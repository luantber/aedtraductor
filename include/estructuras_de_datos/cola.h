#ifndef COLA_H
#define COLA_H
#include "Nodo.h"

using namespace std;

template<class T>
class Cola
{
    public:
        Cola(): m_phead(0) {}
        virtual ~Cola(){};
        void push(T d);
        void imprimir();
        T top();
        void pop();
        bool isEmpty();
    protected:
    private:
        Nodo<T>*m_phead;
};

template<class T>
void Cola<T>::push(T d){
    Nodo<T>*nuevo= new Nodo<T>(d);
    if(!m_phead) m_phead=nuevo;
    else{
        Nodo<T>*temp=m_phead;
        while(temp->m_psig){
            temp=temp->m_psig;
        }
        temp->m_psig=nuevo;
    }
}

template<class T>
void Cola<T>::imprimir(){
    Nodo<T>*temp=m_phead;
    while(temp){
        cout<<temp->m_dato<<endl;
        temp=temp->m_psig;
    }
}


template<class T>
T Cola<T>::top(){
    if(m_phead){
        return m_phead->m_dato;
    }
    else{
        cout<<"cola vacia"<<endl;
    }
}

template<class T>
void Cola<T>::pop(){
    if(m_phead){
        Nodo<T>*temp=m_phead;
        m_phead=m_phead->m_psig;
        delete temp;
    }
    else{
        cout<<"cola vacia"<<endl;
    }
}

template<class T>
bool Cola<T>::isEmpty(){
    if(m_phead) return false;
    return true;
}

#endif // COLA_H

