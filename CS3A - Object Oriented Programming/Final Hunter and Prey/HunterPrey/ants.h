#ifndef ANTS_H
#define ANTS_H
#include "organism.h"
class ants: public organism
{
public:
    ants();
    //you are going to only put virtual funct here
    virtual void move();
    virtual void breed();
    virtual void set_point(int j, int i);
    virtual void get_point();
private:
};

#endif // ANTS_H
