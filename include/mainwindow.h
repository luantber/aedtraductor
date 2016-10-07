#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<iostream>
#include<QLabel>
#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(QMainWindow*vtk_window,QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    //SimpleView * ventana_vtk;
    Ui::MainWindow *ui;
    QMainWindow* m_vtk_window;
};

#endif // MAINWINDOW_H
