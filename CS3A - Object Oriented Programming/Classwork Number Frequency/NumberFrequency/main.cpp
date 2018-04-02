#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//Number Frequency

int random(int low, int hi);    //this is a easier way to execute my random code (be sure to include time.h)


using namespace std;

int main()
{
    srand(time(NULL));
    int hi;
    int low;
    int rolls;
    int freq[2000];
    int randomNum;

    //TEST CODE-------------------------------------------------------------------------------------------------------------------

    cout << "Minimum: ";
    cin >> low;
    cout << endl;
    cout << "Max Range: ";
    cin >> hi;
    cout << endl;
    cout << "Number of Rolls: ";
    cin >> rolls;
    cout << endl;



    for(int i = low; i <= hi; i++)      // This will set the min to max as 0 in the integer array
        freq[i] = 0;


    for(int i = 0; i < rolls; i++)      //this will roll the number generator until desired
    {
        randomNum = random(low,hi);
        freq[randomNum]++;
        cout << "Random Number [" << i+1 << "]: " << randomNum << endl;
    }

    //    for(int i = low; i <= hi; i++)      // this simply displays the array
    //    {
    //        cout << "freq[" << i << "]: " <<  freq[i] << endl;
    //    }
    for(int i = low; i <= hi; i++)
        cout << "Number of times [" << i << "] was rolled: " << freq[i] << endl;


    return 0;
}



int random(int low, int hi)
{
    //make sure srand(NULL)); is called in the main function.
    return rand()%hi + low;
}


