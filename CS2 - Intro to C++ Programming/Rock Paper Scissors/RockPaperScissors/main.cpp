#include <iostream>
#include <string>

//CH3 #1: Rock Paper Scissors

using namespace std;

int main()
{
    char player1choice; // whatever the user (player 1) inputs
    char player2choice; // whatever the user (player 2) inputs
    char rock; //rock
    char paper; //paper
    char scissor; //scissor
    bool done = false;
    char again;

    while (done == false)
    {

        cout << "Begin.. Will it be rock, paper, or scissors?" << endl;
        cout << "Player 1: Rock, Paper, or Scissors? Input:(R,P,S)" << endl;
        cin >> player1choice;    // player 1's choice
        switch(player1choice)    //switch for lower and upper case usage of choices for player 1
        {
        case 'R':
        case 'r':
            player1choice = rock;
            break;
        case 'P':
        case 'p':
            player1choice = paper;
            break;
        case 'S':
        case 's':
            player1choice = scissor;
            break;
        default: cout << "Player 1 is undefined" << endl;
        }


        cout << "Player 2: Rock, Paper, or Scissors? Input:(R,P,S)" <<endl;
        cin >> player2choice;
        switch(player2choice)//switch for lower and upper case usage of choices for player 2
        {
        case 'R':
        case 'r':
            player2choice = rock;
            break;
        case 'P':
        case 'p':
            player2choice = paper;
            break;
        case 's':
        case 'S':
            player2choice = scissor;
            break;
        default: cout << "Player 2 is undefined" << endl;
        }
        if (player1choice == (rock))
        {
            if (player2choice == (scissor))
                cout << "Player 1 wins, Rock breaks Scissors"<< endl;
            else if (player2choice == (paper))
                cout << "Player 2 wins, Paper Covers Rock"<< endl;
            else if (player2choice == (rock))
                cout << "Nobody Wins" << endl;
        }
        else if (player1choice == (paper))
        {
            if (player2choice == (rock))
                cout << "Player 1 wins, Paper covers Rock"<< endl;
            else if (player2choice == (scissor))
                cout << "Player 2 wins, Scissors cut Paper"<< endl;
            else if (player2choice == (paper))
                cout << "Nobody Wins" << endl;
        }
        else if (player1choice == (scissor))
        {
            if (player2choice == (paper))
                cout << "Player 1 wins, Scissor cuts Paper"<< endl;
            else if (player2choice == (rock))
                cout << "Player 2 wins, Rocks break Scissors"<< endl;
            else if (player2choice == (scissor))
                cout << ("Nobody Wins") << endl;
        }
        cout << "Try Again? y or n" << endl;        //Determines whether to loop or not.
        cin >> again;
        if (again == 'n')
            done = true;
        else
            cout << "MORE IT IS!" <<endl;
        cout << endl<< endl << endl;
    }
    return 0;
}

