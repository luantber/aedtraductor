#include "vtkwindow.h"
#include "ui_vtkwindow.h"
#include "vtkPolyLine.h"




VtkWindow::VtkWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VtkWindow)
{
    ui->setupUi(this);

    ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);

    renderer->SetBackground(0.0,0.04,0.0);
}

VtkWindow::~VtkWindow()
{
    delete ui;
}

void VtkWindow::setBinomialHeap(BinomialHeap<palabra> * bi){

    Renderer renderer = Renderer::New();
    ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);

    vec.clear();

      bi->puntos(vec);
      cout << "end HAllar Puntos"<<endl;
      int tamanio = vec.size();
      cout << "tamanio: " <<tamanio << endl;

      //cout << "tamanito: " <<tamanito << endl;


      for (int i = 0; i<tamanio;i++){
          double a = ((vec.at(i).par.x)*(1.9))-7;
          double b = (vec.at(i).par.y)*(-1.9)+3;

          if(i>=100) break;
          cout << i << "iteracion nodo" <<  endl;

          int tamanito = vec.at(i).hijos.size();

          /*
          for(int j = 0; j<tamanito;j++){

              cout << vec.at(i).hijos.at(j).x <<" ....  "<< vec.at(i).hijos.at(j).y << endl;

              double c = ((vec.at(i).hijos.at(j).x)*(1.9))-7;
              double d = (vec.at(i).hijos.at(j).y)*(-1.9)+3;

              cout<<a<<" "<<b<<"  "<<c<<"  "<<d<<"sssss" << endl;
              double k = 0.8, t = 0.1;
              double p = c-a;
              double q = d-b;

              double m = a+k*p, n = b+k*q;
              double cx = m+t, cy = n-(t*p)/q;
              double bx = m-t, by = n+(t*p)/q;

              double inicio[3] = {a, b, 0.0};
              double fin[3] = {c, d, 0.0};
              double medio[3]={cx, cy, 0};
              double costa1[3] = {m, n, 0};
              double costa2[3] = {bx, by, 0};

              // Creando los puntos ....
              Points points =Points::New();
              points->InsertNextPoint(inicio);
              points->InsertNextPoint(fin);
              points->InsertNextPoint(medio);
              points->InsertNextPoint(costa1);
              points->InsertNextPoint(fin);
              points->InsertNextPoint(costa2);
              points->InsertNextPoint(medio);



              PolyLine polyLine =PolyLine::New();
              polyLine->GetPointIds()->SetNumberOfIds(7);
              for(unsigned int kl = 0; kl < 7; kl++)
                {
                polyLine->GetPointIds()->SetId(kl,kl);
                }

              // Create a cell array to store the lines in and add the lines to it
              CellArray cells =CellArray::New();
              cells->InsertNextCell(polyLine);

              // Create a polydata to store everything in
              PolyData polyData =PolyData::New();

              // Add the points to the dataset
              polyData->SetPoints(points);

              // Add the lines to the dataset
              polyData->SetLines(cells);

              // Setup actor and mapper
              PolyDataMapper lineasmapper = PolyDataMapper::New();
            #if VTK_MAJOR_VERSION <= 5
              lineasmapper->SetInput(polyData);
            #else
              lineasmapper->SetInputData(polyData);
            #endif

              Actor lineasActor =Actor::New();
              lineasActor->SetMapper(lineasmapper);
              lineasActor->GetProperty()->SetColor(.1,.9,0.0);


              renderer->AddActor(lineasActor);

          }

        */
          SphereSource sphereSource =  SphereSource::New();
           sphereSource->SetCenter(a, b, 0);


          PolyDataMapper sphereMapper = PolyDataMapper::New();
           sphereMapper->SetInputConnection( sphereSource->GetOutputPort() );


          Actor sphereActor = Actor::New();
           sphereActor->SetMapper( sphereMapper );


           sphereActor->GetProperty()->SetColor(.2,.5,0.7);

          //para que sea transparente las bolitas
           sphereActor->GetProperty()->SetOpacity(0.4);

           Follower xLabel = Follower::New();
           VectorText xText = VectorText::New();
           PolyDataMapper xTextMapper = PolyDataMapper::New();;

           std::string str = vec.at(i).palabra.getPalabra();;
           const char * c = str.c_str();

           xText->SetText(c);
           xTextMapper->SetInputConnection( xText->GetOutputPort() );
           xLabel->SetMapper( xTextMapper );
           xLabel->SetScale( 0.1 );
           xLabel->SetCamera(renderer->GetActiveCamera());
           //xLabel->SetPosition(((vtkProp3D*)collection->GetItemAsObject( 3 ))->GetCenter()); // XAxisTip
           xLabel->SetPosition(a,b,0);
           xLabel->PickableOff();

           renderer->AddActor( xLabel );
           //renderer->AddActor ( textActor );
           renderer->AddActor( sphereActor );
      }
      renderer->ResetCamera();
      //renderer->UpdateCamera();
//     renderer->SetBackground(0.0,0.04,0.0);
      this->ui->qvtkWidget->update();

}





void VtkWindow::on_pushButton_clicked()
{
    //INSERTAR
    vec.clear();
    cout<<vec.size()<<"tamaño !!"<<endl;
    vector<string> tr = {"b","c"};

    string insertando = (ui->lineEdit->text().toStdString());

    this->binomialheap->Insert(palabra(insertando,tr));

    graficarBinomial();

}


void VtkWindow::graficarBinomial(){
    Renderer renderer = Renderer::New();
    ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderer);


    binomialheap->puntos(vec);
    cout << "end HAllar Puntos"<<endl;
    int tamanio = vec.size();
    cout << "tamanio: " <<tamanio << endl;

    //cout << "tamanito: " <<tamanito << endl;


    for (int i = 0; i<tamanio;i++){
        double a = ((vec.at(i).par.x)*(1.9))-7;
        double b = (vec.at(i).par.y)*(-1.9)+3;

        int tamanito = vec.at(i).hijos.size();
        for(int j = 0; j<tamanito;j++){

            cout << vec.at(i).hijos.at(j).x <<" ....  "<< vec.at(i).hijos.at(j).y << endl;

            double c = ((vec.at(i).hijos.at(j).x)*(1.9))-7;
            double d = (vec.at(i).hijos.at(j).y)*(-1.9)+3;

            cout<<a<<" "<<b<<"  "<<c<<"  "<<d<<"sssss" << endl;
            double k = 0.8, t = 0.1;
            double p = c-a;
            double q = d-b;

            double m = a+k*p, n = b+k*q;
            double cx = m+t, cy = n-(t*p)/q;
            double bx = m-t, by = n+(t*p)/q;

            double inicio[3] = {a, b, 0.0};
            double fin[3] = {c, d, 0.0};
            double medio[3]={cx, cy, 0};
            double costa1[3] = {m, n, 0};
            double costa2[3] = {bx, by, 0};

            // Creando los puntos ....
            Points points =Points::New();
            points->InsertNextPoint(inicio);
            points->InsertNextPoint(fin);
            points->InsertNextPoint(medio);
            points->InsertNextPoint(costa1);
            points->InsertNextPoint(fin);
            points->InsertNextPoint(costa2);
            points->InsertNextPoint(medio);



            PolyLine polyLine =PolyLine::New();
            polyLine->GetPointIds()->SetNumberOfIds(7);
            for(unsigned int kl = 0; kl < 7; kl++)
              {
              polyLine->GetPointIds()->SetId(kl,kl);
              }

            // Create a cell array to store the lines in and add the lines to it
            CellArray cells =CellArray::New();
            cells->InsertNextCell(polyLine);

            // Create a polydata to store everything in
            PolyData polyData =PolyData::New();

            // Add the points to the dataset
            polyData->SetPoints(points);

            // Add the lines to the dataset
            polyData->SetLines(cells);

            // Setup actor and mapper
            PolyDataMapper lineasmapper = PolyDataMapper::New();
          #if VTK_MAJOR_VERSION <= 5
            lineasmapper->SetInput(polyData);
          #else
            lineasmapper->SetInputData(polyData);
          #endif

            Actor lineasActor =Actor::New();
            lineasActor->SetMapper(lineasmapper);
            lineasActor->GetProperty()->SetColor(.1,.9,0.0);


            renderer->AddActor(lineasActor);

        }


        SphereSource sphereSource =  SphereSource::New();
         sphereSource->SetCenter(a, b, 0);


        PolyDataMapper sphereMapper = PolyDataMapper::New();
         sphereMapper->SetInputConnection( sphereSource->GetOutputPort() );


        Actor sphereActor = Actor::New();
         sphereActor->SetMapper( sphereMapper );


         sphereActor->GetProperty()->SetColor(.2,.5,0.7);

        //para que sea transparente las bolitas
         sphereActor->GetProperty()->SetOpacity(0.4);

         Follower xLabel = Follower::New();
         VectorText xText = VectorText::New();
         PolyDataMapper xTextMapper = PolyDataMapper::New();;

         std::string str = vec.at(i).palabra.getPalabra();;
         const char * c = str.c_str();

         xText->SetText(c);
         xTextMapper->SetInputConnection( xText->GetOutputPort() );
         xLabel->SetMapper( xTextMapper );
         xLabel->SetScale( 0.1 );
         xLabel->SetCamera(renderer->GetActiveCamera());
         //xLabel->SetPosition(((vtkProp3D*)collection->GetItemAsObject( 3 ))->GetCenter()); // XAxisTip
         xLabel->SetPosition(a,b,0);
         xLabel->PickableOff();

         renderer->AddActor( xLabel );
         //renderer->AddActor ( textActor );
         renderer->AddActor( sphereActor );
    }
    renderer->ResetCamera();
    //renderer->UpdateCamera();
    this->ui->qvtkWidget->update();


}


