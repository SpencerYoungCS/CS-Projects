#include <iostream>

//Get Next Token

using namespace std;


//Global Character Arrays.
char alphabet[101] = {"abcdefghijklmnopqrstuvwxyzABCDEFHIJKLMNOPQRSTUVWXYZ"};
char number[11] = {"0123456789"};
char punctuation[50] = {";:'!@#$%^&*()-_\.][}{,><?/~`"};
char space[10] = {" "};

int zorg(char block[], char tokentype[], char token[], int pos);
int strlen(char string1[]);
void strcpy(char string1[], char string2[]);
void strcat(char string1[], char string2[]);
int findany(char s1[],char s2[], int pos);
int findnotany(char s1[], char s2[], int pos);
int strcmp(char s1[], char s2[]);
void substr(char s1[], char sub[], int start, int length);
bool getnexttoken(char block[], char tokentype[], char token[], int &pos);


int main()
{
    char tokentype[50];
    char block[50];
    char token[50];
    int position;
    char choice;
    cout << "TESTING: Get Next Token" << endl;
    cout << "Please enter the string for block" << endl;
    cout << "Block: ";
    cin >> block;
    cout << endl;
    cout << "Please Enter a starting location for string 1" << endl;
    cout << "Position: ";
    cin >> position;
    cout << endl;
    cout << "Not End of Array? : " << getnexttoken(block, tokentype, token, position ) << endl;
    cout << "1 = True, 0 = False" << endl << endl;
    cout << "New Position is: ";
    cout << "[" << position << "]" << endl;
    cout << "Tokentype[] = " << '[' << tokentype << ']' << endl;

    cout << "Token[] = " << "[" << token << "]" << endl;

    return 0;
}


//------------------------------------------------------------------------------------------------------------

bool getnexttoken(char block[], char tokentype[], char token[] , int &pos)
{
    // give me the type. throw into token array. if block[finish] == null, its false. otherwise true

    if (findany( block, alphabet, pos) == pos)
    {
        strcpy(tokentype, alphabet);
        //tokentype = alphabet
        zorg(block, tokentype, token, pos);
        pos = findnotany(block, tokentype, pos);
        return true;
    }
    else if (findany(block, space, pos) == pos)
    {
        strcpy(tokentype, space);
        // tokentype = space
        zorg(block, tokentype, token, pos);
        pos = findnotany(block, tokentype, pos);
        return true;
    }
    else if (findany(block, number, pos) == pos)
    {
        strcpy(tokentype, number);
        //tokentype = number
        zorg(block, tokentype, token, pos);
        pos = findnotany(block, tokentype, pos);
        return true;
    }
    else if (findany(block, punctuation, pos) == pos)
    {
        strcpy(tokentype, punctuation);
        //tokentype = punctuation
        zorg(block, tokentype, token, pos);
        pos = findnotany(block, tokentype, pos);
        return true;
    }

    else if(block[pos] == '\0')
    {
        return false;
    }
    return false;


}


int zorg(char block[], char tokentype[], char token[], int pos)
{
    //substr(char block[], char substring[], int start, int length)
    int start = findany(block,tokentype,pos);
    int finish = findnotany(block,tokentype, pos);
    if (start > finish)
    {
        cout << "Error: start > finish" << endl;
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

