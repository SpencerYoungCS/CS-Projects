#include <iostream>

//CH5 #2: Waiting Time

using namespace std;

void inputtime(int &hour, int &minutes);


int main()
{
    {
        int wHour;
        int wMinutes;
        int hour;
        int minutes;
        bool done = false;
        char again;

        while (done == false)
        {
            inputtime(hour,minutes);
            cout << "How many hours would you like to wait?" << endl;
            cin >> wHour;
            cout << "How many minutes would you like to wait?" << endl;
            cin >> wMinutes;

            hour = hour + wHour;
            minutes = minutes + wMinutes;

            while (minutes > 59)
            {
                minutes = minutes - 60;
                hour++;

            }

            while (hour > 23)
            {
                hour = hour - 24;
            }
            if (minutes < 10)
            {
                cout << "The time in the future after waiting will be: " << hour << ":0" << minutes << endl;
            }
            else
            {
                cout << "The time in the future after waiting will be: " << hour << ":" << minutes << endl;
            }


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
}

void inputtime(int &hour, int &minutes)
{
    cout << "Please enter an hour" << endl;
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

