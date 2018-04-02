#ifndef PERMANENT_H
#define PERMANENT_H
#include "salariedemployee.h"
class Permanent : public SalariedEmployee
{
public:
    Permanent();
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
};

#endif // PERMANENT_H
