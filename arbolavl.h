#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include "arbol.h"

template <class T>
class ArbolAVL:public Arbol<T>
{
public:
    ArbolAVL() {}
    void insertar(T d);
    void insertarAVL(T ,Nodo<T>*&,bool&);
    void rs(Nodo<T>*&,bool);
    void rd(Nodo<T>*&,bool);
};


template <class T>
void ArbolAVL<T>::rs(Nodo<T>*& p,bool v){

    Nodo<T>*q = p->mp_son[v];
    p->mp_son[v]=q->mp_son[!v];
    q->mp_son[!v]=p;
    p->fe = q->fe=0;
    p=q;
}

template <class T>
void ArbolAVL<T>::rd(Nodo<T> *& p, bool v){
    Nodo<T>*q = p->mp_son[v];
    Nodo<T>*r = q->mp_son[!v];
    p->mp_son[v]=r->mp_son[!v];
    q->mp_son[!v]=r->mp_son[v];
    r->mp_son[!v]=p;
    r->mp_son[v]=q;
    
    switch (r->fe) {
    case 0:
        p->fe=q->fe=0;
        break;
    case -1:
        if(v){
            q->fe = 0;
            p->fe = 1;
        }
        else{
            q->fe = 0;
            p->fe = 1;
        }
        break;
    case 1:
        if(v){
            q->fe= -1;
            p->fe = 0;
        }
        else{
            q->fe= 0;
            p->fe = -1;
        }

        break;
    }
    p=r;
}

template <class T>
void ArbolAVL<T>::insertarAVL(T d,Nodo<T> * &p,bool & stop){
    if (!p){ p = new Nodo<T>(d); return;}
    if(p->dato == d) return;
    insertarAVL(d,p->mp_son[p->dato<d],stop);

    if(stop) return;

    if(p->dato<d)
        p->fe++;
    else
        p->fe--;

    if(p->fe == 0) stop = true;


    else if(p->fe == 2){

        if(p->mp_son[1]->fe==1)
            rs(p,1);

        else rd(p,1);
        stop = true;

    }
    else if(p->fe == -2){
        if(p->mp_son[0]->fe==-1)
            rs(p,0);
        else rd(p,0);
        stop = true;
    }

}

template <class T>
void ArbolAVL<T>::insertar(T d){
    bool stop = false;
    insertarAVL(d,this->mp_root,stop);
}


#endif // ARBOLAVL_H

