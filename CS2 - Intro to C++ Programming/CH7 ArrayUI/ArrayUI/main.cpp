#include <iostream>

//CH7: Array UI

void show(int &size, int array[], int &cursor);
void apphend(int &size, int array[], int addthis);
void del(int &size, int array[], int delpos);
void insert(int &size, int array[], int addpos, int addthis);

using namespace std;

int main()
{
    bool done = false;
    char choice;
    int cursor = 0;
    int Array[50]= {1,2,3,4,5};
    int size = 5;
    int addnum;
    int apphendthis;

    cout << "Welcome to the Array Modifier UI" << endl << endl;
    cout << "Your options are: D to delete, 4 to move the cursor left" << endl;
    cout << "6 to move the cursor right, D to delete the value, I to insert" << endl;
    cout << "A to apphend and X to Exit" << endl << endl;
    show(size, Array, cursor);                      // this will show the initial array
    cout << endl;


    while (!done)
    {
        cout << "What would you like to do?" << endl;
        cout << "Command: ";
        cin >> choice;
        switch(choice)
        {
        case 'x':
        case 'X': done = true;
            break;
        case '4': if(cursor == 0)                   // this moves the bracket to the left by 1 element
            {
                cursor = 0;
                show(size, Array, cursor);
            }
            else
            {
                cursor--;
                show(size, Array, cursor);
            }
            break;
        case '6': if (cursor == size - 1)           // this moves the bracket to the right by 1 element
            {
                cursor = size - 1;
                show(size, Array, cursor);
            }
            else
            {
                cursor++;
                show(size, Array, cursor);
            }
            break;
        case 'i':
        case 'I': cout << "What number would you like to insert?" << endl;      //Insert case
            cout << "Number: ";
            cin >> addnum;
            if (cursor < 0)                        // this is so that if there is currently no useful elements in an array, you can at least still insert a number
            {
                apphend(size,Array,addnum);
                cursor = size -1;
            }
            else
            {
                insert(size, Array, cursor, addnum);
            }

            cout << endl;
            show(size, Array, cursor);
            break;
        case 'a':
        case 'A': cout << "Enter the number you would like to apphend" << endl;     //Apphend case
            cin >> apphendthis;
            apphend(size,Array,apphendthis);
            cursor = size -1;
            cout << endl;
            show(size, Array, cursor);
            break;
        case 'd':
        case 'D': del(size,Array,cursor);       //Delete case
            if (cursor > size - 1)              // this makes sure that the cursor does not go past or below the array during deletion
            {
                cursor = size - 1;
            }
            else if (cursor <= 0)
            {
                cursor = 0;
            }
            else
            {
                //do nothing
            }
            show(size, Array, cursor);
            break;
        default: cout << "Please enter one of the selected commands" << endl;
        }
        cout << endl;

    }
    cout << "Goodbye!" << endl;
    return 0;
}


void show(int &size, int array[], int &cursor)
{
    for (int i = 0; i < size; i++)
    {
        if (i == cursor)
        {
            cout << "[" << array[i] << "] ";
        }
        else
        {
            cout << array[i] << " ";
        }

    }
    cout << endl << endl;
}


void insert(int &size, int array[], int addpos, int addthis)
{
    for (int i = size -1; i >= addpos; i--)
    {
        array[i + 1] = array[i];
    }
    array[addpos] = addthis;
}

void apphend(int &size, int array[], int addthis)
{
    size++;
    array[size - 1] = addthis;
}
void del(int &size, int array[], int delpos)
{
    if (size == 0)
    {
        size = 0;
    }
    else
    {
        size--;
    }

    for(int i = delpos; i < size; i++)
    {
        array[i] = array[i+1];
    }
}

