#include <iostream>

// CH5 #5: Coins

using namespace std;

void compute_coins(int coin_value, int &num, int &amount_left);

int main()
{
    int amt_left;
    int amt;
    bool done = false;
    char again;

    while (!done)
    {
        cout << "Enter the amount you want changed (1-99)" << endl;
        cin >> amt_left;
        while (amt_left > 99 || amt_left < 1)
        {
            cout << "Please enter an amount between 1 and 99" << endl;
            cin >> amt_left;
        }
        compute_coins(25, amt, amt_left);

        cout << "Quarters: " << amt <<endl;

        compute_coins(10, amt, amt_left);

        cout << "Dimes: " << amt << endl;

        compute_coins(1, amt, amt_left);
        cout << "Pennies: "<< amt << endl;


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

void compute_coins(int coin_value, int &num, int &amount_left)
{
    num = amount_left/coin_value;
    amount_left = amount_left - (num*coin_value);
}

