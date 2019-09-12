#include <iostream>

//CH7 Show, Delete, Add Functions

using namespace std;

void show(int numused, int array[]);
int search(int numused, int array[], int key);
void del(int numused, int array[], int delpos);
void add(int numused, int array[], int addpos, const int addthis);


int main()
{    
    const int size = 5;
    int numtosearch = 5;

    cout << "in the Array that contains 5, values listed as 1,2,3,4,5" << endl << endl;
    int Array[size]= {1,2,3,4,5}; //test array

    cout << "This lists the elements in the test array" << endl;
    show(size, Array);
    cout << endl;

    cout << "Searching for the index in which contains the number 5" << endl;
    if (search(size,Array,numtosearch) == -1)
    {
        cout << "Your number was not found, please enter something else" << endl << endl ;
    }
    else
    {
        cout << search(size,Array, numtosearch) << endl << endl;
    }



    cout << "TEST: 3rd Position is: " <<  Array[3] << endl << endl;


    cout << "Delete function should replace the test number 4 (Position 3)" << endl;
    del(size,Array, 3);
    cout << endl;

    cout << "This should add the number 8 in between 2 and 3" << endl;
    add(size, Array, 2, 8);

    return 0;
}

void show(int numused, int array[])
{
    //numused is the amount of values an array has
    for (int i = 0; i < numused; i++)
    {
        cout << array[i] << endl;
    }
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
    if (delpos == numused)      // This prevents it from glitching if the user wants to delete the last element
    {
        show(delpos-1, array);
    }
    else
    {
        show(delpos,array);
        for (int i = delpos; i < numused - 1; i++ )
        {
            array[i] = array[i+1];
            cout << array[i] << endl;
        }
    }
}

void add(int numused, int array[], int addpos, const int addthis)
{
    int clonearray[numused];
    clonearray = array;

    for (int i = 0 ; i < numused ; i ++)
    {
        clonearray[i] = array[i];
    }


    array[addpos] = addthis;
    for(addpos; addpos < numused; addpos++)
    {
        array[addpos+1] = arrayclone[addpos];
    }



    show(numused,array);


}


