#include "ants.h"

ants::ants(): organism()
{
    direction = 0;
    genetype = 1;
    coordinate.i = 0;
    coordinate.j = 0;
    next.i = 0;
    next.j = 0;
    notEaten = 0;
    hasMoved = false;
    breedCount = 0;
}

void ants::move()
{
    int direction = (rand()%4);
    switch(direction)
    {
    case 0:
//        up
        next.j = coordinate.j - 1;
        next.i = coordinate.i;
        break;
    case 1:
        next.j = coordinate.j + 1;
        next.i = coordinate.i;
//        down
        break;
    case 2:
        next.j = coordinate.j;
        next.i = coordinate.i - 1;
//        left
        break;
    case 3:
        next.j = coordinate.j;
        next.i = coordinate.i + 1;
//        right
        break;
    }
}

void ants::set_point(int j, int i)
{
    coordinate.j = j;
    coordinate.i = i;
    next.j = j;
    next.i = i;
}


void ants::get_point()
{
    cout << "[" << coordinate.j << "]" << "[" << coordinate.i << "]" << endl;
    cout << "im an ant!" << endl;
}



void ants::breed()
{
    direction = (rand()%4);
    switch(direction)
    {
    case 0:
//        up
        breednext.j = coordinate.j - 1;
        breednext.i = coordinate.i;
        break;
    case 1:
        breednext.j = coordinate.j + 1;
        breednext.i = coordinate.i;
//        down
        break;
    case 2:
        breednext.j = coordinate.j;
        breednext.i = coordinate.i - 1;
//        left
        break;
    case 3:
        breednext.j = coordinate.j;
        breednext.i = coordinate.i + 1;
//        right
        break;
    }
}

