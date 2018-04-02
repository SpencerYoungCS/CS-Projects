#include "point.h"
#include <iostream>
using namespace std;

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(double newx, double newy)
{
    setx(newx);
    sety(newy);
}

double Point::getx()
{
    return x;
}
double Point::gety()
{
    return y;
}
void Point::setx(double newx)
{
    x = newx;
}
void Point::sety(double newy)
{
    y = newy;
}

void Point::setboth(double newx, double newy)
{
    x = newx;
    y = newy;
}

