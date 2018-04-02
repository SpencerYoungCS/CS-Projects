#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H
#include <string>
#include "employee.h"
using namespace std;

class HourlyEmployee : public Employee
{
public:
    HourlyEmployee( );
    HourlyEmployee(string the_name, string the_ssn,
                       double the_wage_rate, double the_hours);
    void set_rate(double new_wage_rate);
    double get_rate( ) const;
    void set_hours(double hours_worked);
    double get_hours( ) const;

    void print_check( ) ;
private:
    double wage_rate;
    double hours;
};

#endif // HOURLYEMPLOYEE_H
