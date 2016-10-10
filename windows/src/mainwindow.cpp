#include "mainwindow.h"
#include "ui_mainwindow.h"

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
            arbol_binario->add1(word);
            break;
        case 3 :
            lista->list_add(word);
            break;
        default:
            break;
        }




        //---------------------------------aqui se insertaran las palabras

        this->bino.Insert(word);

        for(auto ite:traducciones){
            cout<<it<<"->"<<ite<<endl;
        }

    }


}




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
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


  string s_estructura_de_dato= (ui->estructura_comboBox->currentText()).toStdString();
  if(s_estructura_de_dato=="Ärbol AVL"){
       estructura_de_dato=0;
       arbol_avl=new avl_tree<palabra>;
  }
  else if(s_estructura_de_dato=="Árbol Red-Black"){
      estructura_de_dato=1;
      arbol_red_black=new red_black_tree<palabra>;
  }
  else if(s_estructura_de_dato=="Árbol Binario"){
      estructura_de_dato=2;
      arbol_binario=new Binary_tree<palabra>;
  }
  else if(s_estructura_de_dato=="Lista Simple"){
      estructura_de_dato=3;
      lista=new List<palabra>;
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

    ui->ram_label->setText(QString::number(m.getRam()).append(" kb"));
}
