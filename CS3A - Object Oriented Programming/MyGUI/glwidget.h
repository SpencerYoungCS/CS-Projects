#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "coord.h"
#include "polygon.h"
#include "glwidget.h"

class glWidget : public QGLWidget
{
    Q_OBJECT

public:
    glWidget();
    PolyNOTgon* PList;
public slots:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void process();

private:
    bool alive = false;
};

#endif // GLWIDGET_H
