#ifndef LINE_H
#define LINE_H
#include "point.h"


class Line
{
public:

    //Constructors

    Line();
    Line(Point NewA, Point NewB);


    //Mutators

    void setpointA(Point NewA);
    void setpointB(Point NewB);

    //functions

    double distance(Point First, Point Second);
    void findslope(Point First, Point Second);
    double getslope();
    double yintercept(Point First);
    void setslope(int newslopex, int newslopey);



private:
    double slopeY ;
    double slopeX ;
    Point A;
    Point B;

};


#endif // LINE_H
