#ifndef VTKWINDOW_H
#define VTKWINDOW_H

#include <QWidget>

#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkArrowSource.h>
#include <vtkPolyData.h>

#include "binomial.h"
#include "palabra.h"

typedef vtkSmartPointer<vtkSphereSource> SphereSource;
typedef vtkSmartPointer<vtkArrowSource> ArrowSource;
typedef vtkSmartPointer<vtkPolyDataMapper> PolyDataMapper;
typedef vtkSmartPointer<vtkActor> Actor;
typedef vtkSmartPointer<vtkRenderer> Renderer;

namespace Ui {
class VtkWindow;
}

class VtkWindow : public QWidget
{
    Q_OBJECT

public:


    Renderer renderer = Renderer::New();


    //Constructor
    explicit VtkWindow(QWidget *parent = 0);
    ~VtkWindow();

private:
    //Vector de NodosVTK imprimibles
    vector<NodoVTK<palabra>> vec;

    BinomialHeap<palabra> heap;
    Ui::VtkWindow *ui;
};

#endif // VTKWINDOW_H
