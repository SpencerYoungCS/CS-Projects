#include "mypanelopengl.h"
#include <cmath>

mypanelopengl::mypanelopengl(QWidget *parent) :
    QGLWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    sides = 3;
    radius = 1.0;
}

void mypanelopengl::initializeGL(){
    glShadeModel(GL_SMOOTH);
    glClearColor(1.0,1.0,1.0,1.0);
    glClearDepth(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
}

void mypanelopengl::resizeGL(int w, int h){

}

void mypanelopengl::paintGL(){

}

void mypanelopengl::changeSides(int s){

}

void mypanelopengl::changeRadius(double r){

}

