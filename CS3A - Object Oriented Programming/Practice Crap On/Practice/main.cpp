#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
int getbits(int num); //finding the numbers of 1's in a binary
int main()
{
    srand(time(NULL));
    cout <<"Random: " << rand()%4 << endl;




    cout << getbits(40) << endl;
    return 0;

}

int getbits(int num){
    int temp = 0;
    while(num > 1){
        if(num%2 == 1){
            temp++;
            num = num - 1;
        }
        num = num/2;
    }
    if(num == 1)
        temp++;

    return temp;

}
