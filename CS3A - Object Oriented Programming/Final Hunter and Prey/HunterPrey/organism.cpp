#include "organism.h"
organism::organism() : breedCount(0)
{
    genetype = 0; //empty organism
    hasMoved = false;

}

void organism::move()
{

    cout << "ORGANISM MOVE ACTIVATED" << endl;
}

void organism::breed()
{

}

void organism::set_point(int j, int i)
{
}

void organism::get_point()
{
}

void organism::set_genetype(int i)
{
    genetype = i;
}
