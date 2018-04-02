#ifndef WALL_H
#define WALL_H
#include "organism.h"

class wall : public organism
{
public:
    wall();
    virtual void get_point();
    virtual void set_point(int j, int i);
    virtual void move();
private:
};

#endif // WALL_H
