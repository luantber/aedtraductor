#include <string>
#include <vector>
#include <iostream>
typedef int cor;
using namespace std;

class Par
{
public:
    Par(){

    }

    Par(cor x1, cor y2) {
        x = x1;
        y = y2;
    }
    cor x,y;
};


class NodoVTK
{
public:
    NodoVTK(){

    }

    NodoVTK(cor x, cor y ,int s, vector<Par> h) {
        par = Par(x,y);
        palabra = s;
        hijos = h;
    }
    Par par;
    int palabra;
    vector<Par> hijos;

    void show(){
        cout << par.x << " , " << par.y << endl;
    }
};
