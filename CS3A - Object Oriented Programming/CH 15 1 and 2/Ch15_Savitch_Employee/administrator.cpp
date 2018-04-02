#include "administrator.h"

Administrator::Administrator()
{
    title = "UNIDENTIFIED";
    job = "UNIDENTIFIED";
    supervisor = "UNIDENTIFIED";
    salary = get_salary();
}

Administrator::Administrator(string new_title)
{
    title = new_title;
    job = "UNIDENTIFIED";
    supervisor = "UNIDENTIFIED";
    salary = get_salary();
}

Administrator::Administrator(string new_title, string new_job, string new_supervisor)
{
    title = new_title;
    job = new_job;
    supervisor = new_supervisor;
}

void Administrator::set_title(string newtitle)
{
    title = newtitle;
}

void Administrator::set_supervisor(string new_supervisor)
{
    supervisor = new_supervisor;
}

string Administrator::getTitle()
{
    return title;
}

string Administrator::getJob()
{
    return job;
}

string Administrator::getSupervisor()
{
    return supervisor;
}

void Administrator::print()
{
    cout << endl;
    cout << "----------------" << getTitle() << "---------------------" << endl;
    cout << "Title: " << getTitle() << endl;
    cout << "Job: " << getJob() << endl;
    cout << "Supervisor: " << getSupervisor() <<  endl;
}

void Administrator::print_check()
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
