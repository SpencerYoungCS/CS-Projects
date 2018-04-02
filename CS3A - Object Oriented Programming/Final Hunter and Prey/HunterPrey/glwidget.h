#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "coord.h"
#include "glwidget.h"
#include "world.h"


class glWidget : public QGLWidget
{
    Q_OBJECT

public:
    glWidget();
public slots:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void process();

private:
    bool alive = false;
    world neworld;
};

#endif // GLWIDGET_H
