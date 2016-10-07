#include "mainwindow.h"
#include "ui_mainwindow.h"







MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::MainWindow(QMainWindow*vtk_window,QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_vtk_window=vtk_window;
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    std::string str = "Hello world";
    QString qstr = QString::fromStdString(str);


}


void MainWindow::on_pushButton_2_clicked()
{
    //ventana_vtk=new Simple_view();
    //ventana_vtk->show();
    m_vtk_window->show();
}
