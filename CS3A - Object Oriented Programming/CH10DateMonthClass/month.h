#ifndef MONTH_H
#define MONTH_H

class Month
{
public:
    Month();
    Month(char first, char second, char third);
    Month(int num);

    void SetNum(int num);
    void SetChar(char first, char second, char third);

    int getNumMonth();
    char getcharmonth();

    int getNextMonth();


private:
    int NumMonth;
    char ltr1;
    char ltr2;
    char ltr3;

};

#endif // MONTH_H
