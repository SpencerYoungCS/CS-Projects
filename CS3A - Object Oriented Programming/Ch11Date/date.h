#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
private:
    int day;

public:
    Date();
    Date(int NewDay);
    Date(int NewMonth, int NewDay, int NewYear);

    //Accessors
    int getday();
    int getmonth();
    int getyear();
    int getrawday();
    //    bool getleap();

    //Mutators
    void setday(int NewDay);
    void setmonth(int NewMonth);
    void setyear(int NewYear);
    void set( int NewMonth,int NewDay, int NewYear);
    void setraw(int rawday);


    Date Add(Date A);
    Date Sub(Date A);

    //Business days

    int GetTotalbusinessdays();
    int BusinessDays(Date toDate); //return number of working days between two dates
    int Weekends(Date toDate); //return number of weekend days between two dates
    Date InXBusinessDays(int numOfDays); //return the date of so many business days after a start day.


    //Friends and Operators

    friend Date operator + (Date A, Date B);
    friend Date operator + (int A, Date B);
    friend Date operator + (Date B, int A);
    friend Date operator - (Date A, Date B);
    friend Date operator - (int A, Date B);
    friend Date operator - (Date B, int A);
    friend ostream& operator << (ostream& out, Date A);
    friend istream& operator >> (istream& in, Date& A);
    

};

//BUSINESS DAYS------------------------------------------------------------------------------------------------



#endif // DATE_H
