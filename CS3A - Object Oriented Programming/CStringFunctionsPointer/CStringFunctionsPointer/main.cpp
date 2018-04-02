#include <iostream>

int ptrlen(char* ptr);
void ptrcpy(char *cpt1,char *cpt2);
void strcat(char *cpt1, char *cpt2);
void substr(char *cpt1,char *cpt2, int start, int length);
int findany(char *cpt1, char *cpt2, int pos);
int strcmp(char *cpt1,char *cpt2);
int find(char *inthis, char *findthis); //string within a string
using namespace std;

int main()
{
    char word[50] = "bacon";
    char word2[50] = "what";
    char sub[50] = "waffles";
    char* ptr = word;
    char* ptr2 = word2;
    char* ptrsub = sub;

    cout << "strcmp :" << strcmp(ptr2, ptr) << endl;

    cout << "ptr: " << word << " " << "ptr2: " << word2 <<endl;
    ptrcpy(ptr, ptr2);

    cout << word << endl;

    cout << "ptrcpy: ptr1: " << word << " ptr2: "  << word2 << endl;

    cout << "ptrlen: " << ptrlen(ptr) << endl;
    strcat(ptr,ptr2);
    cout << "strcat: " << word << endl;
    cout << "findany :" << findany(ptr,ptr2,3) << endl;
    substr(ptr, ptrsub, 2,3);
    cout << "substr(ptr, ptrsub, 2,3): ptrsub: " << ptrsub << endl;
    cout << endl;
    cout << "ptr: " << word << " " << "ptr2: " << word2 <<endl;
    cout << "find in string: " << find(ptr,ptr2) << endl;

    return 0;
}

int ptrlen(char* ptr)
{
    int i = 0;
    while (*ptr)
    {
        ptr++;
        i++;
    }
    return i;
}

void ptrcpy(char *cpt1,char *cpt2)
{
    while(*cpt2)
    {
        *cpt1 = *cpt2;
        cpt1++;
        cpt2++;
    }
    *cpt1 = '\0';
}

void strcat(char *cpt1,char *cpt2)
{
    cpt1 = cpt1 + ptrlen(cpt1);
    while(*cpt2)
    {
        *cpt1 = *cpt2;
        cpt2++;
        cpt1++;
    }
    *cpt1 = '\0';
}

void substr(char *cpt1,char *cpt2, int start, int length)
{
    cpt1 = cpt1 + start;
    int i = 0;
    while ( i != length )
    {
        *cpt2 = *cpt1;
        i++;
        cpt1++;
        cpt2++;
    }
    *cpt2 = '\0';
}

int strcmp(char *cpt1,char *cpt2)
{
    while (*cpt1 != '\0' || *cpt2 != '\0')
    {
        if (*cpt1 == '\0' && *cpt2 == '\0')
        {
            return 0;
        }
        else if (*cpt1 == *cpt2)
        {
            cpt1++;
            cpt2++;
        }
        else if (*cpt1 > *cpt2)
        {
            return 1;
        }
        else
        {
            return -1;
        }

    }
    return 0;
}



int findany(char *cpt1, char *cpt2, int pos)
{
    int x = 0;
    int i = pos;
    while ( i != ptrlen(cpt1))
    {
        while( x != ptrlen(cpt2))
        {

            if (*cpt1 == *cpt2)
                return i;
            else
                cpt2++;
        }
        cpt1++;
        x = 0;
    }
    return -1;
}

int find(char *inthis, char *findthis)
{
    int i = 0;
    while(findthis)
    {
        while(*findthis = *inthis)
        {
            findthis++;
            inthis++;
            if (*findthis = '\0')
            {
                return i;
            }
            else
            {
                findthis;
            }

        }
        i++;
        inthis++;
        cout << i;
    }
    // i was told to use walker but it feels impossible to do this without using brackets like findthis[walker]
    return -1;
}
