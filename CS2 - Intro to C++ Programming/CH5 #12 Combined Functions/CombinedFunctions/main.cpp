#include <iostream>

// CH5 #12: Combined Functions

using namespace std;

void feetconvert();
void meterconvert();
void poundsconvert();
void gramsconvert();
void feetmeterconvert();
void poundsgramsconvert();
void lengthsorweights();

int main()
{
    lengthsorweights();
    return 0;
}

void poundsconvert()
{
    double pounds, ounces, kilograms, grams;

    cout << "Enter the pounds you want to convert" << endl;
    cin >> pounds;
    cout << "Enter the ounces you want to convert" << endl;
    cin >> ounces;

    pounds = pounds + (ounces / 16);
    kilograms = pounds * 2.2046;
    grams = kilograms * 1000;

    cout << "Kilograms: " << kilograms << endl;
    cout << "Grams: " << grams << endl;
}

void gramsconvert()
{
    double pounds, ounces, kilograms, grams;
    cout << "Enter the Amount of Kilograms you want to convert" << endl;
    cin >> kilograms;
    cout << "Enter ther grams you want to convert" << endl;
    cin >> grams;

    kilograms = kilograms + (grams/1000);
    pounds = kilograms / 2.2046;
    ounces = pounds * 16;

    cout << "Pounds: " << pounds << endl;
    cout << "Ounces: " << ounces << endl;
}

void feetconvert()
{
    double feet, inches, meters, centimeters;

    cout << "Enter the total feet you want to convert" << endl;
    cin >> feet;
    cout << "Enter the inches you want to convert" << endl;
    cin >> inches;

    feet = feet + (inches/12);
    meters = feet * 0.3048;
    centimeters = meters * 100;

    cout << "meters: " << meters << endl;
    cout << "centimeters: " << centimeters << endl;
}

void meterconvert()
{
    double feet, inches, meters, centimeters;

    cout << "Enter the total meters you want to convert" << endl;
    cin >> meters;
    cout << "Enter the centimeters you want to convert" << endl;
    cin >>  centimeters;

    meters = meters + (centimeters/100);
    feet = meters / 0.3048;
    inches = feet * 12;

    cout << "feet: " << feet << endl;
    cout << "inches: " << inches << endl;
}

void feetmeterconvert()
{
    int decision;
    bool inrange = false;
    while (inrange == false )
    {
        cout << "Would you like to convert feet to meter (1)" << endl;
        cout << "Or meter to feet? (2)" << endl;
        cin >> decision;
        if (decision == 1)
        {
            feetconvert();
            inrange = true;
        }
        else if (decision == 2)
        {
            meterconvert();
            inrange = true;
        }
        else
        {
            cout << endl << "Please enter 1 or 2" << endl << endl;
            inrange = false;
        }
    }

}

void poundsgramsconvert()
{

    int decision;
    bool inrange = false;
    while (inrange == false )
    {
        cout << "Would you like to convert Pounds to Grams (1)" << endl;
        cout << "Or Grams to Pounds? (2)" << endl;
        cin >> decision;
        if (decision == 1)
        {
            poundsconvert();
            inrange = true;
        }
        else if (decision == 2)
        {
            gramsconvert();
            inrange = true;
        }
        else
        {
            cout << endl << "Please enter 1 or 2" << endl << endl;
            inrange = false;
        }
    }
}

void lengthsorweights()
{
    int decision;
    bool inrange = false;
    bool done = false;
    char again;

    while (!done)
    {
        while (!inrange)
        {
            cout << "Would you like to convert lengths (1)" << endl;
            cout << "Or would you like to convert weights (2)" << endl;
            cin >> decision;
            if (decision == 1)
            {
                feetmeterconvert();
                inrange = true;
            }
            else if (decision == 2)
            {
                poundsgramsconvert();
                inrange = true;
            }
            else
            {
                cout << endl << "Please enter 1 or 2" << endl << endl;
                inrange = false;
            }

        }
        cout << "Would you like to try again? (y/n)" << endl;
        cin >> again;
        if (again == 'y' || again == 'Y')
        {
            done = false;
            inrange = false;
        }
        else
        {
            done = true;
        }
    }
}
