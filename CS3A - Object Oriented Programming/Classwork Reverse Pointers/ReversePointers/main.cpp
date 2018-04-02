#include <iostream>

using namespace std;

void reverse(char *cpt);
int strlen(char string1[]);
void ptrcpy(char *cpt1,char *cpt2);

int main()
{
    char word[] = "CHOCOLATE!!!!!!";
    char *cpt = word;


    cout << "Original Character String: " << cpt << endl;
    reverse(cpt);
    cout << endl;
    cout << "New Reveresed Character String: " << cpt << endl;

    cout << endl;

    return 0;
}


void reverse(char *cpt)
{
    char *back = cpt+strlen(cpt) - 1;   // points to the end of the array
    char *front = cpt;      // point to the front of the array
    char* temp = new char [50];
    int i = 0;
    int j = strlen(cpt) - 1;

        while(i <= strlen(cpt)/2)// this is the reverse function
        {

            temp[i] = *back;
            temp[j] = *front;
            front++;
            back--;
            i++;
            j--;
        }

        temp[strlen(cpt)] = '\0';
        ptrcpy(cpt, temp);
        delete[]temp;
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

void ptrcpy(char *cpt1,char *cpt2)
{
    for(int i = 0; *cpt2 != '\0'; *cpt2++)
    {
        *cpt1 = *cpt2;
        cpt1++;
    }
    *cpt1 = '\0';
}