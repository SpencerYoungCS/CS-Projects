#include <iostream>
#include "countertype.h"

using namespace std;

int main()
{
    CounterType A;


    A.decrease();A.decrease();

    cout << "A.decrease x2" << endl;

    cout << "counter: " << A.getcounter() << endl;

    return 0;


    A.increase(); A.increase();
    cout << "A.increase x2" << endl;

    cout << "counter: " << A.getcounter() << endl;
return 0;


}

