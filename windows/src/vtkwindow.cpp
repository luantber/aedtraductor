#include "vtkwindow.h"
#include "ui_vtkwindow.h"

VtkWindow::VtkWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VtkWindow)
{
    ui->setupUi(this);


    //Traducciones;
    vector<string> tr = {"b","c"};

    //Test Clase Palabra
    palabra n("a",tr);
    cout << n << endl;




    //Heaps -> inserto palabra
    heap.Insert(palabra("a",tr));
    heap.Insert(palabra("b",tr));
    heap.Insert(palabra("c",tr));
    
    //hallar puntos
    heap.puntos(vec);

    cout << "tamanio: " <<vec.size() << endl;

    //imprimo puntos
    for(auto it:vec){
        it.show() ;
    }

   cout << endl;

   //primer punto"
    cout << vec.at(0).par.x << endl;
    cout << vec.at(0).par.y << endl;
    cout << vec.at(0).palabra << endl; // Funciona por la sobrecarga si quieres usarlo
    cout << vec.at(0).palabra.getPalabra() << endl;

        //primer hijo
    cout << vec.at(0).hijos.at(0).x << endl;






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


