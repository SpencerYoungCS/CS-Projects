#include "month.h"

Month::Month()
{
    NumMonth = 0;
}

Month::Month(char first, char second, char third)
{
    ltr1 = first;
    ltr2 = second;
    ltr3 = third;
}

Month::Month(int num)
{
    NumMonth = num;
}

char Month::getcharmonth(){
    return ltr1;

}

int Month::getNumMonth(){
    return NumMonth;
}

int Month::getNextMonth(){

    NumMonth++;
    while(NumMonth > 12)
    {
        NumMonth = 1;
    }
    return NumMonth;
}

void Month::SetNum(int num){
    NumMonth = num;
    while (NumMonth > 12)
    {
        NumMonth = NumMonth - 12;
    }
}

void Month::SetChar(char first, char second, char third)
{

    ltr1 = first;
    ltr2 = second;
    ltr3 = third;

}
