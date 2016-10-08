#ifndef ESTRUCTURA_DE_DATO_H
#define ESTRUCTURA_DE_DATO_H


class palabra;

template<class T>
class estructura_de_dato
{
public:
	estructura_de_dato(){}
	~estructura_de_dato(){}
	void insertar(T d);
	std::vector<palabra> buscar(std::string palabra);
	
};


#endif