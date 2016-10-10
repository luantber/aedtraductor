#ifndef PALABRA_H
#define PALABRA_H
#include <iostream>
#include <vector>
	

using namespace std;


class MainWindow;

class palabra
{
public:
    palabra(string palabra,vector<string> traducciones){ m_palabra=palabra; m_traducciones=traducciones; }
    palabra(){}
	~palabra(){}
    friend bool operator > (const palabra&,const palabra&);
    friend bool operator < (const palabra&,const palabra&);
    friend bool operator >=(const palabra&,const palabra&);
    friend bool operator <=(const palabra&,const palabra&);
    friend bool operator ==(const palabra&,const palabra&);
    friend bool operator !=(const palabra&,const palabra&);
    void operator = (palabra);

    string getPalabra() const {return m_palabra;}

private:
    string m_palabra;
	std::vector<string> m_traducciones;

friend class MainWindow;
};

inline std::ostream& operator<<(std::ostream& os, const palabra& word)
{

  return os  << "'"<<word.getPalabra() << "'" ;
}

#endif

