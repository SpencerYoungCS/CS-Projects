#include "triangle.h"
#include "point.h"
#include "line.h"
#include <iostream>
#include <cmath>

using namespace std;

Triangle::Triangle()
{
    A.setx(0);
    A.sety(0);
    B.setx(0);
    B.sety(0);
    C.setx(0);
    C.sety(0);


}

Triangle::Triangle(Point NewA, Point NewB, Point NewC)
{
    A.setboth(NewA.getx(),NewA.gety());
    B.setboth(NewB.getx(),NewB.gety());
    C.setboth(NewC.getx(),NewC.gety());
}

double Triangle::distance(Point First, Point Second)
{
    return sqrt(pow(Second.getx()-First.getx(), 2)+ pow(Second.gety()-First.gety(), 2));
}


double Triangle::perimeter(Point First, Point Second, Point Third)
{
    return distance(First,Second) + distance(Second, Third) + distance(First, Third);

}

double Triangle::surfacearea(Point First, Point Second, Point Third)
{
    return (distance(First,Second) * distance(First, Third))/2;
}
