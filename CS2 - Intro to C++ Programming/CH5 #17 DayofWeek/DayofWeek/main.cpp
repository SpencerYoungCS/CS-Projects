#include <iostream>

//CH5 #17 Day of Week.
//Calculation from suggested website.

using namespace std;

int dow(int y, int m, int d);

int main()
{
    int year;
    int month;
    int day;

    cout << "Please enter the year" << endl;
    cin >> year;
    cout << "Please enter the month" << endl;
    cin >> month;
    cout << "Please enter the day" << endl;
    cin >> day;
    cout << dow(year, month, day) << endl;
    return 0;
}

int dow(int y, int m, int d)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
