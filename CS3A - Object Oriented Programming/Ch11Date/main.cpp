#include <iostream>
#include "date.h"

using namespace std;

int main()
{

    //    cout << "Date A(146158);" << endl;
    //146157 is year 400 feb 29. (leap year)

    cout << "Date A(3,4,2014);" << endl;
//  cout << "Date B(3,14,2014);" << endl;
    Date A;
    Date B;
    A.set(3,4,2014);
//    B.set(3,14,2014);

    //    cout << "A.setyear(2000)" << endl;
    //    cout << "A.setmonth(2)" << endl;
    //    cout << "A.setday(40)" << endl;
    //    A.setyear(2000);
    //    A.setmonth(2);
    //    A.setday(40);
    //    cout << "A.GetTotalbusinessdays(): " << A.GetTotalbusinessdays() << endl;
    //    cout << "B.GetTotalbusinessdays(): " << B.GetTotalbusinessdays() << endl;

    //    cout << "B.GetTotalbusinessdays() - A.GetTotalbusinessdays(): " << B.GetTotalbusinessdays()- A.GetTotalbusinessdays() << endl;

//    cout << "A.BusinessDays(B): "  << A.BusinessDays(B) << endl;
//    cout << "A.Weekends(B): " << A.Weekends(B) << endl;

    cout << "A.InXBusinessDays(20): " << A.InXBusinessDays(20) << endl;

    cout <<"A: " << A << endl;
//    cout <<"B: " << B << endl;
    cout <<"raw day: " << A.getrawday() << endl;

    return 0;
}

