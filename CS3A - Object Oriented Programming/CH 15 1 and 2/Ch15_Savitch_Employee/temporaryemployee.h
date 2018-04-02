#ifndef TEMPORARYEMPLOYEE_H
#define TEMPORARYEMPLOYEE_H
#include "salariedemployee.h"

class TemporaryEmployee : public SalariedEmployee{
public:

    TemporaryEmployee();

    //mutators
    void set_job(string newjob);
    //accessors

    string getJob();
    void print_check();

private:
    string job;
    string supervisor;
    double salary;
};

#endif // TEMPORARYEMPLOYEE_H
