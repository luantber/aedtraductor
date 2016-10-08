
#include <QApplication>
#if QT_VERSION < 0x050000
  #include <QCleanlooksStyle>
#endif

#include "SimpleView.h"
#include "mainwindow.h"


//extern int qInitResources_icons();

int main( int argc, char** argv )
{


  // QT Stuff
  QApplication app( argc, argv );

  #if QT_VERSION >= 0x050000
    QApplication::setStyle("fusion");
  #else
    QApplication::setStyle(new QCleanlooksStyle);
  #endif

  //qInitResources_icons();

  //SimpleView mySimpleView;
  QMainWindow * vtk_window= new SimpleView();
  MainWindow m_window(vtk_window);
  m_window.show();
  //mySimpleView.show();

  return app.exec();
}
