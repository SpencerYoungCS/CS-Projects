#include <iostream>

using namespace std;

int strlen(char string1[]);             //calculated length
void strcpy(char string1[], char string2[]);        //copies second string over the first
void strcat(char string1[], char string2[]);


int findany(char s1[], char s2[], int pos);
int findnotany(char s1[], char s2[], int pos);
void toupper(char s1[]);
void tolower(char s1[]);
void GreaterThan(char s1[],char s2[]);
int strcmp(char s1[], char s2[]);

void substr(char s1[], char sub[], int start, int length);


int main()
{
    char s1[50];
    char s2[50];
    char array1[20];
    char array2[20];
    char array3[20];
    char compare1[20];
    char compare2[20];
    int length;
    int start;
    char string1[20];
    char substring1[20];
    int position;

    cout << "TESTING: # Of Characters in a string" << endl;
    cout << "Enter the characters for String 1" << endl;
    cout << "String 1: ";
    cin >> s1;
    cout << endl;
    cout << "Number of characters in String 1" << endl;
    cout << strlen(s1) << endl << endl;


    cout << "TESTING: String Copy" << endl;
    cout << "Enter the string you wish to copy over String 1" << endl;
    cout << "String 2: ";
    cin >> s2;
    cout << "This function will copy String 2 over String 1" << endl;
    cout << "String 1 Before: " << s1 << endl;
    cout << "String 2 Before: " << s2 << endl;
    strcpy(s1,s2);
    cout << "String 1 After: " << s1 << endl;
    cout << "String 2 After: " << s2 << endl << endl;

    cout << "TESTING: Concatenated String" << endl;
    cout << "This is the Concatenated String." << endl;
    cout << "String 2 will add onto String 1" << endl << endl;
    strcat(s1,s2);
    cout << "CONCATENATED STRING1: "<< s1 << endl << endl;

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


    cout << "TESTING: Find Any" << endl << endl;
    cout << "Enter The first string" << endl;
    cout << "Array 1: ";
    cin >> array1;
    cout << endl;
    cout << "Enter The second string" << endl;
    cout << "Array 2: ";
    cin >> array2;
    cout << endl;
    cout << "Enter the starting postion" << endl;
    cout << "Position: ";
    cin >> position;
    cout << "Index Found: " << findany(array1,array2, position) << endl << endl;
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
    cout << "Enter the starting postion" << endl;
    cout << "Position: ";
    cin >> position;
    cout << "Find Not Any Index: " << findnotany(array1,array2,position) << endl << endl;
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
    cout << "TESTING SUBSTRING" << endl;
    cout << "Please enter the string you wish to copy." << endl;
    cout << "String 1: ";
    cin >> string1;
    cout << endl << endl;
    cout << "Please enter the start location (index) of the string";
    cout << " you wish to copy" << endl;
    cout << "Start Location: ";
    cin >> start;
    cout << endl << endl;
    cout << "Please enter the length of characters you wish to copy." << endl;
    cout << "Length: ";
    cin >> length;
    cout << endl << endl;
    substr(string1,substring1, start, length);
    cout << "This is your substring: ";
    for(int i = 0; i != length; i++)
    {
        cout << substring1[i];
    }

    cout << endl << endl;




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



void strcpy(char string1[], char string2[])
{
    for(int i = 0 ; i != strlen(string2); i++)
    {
        string1[i] = string2[i];
        string1[i+1] = '\0';
    }
}

void strcat(char string1[], char string2[])
{
    int i = strlen(string1);
    int j = 0;
    while (j != strlen(string2))
    {
        string1[i] = string2[j];
        i++;
        j++;
    }
    string1[i] = '\0';

}

int findany(char s1[], char s2[], int pos)
{
    int x = 0;
    int i = pos;
    while ( i != strlen(s1))
    {
        while( x != strlen(s2))
        {

            if (s1[i] == s2[x])
                return i;
            else
                x++;
        }
        i++;
        x = 0;
    }
    return -1;
}

int findnotany(char s1[], char s2[], int pos)
{
    int x = 0;
    int i = pos;
    while ( i < strlen(s1))
    {
        while( x != strlen(s2))
        {

            if (s1[i] != s2[x])
                x++;
            else if (i == strlen(s1))
            {
                return -1;
            }

            else
            {
                i++;
                x = 0;
            }
        }
        return i;
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


void substr(char s1[], char sub[], int start, int length)
{
    int i = start;
    int x = 0;
    while ( x != length )
    {
        sub[x] = s1[i];
        i++;
        x++;
    }
    sub[x] = '\0';
}

