#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

#include "nodoarbol.h"

class mainwindow;


template<class T>
class arbolbinario{
	public:
		nodoarbol<T>* m_root;
		arbolbinario<T>(){
			m_root = NULL;
		}
		bool buscar(T d, nodoarbol<T>**& p){
			p = &m_root;
			while(*p){
				if((*p) -> m_dato == d) return true;
				p = &((*p) -> m_pSon[(*p) -> m_dato < d]);
			}
			return false;
		}
        bool find(T d){
            nodoarbol<T>** p;
            return buscar(d,p);
        }

        void buscar_r(string busqueda,int radio, vector<string>&palabras,vector<string>&traducciones,int (*funcion)(const string &, const string &),nodoarbol<T>*p){

        }

        void buscar(string busqueda,int radio, vector<string>&palabras,vector<string>&traducciones,int (*funcion)(const string &, const string &)){
            buscar_r(busqueda,radio,palabras,traducciones,funcion,m_root);
        }

		void add(T d){
			nodoarbol<T>** q = &m_root;
			if(buscar(d, q) == true) return;
			*q = new nodoarbol<T>(d);
		}

        ~arbolbinario(){
            if(m_root) m_root->borrarRecursivo(m_root);
        }
    friend class mainwindow;
};

#endif
