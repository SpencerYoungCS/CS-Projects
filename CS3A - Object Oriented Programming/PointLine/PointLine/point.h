#ifndef POINT_H
#define POINT_H


class Point
{
public:
    Point();
    Point(double newx, double newy);

    //Accessors

    double getx();
    double gety();

    //Mutators

    void setx(double newx);
    void sety(double newy);
    void setboth(double newx, double newy);

private:
    double x;
    double y;
};

#endif // POINT_H
