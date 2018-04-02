#include "permanent.h"

Permanent::Permanent()
{
}

void Permanent::set_title(string newtitle)
{
    title = newtitle;
}

void Permanent::set_supervisor(string new_supervisor)
{
    supervisor = new_supervisor;
}

string Permanent::getTitle()
{
    return title;
}

string Permanent::getJob()
{
    return job;
}

string Permanent::getSupervisor()
{
    return supervisor;
}

void Permanent::print()
{
    cout << endl;
    cout << "----------------" << getTitle() << "---------------------" << endl;
    cout << "Title: " << getTitle() << endl;
    cout << "Job: " << getJob() << endl;
    cout << "Supervisor: " << getSupervisor() <<  endl;
}

void Permanent::print_check()
{
    cout << "\n__________________________________________________\n";
    cout << "Pay to the order of " << getTitle()<< ": " << get_name() << endl;
    cout << "The sum of: " << get_net_pay() << " Dollars\n";
    cout << "_________________________________________________\n";
    cout << "Check Stub NOT NEGOTIABLE \n";
    cout << "Employee Number: " << get_ssn( ) << endl;
    cout << "Salaried Employee: " << getTitle() << " Pay: "
         << get_salary() << endl;
    cout << "_________________________________________________\n";

}
