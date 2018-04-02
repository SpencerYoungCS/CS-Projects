#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "pokerClasses.h"
#include "pokerai.h"
#include <cmath>

class Human : public pokerAI
{
    int bet(int game, int round, int dealerNum, int playerNum,
            vector<Player> players, vector<Card> communityCards,
            int minBet, int pot, vector<Card> hand)
    {
//        system("cls");
        cout << endl << endl << endl;
        cout << "Game: " << game <<endl<< "Round: " << round <<  endl
             << "Pot: " << pot << endl << "Minimum Bet: " << minBet << endl<<endl;

        cout << "The dealer is player [" << dealerNum <<"]\n\n";

        for(int i = 0; i < players.size(); ++i)
        {
            if (!players[i].inRound)
                continue;
            Player player = players[i];
            cout << "Player [" << i
                 << "]  " << "Total Money: " << player.total_money << endl
                 << "  " << "Bet Amount: " << player.bet_amount << endl<<endl;
        }
        cout << "*****PLAYER [" << playerNum << "] TURN*****\n\n";

        cout<< "COMMUNITY CARDS: ";
        if (communityCards.size() == 0)
            cout<<" n/a\n\n";
        else
        {
            for (int i = 0; i < communityCards.size(); i++)
                cout<<communityCards[i];
            cout << endl << endl;
        }

        if(hand.size() == 2)
        {
            cout << "YOUR HAND: " << hand[0] << hand[1] << endl<<endl;
        }


        int hiBet = getHighBet(players);
        int prevBet = players[playerNum].bet_amount;
        int total = players[playerNum].total_money;

//        cout << prevBet << endl;

        cout << "To call: " << hiBet - prevBet << endl << endl;

        int bet_amount;
        do
        {
            cout << "ENTER YOUR BET: ";
            cin >> bet_amount;
            if (bet_amount > total + prevBet)
                cout << "Your bet was more than your total money, please place another bet...\n";
            //  should allow for folding
            else if (bet_amount < 0)
                cout << "Your bet can not be negative, please place another bet...\n";
            else if (bet_amount > 0 && bet_amount < (minBet - prevBet))
                cout << "Your bet was below the minimum, please place another bet...\n";
        } while (bet_amount > total
                 || (bet_amount > 0 && bet_amount < min((minBet - prevBet), (total - prevBet)))
                 || bet_amount < 0);

        cout << "\n--------------------------------------------------\n\n";

//        cout << bet_amount << endl << prevBet << endl << bet_amount + prevBet << endl;

        return (bet_amount + prevBet);
    }

    int getHighBet(vector<Player> players)
    {
        int hiBet = 0;
        for (int i = players.size() - 1; i >= 0; i--)
            if (players[i].bet_amount > hiBet)
                hiBet = players[i].bet_amount;

        return hiBet;
    }

    void reveal(vector<Player> players, vector<vector<Card> > revealedHand){}
};

#endif
