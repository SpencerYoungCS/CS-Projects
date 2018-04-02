#include "counter.h"

Counter::Counter()
{
    i = 0;
}

Counter::Counter(int newi)
{
    i=newi;
}

void Counter::incr1()
{
    i++;
}

void Counter::incr10()
{
    i = i+10;
}

void Counter::incr100()
{
    i = i+100;
}

void Counter::incr1000()
{
    i = i+1000;
}

bool Counter::overflow()
{
    if(i > 9999)
    {
        return true;
    }
    return false;
}

char Counter::keys(char key)
{
    switch(key){
    case 'a':
        incr1();
        break;
    case 's':
        incr10();
        break;
    case 'd':
        incr100();
        break;
    case 'f':
        incr1000();
        break;
    }
}

int Counter::geti()
{
    return i;
}
