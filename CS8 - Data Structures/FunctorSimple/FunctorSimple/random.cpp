#include "random.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

Random::Random()
{
    srand(time(0));
}

int Random::GetNext(int lo, int hi){
    int r = rand()%(hi-lo+1)+lo;
    return r;

}
