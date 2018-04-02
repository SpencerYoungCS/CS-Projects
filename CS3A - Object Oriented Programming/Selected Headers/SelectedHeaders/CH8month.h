#ifndef CH8MONTH_H
#define CH8MONTH_H

// im not too sure how this one is different
//from ch6 for the headers
class CH8Month
{
public:
    CH8Month();
    CH8Month(int MonthNum); //returns the month based on the number
    //Accessors
    int getMonthNum();
    //Mutators
    void setmonth(int newMonthNum);

private:
    int MonthNum;
};

#endif // CH8MONTH_H
