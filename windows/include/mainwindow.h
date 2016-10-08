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
    void on_pushButton_2_clicked();

    void on_cargar_button_clicked();

    void on_folder_button_clicked();

private:
    VtkWindow vtk;
    Ui::MainWindow *ui;
    estructura_de_dato<palabra>* estructura;
};

#endif // MAINWINDOW_H
