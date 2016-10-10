#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "NodoT.h"


using namespace std;

template<class T>
class Binary_tree
{
    public:
        Binary_tree(): m_pRoot(0){}
        virtual ~Binary_tree(){}


        bool find1(T d);
        bool findR(T d, NodoT<T>*p);
        void addR(T d, NodoT<T>*&p);
        bool find2(T d, NodoT<T>**&p);
        bool add1(T d);
        bool add2(T d);
        bool delete1(T d);
        T get_maximo();
        T get_maximo2(NodoT<T>**&);
        T get_minimo2(NodoT<T>**&);
        void imprimir_pre_orden(NodoT<T>*p);
        void imprimir_pre_orden();
        void imprimir_por_niveles();
        void imprimir_camino_nodo(NodoT<T>*n);
        NodoT<T>* m_pRoot;
        void contar_hojas(NodoT<T>*n,int&cont);
        T padre_nodo(NodoT<T>**&padre,NodoT<T>*hijo);
        T tio_nodo(NodoT<T>**&tio,NodoT<T>*n);
        T hermano_nodo(NodoT<T>**&hermano,NodoT<T>*n);
        bool es_hijo_izquierdo(NodoT<T>*n);
        bool es_hijo_derecho(NodoT<T>*n);
        int nivel(T d);

    protected:
    private:


};




template<class T>
bool Binary_tree<T>::find1(T d){
    if(!m_pRoot) return false;
    NodoT<T>*temp=m_pRoot;
    while(temp){
        if(temp->m_dato==d) return true;
        if(temp->m_dato<d) temp=temp->m_pDer;
        else temp=temp->m_pIzq;
    }
    return false;
}

template<class T>
bool Binary_tree<T>::add1(T d){
    if(!m_pRoot) m_pRoot=new NodoT<T>(d);
    else{
        NodoT<T>*p,*q;
        p=q=m_pRoot;
        while(!q){
            p=q;
            if(q->m_dato==d) return false;
            if(q->m_dato<d) q=q->m_pDer;
            else q=q->m_pIzq;
        }
        if(p->m_dato<d) p->m_pDer=new NodoT<T>(d);
        else p->m_pIzq=new NodoT<T>(d);
    }
    return true;

}

template<class T>
bool Binary_tree<T>::find2(T d, NodoT<T>**&p){
    p=&m_pRoot;
    while(*p){
        if((*p)->m_dato==d) return true;
        if((*p)->m_dato<d) p=&((*p)->m_pDer);
        else p=&((*p)->m_pIzq);
    }
    return false;
}

template<class T>
bool Binary_tree<T>::add2(T d){
    NodoT<T>**q;
    if(!find2(d,q)){
        (*q)=new NodoT<T>(d);
        return true;
    }
    return false;
}

template<class T>
bool Binary_tree<T>::delete1(T d){
    NodoT<T>**q;
        if( !((*q)->m_pIzq) && !((*q)->m_pDer) ){
            delete (*q);
            return true;
    if(find2(d,q)){
        }

        else if(!((*q)->m_pIzq)){
            NodoT<T>*temp=*q;
            q=&((*q)->m_pDer);
            delete temp;
        }
        else if(!((*q)->m_pDer)){
            NodoT<T>*temp=*q;
            q=&((*q)->m_pIzq);
            delete temp;
        }
        else{
            //falta implementar
        }
    }
}

template<class T>
bool Binary_tree<T>::findR(T d, NodoT<T>*p){
    if(!p) return false;
    if(p->m_dato==d) return true;
    if(p->m_dato<d) return findR(d,p->m_pDer);
    else return findR(d,p->m_pIzq);
}

template<class T>
void Binary_tree<T>::addR(T d, NodoT<T>*&p){
    if(!p){
        p=new NodoT<T>(d);
        return;
    }
    if(p->m_dato==d) return;
    if(p->m_dato<d) addR(d,p->m_pDer);
    else addR(d,p->m_pIzq);


}


template<class T>
T Binary_tree<T>::get_maximo(){
    NodoT<T>*temp=m_pRoot;
    while(temp->m_pDer){
        temp=temp->m_pDer;
    }
    return temp->m_dato;
}

template<class T>
T Binary_tree<T>::get_maximo2(NodoT<T>**& p){
    while((*p)->m_pDer){
        p=&((*p)->m_pDer);
    }
    return (*p)->m_dato;
}


template<class T>
void Binary_tree<T>::imprimir_pre_orden(NodoT<T>*p){
    if(!p) return;
    cout<<p->m_dato<<endl;
    imprimir_pre_orden(p->m_pIzq);
    imprimir_pre_orden(p->m_pDer);
}
/*
template<class T>
void Binary_tree<T>::imprimir_pre_orden(){
    if(!m_pRoot) return;
    Pila<NodoT<T>*> pila;
    pila.push(m_pRoot);
    while(!(pila.isEmpty())){
        NodoT<T>*temp=pila.top();
        cout<<temp->m_dato<<endl;
        pila.pop();
        if(temp->m_pDer){
            pila.push(temp->m_pDer);
        }
        if(temp->m_pIzq){
            pila.push(temp->m_pIzq);
        }

    }
}
*/
/*
template<class T>
void Binary_tree<T>::imprimir_por_niveles(){
    if(m_pRoot){
        Cola<NodoT<T>*>cola;
        cola.push(m_pRoot);
        while(!cola.isEmpty()){
            NodoT<T>*temp=cola.top();
            cola.pop();
            cout<<temp->m_dato<<endl;
            if(temp->m_pIzq){
                cola.push(temp->m_pIzq);
            }
            if(temp->m_pDer){
                cola.push(temp->m_pDer);
            }
        }
    }
}

*/
template<class T>
void Binary_tree<T>::imprimir_camino_nodo(NodoT<T>*n){
    NodoT<T>*temp=m_pRoot;
    while(temp->m_dato!=n->m_dato){
        cout<<temp->m_dato<<endl;
        if(temp->m_dato>n->m_dato) temp=temp->m_pIzq;
        else temp=temp->m_pDer;
    }

}

template<class T>
void Binary_tree<T>::contar_hojas(NodoT<T>*n,int&cont){
    if(!n) return ;
    if(!(n->m_pDer) && !(n->m_pIzq)){
        cont++;
        return;
    }
    contar_hojas(n->m_pDer,cont);
    contar_hojas(n->m_pIzq,cont);

}


template<class T>
T Binary_tree<T>::padre_nodo(NodoT<T>**&padre,NodoT<T>*hijo){
    padre=&m_pRoot;
    while(*padre){
        if( ( (*padre)->m_pDer->m_dato==hijo->m_dato) || ( (*padre)->m_pIzq->m_dato==hijo->m_dato) ) return (*padre)->m_dato;
        if((*padre)->m_dato<hijo->m_dato) padre=&((*padre)->m_pDer);
        else padre=&((*padre)->m_pIzq);
    }
}

//temp seria el hermano
template<class T>
T Binary_tree<T>::hermano_nodo(NodoT<T>**&temp,NodoT<T>*n){
    padre_nodo(temp,n);
    if((*temp)->m_pIzq && (*temp)->m_pDer){
        if((*temp)->m_pDer->m_dato==n->m_dato)  temp=&((*temp)->m_pIzq);
        else temp=&((*temp)->m_pDer);
        return (*temp)->m_dato;
    }
    else (*temp)=0;


}

template<class T>
T Binary_tree<T>::tio_nodo(NodoT<T>**&temp,NodoT<T>*n){
    padre_nodo(temp,n);
    hermano_nodo(temp,(*temp));
}

template<class T>
bool Binary_tree<T>::es_hijo_izquierdo(NodoT<T>*n){
    NodoT<T>**q;
    padre_nodo(q,n);
    if((*q)->m_pIzq==n) return true;
    return false;
}

template<class T>
bool Binary_tree<T>::es_hijo_derecho(NodoT<T>*n){
    NodoT<T>**q;
    padre_nodo(q,n);
    if((*q)->m_pDer==n) return true;
    return false;
}


/*
template<class T>
int Binary_tree<T>::nivel(T d){
    int nivel=0;
    NodoT<T>*temp=m_pRoot;
    while(!temp){
        if(temp->m_dato==d) break;
        if(temp->m_dato)
    }
}
*/

#endif // BINARY_TREE_H
