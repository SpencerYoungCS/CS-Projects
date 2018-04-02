#ifndef VIRUS_H
#define VIRUS_H
#include "organism.h"

class virus : public organism
{
public:
    virus();
    virtual void move();
    virtual void breed();
    virtual void set_point(int j, int i);
    virtual void get_point();

};

#endif // VIRUS_H
