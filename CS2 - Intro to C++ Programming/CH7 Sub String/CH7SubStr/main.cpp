#include <iostream>

int strlen(char string1[]);
void substr(char s1[], char sub[], int start, int length);

using namespace std;

int main()
{
    int length;
    int start;
    char string1[20];
    char substring1[20];
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
    for(int i =0; i != length; i++)
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

void substr(char s1[], char sub[], int start, int length)
{
    int i = start;
    int x = 0;
    while ( x != length)
    {
        sub[x] = s1[i];
        i++;
        x++;
    }
}
