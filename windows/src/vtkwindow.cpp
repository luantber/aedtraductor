#include "vtkwindow.h"
#include "ui_vtkwindow.h"

VtkWindow::VtkWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VtkWindow)
{
    ui->setupUi(this);

    //Heaps
    heap.Insert(5);
    heap.Insert(6);
    heap.Insert(7);
    heap.Insert(8);

    heap.Insert(9);


    //Codigo VTK


int x=0, y=0, z=0;

for (int x=0;x<5;x++){

    for(int y=0;y<5;y++){
    cout<<x<<" "<<y<<" "<<z<<endl;


    SphereSource sphereSource =  SphereSource::New();
     sphereSource->SetCenter(x, y, 0);

    PolyDataMapper sphereMapper = PolyDataMapper::New();
     sphereMapper->SetInputConnection( sphereSource->GetOutputPort() );

    Actor sphereActor = Actor::New();
     sphereActor->SetMapper( sphereMapper );

    ArrowSource arrowSource = ArrowSource::New();
    PolyDataMapper mapper = PolyDataMapper::New();
     mapper->SetInputConnection(arrowSource->GetOutputPort());

    Actor actor = Actor::New();
     actor->SetMapper(mapper);

     renderer->AddActor( sphereActor );

     renderer->AddActor( actor );

    }
   }


     renderer->SetBackground(0.3,0.01,0.1);



    //Conexion VTK-QT
    ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);

    //
}

VtkWindow::~VtkWindow()
{
    delete ui;
}


