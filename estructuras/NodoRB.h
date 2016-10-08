#ifndef NODORB_H
#define NODORB_H
#include <iostream>

template<class T>
class red_black_tree;

template <class T>
class NodoRB
{
public:
	NodoRB(T d){m_dato=d; m_pSon[0]=0; m_pSon[1]=0; m_bColor=0; m_pFather=0;}
	~NodoRB(){};
private:
	// negro para 1  y rojo para 0
	T m_dato;
	bool m_bColor;
	NodoRB<T>* m_pSon[2];
	NodoRB<T>* m_pFather;
friend class red_black_tree<T>;
};


#endif