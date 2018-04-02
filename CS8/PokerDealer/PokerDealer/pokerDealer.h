#ifndef POKERDEALER_H
#define POKERDEALER_H

#include <iostream>
#include "pokerClasses.h"
#include "pokerai.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

class pokerDealer
{
public:
    pokerDealer(int _startChips = 5000, int _min = 5);
    ~pokerDealer();

    //  game types
    void tournament(int maxGame = 150);
    void handByHand(int maxGame = 150);

    //  accessor
    int getMin();
    int getStartChips();
    //  mutator
    void push_back(pokerAI* ai, string name);
    void setMin(int min);
    void setStartChips(int chips);
private:
    //  checks to see if there's only one player
    bool onlyOne();

    //  updates the dealer to be the next valid player
    void updateDealer();
    //  adjusts starting position based on round
    int adjust(int round);
    //  sets the blinds up for the game
    void setBlind(int minBet);
    //  updates gross
    void updateGross(vector<int>& gross);

    //  handles preflop to river
    void preflopToRiver(int minBet);
    //  makes sure the bet is valid
    void checkBet(int &betAmt, int& highBet, Player &player);
    //  checks to see if players are still betting
    bool stillBetting(int highBet);

    //  determines winner
    //  returns vector of winner positions
    //  also keeps track of players that revealed their cards
    void showdown();
    //  splits pot and distributes to winner
    void giveWinning();
    //  reveal necessary cards to all ai
    void revealToAI();
    //  output to screen all revealed cards
    void outputRevealedCards();
    //  output to console who won how many chips and with what
    void outputWinner();
    //  output community cards to console
    void outputCommunity();

    //  sets up variables for next game
    void newGame(int minBet);
    //  clear all necessary card vectors for next game
    void clearCards();
    //  resets all variables
    void reset();
    //  resets chip
    void chipReset();

    int startChips;
    int minimum;

    int game;
    int dealerPos;

    int pot;

    vector<pokerAI*> ai;
    vector<Player> players;

    vector<Card> community;
    vector< vector<Card> > hands;

    vector<int> winner;
    vector<Player> playerReveal;
    vector< vector<Card> > handReveal;
};

#endif // POKERDEALER_H
