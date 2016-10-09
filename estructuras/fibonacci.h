#include <list>
#include <math.h>
#include "fibonaccinodo.h"

using namespace std;
template <class T>
class Fibonacci
{


    typedef NodoB<T> *  pNodo;
    typedef    list< NodoB<T> *>       TLista;
    typedef typename   TLista::iterator  TIterator;

public:
    Fibonacci() {
        num_datos = 0;
    }
    pNodo p_minimo;
    int num_datos;
    TLista m_Heads;


    void insertar(T d){
         pNodo nuevo = new NodoB<T>(d);
         if ( m_Heads.empty() )
             p_minimo = nuevo;

         m_Heads.push_back(nuevo);
         num_datos++;

        if (p_minimo->m_Dato > nuevo->m_Dato)
            p_minimo = nuevo;
    }

    void extractMin(){
        TIterator it_son = p_minimo->m_Son.begin();
        for(; it_son != p_minimo->m_Son.end() ; ++it_son)
             m_Heads.push_back(*it_son);
        m_Heads.remove(p_minimo);

        num_datos=num_datos-1;
        merge();

        p_minimo = *(m_Heads.begin());
        for(TIterator t2=m_Heads.begin(); t2!=m_Heads.end();++t2){
            if((*t2)->m_Dato < p_minimo->m_Dato)
                p_minimo = *t2;
        }
    }

    void merge()
    {		int n = log2(num_datos)+1;
          pNodo arreglo[n] ;

          for( int i =0;i<n ; ++i) arreglo[i] = 0;


          TIterator it = m_Heads.begin();
          while(it!=m_Heads.end()){
              int posicion = (*it)->m_Grado;

              if(arreglo[posicion] == 0){
                  arreglo[posicion] = (*it);
                  it++;
              }
              else{
                  if (arreglo[posicion]->m_Dato > (*it)->m_Dato){
                      swap(*(arreglo[posicion]),*(*it));


                      for(TIterator it2 = arreglo[posicion]->m_Son.begin() ;it2!= arreglo[posicion]->m_Son.end();++it2){
                          (*it2)->m_pPadre = arreglo[posicion];
                      }
                      for(TIterator it2 = (*it)->m_Son.begin(); it2!= (*it)->m_Son.end();++it2){
                          (*it2)->m_pPadre = *it;
                      }
                  }

                  arreglo[posicion]->m_Son.push_back(*it);
                  (*it)->m_pPadre = arreglo[posicion];
                  TIterator temp = it;
                  temp--;
                  m_Heads.erase(it);
                  it = temp;
                  arreglo[posicion]->m_Grado++;
                  arreglo[posicion] = 0;
              }
          }

          return ;
    }

};

