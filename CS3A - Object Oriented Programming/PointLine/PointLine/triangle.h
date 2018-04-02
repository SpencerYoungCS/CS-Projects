#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "point.h"
#include "line.h"



class Triangle
{
public:
    //perimeter surface area
    Triangle();

    Triangle(Point NewA, Point NewB, Point NewC);


    double distance(Point First, Point Second);

    double perimeter(Point First, Point Second, Point Third);

    double surfacearea(Point First, Point Second, Point Third);



private:
Point A;
Point B;
Point C;

Line L1;
Line L2;
Line L3;

};

#endif // TRIANGLE_H
