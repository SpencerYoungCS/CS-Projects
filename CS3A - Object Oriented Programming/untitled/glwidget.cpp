#include "glwidget.h"

glWidget::glWidget()
{
}

void glWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,1,0);

    //DRAWING TIME BABY

    glBegin(GL_QUADS);
    glVertex3f(-0.5,-0.5,0);
    glVertex3f(-0.5,0.5,0);
    glVertex3f(0.5,0.5,0);
    glVertex3f(0.5,-0.5,0);
    glEnd();


}
void glWidget::initializeGL(){
    glClearColor(1,0,0,0);
}

void glWidget::resizeGL(int width, int height){
    glViewport(0,0,width,height);
}
