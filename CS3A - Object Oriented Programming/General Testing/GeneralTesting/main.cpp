#include <iostream>
#include "test.h"
using namespace std;


int main()
{
    Test A;

    cout <<"num: "<< A.num()<<endl;
    cout <<"double: "<< A.dou()<<endl;
    cout <<"str: "<< A.ReturnStr()<<endl;
    return 0;
    
}
