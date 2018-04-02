#ifndef POKERAI_H
#define POKERAI_H

#include <vector>
#include "pokerClasses.h"

using namespace std;

class pokerAI
{
public:
    pokerAI(){};

    virtual int bet(int game, int round,
                           int dealerNum, int playerNum,
                           vector<Player> players, vector<Card> communityCards,
                           int minBet, int pot,
                       vector<Card> cards) = 0;

    virtual void reveal(vector<Player> players, vector<vector<Card> > revealedHand) = 0;
};

#endif // POKERAI_H
