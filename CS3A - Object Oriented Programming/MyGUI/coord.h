#ifndef COORD_H
#define COORD_H

#include <Qtimer>
#include <QKeyEvent>
#include <QResizeEvent>
#include <QtGui>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <QDebug>
#include "GL/glu.h"
#include <cmath>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QGLWidget>
#include <QApplication>
#include <QDebug>
#include <QGLWidget>
#include <iostream>
using namespace std;
class Coord
{
public:
    Coord();
    Coord(float newX, float newY);
    friend ostream& operator <<(ostream& out, const Coord& p);

    float x;
    float y;
};

#endif // COORD_H
