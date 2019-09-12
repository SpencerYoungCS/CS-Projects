#include <iostream>

//Chapter 5 #1: Military Time to 12 Hour conversion

using namespace std;

void inputtime(int &hour, int &minutes);
void convertime(int &hour, bool &am);
void outputtime(int hour, int minutes, bool am);



int main()
{
    bool isam;
    int hour;
    int minutes;
    bool done = false;
    char again;

    while (done == false)
    {
        cout << "Welcome to the military to 12 Hour Converter!"<< endl;
        cout << "Please enter the time in Military Time" << endl;
        cout << "What is the hour you would like to convert to?" << endl;

        inputtime(hour,minutes);
        convertime(hour,isam);
        outputtime(hour,minutes, isam);

// cout << "DEBUG: " << hour << ":"<<minutes << " IS AM: " << isam << endl;

        cout << "Would you like to try again? (y/n)" << endl;
        cin >> again;
        if (again == 'y' || again == 'Y')
        {
            done = false;
        }
        else
        {
            done = true;
        }
    }
    return 0;


}

void inputtime(int &hour, int &minutes)
{
    cin >> hour;
    while (hour > 23)
    {
        cout << "Enter a time under 24 hours!" << endl;
        cin >> hour;
    }
    cout << "Please enter the minute" << endl;
    cin >> minutes;
    while (minutes >59)
    {
        cout <<" Enter a time under 60 minutes!" << endl;
        cin >> minutes;
    }

}


void convertime(int &hour, bool &am)
{
    if (hour > 12)
    {
        hour = hour - 12;
        am = false;
    }
    else
    {
        am = true;
    }
}

void outputtime(int hour, int minutes, bool am)
{
    if (am == true)
    {
        cout << "The time is currently: " << hour << ":" << minutes << " A.M." << endl;
    }
    else
    {

        cout << "The time is currently: " << hour << ":" << minutes << " P.M." << endl;
    }
}
