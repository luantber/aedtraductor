#ifndef PALABRA_H
#define PALABRA_H
#include <iostream>
#include <vector>
	

using namespace std;

class palabra
{
public:
	palabra(string palabra,vector<string> traducciones){ m_palabra=palabra; m_traducciones=traducciones; }
	~palabra(){}
	
private:
	string m_palabra;
	std::vector<string> m_traducciones;
};


#endif
