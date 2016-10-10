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

#include "vtkwindow.h"
#include "palabra.h"
#include "estructura_de_dato.h"

#include "binomial.h"
#include "avl_tree.h"
#include "red_black_tree.h"
#include "Binary_tree.h"
#include "List.h"

#include "monitor.h"



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
    std::vector<string> split(const string &s, char delim);
    ~MainWindow();

private slots:


    void on_vtk_button_clicked();

    void on_cargar_button_clicked();

    void on_folder_button_clicked();

    void on_pushButton_clicked();

private:
    VtkWindow vtk;
    Ui::MainWindow *ui;

    //este int permitira saber que estructura de dato usar
    int estructura_de_dato;

    //punteros a las clases
    avl_tree<palabra>* arbol_avl;
    red_black_tree<palabra>* arbol_red_black;
    Binary_tree<palabra>* arbol_binario;
    List<palabra>* lista;

    BinomialHeap<palabra> bino ;

    Monitor m;

};

#endif // MAINWINDOW_H
