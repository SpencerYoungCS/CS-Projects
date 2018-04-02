#include <iostream>
#include "month.h"

using namespace std;

int main()
{


    Month(5);
    Month A;
    A.SetNum(30);
    cout << "A.SetNum(30): " << A.getNumMonth() << endl;
    A.SetChar('f','e','b');
    cout << "A.SetChar(f,e,b) :" << A.getcharmonth() << endl;
    A.getNextMonth();
    cout << "A.getnextmonth(): " << A.getNumMonth() << endl;


    return 0;
}

