#ifndef NODOAVL_H
#define NODOAVL_H


class MainWindow;

template<class T>
class avl_tree;

template<class T>
class NodoAVL
{
    public:
        NodoAVL(T d){ m_pSon[0]=0; m_pSon[1]=0; m_dato=d; m_FE=0;}

        virtual ~NodoAVL(){};
        NodoAVL<T>* m_pSon[2];
        T m_dato;
    protected:
    private:


        int m_FE;
    friend class avl_tree<T>;
    friend class MainWindow;
};



#endif
