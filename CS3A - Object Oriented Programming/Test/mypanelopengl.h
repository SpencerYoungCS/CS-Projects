#ifndef MYPANELOPENGL_H
#define MYPANELOPENGL_H

#include <QGLWidget>

class mypanelopengl : public QGLWidget{
        Q_OBJECT
private:
int sides;
double radius;

public:
explicit mypanelopengl(QWidget *parent = 0);
signals:

public slots:
void changeSides(int s);
void changeRadius(double r);


protected:
void initializeGL();
void resizeGL(int w, int h);
void paintGL();


};

#endif // MYPANELOPENGL_H
