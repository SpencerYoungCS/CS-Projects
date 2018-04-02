#include "wall.h"

wall::wall():organism()
{
    coordinate.j = 0;
    coordinate.i = 0;
    genetype = 9; // wall is nine
}

void wall::set_point(int j, int i)
{
    coordinate.j = j;
    coordinate.i = i;
    next.j = j;
    next.i = i;
}

void wall::move()
{
    cout << "WALL MOVE ACTIVATED" << endl;
}
void wall::get_point()
{
    cout << "[" << coordinate.j << "][" <<  coordinate.i << "]" << endl;
    cout << "im a wall wtf" << endl;
}
