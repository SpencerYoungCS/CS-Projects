#ifndef COUNTERTYPE_H
#define COUNTERTYPE_H
#include <iostream>

class CounterType
{
public:

    CounterType();
    CounterType(int newCounter);
    void increase();
    void decrease();
    int getcounter();
//    void output(ostream& outstream);

private:
    int counter;

};

#endif // COUNTERTYPE_H
