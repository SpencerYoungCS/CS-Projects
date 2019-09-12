#include <iostream>

using namespace std;

int strlen(char string1[]);
void convertchartoint(char string1[], int array[]);

int main()
{
    char combinedarray[10];
    char array1[10];
    char array2[10];
    char again;
    int intarray1[10];
    int intarray2[10];
    bool done = false;
    while(!done)
    {

        cout << "Enter the first hexidecimal you want to add" << endl;
        cout << "Array 1: ";
        cin >> array1;

//        while (strlen(array1) > 10)
//        {
//            cout << "Please enter a string with a length of shorter than 10 characters" << endl;
//            cin >> array1;
//        }
//        cout << endl;

//        cout << "Enter the first hexidecimal you want to add" << endl;
//        cout << "Array 2: ";
//        cin >> array2;
//        cout << endl;

//        while (strlen(array2) > 10)
        {
            cout << "Please enter a string with a length of shorter than 10 characters" << endl;
            cin >> array2;
            cout << endl;
        }


        cout << endl;
        cout << "TESTS BELOW!" << endl;
        cout << "array1[0]: " << array1[0] << endl;

        //TEST: confirming adding an integer will translate the character into the integer value.

        //cout << "array[0] - 48: " << array1[0] - 48 << endl;

        //cout << array1[0] - 87 << endl; // make the letter a equal 10
        // a begins at 97
        //plan is to convert it to integer form for both arrays then add both of them, then convert back to character hexidecimals

        //array1[0] = array1[0] - 48;

        //cout << "array1[0] symbol after subtracting 48: "<< array1[0] << endl;

        //int x = array1[0];

//        cout << "int x = array1[0]," << endl;
//        cout << "x = " << x << endl << endl;

        convertchartoint(array1,intarray1);

        for (int i = 0; i < 10; i++)
            cout << intarray1[i] << endl;




        cout << "Would you like to try again? (y/n)" << endl;
        cin >> again;
        if (again == 'y' || again == 'Y')
        {
            done = false;
        }
        else
        {
            done = true;
        }
    }
    return 0;
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

void convertchartoint(char string1[], int array[])
{
    int i = 0;
    while (string1[i] != '\0')
    {
        array[i] = string1[i] - 48;
        i++;
    }
    array[i] = '\0' ;
}
