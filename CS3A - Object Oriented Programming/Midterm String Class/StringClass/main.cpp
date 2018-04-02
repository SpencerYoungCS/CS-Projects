#include <iostream>
#include "string.h"

using namespace std;

int main()
{
    String MyString("test");


    MyString.Set("watever");
    cout << "MyString: " << MyString << endl;

    String SecondString("test2");

    cout << "SecondString: "  << SecondString << endl;

    MyString.strcpy(SecondString);

    cout << "length: " << MyString.StrLen() << endl;
    MyString.strcat("lol");

    cout << MyString << endl;

    cout <<  MyString.strcmp("wateverlol") << endl;

    MyString.substr("bacon", 2, 3);

    cout << "MyString.substr(bacon, 2, 3): " << MyString << endl;

    cout << "MyString+SecondString" << endl;

    cout << MyString+SecondString << endl;


    return 0;
}

