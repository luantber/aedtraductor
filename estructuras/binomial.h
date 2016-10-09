#include<iostream>
#include<list>
#include <math.h>

#include "nodovtk.h"

#include "binomialnodo.h"
using namespace std;

template<class T>
class BinomialHeap
{
    typedef NodoB<T> *  pNodo;
    typedef    list< NodoB<T> *>       TLista;
    typedef typename   TLista::iterator  TIterator; 
    
    private:
    	int num_datos;

        //suubir
    public:
        TLista  m_Heads;
      BinomialHeap(){
      	num_datos=0;
      };
      void Insert(T d)
      {
          m_Heads.push_back(new NodoB<T>(d));
          ++num_datos;
          merge();    
      }
      T minimo()
      {
            TIterator it = m_Heads.begin();
            T min =  (*it)->m_Dato;
             for(; it !=m_Heads.end() ; ++it)
                  if(min>(*it)->m_Dato)
                     min = (*it)->m_Dato;
            return min;
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
      void Decrease_key(pNodo p , T d)
      {
          p->m_Dato = d;
          while(p->m_pPadre)
          {
                 if (p->m_Dato < p->m_pPadre->m_Dato)
                        swap(p->m_Dato,p->m_pPadre->m_Dato);
                 else return;
          }
      }
     
      void Extract_min()
      {

            TIterator it = m_Heads.begin();
            pNodo min = *it;
             for(; it !=m_Heads.end() ; ++it)
                  if(min->m_Dato>(*it)->m_Dato)
                     min = (*it);
            
             TIterator it_son = min->m_Son.begin();
             for(; it_son != min->m_Son.end() ; ++it_son)
                  m_Heads.push_back(*it_son);
             m_Heads.remove(min);
             merge();
      }
 
      void Delete(pNodo p)
      {
          Decrease_key(p,-10000);
          Extract_min();    
      }  

      pNodo getCabeza(){
          return *(m_Heads.begin());
      }

      void llenar(vector<NodoVTK> & coordenadas, pNodo & temp, cor x, cor y, cor & max){

          vector<Par> t1;
          Par p(x,y);
          int st = 3;
          NodoVTK tempv(x,y,st,t1);

          coordenadas.push_back(tempv);

          if(temp->isHoja()){
              cout << "isHoja: "<<temp->m_Dato << endl;
              return;
          }

          cor tX = x;
          for (int i= 0; i< temp->m_Son.size();++i){
              Par t2(x,y+1);
              coordenadas.back().hijos.push_back(t2);
              x++;
          }
          x = tX;
          for(auto it:temp->m_Son){
              llenar(coordenadas,it,x,y+1,max);
              x++;
          }
          if(x>max){

              max=x;
              cout <<" max: " << x << endl;
           }

      }

      void puntos(vector<NodoVTK> & coordenadas){
          cor max = 0;

          for(auto it:m_Heads){
              llenar(coordenadas,it,max,0,max);

          }
          return;
      }
};
  

