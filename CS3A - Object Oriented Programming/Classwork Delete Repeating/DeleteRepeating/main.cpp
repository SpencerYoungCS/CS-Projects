#include <iostream>

void deleterepeat(char s1[]);
int strlen(char string1[]);

using namespace std;

int main()
{
    char s1[]= "abc abc abc 123 water fruit juice bacon ";
    cout << "Old String: " << s1 << endl;
    deleterepeat(s1);
    cout << "New Deleted Repeat String: " << s1 << endl;
    return 0;
}

void deleterepeat(char s1[])
{
    int i = strlen(s1) -1;
    int j = strlen(s1) -2;
    while(i > -1)
    {

        while(j > -1)
        {
            if(s1[i] == s1[j])
            {
                s1[i] = s1[i+1];
                i = strlen(s1) -1;
                j = strlen(s1) -2;
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
