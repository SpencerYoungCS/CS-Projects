#include "string.h"
#include <iostream>

using namespace std;



String::String()
{
}

String::String(char *s)
{
    char *walker = s;

    while (*walker!= NULL) // this gives us the length of the string for the dynamic array
    {
        walker++;
        len++;
    }
    char *temp = new char[len];
    temp = s;
    str = temp;
}

int String::StrLen(){
    return len;
}

int strlen(char *s)
{
    int length = 0;
    char * walker = s;
    while (*walker !=NULL){
        walker ++;
        length++;
    }
    return length;
}



void String::strcpy(String &ReplaceThis){
    ReplaceThis.Set(str);
}

void String::strcat(char* AddOn){
    char *temp = new char[len + strlen(AddOn)];
    char* str2 = str;
    char* walker = temp;
    char* walker2 = AddOn;

    while(*str2 != NULL){
        *temp = *str2;
        str2++;
        temp ++;
    }
    while (*walker2 != NULL){
        *temp = *walker2;
        temp++;
        walker2++;
        len++;
    }
    *temp  =NULL;
    str = walker;
}

int String::strcmp(char* s2){
    char* walker = str;
    char* walker2 = s2;
    while (*walker != NULL || *walker2 != NULL){
        if (*walker == NULL && *walker2 == NULL){
            return 0; //if return 0, theyre the same
        }
        else if (*walker == *walker2){
            walker++;
            walker2++;
        }
        else if (*walker > *walker2)	//if returns 1, str is larger
            return 1;
        else
            return -1;	//if return -1 str is smaller
    }
}


void String::substr(char* sub, int start, int length){
    char* walker = str;
    char* walker2 = sub;
    char* temp = walker;

    for(int i = 0; i < start; i++)
        walker++;

    for(int j = 0; j < length; j++){
        *walker = *walker2;
        walker++;
        walker2++;
    }
    str = temp;
}

void String::Set(char *s){
    str = s;
    len = strlen(s);
}

ostream& operator <<(ostream& out, const String& S)
{
    return out << S.str;
}

String operator + (const String& s1, const String& s2){
    String Temp;
    Temp.Set(s1.str);
    Temp.strcat(s2.str);
    return Temp;
}
