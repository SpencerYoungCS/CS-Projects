#include <iostream>

//FindAny, FindNotAny, ToUpper, ToLower, GT, LT, EQ,

using namespace std;

int strlen(char string1[]);
int findany(char s1[],char s2[]);
int findnotany(char s1[], char s2[]);
void toupper(char s1[]);
void tolower(char s1[]);
void GreaterThan(char s1[],char s2[]);
int strcmp(char s1[], char s2[]);

int main()
{
    char array1[20];
    char array2[20];
    char array3[20];
    char compare1[20];
    char compare2[20];
    cout << "TESTING: Find Any" << endl << endl;
    cout << "Enter The first string" << endl;
    cout << "Array 1: ";
    cin >> array1;
    cout << endl;
    cout << "Enter The second string" << endl;
    cout << "Array 2: ";
    cin >> array2;
    cout << endl;
    cout << "Index Found: " << findany(array1,array2) << endl << endl;
    cout << endl;
    cout << "TESTING: Find Not Any" << endl << endl;
    cout << "Enter The first string" << endl;
    cout << "Array 1: ";
    cin >> array1;
    cout << endl;
    cout << "Enter The second string" << endl;
    cout << "Array 2: ";
    cin >> array2;
    cout << endl;
    cout << "Find Not Any Index: " << findnotany(array1,array2) << endl << endl;
    cout << endl;
    cout << "TESTING: To Upper Function" << endl;
    cout << "Enter the characters you want to be upper cased/Lower Cased" <<endl;
    cout << "Array3: ";
    cin >> array3;
    cout << endl;
    toupper(array3);
    cout << "Upper Cased String: ";
    for(int i = 0; array3[i] != '\0'; i++)
    {
        cout << array3[i];
    }
    cout << endl << endl;
    tolower(array3);
    cout << "Lower Cased String: ";
    for(int i = 0; array3[i] != '\0' ; i++)
    {
        cout << array3[i];
    }
    cout << endl << endl;
    cout << "TESTING STRING COMPARE:" << endl;
    cout << "String 1: ";
    cin >> compare1;
    cout << endl;
    cout << "String 2: ";
    cin >> compare2;
    cout << endl << endl;
    cout << "Table:" << endl;
    cout << "1  = String 1 is greater" << endl;
    cout << "-1 = String 2 is greater" << endl;
    cout << "0  = Both Strings are Equal" << endl << endl;
    cout << "Returned Compred Value: " <<  strcmp(compare1,compare2) << endl << endl;


    return 0;
}




int strlen(char string1[])
{
    int i = 0;
    while (string1[i]!= '\0')
    {
        i++;
    }
    return i;
}

int findany(char s1[], char s2[])
{
    int x = 0;
    int i = 0;
    while ( x != strlen(s2))
    {
        while( i != strlen(s1))
        {

            if (s1[i] == s2[x])
                return i;
            else
                i++;
        }
        x++;
        i = 0;
    }
    return -1;
}

int findnotany(char s1[], char s2[])
{
    int x = 0;
    int i = 0;
    while( s1[i] != '\0')
    {
        while(s1[i] != s2[x])
        {
            x++;
            if (s2[x] == '\0')
            {
                return i;
            }
            else
            {
                //do nothing
            }
        }
        i++;
        x = 0;
    }

    return -1;
}


void toupper(char s1[])
{
    int i = 0;
    while (s1[i] != '\0')
    {
        if(s1[i] > 96 && s1[i] < 123)
        {
            s1[i] = s1[i] - 32;
            i++;
        }
        else
            i++;



    }
}

void tolower(char s1[])
{
    int i = 0;
    while (s1[i] != '\0')
    {
        if (s1[i] > 64 && s1[i] < 91 )
        {
            s1[i] = s1[i] + 32;
            i++;
        }
        else
            i++;
    }
}

int strcmp(char s1[],char s2[])
{
    int i = 0;
    while (s1[i] != '\0' || s2[i] != '\0')
    {
        if (s1[i] == '\0' && s2[i] == '\0')
        {
            return 0;
        }
        else if (s1[i] == s2[i])
        {
            i++;
        }
        else if (s1[i] > s2[i])
        {
            return 1;
        }
        else
        {
            return -1;
        }

    }
}
