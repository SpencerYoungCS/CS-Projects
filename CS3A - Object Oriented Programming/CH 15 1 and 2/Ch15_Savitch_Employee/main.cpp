#include <iostream>
#include "hourlyemployee.h"
#include "salariedemployee.h"
#include "administrator.h"
#include "temporaryemployee.h"
#include "permanent.h"
using namespace std;

int main( )
{

//        cout << "----------ADMINISTRATOR TEST CODE-----------------------" << endl;
//        Administrator Test("Doctor");
//        Test.print();
//        Test.set_name("Spencer");
//        Test.set_salary(20000);
//        Test.set_net_pay(400000);
//        Test.set_ssn("123-123-2344");
//        Test.print_check();

        char choice;
        string Name;
        string Salary;
        string Net_Pay;
        string Title;
        string SSN;
        cout << "Welcome to the check printing station!" << endl;
        cout << "What is your name?" << endl;
        cout << "Name: ";
        cin >> Name;
        cout << "SSN?" << endl;
        cout << "SSN: ";
        cin >> SSN;
        cout << "What are you?" << endl;
        cout << "A for Admin, T for Temporary, P for Permanent Employee" << endl;
        cin >> choice;

        switch(choice){
        case 'A':
        case 'a':
        {
            cout << "What is your title?" << endl;
            cout << "Title: "; cin >> Title;
            Administrator Admin(Title);
            Admin.set_salary(50000);
            Admin.set_net_pay(50000);
            Admin.set_ssn(SSN);
            Admin.print_check();
            break;
        }
        case 'P':
        case 'p':
        {
            Permanent Perm;
            cout << "What is your title?" << endl;
            cout << "Title: "; cin >> Title;
            Perm.set_title(Title);
            Perm.set_salary(50000);
            Perm.set_net_pay(50000);
            Perm.set_ssn(SSN);
            Perm.print_check();
            break;
        }
        case 'T':
        case 't':
        {
            TemporaryEmployee Temp;
            Temp.set_salary(20000);
            Temp.set_net_pay(20000);
            Temp.set_ssn(SSN);
            Temp.print_check();
            break;
        }
        default:
            cout << "WRONGGGGGGG" << endl;
       }



    //    myString.printTitle();


    return 0;
}
