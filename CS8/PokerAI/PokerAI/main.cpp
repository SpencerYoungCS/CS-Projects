#include <iostream>
#include "pokerClasses.h"
#include "pokerai.h"
#include "humanplayer.h"
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

bool stillBetting(vector<Player> players, vector<bool> inRound,
                  double highBet
                  );

// Instantiate your classes here if necessary //

int main()
{
    // setup
    int game = 0;
    int numPlayers = 2;
    srand(time(NULL));

    //  initialize minBet & also update it every so often
    int minBet;

//    vector<Player> players;
//    for(int i=0; i<numPlayers; i++)
//    {
//        Player player(5000.00);
//        players.push_back(player);
//    }

    //  this keeps tracks of which player is which after erasing
    vector<int> playerNum;
    for (int i = 0; i < numPlayers; i++)
    {
        playerNum.push_back(i);
    }

    //  initiate list of ai
    vector<pokerAI*> ai;
    //  push back reference of all ai
    //ai.push_back(new alexPokerAI());
//    ai.push_back(new Human());
//    ai.push_back(new Human());

    if (ai.size() != numPlayers)
    {
        cout << "Incorrect number of AI" << endl;
        exit(1);
    }

    // game loop
    while(game < 2)
    {
        // create a new deck
        Deck deck;
        // create a new pot
        double pot = 0.0;
        //  updates player size
//        numPlayers = players.size();
        //  reset everything
        vector<Card> community_cards;
        vector< vector<Card> > cards;
        //  creates a new still in vector (checks whether players are in the round)
        vector<bool> inRound;
        for (int i = 0; i < numPlayers; i++)
        {
            cards.push_back(vector<Card>());
            inRound.push_back(true);
        }

        // for each round....
        for(int round = PreFlop; round <= River; ++round)
        {
            if (round == PreFlop)
            {
                //  deal each player cards
                for (int i = 0; i < numPlayers; i++)
                {
                    //  deal 2 cards per player
                    for (int j = 0; j < 2; j++)
                    {
                        cards[i].push_back(deck.deal());
                    }
                }
            }
            else if (round == Flop)
            {
                // deal the community cards
                for(int i=0; i<3; ++i)
                {
                    community_cards.push_back(deck.deal());
                }
            }
            else // (round == Turn || round == River)
            {
                community_cards.push_back(deck.deal());
            }

            // bet loop.. keep betting until everyone has the same bet, or they fold
            // aka bet of 0

            //  keeps track of highest bet
            double highBet = 0.0;
            double betAmt;

            do
            {
                for (int i = 0; i < numPlayers; i++)
                {
                    if (inRound[i]) // vector<bool> inRound -   keeps track of which players are still in the round
                    {
                        betAmt = players[i].bet_amount = ai[i]->bet(game, round,
                                                                    game % numPlayers,            //  dealer position - NEED TO EDIT THIS
                                                                    i,                            //  player position
                                                                    players, community_cards,     //  vector of player bets/money & community cards
                                                                    minBet, pot,
                                                                    cards[i]);                    //  vector of player cards
                    }

                    //  keeping track of highest bet (raise)
                    if (betAmt > highBet)
                    {
                        highBet = betAmt;
                        players[i].total_money -= betAmt;
                    }
                    //  player called
                    else if (betAmt == highBet)
                    {
                        players[i].total_money -= betAmt;
                    }
                    //  determine if player folded, or all in
                    else if (betAmt < highBet)
                    {
                        // player is all in...
                        if (betAmt != players[i].total_money)
                        {
                            inRound[i] = false;
                        }
                        // if player made a bet below the last one... automatically fold
                        else 
                        {
                            inRound[i] = false;
                        }
                    }
                }
            } while(stillBetting(players, inRound, highBet));
            //  checks to see if players are still betting

            // after all the bets, clear everyone's bet, add it to the pot
            for (int i = 0; i < numPlayers; i++)
            {
                //  update player money & pot
                double betAmt = players[i].bet_amount;
                pot += betAmt;
                players[i].bet_amount = 0;

                //  check to see if player is out of the game
                if (players[i].total_money == 0)
                {
                    //  erase the player from all lists
                    delete ai[i];
                    ai.erase(ai.begin() + i);
                    players.erase(players.begin() + i);
                    playerNum.erase(playerNum.begin() + i);
                }

            }
        }

        //  WIP
        //  determine winner
        //  maybe another vector to save winners if there are multiple?
        //  int winner = findWinner(community_cards, cards);
        //  give him pot
        //  players[winner].total_money += pot;

        ++game;

        cout << "==================" << endl;
    }


    //  deletes dynamic memory
    for (int i = ai.size() - 1; i >= 0; i--)
    {
        delete ai[i];
    }

    return 0;
}

bool stillBetting(
        vector<Player> players,
        vector<bool> inRound,
        double highBet
        )
{
    //  goes through all players and checks if they have finished betting
    for (int i = players.size() - 1; i >= 0; i--)
    {
        //  if player is still in the round
        if (inRound[i])
        {
            //  check if the player has not met the high bet
            if (players[i].bet_amount != highBet)
            {
                //  check if players are not all in
                if (players[i].bet_amount != players[i].total_money)
                {
                    //  therefore players still need to take action
                    return true;
                }
            }
        }
    }
    //  else return false
    return false;
}
