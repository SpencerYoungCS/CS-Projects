#ifndef WORLD_H
#define WORLD_H
#include "ants.h"
#include "doodlebugs.h"
#include "wall.h"

class world
{
public:
    world();
    organism* NewWorld[MAX_j][MAX_i];
    void randomize();
    void step();
    bool checkant(int j, int i);
    bool checkprey(int j, int i);
    void print();
    void circle();

private:
};
#endif // WORLD_H
