#include "mainwindow.h"
#include <QApplication>

#include "arbolavl.h"
#include <iostream>
int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
    */
    ArbolAVL<int> arbol;

 //   for(int i=0; i<500000 ; ++i)
        arbol.insertar(5);
        arbol.insertar(6);
        arbol.insertar(8);
        arbol.insertar(10);
        arbol.insertar(7);
        arbol.insertar(15);
        arbol.insertar(4);
        arbol.insertar(3);
        arbol.insertar(3);





    std::cout << "Hello";



}




