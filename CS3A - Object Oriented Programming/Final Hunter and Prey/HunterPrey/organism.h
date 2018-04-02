#ifndef ORGANISM_H
#define ORGANISM_H
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "coordinate.h"
#include "constants.h"


using namespace std;
class organism
{
public:
    organism();
    //you are going to only put virtual funct here
    virtual void move();
    virtual void breed();
    virtual void set_point(int j, int i);
    virtual void get_point();
    void set_genetype(int i);

    int direction;
    int breedCount;
    int genetype;
    bool hasMoved;
    int notEaten;

    point coordinate;
    point next;
    point breednext;
private:
};

#endif // ORGANISM_H
