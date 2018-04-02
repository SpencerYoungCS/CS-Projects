#include <iostream>

using namespace std;

int strlen(char string1[]);
void converttoint(char fromchar[], int toint[] );
void converttochar(char tochar[], int fromint[]);
void add(char num1[], char num2[], char result[]);

int main()
{
    char num1[100];
    char num2[100];
    int intnum1[100];
    int intnum2[100];
    char result[100];

    cout << "Enter the First char to add" << endl;
    cout << "Num 1: ";
    cin >> num1;
    cout << endl;
    cout << "Enter Second char to add" << endl;
    cout << "Num 2: ";
    cin >> num2;
    cout << endl;

    converttoint(num1, intnum1);
    converttoint(num2, intnum2);

    cout << "intnum1: ";
    for(int i = 0; i < strlen(num1); i++)
        cout << intnum1[i];

    cout << endl;


    cout << "intnum2: ";
    for(int i = 0; i < strlen(num2); i++)
        cout << intnum2[i];

    cout << endl;

    add(num1,num2, result);

    cout << result << endl;



    return 0;
}

void add(char num1[], char num2[], char result[])
{
    int tempint[100];
    int tempint2[100];
    int temptotal[100];
    int check;
    converttoint(num1, tempint);
    converttoint(num2, tempint2);

    for(int i = 0; i <= strlen(num1) + 1; i++)
    {
        check = tempint[i] + tempint[i];
        if(check > 9)
        {
            check = check -10;

            tempint[i+1] = temp[i+1] + 1;
        }
        temptotal[i]= check;

    }

    converttochar(result, temptotal);

}


void converttoint(char fromchar[], int toint[] )
{
    for (int i = 0; i <= strlen(fromchar); i++)
    {
        toint[i] = fromchar[i] - 48;
    }
}

void converttochar(char tochar[], int fromint[])
{
    for (int i = 0; i <= strlen(tochar); i++)
    {
        tochar[i] = fromint[i] + 48;
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
