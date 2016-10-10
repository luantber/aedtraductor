#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H
#include "NodoRB.h"
#include "cola.h"
#include <vector>

enum color{red,black};

template<class T>
class red_black_tree
{
public:
    red_black_tree(){m_pRoot=0;}
    ~red_black_tree(){}





    //----------------
    NodoRB<T>** get_d_father(NodoRB<T>*);
    NodoRB<T>** get_d_uncle(NodoRB<T>*);
    NodoRB<T>** get_d_brother(NodoRB<T>*);
    NodoRB<T>** get_d_Gfather(NodoRB<T>*);
    NodoRB<T>* get_brother(NodoRB<T>*);
    NodoRB<T>* get_father(NodoRB<T>*);
    NodoRB<T>* get_uncle(NodoRB<T>*);
    NodoRB<T>* get_Gfather(NodoRB<T>*);
    void add(T d);
    void add(std::vector<T>);
    bool der_izq(NodoRB<T>*);
    bool is_red(NodoRB<T>*);
    bool get_color(NodoRB<T>*);
    //----------------
    NodoRB<T>* rotacion_derecha(NodoRB<T>* p);
    NodoRB<T>* rotacion_izquierda(NodoRB<T>* p);
    bool verif_properties(NodoRB<T>*& p);
    void insertar(T d,NodoRB<T>*& p,NodoRB<T>*& q);
    bool find(T d,NodoRB<T>**& p);
    void imprimir_por_niveles();
    void imprimir(NodoRB<T>*);
    NodoRB<T>* m_pRoot;
private:

};


template<class T>
void red_black_tree<T>::imprimir(NodoRB<T>* p){
    if(!p) return;
    imprimir(p->m_pSon[0]);
    cout<<p->m_dato<<"--"<<p->m_bColor<<endl;
    imprimir(p->m_pSon[1]);
}

template<class T>
bool red_black_tree<T>::find(T d, NodoRB<T>**& p){
    p=&m_pRoot;
    while(*p){
        if((*p)->m_dato==d) return true;
        if((*p)->m_dato<d) p=&((*p)->m_pSon[1]);
        else p=&((*p)->m_pSon[0]);
    }
    return false;
}

template<class T>
bool red_black_tree<T>::get_color(NodoRB<T>*p){
    if(!p) return black;
    else return p->m_bColor;
}

template<class T>
NodoRB<T>* red_black_tree<T>::rotacion_derecha(NodoRB<T>* p){
    NodoRB<T>* F=get_father(p);
    if(F==m_pRoot){
        //padres
        F->m_pFather=p;
        p->m_pFather=0;
        if(p->m_pSon[1]) p->m_pSon[1]->m_pFather=F;
        //hijos
        F->m_pSon[0]=p->m_pSon[1];
        p->m_pSon[1]=F;

        //m_pRoot
        m_pRoot=p;


    }

    else{
        NodoRB<T>* G=get_father(get_father(p));

        G->m_pSon[der_izq(F)]=p;
        //cambiar padres
        p->m_pFather=G;
        F->m_pFather=p;
        //cambiar padre del hijo derecho de p en caso que tenga uno
        if(p->m_pSon[1]) p->m_pSon[1]->m_pFather=F;

        //Cambiar hijos;
        F->m_pSon[0]=p->m_pSon[1];
        p->m_pSon[1]=F;



    }


    return p;

    /*
    NodoRB<T>**d_father=get_d_father(p);
    //padres
    p->m_pFather=(*d_father)->m_pFather;
    (*d_father)->m_pFather=p;
    if(p->m_pSon[1]) p->m_pSon[1]->m_pFather=(*d_father);

    //hijos



    ((*d_father)->m_pSon[0])=p->m_pSon[1];

    //((*d_father)->m_pSon[0])=0;




    p->m_pSon[1]=(*d_father);

    (*d_father)=&(*p);
    */

}

template<class T>
NodoRB<T>* red_black_tree<T>::rotacion_izquierda(NodoRB<T>* p){


    NodoRB<T>* F=get_father(p);
    if(F==m_pRoot){
        //padres
        F->m_pFather=p;
        p->m_pFather=0;
        if(p->m_pSon[0]) p->m_pSon[0]->m_pFather=F;
        //hijos
        F->m_pSon[1]=p->m_pSon[0];
        p->m_pSon[0]=F;

        //m_pRoot
        m_pRoot=p;


    }

    else{
        NodoRB<T>* G=get_father(get_father(p));

        //cambiar padres
        G->m_pSon[der_izq(F)]=p;
        p->m_pFather=G;
        F->m_pFather=p;
        //cambiar padre del hijo derecho de p en caso que tenga uno
        if(p->m_pSon[0]) p->m_pSon[0]->m_pFather=F;

        //Cambiar hijos;
        F->m_pSon[1]=p->m_pSon[0];
        p->m_pSon[0]=F;



    }


    return p;
    /*
    NodoRB<T>**d_father;
    cout<<get_d_father(p)<<endl;
    d_father=get_d_father(p);

    //padres

    p->m_pFather=(*d_father)->m_pFather;
    (*d_father)->m_pFather=p;
    if(p->m_pSon[0]) p->m_pSon[0]->m_pFather=(*d_father);

    //hijos

    NodoRB<T>*temp=&(*p);

    (*d_father)->m_pSon[1]=p->m_pSon[0];

    temp->m_pSon[0]=(*d_father);

    (*d_father)=&(*temp);
    */
}


//retorna falso si viola alguna propiedad
template<class T>
bool red_black_tree<T>::verif_properties(NodoRB<T>*& p){
    if(!p) return true;
    m_pRoot->m_bColor=1;
    if(p!=m_pRoot){
        if(p->m_pFather->m_bColor==0 && p->m_bColor==0) return false;
    }
    return true;
}

template<class T>
void red_black_tree<T>::add(std::vector<T> d){
    for(auto it:d){
        add(it);
    }
}

template<class T>
void red_black_tree<T>::add(T d){
    NodoRB<T>*q;
    insertar(d,m_pRoot,q);
}

template<class T>
void red_black_tree<T>::insertar(T d,NodoRB<T>*&p, NodoRB<T>*& q){
    if(!p){
        p=new NodoRB<T>(d);
        p->m_pFather=q;
        if(p==m_pRoot) p->m_bColor=black;


    }

    else{
        if (p->m_dato==d) return;
        insertar(d,p->m_pSon[p->m_dato<d],p);
    }




    if(verif_properties(p)==false){
        //caso de solo colorear
        cout<<"entro"<<endl;
        //if(p->m_pFather && get_uncle(p)) cout<<p->m_pFather->m_dato<<";"<<p->m_pFather->m_bColor<<"--"<<get_uncle(p)->m_dato<<";"<<get_color(get_uncle(p))<<endl;

        if(p->m_pFather->m_bColor==red && get_color(get_uncle(p))==red){
            cout<<"color"<<endl;
            get_uncle(p)->m_bColor=black;
            get_father(p)->m_bColor=black;
            get_Gfather(p)->m_bColor=red;
            return;
        }
        if(p->m_pFather->m_bColor==red && get_color(get_uncle(p))==black){
            cout<<"entrooo"<<endl;
            if(der_izq(get_father(p))==0){
                if(der_izq(p)==0){
                    cout<<"izquierda izquierda"<<endl;

                    rotacion_derecha(p->m_pFather);
                    p->m_pFather->m_bColor=black;
                    p->m_pFather->m_pSon[1]->m_bColor=red;
                }
                else{
                    cout<<"izquierda derecha"<<endl;
                    NodoRB<T>* temp;
                    temp=rotacion_izquierda(p);
                    NodoRB<T>* temp2;
                    temp2=rotacion_derecha(temp);
                    temp2->m_bColor=black;
                    temp2->m_pSon[1]->m_bColor=red;

                }
            }
            else{
                if(der_izq(p)==0){
                    cout<<"derecha izquierda"<<endl;
                    NodoRB<T>* temp;
                    temp=rotacion_derecha(p);


                    NodoRB<T>* temp2;
                    temp2=rotacion_izquierda(temp);
                    temp2->m_bColor=black;
                    temp2->m_pSon[0]->m_bColor=red;
                }
                else{
                    cout<<"derecha derecha"<<endl;
                    NodoRB<T>* temp;
                    rotacion_izquierda(p->m_pFather);
                    p->m_pFather->m_bColor=black;
                    p->m_pFather->m_pSon[0]->m_bColor=red;

                }
            }
        }

    }

}


template<class T>
bool red_black_tree<T>::is_red(NodoRB<T>*p){
    if(p->m_bColor==0) return true;
    return false;
}


template<class T>
bool red_black_tree<T>::der_izq(NodoRB<T>* p){
    if(p->m_pFather){
        if(p->m_pFather->m_pSon[1]==p) return true;
        return false;
    }
}



template<class T>
NodoRB<T>* red_black_tree<T>::get_brother(NodoRB<T>*p){
    return p->m_pFather->m_pSon[!p->der_izq()];
}

template<class T>
NodoRB<T>* red_black_tree<T>::get_Gfather(NodoRB<T>*p){
    return p->m_pFather->m_pFather;
}

template<class T>
NodoRB<T>* red_black_tree<T>::get_uncle(NodoRB<T>*p){
    return p->m_pFather->m_pFather->m_pSon[!der_izq(p->m_pFather)];
}

template<class T>
NodoRB<T>* red_black_tree<T>::get_father(NodoRB<T>*p){

    return (p->m_pFather);
}


template<class T>
NodoRB<T>** red_black_tree<T>::get_d_brother(NodoRB<T>* p){
    if(p==m_pRoot) return;
    NodoRB<T>** brother = &(p->m_pFather->m_pSon[!der_izq(p)]);
    return brother;
}

template<class T>
NodoRB<T>** red_black_tree<T>::get_d_uncle(NodoRB<T>* p){
    if(p->m_pFather==m_pRoot) return ;

    NodoRB<T>** father;
    return father=&(p->m_pFather->m_pFather->m_pSon[!der_izq(p->m_pFather)]);
}

template<class T>
NodoRB<T>** red_black_tree<T>::get_d_father(NodoRB<T>* p){
    NodoRB<T>** father;

    if(p->m_pFather==m_pRoot) {
        cout<<"father"<<endl;
        father=&(m_pRoot);

    }
    else father=&(p->m_pFather->m_pFather->m_pSon[der_izq(p->m_pFather)]);

    return father;
}

template<class T>
NodoRB<T>** red_black_tree<T>::get_d_Gfather(NodoRB<T>* p){
    NodoRB<T>** Gfather;
    if(p->m_pFather->m_pFather==m_pRoot) return Gfather=&m_pRoot;
    return Gfather=&(p->m_pFather->m_pFather->m_pFather->m_pSon[der_izq(p->m_pFather->m_pFather)]);
}


template<class T>
void red_black_tree<T>::imprimir_por_niveles(){
    if(!m_pRoot) return;
    Cola<NodoRB<T>*> cola;
    cola.push(m_pRoot);
    while(!cola.isEmpty()){
        NodoRB<T>*temp=cola.top();
        cola.pop();
        cout<<temp->m_dato<<"->"<<temp->m_bColor<<endl;
        if(temp->m_pSon[0]) cola.push(temp->m_pSon[0]);
        if(temp->m_pSon[1]) cola.push(temp->m_pSon[1]);
    }
}



#endif
