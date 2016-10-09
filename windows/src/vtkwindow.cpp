#include "vtkwindow.h"
#include "ui_vtkwindow.h"




VtkWindow::VtkWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VtkWindow)
{
    ui->setupUi(this);


    //Traducciones;
    vector<string> tr = {"b","c"};
    vector<string> tr2 = {"d","e"};

    //Test Clase Palabra
    palabra n("a",tr);
    cout << n << endl;
    palabra n2("b",tr2);




    //Heaps -> inserto palabra

    heap.Insert(palabra("a",tr));
    heap.Insert(palabra("b",tr));
    heap.Insert(palabra("c",tr));
    heap.Insert(palabra("d",tr));
    heap.Insert(palabra("e",tr));
    heap.Insert(palabra("f",tr));
    heap.Insert(palabra("g",tr));


    //hallar puntos
    heap.puntos(vec);
    int tamanio = vec.size();
    cout << "tamanio: " <<tamanio << endl;

    //imprimo puntos
    for(auto it:vec){
        cout<<"1 ";
        it.show() ;
        cout<<endl;
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
int contador=0;
//    while(contador <tamanio+1){

  //  }

for (int x=0;x<5;x++){

    for(int y=0;y<5;y++){

 //   cout<<x<<" "<<y<<" "<<z<<endl;
    }
    }

std::vector<std::string> titles;

for (int i = 0; i<tamanio;i++){
    double a = ((vec.at(i).par.x)*(1.5))-7;
    double b = (vec.at(i).par.y)*(-1.5)+3;

    cout <<"a"<<i<<" "<<a<<" b"<<i<<" "<<b<<endl;


    SphereSource sphereSource =  SphereSource::New();
     sphereSource->SetCenter(a, b, 0);


    PolyDataMapper sphereMapper = PolyDataMapper::New();
     sphereMapper->SetInputConnection( sphereSource->GetOutputPort() );

    Actor sphereActor = Actor::New();
     sphereActor->SetMapper( sphereMapper );
     sphereActor->GetProperty()->SetColor(.2,.5,0.7);

     sphereActor->GetProperty()->SetOpacity(0.2);

    ArrowSource arrowSource = ArrowSource::New();
   // arrowSource->SetShaftRadius(1.0);
    arrowSource->SetShaftResolution(10);
    //arrowSource->SetTipLength(1.0);

    PolyDataMapper mapper = PolyDataMapper::New();
     mapper->SetInputConnection(arrowSource->GetOutputPort());

    Actor actor = Actor::New();
     actor->SetMapper(mapper);
     actor->GetProperty()->SetColor(.1,.9,0.0);

     TextActor textActor = TextActor::New();
       textActor->SetInput ( "BINOMIAL HEAP" );
       textActor->SetPosition2 ( 8, 20 );
       textActor->GetTextProperty()->SetFontSize ( 15 );
       textActor->GetTextProperty()->SetColor ( .1,.9,0.0);

       //Palabras ...!!!!!

       Follower xLabel = Follower::New();
       VectorText xText = VectorText::New();
       PolyDataMapper xTextMapper = PolyDataMapper::New();

       xText->SetText( "palabra" );
       xTextMapper->SetInputConnection( xText->GetOutputPort() );
       xLabel->SetMapper( xTextMapper );
       xLabel->SetScale( 0.1 );
       xLabel->SetCamera(renderer->GetActiveCamera());
       //xLabel->SetPosition(((vtkProp3D*)collection->GetItemAsObject( 3 ))->GetCenter()); // XAxisTip
       xLabel->SetPosition(a-0.27,b,0);
       xLabel->PickableOff();
       //**************


     renderer->AddActor( xLabel );
     renderer->AddActor ( textActor );
     renderer->AddActor( actor );
     renderer->AddActor( sphereActor );
     renderer->ResetCamera();

}


     renderer->SetBackground(0.0,0.04,0.0);



    //Conexion VTK-QT
    ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);

    //
}

VtkWindow::~VtkWindow()
{
    delete ui;
}


