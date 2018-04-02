#include <iostream>
using namespace std;
#include <QApplication>
#include "glwidget.h"
//#include "mywindow.h"


int main(int argc, char **argv)
{
    QApplication a(argc, argv);
//MyWindow window;
//    window.show();
//    return a.exec();

    glWidget window;
    window.show();
    return a.exec();
}
