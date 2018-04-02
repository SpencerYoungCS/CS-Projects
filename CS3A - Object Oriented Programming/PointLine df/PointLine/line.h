#ifndef LINE_H
#define LINE_H
#include "point.h"


class Line
{
public:
    Line();

    Line(double x1, double y1, double x2, double y2);

//    Line(Point A, Point B);


    int yintercept();

    void findslope();

    void setslope(int newslopex, int newslopey);

    int getslope();

    double distance();




private:
    int slopeY;
    int slopeX;



};


#endif // LINE_H
