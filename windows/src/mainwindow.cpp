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
    estructura=new avl_tree<palabra>;

    for (auto it:palabras){

        palabra word(it,traducciones);
        estructura->add(word);

        //---------------------------------aqui se insertaran las palabras
        //estructura -> insertar(palabra);
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
