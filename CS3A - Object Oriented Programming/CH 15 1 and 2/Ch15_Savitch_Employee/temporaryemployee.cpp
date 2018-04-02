#include "temporaryemployee.h"

TemporaryEmployee::TemporaryEmployee()
{
    job = "unknown";
}

void TemporaryEmployee::set_job(string newjob)
{
    job = newjob;
}

string TemporaryEmployee::getJob()
{
    return job;
}

void TemporaryEmployee::print_check()
{
    cout << "\n__________________________________________________\n";
    cout << "Pay to the order of "<< get_name() << endl;
    cout << "The sum of: " << get_net_pay() << " Dollars\n";
    cout << "_________________________________________________\n";
    cout << "Check Stub NOT NEGOTIABLE \n";
    cout << "Employee Number: " << get_ssn( ) << endl;
    cout << "Temporary Employee: " << getJob() << " Pay: "
         << get_salary() << endl;
    cout << "_________________________________________________\n";
}
