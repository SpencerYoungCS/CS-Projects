#include <iostream>
#include <string>

using namespace std;
int main()
{
    string command; //cin string for different commands
    int yes;
    cout << "Welcome to Spencer's Text Adventure!" << endl; //Intro
    cout << "Enter 1 to proceed" << endl;
    cin >> yes;
    if (yes == 1)
    {
        cout << endl << endl << endl << endl; // Fancy Spacing
        cout << "Lets Proceed..." << endl;
        cout << endl << endl << endl << endl; // Fancy Spacing
        cout << "After a long day of work, you decide to go to get rest at home." << endl;
        cout << "You thought you heard whispering but decided to ignore it and" << endl;
        cout << "fall into deep sleep due to exhaustion" << endl;
        cout << endl << endl; // Fancy Spacing
        cout << "You wake up the next morning to find yourself in a completely" << endl;
        cout << "different room." << endl;
        cout << endl << endl << endl << endl; // Fancy Spacing
        cout << "Type options to see your available commands" << endl;
        cout << endl << endl;
        yes = 0;
        cin>> command;
        switch (command)
        {
        case "option": cout << "enter u for up";
            break;
        default: cout << "nothing" << endl;
        }
    }
    else
    {
        cout << endl << endl << endl << endl; // Fancy Spacing
        cout << "Why are you even here? Get out!" << endl;
        cout << endl << endl << endl << endl; // Spacing

    }
}
    // If they type "options" a list options are available

//    cin >> command;
//    if (command == "option")
//    {
//        cout << "Eat" << endl;
//        command = command
//    }
//    else
//    {
        //do nothing
//    }




//    cout << endl << endl << endl << endl; // Spacing
//    return 0;
//}
