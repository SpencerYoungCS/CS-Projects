#include <iostream>
//CH7 Show, Delete, Add Functions

using namespace std;

void show(int numused, int array[]);
int search(int numused, int array[], int key);
void del(int numused, int array[], int delpos);
void insert(int numused, int array[], int addpos, int addthis);



using namespace std;

int main()
{
    const int size = 50;
    int Array[size] = {1,2,3,4,5};
    int Array2[size] = {1,2,3,4,5}; // Because the arrays are automatically pass by reference, i need another array to display the delete and the insert function
    int numused = 5;
    int numtosearch = 3;

    cout << "The Array is shown here: ";
    show(numused,Array);
    cout << endl;
    cout << "The search function should display which element the key is contained in" << endl;
    cout << "It should search 3, and return 2. if its not found, then it will tell the user" << endl << endl;
    if (search(numused,Array,numtosearch) == -1)
    {
        cout << "Your number could not be found" << endl;
    }
    else
    {
        cout << "The location where 3 can be found is in the array[" << search(numused, Array, 3)<< "]" << endl << endl;
    }
    cout << "The delete function should delete the element 0 (number 1)" << endl;
    cout << "Deleted Array: ";
    del(numused, Array2, 0); // This should delete the first element

    cout << endl;

    cout << "The insert function should insert the number 8 in between 2 and 3 (Position 2)" << endl;
    cout << "Inserted Function: ";
    insert(numused, Array, 2, 8);

    cout << endl;

    return 0;
}

void show (int numused, int array[])
{
    for (int i = 0; i < numused; i++)
    {

        cout << array[i] << " ";
    }
    cout << endl << endl;
}

int search(int numused, int array[], int key)
{
    for (int i = 0; i < numused; i++)
    {
        if (array[i] == key)
        {
            return i;
        }

        else
        {

        }
    }
    return -1;
}

void del(int numused, int array[], int delpos)
{
    for (int i = delpos; i < numused - 1; i++)
    {
        array[i] = array[i+1];
    }
    show(numused -1,array);
}

void insert(int numused, int array[], int addpos, int addthis)
{
    for (int i = numused -1; i >= addpos; i--)
    {
        array[i + 1] = array[i];
    }
    array[addpos] = addthis;
    show (numused, array);
}
