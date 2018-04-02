#ifndef MONTH_H
#define MONTH_H

class Month
{
public:
    Month();
    Month(int MonthNum); //returns the month based on the number
    //Accessors
    int getMonthNum();
    //Mutators
    void setmonth(int newMonthNum);


private:
    int MonthNum;

};

#endif // MONTH_H
