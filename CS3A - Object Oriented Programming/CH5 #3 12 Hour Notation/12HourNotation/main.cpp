#include <iostream>

bool tryagain(char again); //I finally decided to make this a function because I use this way too often
void calculatetime(int &hour, int &minute, int waithour, int waitminute);   //This is responsible for the calculations
void showtime(int hour, int minute);        // This will simply display the time without the minute time being broken
bool isAM(int hour);    //This determines whether or not it is AM or PM
void newnotation(int &hour);      //This will take hour and minute and convert it from 24 hour notation to 12


using namespace std;

int main()
{
    char again;

    do{                 //notice these initializations are called afterwards so that the values will be reset when the program restarts by the user
        int hour = 0;
        int minute = 0;
        int waithour = 0;
        int waitminute = 0;


        cout << "Please enter the current time in 24 hour notation" << endl;

        do      //This do while loop will take care of invalid hour values
        {
            cout << "Hour: ";
            cin >> hour;
            if (hour > 24 || hour < 0)
            {
                cout << "Please enter a real time!" << endl;
            }
        }while(hour > 24 || hour < 0);


        do      //This do while loop will take care of invalid minute values
        {
            cout << "Minute: ";
            cin >> minute;
            if (minute > 59 || minute < 0)
            {
                cout << "Please enter a real time!" << endl;
            }
        }while(minute > 59 || minute < 0);

        cout << "Hours to wait: ";
        cin >> waithour;

        cout << "Minutes to wait: ";
        cin >> waitminute;

        cout << endl;

        calculatetime(hour,minute,waithour,waitminute);

        if (isAM(hour))     // This will simply check whether or not it is AM or PM before calling the new notation function, as well as finishing the rest of the program
        {
            newnotation(hour);
            cout << "The time will be: ";
            showtime(hour, minute);
            cout << " A.M" << endl;
        }
        else
        {
            newnotation(hour);
            cout << "The time will be: ";
            showtime(hour, minute);
            cout << " P.M" << endl;
        }

        cout << endl;



    }while(tryagain(again));

    return 0;
}

bool tryagain(char again)
{
    cout << "Would you like to try again? (Y/N)" << endl;
    cin >> again;
    if (again == 'y'|| again == 'Y')
    {
        return true;
    }
    else
    {
        return false;
    }
    cout << endl;
}

void calculatetime(int &hour, int &minute, int waithour, int waitminute)    //This void function will use hour and minute as a pass by reference so I can use less variables
{
    minute = minute + waitminute;
    hour = hour + waithour;

    for(minute; minute > 59; hour ++)   //for loop to increment hours for every 60 minutes that go by
        minute = minute - 60;

    for(hour; hour > 24; hour = hour - 24);     //for loop to decrement total hours by 24 until a realistic time is achieved

}

void showtime(int hour, int minute)     //I want to prevent the minute time from being cut
{
    if (minute < 10)
        cout << hour << ":0" << minute;
    else
        cout << hour << ":" << minute;
}


bool isAM(int hour)     //If true its AM, if false its PM
{
    if (hour < 13)
        return true;
    else
        return false;
}

void newnotation(int &hour)
{
    for(hour; hour > 12; hour = hour - 12);
}
