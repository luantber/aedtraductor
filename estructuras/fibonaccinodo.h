#ifndef FIBONACCI_H
#define FIBONACCI_H

template<class T>
class NodoB
{
    typedef NodoB<T> *  pNodo;
     public:
      int                m_Grado;
      T                  m_Dato;
      pNodo              m_pPadre;
      list< pNodo >      m_Son;
      bool               mark;
     NodoB(T d)
      {
           m_Dato = d;
           m_Grado =0;
           mark = 0;
      }
};

#endif

