#include <iostream>

int strlen(char string1[]);
int find(char string1[], char findthis[], int start);     //returns the index from string 1
int findnext(char string1[], char findthis[], int &start);  // this uses a pass by reference to extend the search if the first fails
int findstring(char string1[], char findthis[], int start);

using namespace std;

int main()
{
    int start = 0;
    char s1[50] = "abc abcd";
    char s2[50] = "abcd";

    //TEST CODE---------------------------------------------------------


    while(find(s1,s2,start) != -1)
    {
        if (findstring(s1,s2,start) == -1)
        {
            findnext(s1,s2,start);
        }
        else
        {
            cout << "Findstring: " << findstring(s1,s2,start) << endl;
            findnext(s1,s2,start);
        }
    }

    return 0;

}

//---------------FUNCTIONS--------------------------------------------------


int find(char string1[], char findthis[], int start)
{
    for (int i = start; i < strlen(string1) ; i++)
    {
        if (string1[i] == findthis[0])
            return i;

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

int findnext(char string1[], char findthis[], int &start)
{
    start = find(string1,findthis,start) + 1;
    return start;
}

int findstring(char string1[], char findthis[],int start)
{
    start = find(string1,findthis,start);
    int i = find(string1,findthis,start);
    int j = 0;
    while(find(string1,findthis,start) != -1)
    {
        while (j < strlen(findthis))
        {
            if(string1[i] == findthis[j])
            {
                j++;
                i++;
            }
            else
                return -1;

        }
        if(j == strlen(findthis))
        {
            return start;
        }
        return -1;

    }
    return -1;
}
