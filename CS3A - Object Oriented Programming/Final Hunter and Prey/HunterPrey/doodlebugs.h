#ifndef DOODLEBUGS_H
#define DOODLEBUGS_H
#include "organism.h"

class doodlebugs : public organism
{
public:
    doodlebugs();
    //you are going to only put virtual funct here
    //WARNINIG : Non- virtual function will never get called by Organism-> ... ,why, organism cant see non-virtual functionthat belong to child
    virtual void move();
    virtual void breed();
    virtual void set_point(int j, int i);
    virtual void get_point();
private:
};

#endif // DOODLEBUGS_H
