#ifndef VTKWINDOW_H
#define VTKWINDOW_H

#include <QWidget>

#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>

namespace Ui {
class VtkWindow;
}

class VtkWindow : public QWidget
{
    Q_OBJECT

public:
    explicit VtkWindow(QWidget *parent = 0);
    ~VtkWindow();

private:
    Ui::VtkWindow *ui;
};

#endif // VTKWINDOW_H
