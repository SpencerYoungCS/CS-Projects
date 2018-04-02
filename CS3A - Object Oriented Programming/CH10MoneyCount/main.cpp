#include <iostream>
#include "counter.h"

using namespace std;

int main()
{
    Counter A;
    A.keys('a');
    cout << "A.keys('a'): " << A.geti() << endl;

    A.keys('f');

    cout << "A.keys('f'): " << A.geti() << endl;

    return 0;
}

//friend ostream& operator << (ostream &outs,

//foo(string s )

//string s("hello")
