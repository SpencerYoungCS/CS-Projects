#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "salariedemployee.h"
#include <string>

class Administrator : public SalariedEmployee
{
public:
    Administrator();
    Administrator(string new_title);
    Administrator(string new_title, string new_job, string new_supervisor);

    //mutators
    void set_title(string newtitle);
    void set_supervisor(string new_supervisor);

    //accessors
    string getTitle();
    string getJob();
    string getSupervisor();

    void print();
    void print_check();

private:
    string title;
    string job;
    string supervisor;
    double salary;

};

//A member function for reading in an administrator’s data from the
//keyboard.
//A member function called print, which outputs the object’s data to
//the screen.
//An overloading of the member function print_check( ) with appropriate
//notations on the check.

#endif // ADMINISTRATOR_H
