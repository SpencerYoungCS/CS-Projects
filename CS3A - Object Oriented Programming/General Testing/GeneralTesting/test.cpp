#include "test.h"

Test::Test()
{
    n = 0;
    d = 0.0;
    str = "testttttttingggggggggg";
}


int Test::num() const
{
    return n;
}

double Test::dou() const
{
    return d;
}

string Test::ReturnStr() const
{
    return str;
}
