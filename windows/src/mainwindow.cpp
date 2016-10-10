#include "mainwindow.h"
#include "ui_mainwindow.h"


int levenshtein(const string &s1, const string &s2)
{
   int N1 = s1.size();
   int N2 = s2.size();
   int i, j;

   vector<int> T(N2+1);

   for ( i = 0; i <= N2; i++ )
      T[i] = i;

   for ( i = 0; i < N1; i++ )
   {
      T[0] = i+1;
      int corner = i;
      for ( j = 0; j < N2; j++ )
      {
         int upper = T[j+1];
         if ( s1[i] == s2[j] )
            T[j+1] = corner;
         else
            T[j+1] = min(T[j], min(upper, corner)) + 1;
         corner = upper;
      }
   }
   return T[N2];
}







std::vector<string> MainWindow::split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

void MainWindow::erase_spaces(string& cosa){
    if(cosa[0]==' ') cosa = cosa.substr(1,cosa.length()-1);
    if(cosa[cosa.length() -1] == ' ') cosa = cosa.substr(0,cosa.length() -1);
}


void MainWindow::process_text(string texto){
    std::vector<std::string> temp = split(texto,char(9));
    std::vector<std::string> palabras = split(temp.at(0),';');
    std::vector<std::string> traducciones = split(temp.at(1),';');
    for (auto& it:palabras) erase_spaces(it);
    for (auto& it:traducciones) erase_spaces(it);


    for (auto it:palabras){

        palabra word(it,traducciones);


        switch (estructura_de_dato) {
        case 0 :
            arbol_avl->add(word);
            break;
        case 1 :
            arbol_red_black->add(word);
            break;
        case 2 :

            arbol_binario->add(word);
            break;
        case 3 :
            lista->list_add(word);
            break;
        case 4 :
            binomialheap->Insert(word);
            cout << "insertado en binomial"<<word;
            break;
        default:
            break;
        }


    }


}




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->arbol_binario = new arbolbinario<palabra>();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_vtk_button_clicked()
{
    this->vtk.show();

}

void MainWindow::on_cargar_button_clicked()
{

  float tiempo;
  timeb tiempoi, tiempof;
  start(&tiempoi);

  string s_estructura_de_dato= (ui->estructura_comboBox->currentText()).toStdString();
  if(s_estructura_de_dato=="Arbol AVL"){
       estructura_de_dato=0;
       delete(arbol_avl);
       arbol_avl=new avl_tree<palabra>();
  }
  else if(s_estructura_de_dato=="Arbol Red-Black"){
      estructura_de_dato=1;
      delete(arbol_red_black);
      arbol_red_black=new red_black_tree<palabra>;
  }
  else if(s_estructura_de_dato=="Arbol Binario"){

      estructura_de_dato=2;
      delete(arbol_binario);

      arbol_binario=new arbolbinario<palabra>();

  }

  else if(s_estructura_de_dato=="Lista Simple"){

      estructura_de_dato=3;
      delete(lista);
      lista=new List<palabra>;
  }
  else if(s_estructura_de_dato=="Binomial Heap"){

      cout << "binomial Selected" << endl;
      estructura_de_dato=4;

      delete(binomialheap);

      //borrado binomial
      binomialheap = new BinomialHeap<palabra>;
  }



  std::string line;
  std::ifstream myfile ((ui->path_label->text()).toStdString()+"/"+(ui->idioma_comboBox->currentText()).toStdString()+"_"+(ui->idioma_destino_combobox->currentText()).toStdString()+".txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      process_text(line);

    }
    myfile.close();
    end_(&tiempof, tiempoi, &tiempo);
    ui->t_carga_label->setText(QString::number(tiempo));
    this->on_pushButton_clicked();
  }
  else std::cout << "Unable to open file";
}

void MainWindow::on_folder_button_clicked()
{
    QFileDialog folderDlg;
    ui->path_label->setText(folderDlg.getExistingDirectory(0,"Caption",QString(),QFileDialog::ShowDirsOnly));

}



void MainWindow::on_pushButton_clicked()
{

    ui->ram_label->setText(QString::number(monitor.getRam()).append(" kb"));
}

void MainWindow::on_buscar_button_clicked()
{
    float tiempo;
    timeb tiempoi, tiempof;
    start(&tiempoi);
    string busqueda= (ui->palabra_lineEdit->text()).toStdString();


    vector<string> palabras;
    vector<string> traducciones;
    vector<int> radios;
    int radio=std::stoi((ui->radio_lineEdit->text()).toStdString());


    buscar(busqueda,radio,palabras,radios,traducciones);
    ui->palabras_textBrowser->clear();
    //ui->traducciones_textBrowser->clear();

    auto func = [](vector<string>& palabras, vector<string>& traducciones,vector<int>& radios){
      for(int i=0;i<palabras.size();i++){
          for(int j=0;j<palabras.size();j++){
            if(radios.at(i)<=radios.at(j)){
                int temp= radios.at(i);
                radios.at(i)=radios.at(j);
                radios.at(j)=temp;
                string temp2= palabras.at(i);
                palabras.at(i)=palabras.at(j);
                palabras.at(j)=temp2;
                string temp3= traducciones.at(i);
                traducciones.at(i)=traducciones.at(j);
                traducciones.at(j)=temp3;
            }
          }
      }

    };

    func(palabras,traducciones,radios);

    for(int i=0;i<palabras.size();i++){


        ui->palabras_textBrowser->append(        QString::fromStdString(palabras.at(i)) + "      ->      " + QString::fromStdString(traducciones.at(i)) +  "    ->   " + QString::number(radios.at(i))  );

    }
    end_(&tiempof, tiempoi, &tiempo);
    ui->t_busqueda_label->setText(QString::number(tiempo));

}

void MainWindow::buscar(string busqueda,int radio, vector<string>&palabras,vector<int>&radios,vector<string>&traducciones){


    switch (estructura_de_dato) {
    case 0 :
        buscar_arbol_avl(busqueda,radio,palabras,traducciones,radios,arbol_avl->m_pRoot);
        break;
    case 1 :
        buscar_arbol_red_black(busqueda,radio,palabras,traducciones,radios,arbol_red_black->m_pRoot);
        break;
    case 2 :

        buscar_arbol_binario(busqueda,radio,palabras,traducciones,radios,arbol_binario->m_root);
        break;
    case 3 :
        buscar_lista(busqueda,radio,palabras,traducciones,radios,lista->m_phead);
        break;
    default:
        break;
    }

}

void MainWindow::buscar_arbol_binario(string busqueda,int radio, vector<string>&palabras,vector<string>&traducciones,vector<int>&radios,nodoarbol<palabra>*p){
    if(!p) return;
    palabra word=p->m_dato;
    if(radio>=levenshtein(busqueda,word.m_palabra)){
        palabras.push_back(word.m_palabra);
        string s_traducciones="";
        for (auto it:word.m_traducciones) s_traducciones+= (" "+it);
        traducciones.push_back(s_traducciones);
        radios.push_back(levenshtein(busqueda,word.m_palabra));
    }
    buscar_arbol_binario(busqueda,radio,palabras,traducciones,radios,p->m_pSon[0]);
    buscar_arbol_binario(busqueda,radio,palabras,traducciones,radios,p->m_pSon[1]);
}


void MainWindow::buscar_arbol_avl(string busqueda,int radio, vector<string>&palabras,vector<string>&traducciones,vector<int>&radios,NodoAVL<palabra>*p){
    if(!p) return;
    palabra word=p->m_dato;
    if(radio>=levenshtein(busqueda,word.m_palabra)){
        palabras.push_back(word.m_palabra);
        string s_traducciones="";
        for (auto it:word.m_traducciones) s_traducciones+= (" "+it);
        traducciones.push_back(s_traducciones);
        radios.push_back(levenshtein(busqueda,word.m_palabra));
    }
    buscar_arbol_avl(busqueda,radio,palabras,traducciones,radios,p->m_pSon[0]);
    buscar_arbol_avl(busqueda,radio,palabras,traducciones,radios,p->m_pSon[1]);
}


void MainWindow::buscar_arbol_red_black(string busqueda,int radio, vector<string>&palabras,vector<string>&traducciones,vector<int>&radios,NodoRB<palabra>*p){
    if(!p) return;
    palabra word=p->m_dato;
    if(radio>=levenshtein(busqueda,word.m_palabra)){
        palabras.push_back(word.m_palabra);
        string s_traducciones="";
        for (auto it:word.m_traducciones) s_traducciones+= (" "+it);
        traducciones.push_back(s_traducciones);
        radios.push_back(levenshtein(busqueda,word.m_palabra));
    }
    buscar_arbol_red_black(busqueda,radio,palabras,traducciones,radios,p->m_pSon[0]);
    buscar_arbol_red_black(busqueda,radio,palabras,traducciones,radios,p->m_pSon[1]);
}

void MainWindow::buscar_lista(string busqueda,int radio, vector<string>&palabras,vector<string>&traducciones,vector<int>&radios,Nodo<palabra>*p){
    if(!p) return;
    palabra word=p->m_dato;
    if(radio>=levenshtein(busqueda,word.m_palabra)){
        palabras.push_back(word.m_palabra);
        string s_traducciones="";
        for (auto it:word.m_traducciones) s_traducciones+= (" "+it);
        traducciones.push_back(s_traducciones);
        radios.push_back(levenshtein(busqueda,word.m_palabra));
    }
    buscar_lista(busqueda,radio,palabras,traducciones,radios,p->m_psig);

}

void MainWindow::on_estructura_comboBox_currentIndexChanged(int index)
{
    cout << index;
}

float MainWindow::dif_sec(int tiempoi, int tiempof){
    return (float)(tiempof - tiempoi);
}

float MainWindow::dif_mil(int tiempoi, int tiempof){
    return (float)(tiempof - tiempoi) * 0.001;
}

void MainWindow::start(timeb *t){
    ftime(t);
}

void MainWindow::end_(timeb *tiempof, timeb tiempoi, float *resultado){
    ftime(tiempof);
    //cout<<tiempoi.time<<endl;
    //cout<<tiempof->time<<endl;
    *resultado = dif_sec((int)tiempoi.time, (int)((*tiempof).time)) + dif_mil((int)tiempoi.millitm, (int)((*tiempof).millitm));
}

void MainWindow::on_palabras_textBrowser_cursorPositionChanged()
{

}

void MainWindow::on_verDiccionario_clicked()
{
    this->vtk.show();

    vtk.setBinomialHeap(this->binomialheap);
}
