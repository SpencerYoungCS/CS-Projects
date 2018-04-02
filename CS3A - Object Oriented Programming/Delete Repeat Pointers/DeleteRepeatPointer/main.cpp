#include <iostream>

using namespace std;

void deleterepeat(char *cpt);
int strlen(char string1[]);

int main()
{
    char s1[]= "abc abc abc 123 water fruit juice bacon ";
    char *cpt = s1;
    cout << "Old Pointer: " << cpt << endl;
    deleterepeat(cpt);
    cout << "New Deleted Repeat Pointer: " << cpt << endl;
    return 0;
}

void deleterepeat(char *cpt)
{
    int i = strlen(cpt) -1;
    int j = strlen(cpt) -2;
    while(i > -1)
    {
        while(j > -1)
        {
            if(cpt[i] == cpt[j])
            {
                cpt[i] = cpt[i+1];
                i = strlen(cpt) -1;
                j = strlen(cpt) -2;
            }
            else
                j--;
        }
        i--;
        j = i - 1;
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

