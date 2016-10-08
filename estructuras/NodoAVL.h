#ifndef NODOAVL_H
#define NODOAVL_H

template<class T>
class avl_tree;

template<class T>
class NodoAVL
{
    public:
        NodoAVL(T d){ m_pSon[0]=0; m_pSon[1]=0; m_dato=d; m_FE=0;}
        virtual ~NodoAVL(){};
        NodoAVL<T>* m_pSon[2];
    protected:
    private:

        T m_dato;
        int m_FE;
    friend class avl_tree<T>;
};



#endif