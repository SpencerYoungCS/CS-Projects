#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "point.h"
#include "line.h"



class Triangle
{
public:
    //3 angles and perimeter
    Triangle();
    Triangle();

    int perimeter();




private:
    Point A;
    Point B;
    Point C;


};

#endif // TRIANGLE_H
