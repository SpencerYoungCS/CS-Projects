#ifndef STRING_H
#define STRING_H
#include <iostream>

using namespace std;

class String
{

private:

    int len = 0;
    char* str;
public:


    String();
    String(char* s);
    String (const String& CopyThis);
    //~String(); // destructor

    //string functions

    int StrLen();
    friend int strlen(char * s);
    void strcpy(String &ReplaceThis);
    void strcat(char* AddOn);
    int strcmp(char* s2);
    void substr(char* sub, int start, int length);

    String& operator =(const String& RHS);

    friend ostream& operator <<(ostream& outs, const String& s);
    friend String operator +(const String& s1, const String& s2);

    //Mutators

    void Set(char* s); //strcpy.
    void Append(const String& AppendThis);

};



#endif // STRING_H
