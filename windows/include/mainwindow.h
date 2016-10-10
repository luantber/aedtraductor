#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <fstream>
#include <string>
#include <iostream>
#include <QLabel>
#include <vector>
#include <sstream>
#include <QFileDialog>
#include <algorithm>

#include "vtkwindow.h"
#include "palabra.h"
#include "funciones.h"

#include "binomial.h"
#include "avl_tree.h"
#include "red_black_tree.h"
#include "Binary_tree.h"
#include "List.h"
#include "arbolbinario.h"

#include "monitor.h"

#include <sys/timeb.h>



using namespace std;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void erase_spaces(string& cosa);
    void process_text(string texto);
    //esta funcion llama a las otras funciones de buscar
    void buscar(string busqueda,int radio, vector<string>&palabras,vector<int>&radios,vector<string>&traducciones);

    void buscar_arbol_binario(string busqueda,int radio, vector<string>&palabras,vector<string>&traducciones,vector<int>&radios,nodoarbol<palabra>*p);
    void buscar_arbol_avl(string busqueda,int radio, vector<string>&palabras,vector<string>&traducciones,vector<int>&radios,NodoAVL<palabra>*p);
    void buscar_arbol_red_black(string busqueda,int radio, vector<string>&palabras,vector<string>&traducciones,vector<int>&radios,NodoRB<palabra>*p);
    void buscar_lista(string busqueda,int radio, vector<string>&palabras,vector<string>&traducciones,vector<int>&radios,Nodo<palabra>*p);
    std::vector<string> split(const string &s, char delim);
    ~MainWindow();


private slots:


    void on_vtk_button_clicked();

    void on_cargar_button_clicked();

    void on_folder_button_clicked();

    void on_pushButton_clicked();

    void on_buscar_button_clicked();


    void on_estructura_comboBox_currentIndexChanged(int index);


    void on_palabras_textBrowser_cursorPositionChanged();

    void on_verDiccionario_clicked();

private:
    VtkWindow vtk;
    Ui::MainWindow *ui;

    //este int permitira saber que estructura de dato usar
    int estructura_de_dato;



    //punteros a las clases
    avl_tree<palabra>* arbol_avl=new avl_tree<palabra>;
    red_black_tree<palabra>* arbol_red_black=new red_black_tree<palabra>;
    arbolbinario<palabra>* arbol_binario = new arbolbinario<palabra>;

    BinomialHeap<palabra> * binomialheap = new BinomialHeap<palabra> ;
    List<palabra>* lista=new List<palabra>;


    Monitor monitor;

    float dif_sec(int tiempoi, int tiempof);
    float dif_mil(int tiempoi, int tiempof);
    void start(timeb * t);
    void end_(timeb * tiempof, timeb tiempoi, float * resultado);


    friend class VtkWindow;

};

#endif // MAINWINDOW_H
