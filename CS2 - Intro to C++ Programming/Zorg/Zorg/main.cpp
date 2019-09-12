#include <iostream>

using namespace std;

//Zorg

//Global Character Arrays.
char alphabet[101] = {"abcdefghijklmnopqrstuvwxyzABCDEFHIJKLMNOPQRSTUVWXYZ"};
char number[11] = {"0123456789"};
char punctuation[50] = {";:'!@#$%^&*()-_\.][}{,><?/~`"};
char space[10] = {" "};

int zorg(char block[], char type[], char token[], int pos);



int strlen(char string1[]);
void strcpy(char string1[], char string2[]);
void strcat(char string1[], char string2[]);
int findany(char s1[],char s2[], int pos);
int findnotany(char s1[], char s2[], int pos);
void toupper(char s1[]);
void tolower(char s1[]);
void GreaterThan(char s1[],char s2[]);
int strcmp(char s1[], char s2[]);
void substr(char s1[], char sub[], int start, int length);

int main()
{
    //Character Sets
    char block[50];
    char token[50];
    int position;
    char choice;
    cout << "TESTING: Please enter the string for block" << endl;
    cout << "Block: ";
    cin >> block;
    cout << endl;
    cout << "Please Enter a starting location for string 1" << endl;
    cout << "Position: ";
    cin >> position;
    cout << endl;
    cout << "Please enter the type to grab and throw into the substring" << endl;
    cout << "1: Alphabet, 2: Number, 3: Punctuation, 4: Space" << endl;
    cout << endl;
    cout << "choice: ";
    cin >> choice;


    switch(choice)
    {
    case '1':

        zorg(block, alphabet, token, position );
        cout << "[" << token << "]" << endl;
        break;
    case '2':
        zorg(block, number, token, position );
        cout << "[" << token << "]" << endl;
        break;
    case '3':
        zorg(block, punctuation, token, position );
        cout << "[" << token << "]" << endl;
        break;
    case '4':
        zorg(block, space, token, position );
        cout << "[" << token << "]" << endl;
        break;
    default:
        return 0;
    }


    return 0;
}

//Zorg(char MyString[], char CharSet[], char Substring[], int pos);
int zorg(char block[], char type[], char token[], int pos)
{
    //substr(char block[], char substring[], int start, int length)
    int start = findany(block,type,pos);
    int finish = findnotany(block,type,pos);
    if (start > finish)
    {
        cout << "Error start > finish" << endl;
        return 0;
    }
    else
    {
        substr(block, token, start, finish - start);
    }

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

