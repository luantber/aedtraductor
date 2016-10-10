#ifndef BINOMIALNODO_H
#define BINOMIALNODO_H

template<class T>
class NodoB
{
    typedef NodoB<T> *  pNodo;
    public:
      int                m_Grado;
      T                  m_Dato;
      pNodo              m_pPadre;
      list< pNodo >      m_Son; 
     NodoB(T d)
      {
           m_Dato = d;
           m_Grado =0;
      }
     bool isHoja(){
         if (m_Son.empty()) return true;
         else return false;
     }

     void borrarRecursivo(pNodo temp){
         for(auto it:temp->m_Son){
             borrarRecursivo(it);
         }
         delete temp;
     }
     ~NodoB(){
     }
};


#endif
