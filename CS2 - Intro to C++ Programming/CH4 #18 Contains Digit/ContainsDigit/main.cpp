#include <iostream>

//CH4 #18 Contains Digit

int findany(char s1[], char s2[]);
int strlen(char string1[]);
void strcpy(char string1[], char string2[]);


using namespace std;

int main()
{
    char input[100];
    char alternate1[100];
    char alternate2[100];
    char brokenstring[10] = "147";
    cout << "Welcome to the broken oven. 1,4,7 is broken but dont";
    cout << " worry, we will do the closest possible calculation for you" << endl <<endl;
    cout << "Please enter the desire baking temperature" << endl;

    cout << "Amount: ";
    cin >> input;

    strcpy(alternate1, input);
    strcpy(alternate2, input);

    do{
        if (alternate1[findany(alternate1, brokenstring)] == 49)
        {
            alternate1[findany(alternate1, brokenstring)] = 48;
            alternate2[findany(alternate2, brokenstring)] = 50;
        }
        else if (alternate1[findany(alternate1, brokenstring)] == 52)
        {
            alternate1[findany(alternate1, brokenstring)] = 51;
            alternate2[findany(alternate2, brokenstring)] = 53;
        }
        else if (alternate1[findany(alternate1, brokenstring)] == 55)
        {
            alternate1[findany(alternate1, brokenstring)] = 54;
            alternate2[findany(alternate2, brokenstring)] = 56;
        }

    }while(findany(alternate1, brokenstring) != -1);


    cout << "Your temperature is: " << alternate1 << " or " << alternate2 << endl << endl;

    return 0;
}


void strcpy(char string1[], char string2[])
{
    for(int i = 0 ; i != strlen(string2); i++)
    {
        string1[i] = string2[i];
        string1[i+1] = '\0';
    }
}


int findany(char s1[], char s2[])
{
    int x = 0;
    int i = 0;
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

int strlen(char string1[])
{
    int i = 0;
    while (string1[i]!= '\0')
    {
        i++;
    }
    return i;
}

