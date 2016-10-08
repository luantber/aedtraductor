#ifndef ESTRUCTURA_DE_DATO_H
#define ESTRUCTURA_DE_DATO_H


//--------------------------GG ESTA COSA


template<class T>
class estructura_de_dato
{
public:
	estructura_de_dato(){}
	~estructura_de_dato(){}
    void insertar(T d);
    void add(T d);
    std::vector<T> buscar(std::string word);

};


#endif
