#include "vtkwindow.h"
#include "ui_vtkwindow.h"

typedef vtkSmartPointer<vtkSphereSource> SphereSource;
typedef vtkSmartPointer<vtkArrowSource> ArrowSource;
typedef vtkSmartPointer<vtkPolyDataMapper> PolyDataMapper;
typedef vtkSmartPointer<vtkActor> Actor;
typedef vtkSmartPointer<vtkRenderer> Renderer;

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
    heap.Insert(3);


    vector<NodoVTK> vec;
    heap.puntos(vec);

    cout << "plox: " <<vec.size() << endl;
    for(auto it:vec){
        it.show() ;
    }




    //Codigo VTK

    SphereSource sphereSource =  SphereSource::New();
     sphereSource->SetCenter(0.0, 2.0, 0.0);

    PolyDataMapper sphereMapper = PolyDataMapper::New();
    sphereMapper->SetInputConnection( sphereSource->GetOutputPort() );
    Actor sphereActor = Actor::New();
    sphereActor->SetMapper( sphereMapper );


     ArrowSource arrowSource = ArrowSource::New();
     PolyDataMapper mapper = PolyDataMapper::New();
     mapper->SetInputConnection(arrowSource->GetOutputPort());
     Actor actor = Actor::New();
     actor->SetMapper(mapper);



    Renderer renderer = Renderer::New();
     renderer->AddActor( sphereActor );
     renderer->AddActor( actor );


    //Conexion VTK-QT
    ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);

    //
}

VtkWindow::~VtkWindow()
{
    delete ui;
}
