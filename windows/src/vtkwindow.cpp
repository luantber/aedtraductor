#include "vtkwindow.h"
#include "ui_vtkwindow.h"

VtkWindow::VtkWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VtkWindow)
{
    ui->setupUi(this);

    vtkSmartPointer<vtkSphereSource> sphereSource =
         vtkSmartPointer<vtkSphereSource>::New();

     vtkSmartPointer<vtkPolyDataMapper> sphereMapper =
         vtkSmartPointer<vtkPolyDataMapper>::New();
     sphereMapper->SetInputConnection( sphereSource->GetOutputPort() );

     vtkSmartPointer<vtkActor> sphereActor =
         vtkSmartPointer<vtkActor>::New();
     sphereActor->SetMapper( sphereMapper );

     vtkSmartPointer<vtkRenderer> renderer =
         vtkSmartPointer<vtkRenderer>::New();
     renderer->AddActor( sphereActor );

    ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);
}

VtkWindow::~VtkWindow()
{
    delete ui;
}
