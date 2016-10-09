#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <vector>
#include "NodoAVL.h"
#include "cola.h"
#include "estructura_de_dato.h"




template<class T>
class avl_tree
{
public:
	avl_tree():m_pRoot(0){}
    ~avl_tree(){}
	bool find(T,NodoAVL<T>**&);
	void add(std::vector<T>);	
	void add(T d);
	void rotacion_left_left(NodoAVL<T>*&p);
    void rotacion_right_right(NodoAVL<T>*&p);
    void rotacion_right_left(NodoAVL<T>*&p);
    void rotacion_left_right(NodoAVL<T>*&p);
    void rotacion_simple(NodoAVL<T>*&p,bool right);
    void rotacion_doble(NodoAVL<T>*&p,bool right);
    void insertar(T d,NodoAVL<T>*& p,bool&);
    void imprimir_fe_por_niveles();
    void imprimir_por_niveles();

private:
    NodoAVL<T>* m_pRoot;

};



template<class T>
bool avl_tree<T>::find(T d, NodoAVL<T>**& p){
    p=&m_pRoot;
    while(*p){
        if((*p)->m_dato==d) return true;
        if((*p)->m_dato<d) p=&((*p)->m_pSon[1]);
        else p=&((*p)->m_pSon[0]);
    }
    return false;
}



template<class T>
void avl_tree<T>::rotacion_simple(NodoAVL<T>*&p, bool right){
    NodoAVL<T>*temp=p;
    p=temp->m_pSon[right];
    temp->m_pSon[!right]=p->m_pSon[!right];
    p->m_pSon[!right]=temp;
    p->m_FE=temp->m_FE=0;
}

template<class T>
void avl_tree<T>::rotacion_doble(NodoAVL<T>*&p, bool right){
    NodoAVL<T>*temp=p;
    p=temp->m_pSon[!right]->m_pSon[right];
    temp->m_pSon[!right]->m_pSon[right]=p->m_pSon[!right];
    p->m_pSon[!right]=temp->m_pSon[!right];
    temp->m_pSon[!right]=p->m_pSon[right];
    p->m_pSon[right]=temp;
    p->m_FE=temp->m_FE=0;
    if(p->m_pSon[!right]->m_pSon[!right]) p->m_pSon[!right]->m_FE*=-1;
}


template<class T>
void avl_tree<T>::add(std::vector<T> d){
	for(auto it:d){
		add(it);
	}
}

template<class T>
void avl_tree<T>::add(T d){
	bool seguir=1;
	insertar(d,m_pRoot,seguir);
}


template<class T>
void avl_tree<T>::insertar(T d,NodoAVL<T>*& p,bool& seguir){
	if(!p){
		p=new NodoAVL<T>(d);
		return;
	}
	if(p->m_dato==d) return; 
	
	insertar(d,p->m_pSon[p->m_dato<d],seguir);
	if(!seguir) return;
	if(p->m_dato<d)
		p->m_FE++;
	else
		p->m_FE--;
	
	switch(p->m_FE){
		case 0: 
			seguir=false;
			return;
			
		case 2:
			if(p->m_pSon[1]->m_FE==1) rotacion_right_right(p);
			else rotacion_right_left(p);
			seguir=false;
			break;
		case -2:
			if(p->m_pSon[0]->m_FE==1) rotacion_left_right(p);
			else rotacion_left_left(p);
			seguir=false;
			break;
	}
}

template<class T>
void avl_tree<T>::rotacion_left_left(NodoAVL<T>*&p){
    p->m_pSon[0]->m_FE=0;
	p->m_FE=0;
    if(p->m_pSon[1]){
    	if(p->m_pSon[0]->m_pSon[0]->m_pSon[1]){
    		p->m_pSon[0]->m_pSon[0]->m_FE=1;

    	}
    	else{
    		p->m_pSon[0]->m_pSon[0]->m_FE=-1;
    	}
    }
    else{
    	
    	p->m_pSon[0]->m_pSon[0]->m_FE=0;
    }

    NodoAVL<T>*temp=p;
    p=temp->m_pSon[0];

    //salvar hijo de p
    temp->m_pSon[0]=p->m_pSon[1];
    p->m_pSon[1]=temp;
}

template<class T>
void avl_tree<T>::rotacion_right_right(NodoAVL<T>*&p){
	p->m_pSon[1]->m_FE=0;
	p->m_FE=0;
    if(p->m_pSon[0]){
    	if(p->m_pSon[1]->m_pSon[1]->m_pSon[0]){
    		p->m_pSon[1]->m_pSon[1]->m_FE=-1;

    	}
    	else{
    		p->m_pSon[1]->m_pSon[1]->m_FE=1;
    	}
    }
    else{
    	
    	p->m_pSon[1]->m_pSon[1]->m_FE=0;
    }

    NodoAVL<T>*temp=p;
    p=temp->m_pSon[1];

    //salvar hijo de p
    temp->m_pSon[1]=p->m_pSon[0];
    p->m_pSon[0]=temp;
	    

}

template<class T>
void avl_tree<T>::rotacion_left_right(NodoAVL<T>*&p){
    //Modificar FE 
	p->m_pSon[0]->m_pSon[1]->m_FE=0;
	if(p->m_pSon[1]){
		if(p->m_pSon[0]->m_pSon[1]->m_pSon[1]){
			p->m_FE=0;
			p->m_pSon[0]->m_FE=-1;	
		}
		else{
			p->m_FE=1;
			p->m_pSon[0]->m_FE=0;		
		}
	}
	else{
		p->m_FE=0;
		p->m_pSon[0]->m_FE=0;
		
	}

	NodoAVL<T>*temp=p;
	p=temp->m_pSon[0]->m_pSon[1];
	//salvar hijos de p
	temp->m_pSon[0]->m_pSon[1]=p->m_pSon[0];
	p->m_pSon[0]=temp->m_pSon[0];

	temp->m_pSon[0]=p->m_pSon[1];
	p->m_pSon[1]=temp;
}

template<class T>
void avl_tree<T>::rotacion_right_left(NodoAVL<T>*&p){
	//Modificar FE 
	p->m_pSon[1]->m_pSon[0]->m_FE=0;
	if(p->m_pSon[0]){
		if(p->m_pSon[1]->m_pSon[0]->m_pSon[0]){
			p->m_FE=0;
			p->m_pSon[1]->m_FE=1;	
		}
		else{
			p->m_FE=-1;
			p->m_pSon[1]->m_FE=0;		
		}
	}
	else{
		p->m_FE=0;
		p->m_pSon[1]->m_FE=0;
		
	}

	NodoAVL<T>*temp=p;
	p=temp->m_pSon[1]->m_pSon[0];
	//salvar hijos de p
	temp->m_pSon[1]->m_pSon[0]=p->m_pSon[1];
	p->m_pSon[1]=temp->m_pSon[1];

	temp->m_pSon[1]=p->m_pSon[0];
	p->m_pSon[0]=temp;

   
}


template<class T>
void avl_tree<T>::imprimir_fe_por_niveles(){
    if(!m_pRoot) return;
    Cola<NodoAVL<T>*> cola;
    cola.push(m_pRoot);
    while(!cola.isEmpty()){
        NodoAVL<T>*temp=cola.top();
        cola.pop();
        cout<<temp->m_dato<<"->"<<temp->m_FE<<endl;
        if(temp->m_pSon[0]) cola.push(temp->m_pSon[0]);
        if(temp->m_pSon[1]) cola.push(temp->m_pSon[1]);
    }
}

template<class T>
void avl_tree<T>::imprimir_por_niveles(){
    if(!m_pRoot) return;
    Cola<NodoAVL<T>*> cola;
    cola.push(m_pRoot);
    while(!cola.isEmpty()){
        NodoAVL<T>*temp=cola.top();
        cola.pop();
        cout<<temp->m_dato<<endl;
        if(temp->m_pSon[0]) cola.push(temp->m_pSon[0]);
        if(temp->m_pSon[1]) cola.push(temp->m_pSon[1]);
    }
}

#endif
