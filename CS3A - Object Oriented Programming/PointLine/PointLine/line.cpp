#include "line.h"
#include "point.h"
#include <iostream>
#include <cmath>

using namespace std;

Line::Line()
{
    A.setx(0);
    A.sety(0);
    B.setx(0);
    B.sety(0);
    setslope(0, 0);
}




Line::Line(Point NewA, Point NewB)
{
    A.setx(NewA.getx());
    A.sety(NewA.gety());
    B.setx(NewB.getx());
    B.sety(NewB.gety());
}




void Line::setpointA(Point NewA)
{
    A.setx(NewA.getx());
    A.sety(NewA.gety());

}

void Line::setpointB(Point NewB)
{
    B.setx(NewB.getx());
    B.sety(NewB.gety());

}



double Line::distance(Point First, Point Second)
{

    return sqrt(pow(Second.getx()-First.getx(), 2)+ pow(Second.gety()-First.gety(), 2));

}


void Line::findslope(Point First, Point Second)
{
    // (Y2-Y1/X2-X1)


    slopeY = (Second.gety() - First.gety());
    slopeX = (Second.getx() - First.getx());


}

double Line::getslope()
{

    return (slopeY/slopeX);
}


double Line::yintercept(Point First)
{
    //slope * -x1 + y1

    return ((slopeY/slopeX) * First.getx() * -1) + First.gety();

    cout << slopeY;

}


void Line::setslope(int newslopex, int newslopey)
{
    slopeX = newslopex;
    slopeY = newslopey;
}




