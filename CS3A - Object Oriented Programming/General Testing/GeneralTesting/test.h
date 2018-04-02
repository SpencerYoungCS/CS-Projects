#ifndef TEST_H
#define TEST_H
#include <string>
#include <iostream>

using namespace std;

class Test
{
public:
   // Test();
        Test();
    int num() const;
    double dou() const;
    string ReturnStr() const;
private:
    int n;
    double d;
    string str;
};

#endif // TEST_H
