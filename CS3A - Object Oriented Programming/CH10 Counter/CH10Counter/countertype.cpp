#include "countertype.h"
#include <iostream>

using namespace std;

CounterType::CounterType()
{
    counter = 0;
}

CounterType::CounterType(int newCounter)
{
    counter = newCounter;
    while(counter < 0)
    {
        counter = 0;
    }
}

void CounterType::increase(){
    counter++;
}

void CounterType::decrease(){
    counter--;
    while(counter < 0)
    {
        counter = 0;
    }
}

int CounterType::getcounter(){
    return counter;
}

//void CounterType::output(ostream& outstream)
//{
//    outstream << counter;
//}
