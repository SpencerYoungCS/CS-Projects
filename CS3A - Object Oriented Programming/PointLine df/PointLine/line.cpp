#include "line.h"
#include "point.h"
#include <iostream>;
#include <cmath>;

using namespace std;
Point A;
Point B;

Line::Line()
{
    A.setpoint(0,0);
    B.setpoint(0,0);
}



Line::Line(double x1,double y1, double x2, double y2)
{
    A.setpoint(x1,y1);
    B.setpoint(x2,y2);

}




double Line::distance()
{

return sqrt(pow(B.getx()-A.getx(), 2)+ pow(B.gety()-A.gety(), 2));

}

int Line::yintercept()
{
    //slope * -x1 + y1

    return ((-1*getslope()) * A.getx()) + A.gety();

}


void Line::findslope()
{
    slopeX = B.getx() - A.getx();
    slopeY = B.gety() - A.gety();

}

void Line::setslope(int newslopex, int newslopey)
{
    slopeX = newslopex;
    slopeY = newslopey;
}

int Line::getslope()
{
    return slopeY/slopeX;
}



