#include "glwidget.h"

glWidget::glWidget()
{
    neworld.randomize();
}

void glWidget::initializeGL()
{
    //Sequence: first clear the screen to get ready to draw:
    glClearColor(0, 0, 0, 0);
}

void glWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    float length = 2.0/(MAX_i*1.0); //boxsize


    for(int i = 0; i < MAX_i-1; i++){
        for(int j = 0; j < MAX_j-1; j++)
        {
            if(neworld.NewWorld[j][i] == NULL)
            glColor3f(0, 0, 0); //RGB

            else if (neworld.NewWorld[j][i]->genetype == 1)//if its an ant, green
                glColor3f(0,1,0);
            else if (neworld.NewWorld[j][i]->genetype == 9)//if its a wall its red (shouldnt happen)
                glColor3f(1,0,0);
            else if (neworld.NewWorld[j][i]->genetype == 2)//if its predator, blue
                glColor3f(0,0,1);
            else{
                glColor3f(0,0,0);
                }

            glBegin(GL_POLYGON);
            glVertex2f(-1+(j-1)*length,1-(i-1)*length); //top left
            glVertex2f(-1+(j+1)*length,1-(i-1)*length); //top right
            glVertex2f(-1+(j+1)*length,1-(i+1)*length); //bottom right
            glVertex2f(-1+(j-1)*length,1-(i+1)*length); //bottom left
            glEnd();
            //-++-

        }
    }
}

void glWidget::resizeGL(int w, int h){
    glViewport(0, 0, w, h);
}

void glWidget::process(){
    neworld.step();
    neworld.print();
    repaint();
    updateGL();
}

