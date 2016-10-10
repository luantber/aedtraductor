#ifndef VTKWINDOW_H
#define VTKWINDOW_H
#define USER_MATRIX

#include <QWidget>

#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkArrowSource.h>
#include <vtkPolyData.h>
#include <vtkTextActor.h>
#include <vtkProperty.h>
#include <vtkTextProperty.h>



#include <vtkFollower.h>
#include <vtkVectorText.h>


#include "binomial.h"
#include "palabra.h"

typedef vtkSmartPointer<vtkSphereSource> SphereSource;
typedef vtkSmartPointer<vtkArrowSource> ArrowSource;
typedef vtkSmartPointer<vtkPolyDataMapper> PolyDataMapper;
typedef vtkSmartPointer<vtkActor> Actor;
typedef vtkSmartPointer<vtkRenderer> Renderer;
typedef vtkSmartPointer<vtkTextActor> TextActor;
typedef vtkSmartPointer<vtkFollower> Follower;
typedef vtkSmartPointer<vtkVectorText> VectorText;
typedef vtkSmartPointer<vtkPoints> Points;
typedef vtkSmartPointer<vtkPolyLine> PolyLine;
typedef vtkSmartPointer<vtkCellArray> CellArray;
typedef vtkSmartPointer<vtkPolyData> PolyData;

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

    void setBinomialHeap(BinomialHeap<palabra> * bi);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    //Vector de NodosVTK imprimibles
    vector<NodoVTK<palabra>> vec;
    BinomialHeap<palabra> *binomialheap = new BinomialHeap<palabra>;

    Ui::VtkWindow *ui;

};

#endif // VTKWINDOW_H
