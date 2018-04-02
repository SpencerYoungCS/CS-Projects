#include "date.h"
#include <iostream>

using namespace std;

Date::Date()
{
    day = 1;
}

Date::Date(int NewDay)
{
    day = NewDay;
}

Date::Date(int NewMonth,int NewDay, int NewYear)
{

    //set year calculation
    day = (NewYear * 365) + (NewYear/4) - (NewYear/100) + (NewYear/400);

    //set month calc------------------------------


    int dayholder = day;
    int yearcounter = 0;
    int leapcounter = 0;

    //importing year calculation from getyear-----------------
    while (dayholder > 365)
    {
        dayholder = dayholder - 365;
        yearcounter++;
        leapcounter++;

        if(leapcounter > 3) //these will account for leap years by subtracting total days by 1 more (making it 366)
        {
            if (yearcounter%100 == 0) //if divisible by 100, not leap year however...
            {
                if(yearcounter%400 == 0) // if divisible by 400, it is a leap year.
                {
                    leapcounter = 0;
                    dayholder = dayholder - 1;
                }
                else // not divisible by 400.. not leap year
                {
                    leapcounter = 0;
                }
            }
            else
            {
                leapcounter = 0;
                dayholder = dayholder - 1;
            }
        }
    }


    if (NewMonth == 12)
    {
        if(leapcounter == 0)
        {
            day = day + 335;
        }
        else
        {
            day =  day + 334;
        }
    }

    if (NewMonth == 11)
    {
        if(leapcounter == 0)
        {
            day = day + 305;
        }
        else
        {
            day = day + 304;
        }
    }
    if (NewMonth == 10)
    {
        if(leapcounter == 0)
        {
            day = day + 274;
        }
        else
        {
            day = day + 273;
        }
    }
    if (NewMonth == 9)
    {
        if(leapcounter == 0)
        {
            day = day + 244;
        }
        else
        {
            day = day + 243;
        }
    }
    if (NewMonth == 8)
    {
        if(leapcounter == 0)
        {
            day = day + 213;
        }
        else
        {
            day = day + 212;
        }
    }
    if (NewMonth == 7)
    {
        if(leapcounter == 0)
        {
            day = day + 182;
        }
        else
        {
            day = day + 181;
        }
    }
    if (NewMonth == 6)
    {
        if(leapcounter == 0)
        {
            day = day + 152;
        }
        else
        {
            day = day + 151;
        }
    }
    if (NewMonth == 5)
    {
        if(leapcounter == 0)
        {
            day = day + 121;
        }
        else
        {
            day = day + 120;
        }
    }
    if (NewMonth == 4)
    {
        if(leapcounter == 0)
        {
            day = day + 91;
        }
        else
        {
            day = day + 90;
        }
    }
    if (NewMonth == 3)
    {
        if(leapcounter == 0)
        {
            day = day + 60;
        }
        else
        {
            day = day + 59;
        }
    }
    if (NewMonth == 2)
    {
        day = day + 31;

    }
    if (NewMonth == 1 || NewMonth == 0)
    {
    }


    day = day + NewDay;

}

void Date::setday(int NewDay)
{
    int dayholder = day;
    int yearcounter = 0;
    int leapcounter = 0;

    //importing year calculation from getyear and get month-----------------
    while (dayholder > 365)
    {
        dayholder = dayholder - 365;
        yearcounter++;
        leapcounter++;

        if(leapcounter > 3) //these will account for leap years by subtracting total days by 1 more (making it 366)
        {
            if (yearcounter%100 == 0) //if divisible by 100, not leap year however...
            {
                if(yearcounter%400 == 0) // if divisible by 400, it is a leap year.
                {
                    leapcounter = 0;
                    dayholder = dayholder - 1;
                }
                else // not divisible by 400.. not leap year
                {
                    leapcounter = 0;
                }
            }
            else
            {
                leapcounter = 0;
                dayholder = dayholder - 1;
            }
        }
    }

    if(leapcounter == 0) // it can only be zero if it is leap year because statement above it will always reset it to zero when it hits 4
    {
        if (dayholder > 335) //december
        {
            day = day - dayholder;
            day = day + 335 + NewDay;
        }

        if (dayholder > 305)
        {
            day = day - dayholder;
            day = day + 305 + NewDay;
        }
        if (dayholder > 274)
        {
            day = day - dayholder;
            day = day + 274 + NewDay;
        }
        if (dayholder > 244)
        {
            day = day - dayholder;
            day = day + 244 + NewDay;
        }
        if (dayholder > 213)
        {
            day = day - dayholder;
            day = day + 213 + NewDay;
        }
        if (dayholder > 182)
        {
            day = day - dayholder;
            day = day + 182 + NewDay;
        }
        if (dayholder > 152)
        {
            day = day - dayholder;
            day = day + 152 + NewDay;
        }
        if (dayholder > 121)
        {
            day = day - dayholder;
            day = day + 121 + NewDay;
        }
        if (dayholder > 91)
        {
            day = day - dayholder;
            day = day + 91 + NewDay;
        }
        if (dayholder > 60)
        {
            day = day - dayholder;
            day = day + 60 + NewDay;
        }
        if (dayholder > 31)
        {
            day = day - dayholder;
            day = day + 31 + NewDay;
        }

        if (dayholder == 0)
        {
            day = day +  NewDay;
        }
    }

    else    //other than leap year it will calculate this
    {

        if (dayholder > 334) //december
        {
            day = day - dayholder;
            day = day + 334 + NewDay;
        }
        if (dayholder > 304)
        {
            day = day - dayholder;
            day = day + 304 + NewDay;
        }
        if (dayholder > 273)
        {
            day = day - dayholder;
            day = day + 273 + NewDay;
        }
        if (dayholder > 243)
        {
            day = day - dayholder;
            day = day + 243 + NewDay;
        }
        if (dayholder > 212)
        {
            day = day - dayholder;
            day = day + 212 + NewDay;
        }
        if (dayholder > 181)
        {
            day = day - dayholder;
            day = day + 181 + NewDay;
        }
        if (dayholder > 151)
        {
            day = day - dayholder;
            day = day + 151 + NewDay;
        }
        if (dayholder > 120)
        {
            day = day - dayholder;
            day = day + 120 + NewDay;
        }
        if (dayholder > 90)
        {
            day = day - dayholder;
            day = day + 90 + NewDay;
        }
        if (dayholder > 59)
        {
            day = day - dayholder;
            day = day + 59 + NewDay;
        }
        if (dayholder > 31)
        {
            day = day - dayholder;
            day = day + 31 + NewDay;
        }

        if (dayholder == 0)
        {
            day = day + NewDay;
        }
    }


}

void Date::setmonth(int NewMonth)
{

    int dayholder = day;
    int leapcounter = 0;
    int yearcounter = 0;

    while (NewMonth > 12) //this is incase the user puts more months than 12
    {
        NewMonth = NewMonth - 12;
        dayholder = dayholder + 365;
    }

    //importing year calculation from getyear and get month-----------------
    while (dayholder > 365)
    {
        dayholder = dayholder - 365;
        yearcounter++;
        leapcounter++;

        if(leapcounter > 3) //these will account for leap years by subtracting total days by 1 more (making it 366)
        {
            if (yearcounter%100 == 0) //if divisible by 100, not leap year however...
            {
                if(yearcounter%400 == 0) // if divisible by 400, it is a leap year.
                {
                    leapcounter = 0;
                    dayholder = dayholder - 1;
                }
                else // not divisible by 400.. not leap year
                {
                    leapcounter = 0;
                }
            }
            else
            {
                leapcounter = 0;
                dayholder = dayholder - 1;
            }
        }
    }




    if(leapcounter == 0) // it can only be zero if it is leap year because statement above it will always reset it to zero when it hits 4
    {
        if (dayholder > 335) //december
        {
            dayholder = dayholder - 335;
        }

        if (dayholder > 305)
        {
            dayholder = dayholder - 305;
        }
        if (dayholder > 274)
        {
            dayholder = dayholder - 274;
        }
        if (dayholder > 244)
        {
            dayholder = dayholder - 244;
        }
        if (dayholder > 213)
        {
            dayholder = dayholder - 213;
        }
        if (dayholder > 182)
        {
            dayholder = dayholder - 182;
        }
        if (dayholder > 152)
        {
            dayholder = dayholder - 152;
        }
        if (dayholder > 121)
        {
            dayholder = dayholder - 121;
        }
        if (dayholder > 91)
        {
            dayholder = dayholder - 91;
        }
        if (dayholder > 60)
        {
            dayholder = dayholder - 60;
        }
        if (dayholder > 31)
        {
            dayholder = dayholder - 31;
        }

        if (dayholder == 0)
        {
            dayholder = 1;
        }
    }

    else    //other than leap year it will calculate this
    {

        if (dayholder > 334) //december
        {
            dayholder = dayholder - 334;
        }

        if (dayholder > 304)
        {
            dayholder = dayholder - 304;
        }
        if (dayholder > 273)
        {
            dayholder = dayholder - 273;
        }
        if (dayholder > 243)
        {
            dayholder = dayholder - 243;
        }
        if (dayholder > 212)
        {
            dayholder = dayholder - 212;
        }
        if (dayholder > 181)
        {
            dayholder = dayholder - 181;
        }
        if (dayholder > 151)
        {
            dayholder = dayholder - 151;
        }
        if (dayholder > 120)
        {
            dayholder = dayholder - 120;
        }
        if (dayholder > 90)
        {
            dayholder = dayholder - 90;
        }
        if (dayholder > 59)
        {
            dayholder = dayholder - 59;
        }
        if (dayholder > 31)
        {
            dayholder = dayholder - 31;
        }

        if (dayholder == 0)
        {
            dayholder = 1;
        }
    }


    //---------------end of import----------------------------------------


    //day holder holds the original day. it will add to adjust for the new month

    if (NewMonth == 12)
    {
        if(leapcounter == 0)
        {
            dayholder = dayholder + 335;
        }
        else
        {
            dayholder =  dayholder + 334;
        }
    }

    if (NewMonth == 11)
    {
        if(leapcounter == 0)
        {
            dayholder = dayholder + 305;
        }
        else
        {
            dayholder = dayholder + 304;
        }
    }
    if (NewMonth == 10)
    {
        if(leapcounter == 0)
        {
            dayholder = dayholder + 274;
        }
        else
        {
            dayholder = dayholder + 273;
        }
    }
    if (NewMonth == 9)
    {
        if(leapcounter == 0)
        {
            dayholder = dayholder + 244;
        }
        else
        {
            dayholder = dayholder + 243;
        }
    }
    if (NewMonth == 8)
    {
        if(leapcounter == 0)
        {
            dayholder = dayholder + 213;
        }
        else
        {
            dayholder = dayholder + 212;
        }
    }
    if (NewMonth == 7)
    {
        if(leapcounter == 0)
        {
            dayholder = dayholder + 182;
        }
        else
        {
            dayholder = dayholder + 181;
        }
    }
    if (NewMonth == 6)
    {
        if(leapcounter == 0)
        {
            dayholder = dayholder + 152;
        }
        else
        {
            dayholder = dayholder + 151;
        }
    }
    if (NewMonth == 5)
    {
        if(leapcounter == 0)
        {
            dayholder = dayholder + 121;
        }
        else
        {
            dayholder = dayholder + 120;
        }
    }
    if (NewMonth == 4)
    {
        if(leapcounter == 0)
        {
            dayholder = dayholder + 91;
        }
        else
        {
            dayholder = dayholder + 90;
        }
    }
    if (NewMonth == 3)
    {
        if(leapcounter == 0)
        {
            dayholder = dayholder + 60;
        }
        else
        {
            dayholder = dayholder + 59;
        }
    }
    if (NewMonth == 2)
    {
        dayholder = dayholder + 31;

    }
    if (NewMonth == 1 || NewMonth == 0)
    {
    }


    day = (yearcounter * 365) + (yearcounter/4) - (yearcounter/100) + (yearcounter/400) + dayholder;


}

void Date::setyear(int NewYear)
{
    //{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayholder = day;
    int yearcounter = 0;
    int leapcounter = 0;

    //importing year calculation from getyear and get month-----------------
    while (dayholder > 365)
    {
        dayholder = dayholder - 365;
        yearcounter++;
        leapcounter++;

        if(leapcounter > 3) //these will account for leap years by subtracting total days by 1 more (making it 366)
        {
            if (yearcounter%100 == 0) //if divisible by 100, not leap year however...
            {
                if(yearcounter%400 == 0) // if divisible by 400, it is a leap year.
                {
                    leapcounter = 0;
                    dayholder = dayholder - 1;
                }
                else // not divisible by 400.. not leap year
                {
                    leapcounter = 0;
                }
            }
            else
            {
                leapcounter = 0;
                dayholder = dayholder - 1;
            }
        }
    }

    //---------------end of import----------------------------------------


    //set year calculation
    NewYear = (NewYear * 365) + (NewYear/4) - (NewYear/100) + (NewYear/400);
    day = NewYear + dayholder;

}

void Date::set(int NewMonth, int NewDay, int NewYear)
{

    //set year calculation
    day = (NewYear * 365) + (NewYear/4) - (NewYear/100) + (NewYear/400);

    //set month calc------------------------------


    int dayholder = day;
    int yearcounter = 0;
    int leapcounter = 0;

    //importing year calculation from getyear-----------------
    while (dayholder > 365)
    {
        dayholder = dayholder - 365;
        yearcounter++;
        leapcounter++;

        if(leapcounter > 3) //these will account for leap years by subtracting total days by 1 more (making it 366)
        {
            if (yearcounter%100 == 0) //if divisible by 100, not leap year however...
            {
                if(yearcounter%400 == 0) // if divisible by 400, it is a leap year.
                {
                    leapcounter = 0;
                    dayholder = dayholder - 1;
                }
                else // not divisible by 400.. not leap year
                {
                    leapcounter = 0;
                }
            }
            else
            {
                leapcounter = 0;
                dayholder = dayholder - 1;
            }
        }
    }


    if (NewMonth == 12)
    {
        if(leapcounter == 0)
        {
            day = day + 335;
        }
        else
        {
            day =  day + 334;
        }
    }

    if (NewMonth == 11)
    {
        if(leapcounter == 0)
        {
            day = day + 305;
        }
        else
        {
            day = day + 304;
        }
    }
    if (NewMonth == 10)
    {
        if(leapcounter == 0)
        {
            day = day + 274;
        }
        else
        {
            day = day + 273;
        }
    }
    if (NewMonth == 9)
    {
        if(leapcounter == 0)
        {
            day = day + 244;
        }
        else
        {
            day = day + 243;
        }
    }
    if (NewMonth == 8)
    {
        if(leapcounter == 0)
        {
            day = day + 213;
        }
        else
        {
            day = day + 212;
        }
    }
    if (NewMonth == 7)
    {
        if(leapcounter == 0)
        {
            day = day + 182;
        }
        else
        {
            day = day + 181;
        }
    }
    if (NewMonth == 6)
    {
        if(leapcounter == 0)
        {
            day = day + 152;
        }
        else
        {
            day = day + 151;
        }
    }
    if (NewMonth == 5)
    {
        if(leapcounter == 0)
        {
            day = day + 121;
        }
        else
        {
            day = day + 120;
        }
    }
    if (NewMonth == 4)
    {
        if(leapcounter == 0)
        {
            day = day + 91;
        }
        else
        {
            day = day + 90;
        }
    }
    if (NewMonth == 3)
    {
        if(leapcounter == 0)
        {
            day = day + 60;
        }
        else
        {
            day = day + 59;
        }
    }
    if (NewMonth == 2)
    {
        day = day + 31;

    }
    if (NewMonth == 1 || NewMonth == 0)
    {
    }


    if (NewDay == 0)
    {
        NewDay ++;
    }

    day = day + NewDay ;
}

void Date::setraw(int rawday)
{
    day = rawday;
}

int Date::getday()
{
    //{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayholder = day;
    int yearcounter = 0;
    int leapcounter = 0;

    //importing year calculation from getyear and get month-----------------
    while (dayholder > 365)
    {
        dayholder = dayholder - 365;
        yearcounter++;
        leapcounter++;

        if(leapcounter > 3) //these will account for leap years by subtracting total days by 1 more (making it 366)
        {
            if (yearcounter%100 == 0) //if divisible by 100, not leap year however...
            {
                if(yearcounter%400 == 0) // if divisible by 400, it is a leap year.
                {
                    leapcounter = 0;
                    dayholder = dayholder - 1;
                }
                else // not divisible by 400.. not leap year
                {
                    leapcounter = 0;
                }
            }
            else
            {
                leapcounter = 0;
                dayholder = dayholder - 1;
            }
        }
    }

    if(leapcounter == 0) // it can only be zero if it is leap year because statement above it will always reset it to zero when it hits 4
    {
        if (dayholder > 335) //december
        {
            dayholder = dayholder - 335;
            return dayholder;
        }

        if (dayholder > 305)
        {
            dayholder = dayholder - 305;
            return dayholder;
        }
        if (dayholder > 274)
        {
            dayholder = dayholder - 274;
            return dayholder;
        }
        if (dayholder > 244)
        {
            dayholder = dayholder - 244;
            return dayholder;
        }
        if (dayholder > 213)
        {
            dayholder = dayholder - 213;
            return dayholder;
        }
        if (dayholder > 182)
        {
            dayholder = dayholder - 182;
            return dayholder;
        }
        if (dayholder > 152)
        {
            dayholder = dayholder - 152;
            return dayholder;
        }
        if (dayholder > 121)
        {
            dayholder = dayholder - 121;
            return dayholder;
        }
        if (dayholder > 91)
        {
            dayholder = dayholder - 91;
            return dayholder;
        }
        if (dayholder > 60)
        {
            dayholder = dayholder - 60;
            return dayholder;
        }
        if (dayholder > 31)
        {
            dayholder = dayholder - 31;
            return dayholder;
        }

        if (dayholder == 0)
        {

            dayholder = 1;
            return dayholder;
        }
    }

    else    //other than leap year it will calculate this
    {

        if (dayholder > 334) //december
        {
            dayholder = dayholder - 334;
            return dayholder;
        }

        if (dayholder > 304)
        {
            dayholder = dayholder - 304;
            return dayholder;
        }
        if (dayholder > 273)
        {
            dayholder = dayholder - 273;
            return dayholder;
        }
        if (dayholder > 243)
        {
            dayholder = dayholder - 243;
            return dayholder;
        }
        if (dayholder > 212)
        {
            dayholder = dayholder - 212;
            return dayholder;
        }
        if (dayholder > 181)
        {
            dayholder = dayholder - 181;
            return dayholder;
        }
        if (dayholder > 151)
        {
            dayholder = dayholder - 151;
            return dayholder;
        }
        if (dayholder > 120)
        {
            dayholder = dayholder - 120;
            return dayholder;
        }
        if (dayholder > 90)
        {
            dayholder = dayholder - 90;
            return dayholder;
        }
        if (dayholder > 59)
        {
            dayholder = dayholder - 59;
            return dayholder;
        }
        if (dayholder > 31)
        {
            dayholder = dayholder - 31;
            return dayholder;
        }

        if (dayholder == 0)
        {
            dayholder = 1;
            return dayholder;
        }
    }

}

int Date::getmonth()
{
    int dayholder = day;
    int monthcounter = 1;
    int yearcounter = 0;
    int leapcounter = 0;

    //importing year calculation from getyear-----------------
    while (dayholder > 365)
    {
        dayholder = dayholder - 365;
        yearcounter++;
        leapcounter++;

        if(leapcounter > 3) //these will account for leap years by subtracting total days by 1 more (making it 366)
        {
            if (yearcounter%100 == 0) //if divisible by 100, not leap year however...
            {
                if(yearcounter%400 == 0) // if divisible by 400, it is a leap year.
                {
                    leapcounter = 0;
                    dayholder = dayholder - 1;
                }
                else // not divisible by 400.. not leap year
                {
                    leapcounter = 0;
                }
            }
            else
            {
                leapcounter = 0;
                dayholder = dayholder - 1;
            }
        }
    }

    if(leapcounter == 0) // it can only be zero if it is leap year because statement above it will always reset it to zero when it hits 4
    {
        if (dayholder > 335) //december
        {
            monthcounter = 12;
            return monthcounter;
        }

        if (dayholder > 305)
        {
            monthcounter = 11;
            return monthcounter;
        }
        if (dayholder > 274)
        {
            monthcounter = 10;
            return monthcounter;
        }
        if (dayholder > 244)
        {
            monthcounter = 9;
            return monthcounter;
        }
        if (dayholder > 213)
        {
            monthcounter = 8;
            return monthcounter;
        }
        if (dayholder > 182)
        {
            monthcounter = 7;
            return monthcounter;
        }
        if (dayholder > 152)
        {
            monthcounter = 6;
            return monthcounter;
        }
        if (dayholder > 121)
        {
            monthcounter = 5;
            return monthcounter;
        }
        if (dayholder > 91)
        {
            monthcounter = 4;
            return monthcounter;
        }
        if (dayholder > 60)
        {
            monthcounter = 3;
            return monthcounter;
        }
        if (dayholder > 31)
        {
            monthcounter = 2;
            return monthcounter;
        }
        if (dayholder >= 0) //january
        {
            monthcounter = 1;
            return monthcounter;
        }

    }

    else    //other than leap year it will calculate this
    {

        if (dayholder > 334) //december
        {
            monthcounter = 12;
            return monthcounter;
        }

        if (dayholder > 304)
        {
            monthcounter = 11;
            return monthcounter;
        }
        if (dayholder > 273)
        {
            monthcounter = 10;
            return monthcounter;
        }
        if (dayholder > 243)
        {
            monthcounter = 9;
            return monthcounter;
        }
        if (dayholder > 212)
        {
            monthcounter = 8;
            return monthcounter;
        }
        if (dayholder > 181)
        {
            monthcounter = 7;
            return monthcounter;
        }
        if (dayholder > 151)
        {
            monthcounter = 6;
            return monthcounter;
        }
        if (dayholder > 120)
        {
            monthcounter = 5;
            return monthcounter;
        }
        if (dayholder > 90)
        {
            monthcounter = 4;
            return monthcounter;
        }
        if (dayholder > 59)
        {
            monthcounter = 3;
            return monthcounter;
        }
        if (dayholder > 31)
        {
            monthcounter = 2;
            return monthcounter;
        }
        if (dayholder >= 0) // jamuary
        {
            monthcounter = 1;
            return monthcounter;
        }
    }

}

int Date::getyear()
{
    int dayholder = day;
    int yearcounter = 0;
    int leapcounter = 0;


    while (dayholder > 365)
    {

        dayholder = dayholder - 365;
        yearcounter++;
        leapcounter++;

        if(leapcounter > 3) //these will account for leap years by subtracting total days by 1 more (making it 366)
        {
            if (yearcounter%100 == 0) //if divisible by 100, not leap year however...
            {
                if(yearcounter%400 == 0) // if divisible by 400, it is a leap year.
                {
                    leapcounter = 0;
                    dayholder = dayholder - 1;
                }
                else // not divisible by 400.. not leap year
                {
                    leapcounter = 0;
                }
            }
            else
            {
                leapcounter = 0;
                dayholder = dayholder - 1;
            }
        }

    }

    return yearcounter;

}

int Date::getrawday()
{
    return day;
}


//------------------BUSINESS DAYS ASSIGNMENT!!!!!!!!-------------------------------------------------------------

int Date::GetTotalbusinessdays()
{

    int businessdays;
    int weeks;
    weeks = day/7;
    if (day%7 == 0) // saturday
    {
        return businessdays = weeks*5;
    }
    if (day%7 == 1) // sunday
    {
        return businessdays = weeks*5;
    }
    if (day%7 == 2) // monday
    {
        return businessdays = weeks*5 + 1;
    }
    if (day%7 == 3) // tuesday
    {
        return businessdays = weeks*5 + 2;
    }
    if (day%7 == 4)// wednesday
    {
        return businessdays = weeks*5 + 3;
    }
    if (day%7 == 5)// thursday
    {
        return businessdays = weeks*5 + 4;
    }
    if (day%7 == 6)//friday
    {
        return businessdays = weeks*5 + 5;
    }

}


int Date::BusinessDays(Date toDate)
{
    int businessdays;
    int weeks;
    weeks = day/7;
    if (day%7 == 0) // saturday
    {
        businessdays = weeks*5;
    }
    if (day%7 == 1) // sunday
    {
        businessdays = weeks*5;
    }
    if (day%7 == 2) // monday
    {
        businessdays = weeks*5 + 1;
    }
    if (day%7 == 3) // tuesday
    {
        businessdays = weeks*5 + 2;
    }
    if (day%7 == 4)// wednesday
    {
        businessdays = weeks*5 + 3;
    }
    if (day%7 == 5)// thursday
    {
        businessdays = weeks*5 + 4;
    }
    if (day%7 == 6)//friday
    {
        businessdays = weeks*5 + 5;
    }
    return toDate.GetTotalbusinessdays() - businessdays;
}

int Date::Weekends(Date toDate)
{

    int businessdays;
    int weeks;
    weeks = day/7;
    if (day%7 == 0) // saturday
    {
        businessdays = weeks*5;
    }
    if (day%7 == 1) // sunday
    {
        businessdays = weeks*5;
    }
    if (day%7 == 2) // monday
    {
        businessdays = weeks*5 + 1;
    }
    if (day%7 == 3) // tuesday
    {
        businessdays = weeks*5 + 2;
    }
    if (day%7 == 4)// wednesday
    {
        businessdays = weeks*5 + 3;
    }
    if (day%7 == 5)// thursday
    {
        businessdays = weeks*5 + 4;
    }
    if (day%7 == 6)//friday
    {
        businessdays = weeks*5 + 5;
    }

    return (toDate.getrawday() - toDate.GetTotalbusinessdays()) -(day - businessdays);
}

Date Date::InXBusinessDays(int numOfDays)
{

    int weeks = 0;
    int weekends = 0;
    int extradays = 0;

    if (day%7 == 0) // saturday-------------------------
    {
        if(numOfDays > 8)
        {
            if(numOfDays > 5)
            {
                weeks = (numOfDays/5);
                weekends =  weeks * 2;
                extradays = numOfDays%5;

                return day = day + numOfDays + weekends + extradays;
            }
            else
            {
                weeks = (numOfDays/5) -1; //minus one because adding numofdays into the day already accounts for a weekend
                weekends =  weeks * 2;
                extradays = numOfDays%5;

                return day = day + numOfDays + weekends + extradays;
            }

        }
        if (numOfDays == 7)
        {
            return day = day + numOfDays + 2;
        }
        if(numOfDays == 8)
        {
            return day = day + numOfDays + 1;
        }
        return day = day + numOfDays;
    }
    if (day%7 == 1) // sunday----------------------------
    {
        if(numOfDays > 7)
        {
            if(numOfDays > 5)
            {
                weeks = (numOfDays/5);
                weekends =  weeks * 2;
                extradays = numOfDays%5;

                return day = day + numOfDays + weekends + extradays;
            }
            else
            {
                weeks = (numOfDays/5) -1; //minus one because adding numofdays into the day already accounts for a weekend
                weekends =  weeks * 2;
                extradays = numOfDays%5;

                return day = day + numOfDays + weekends + extradays;
            }

        }
        if (numOfDays == 6)
        {
            return day = day + numOfDays + 2;
        }
        if(numOfDays == 7)
        {
            return day = day + numOfDays + 1;
        }
        return day = day + numOfDays;

    }
    if (day%7 == 2) // monday-----------------------------
    {

        if(numOfDays > 6)
        {
            if(numOfDays > 5)
            {
                weeks = (numOfDays/5);
                weekends =  weeks * 2;
                extradays = numOfDays%5;

                return day = day + numOfDays + weekends + extradays;
            }
            else
            {
                weeks = (numOfDays/5) -1; //minus one because adding numofdays into the day already accounts for a weekend
                weekends =  weeks * 2;
                extradays = numOfDays%5;

                return day = day + numOfDays + weekends + extradays;
            }

        }
        if (numOfDays == 5)
        {
            return day = day + numOfDays + 2;
        }
        if(numOfDays == 6)
        {
            return day = day + numOfDays + 1;
        }
        return day = day + numOfDays;
    }
    if (day%7 == 3) // tuesday------------
    {
        if(numOfDays > 5)
        {
            if(numOfDays > 5)
            {
                weeks = (numOfDays/5);
                weekends =  weeks * 2;
                extradays = numOfDays%5;

                return day = day + numOfDays + weekends + extradays;
            }
            else
            {
                weeks = (numOfDays/5) -1; //minus one because adding numofdays into the day already accounts for a weekend
                weekends =  weeks * 2;
                extradays = numOfDays%5;

                return day = day + numOfDays + weekends + extradays;
            }
        }
        if (numOfDays == 4)
        {
            return day = day + numOfDays + 2;
        }
        if(numOfDays == 5)
        {
            return day = day + numOfDays + 1;
        }
        return day = day + numOfDays;
    }

    if (day%7 == 4)// wednesday---------------------------
    {
        if(numOfDays > 4)
        {
            if(numOfDays > 5)
            {
                weeks = (numOfDays/5);
                weekends =  weeks * 2;
                extradays = numOfDays%5;

                return day = day + numOfDays + weekends + extradays;
            }
            else
            {
                weeks = (numOfDays/5) -1; //minus one because adding numofdays into the day already accounts for a weekend
                weekends =  weeks * 2;
                extradays = numOfDays%5;

                return day = day + numOfDays + weekends + extradays;
            }

        }
        if (numOfDays == 3)
        {
            return day = day + numOfDays + 2;
        }
        if(numOfDays == 4)
        {
            return day = day + numOfDays + 1;
        }
        return day = day + numOfDays;
    }

    if (day%7 == 5)// thursday--------------------------------

    {
        if(numOfDays > 3)
        {
            if(numOfDays > 5)
            {
                weeks = (numOfDays/5);
                weekends =  weeks * 2;
                extradays = numOfDays%5;

                return day = day + numOfDays + weekends + extradays;
            }
            else
            {
                weeks = (numOfDays/5) -1; //minus one because adding numofdays into the day already accounts for a weekend
                weekends =  weeks * 2;
                extradays = numOfDays%5;

                return day = day + numOfDays + weekends + extradays;
            }

        }
        if (numOfDays == 2)
        {
            return day = day + numOfDays + 2;
        }
        if(numOfDays == 3)
        {
            return day = day + numOfDays + 1;
        }
        return day = day + numOfDays;
    }
    if (day%7 == 6)//friday------------------------------------
    {
        if(numOfDays > 2)
        {
            if(numOfDays > 5)
            {
                weeks = (numOfDays/5);
                weekends =  weeks * 2;
                extradays = numOfDays%5;

                return day = day + numOfDays + weekends + extradays;
            }
            else
            {
                weeks = (numOfDays/5) -1; //minus one because adding numofdays into the day already accounts for a weekend
                weekends =  weeks * 2;
                extradays = numOfDays%5;

                return day = day + numOfDays + weekends + extradays;
            }

        }
        if (numOfDays == 1)
        {
            return day = day + numOfDays + 2;
        }
        if(numOfDays == 2)
        {
            return day = day + numOfDays + 1;
        }
        return day = day + numOfDays;
    }
}




//-----------------------------------END OF BUSINESS DAYS ASSIGNMENT-------------------------------------

Date Date::Add(Date A)
{
    day = day + A.getrawday();
    Date B;
    B.setraw(day);

}

Date Date::Sub(Date A)
{
    day = day - A.getrawday();
    Date B;
    B.setraw(day);

}


Date operator + (Date A, Date B)
{
    int num1 = A.day + B.day;

    Date C;
    C.setraw(num1);
    return C;

}

Date operator + (int A, Date B)
{
    int num1 = A + B.day;
    Date C;
    C.setraw(num1);
    return C;
}

Date operator + (Date B, int A)
{
    int num1 = B.day + A;
    Date C;
    C.setraw(num1);
    return C;
}

Date operator - (Date A, Date B)
{
    int num1 = A.day - B.day;
    Date C;
    C.setraw(num1);
    return C;
}

Date operator - (int A, Date B)
{
    int num1 = A - B.day;
    Date C;
    C.setraw(num1);
    return C;
}

Date operator - (Date B, int A)
{
    int num1 = B.day - A;
    Date C;
    C.setraw(num1);
    return C;
}

ostream& operator << (ostream& out, Date A)
{
    return out << A.getmonth() << "/" << A.getday() << "/" << A.getyear();
}

istream& operator >> (istream& in, Date& A)
{
    char slash;
    int a,b,c;
    in >> a >> slash >> b >> slash >> c;

    A.setmonth(a);
    A.setday(b) ;
    A.setyear(c);
    return in;
}


