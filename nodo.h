#ifndef NODO_H
#define NODO_H

template <class T>
class Nodo
{
public:
    Nodo(T d) {
        dato = d;
        mp_son[0]=0;
        mp_son[1]=0;
        fe=0;
    }
    T dato;
    Nodo* mp_son[2];
    int fe;

};
#endif // NODO_H

