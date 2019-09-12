#include <iostream>

#include <fstream>
//Tokenize Block

using namespace std;

//Global Character Arrays.
char alphabet[101] = {"abcdefghijklmnopqrstuvwxyzABCDEFHIJKLMNOPQRSTUVWXYZ"};
char number[11] = {"0123456789"};
char punctuation[50] = {";:'!@#$%^&*()-_\.][}{,><?/~`+="};
char space[10] = {" "};

int zorg(char block[], char tokentype[], char token[], int &pos);
int findany(char s1[],char s2[], int pos);
int findnotany(char s1[], char s2[], int pos);
int strlen(char string1[]);
void strcpy(char string1[], char string2[]);
void strcat(char string1[], char string2[]);
int strcmp(char s1[], char s2[]);
void substr(char s1[], char sub[], int start, int length);
bool getnexttoken(char block[], char tokentype[], char token[], int &pos);
void tokenizeblock(char block[], char tokentype[], char token[], char multiblock[][50] , int &pos, int &rows);


int main()
{
    char tokentype[50];
    char block[100];
    char token[50];
    char multiblock[1001][50];
    int position;
    int rows = 0;
    char filename[100];

    cout << endl;
    cout << "Tokenize Block" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Please enter the name (without extensions) of the text file you" << endl;
    cout << "wish to put into a multi-dimensional array" << endl << endl;
    cout << "File name: ";
    cin >> filename;

    strcat(filename, ".txt");   // makes the program easier to use for the user.

    ifstream infile;
    infile.open(filename);

    if (infile.fail())  // Error Check
    {
        cout << endl;
        cout << "Error: File not found..." << endl;
        cout << "Terminating program..." << endl << endl;
        exit(0);
    }

    while(!infile.eof())
    {
        position = 0;
        infile.getline(block, 100);
        cout <<"[" << block << "]" << endl;
        tokenizeblock(block, tokentype, token, multiblock , position, rows);

    }
    infile.close();

    cout << endl;

    for(int i= 0; i < rows; i++)
    {
        cout << "Multiblock[" << i << "] = " << '[' << multiblock[i] << ']' << endl;
    }
    cout << endl;

    return 0;
}



//-------------------------------------SOURCE CODE BELOW----------------------------------------------------


void tokenizeblock(char block[], char tokentype[], char token[], char multiblock[][50], int &pos, int &rows)
{
    while (getnexttoken(block, tokentype, token, pos)) // while it returns true (not end of the file)
    {
        if (strcmp(tokentype, alphabet) == 0)
        {
            strcpy(multiblock[rows], token);
            rows++;

        }

    }

}


bool getnexttoken(char block[], char tokentype[], char token[],int &pos)
{
    // give me the type. throw into token array. if block[finish] == null, its false. otherwise true

    if (findany( block, alphabet, pos) == pos)
    {
        strcpy(tokentype, alphabet);
        //tokentype = alphabet
        zorg(block, tokentype, token, pos);
        return true;
    }
    else if (findany(block, space, pos) == pos)
    {
        strcpy(tokentype, space);
        // tokentype = space
        zorg(block, tokentype, token, pos);
        return true;
    }
    else if (findany(block, number, pos) == pos)
    {
        strcpy(tokentype, number);
        //tokentype = number
        zorg(block, tokentype, token, pos);
        return true;
    }
    else if (findany(block, punctuation, pos) == pos)
    {
        strcpy(tokentype, punctuation);
        //tokentype = punctuation
        zorg(block, tokentype, token, pos);
        return true;
    }

    else if(block[pos] == '\0')
    {
        return false;
    }
    return false;


}


int zorg(char block[], char tokentype[], char token[], int &pos)
{

    //substr(char block[], char tokentype[], int start, int length)

    int finish = findnotany(block,tokentype, pos);
    substr(block, token, pos, finish - pos);
    pos = finish;

}

//--------------------------------LOWER LEVEL FUNCTIONS BELOW------------------------------------------------


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



