#ifndef NEWMONTH_H
#define NEWMONTH_H

class NewMonth
{
public:
    NewMonth();
    NewMonth(char ltr1, char ltr2, char ltr3); //returns the month based on the number
    //Accessors

    char getMonthChar(char letter);
    //Mutators

    void setmonth1(char newletter1);
    void setmonth2(char newletter2);
    void setmonth3(char newletter3);


private:
    char letter1;
    char letter2;
    char letter3;

};

#endif // NEWMONTH_H
