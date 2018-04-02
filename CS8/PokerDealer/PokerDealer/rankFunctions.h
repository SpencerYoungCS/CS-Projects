#ifndef RANKFUNCTIONS_H
#define RANKFUNCTIONS_H
//  Alex Su's code
//  Written to use Cactus Kevin's poker hand evaluator
//  and Paul Senzee's optimized perfect hash modification
#include <vector>
#include <iostream>
#include "pokerClasses.h"
#include "fast_eval.h"

using namespace std;

short rank(vector<Card> myCards, vector<Card> communityCards);
short rank(vector<Card> allCards);
int eval_5hand_fast(vector<int> best5);
int convert(Card card);
void printBinary(int card);

//  finds the best 5 cards hand and returns the rank from both sets of card vectors
short rank(vector<Card> myCards, vector<Card> communityCards)
{
    vector<Card> allCards;

    //  adds all cards into one vector
    for (short i = myCards.size() - 1; i >= 0; i--)
        allCards.push_back(myCards[i]);
    for (short i = communityCards.size() - 1; i >= 0; i--)
        allCards.push_back(communityCards[i]);

    return rank(allCards);
}

//  takes in the all cards in one vector and finds the best
short rank(vector<Card> allCards)
{
    short totalCards = allCards.size();

    vector<int> best5;
    short bestRank = 7462;

    //  finds the best 5 card hand that can be made
    totalCards == 5 ? ({for (int i = allCards.size() - 1; i >= 0; i--)
                          {
                              best5.push_back(convert(allCards[i]));
                              bestRank = eval_5hand_fast(best5);
                          }
                         })
    : totalCards == 6 ? ({short currentRank;
                          for (int i = 0; i < COMB_6_SIZE; i++)
                          {
                              for (int j = 0; j < 5; j++)
                              {
                                  best5.push_back(convert(allCards[comb6[i][j]]));
                              }
                              currentRank = eval_5hand_fast(best5);

                              if (currentRank < bestRank)
                              {
                                  bestRank = currentRank;
                              }

                              best5.clear();
                          }
                         })
    : totalCards == 7 ? ({short currentRank;
                          for (int i = 0; i < COMB_7_SIZE; i++)
                          {
                              for (int j = 0; j < 5; j++)
                              {
                                  best5.push_back(convert(allCards[comb7[i][j]]));
                              }
                              currentRank = eval_5hand_fast(best5);

//                              cout << "i: " << i << "rank: " << currentRank << endl;
                              if (currentRank < bestRank)
                              {
                                  bestRank = currentRank;
                              }

                              best5.clear();
                          }
                         })
    : ({cout << "Number of cards incorrect" << endl << "You have " << totalCards << endl; throw 1;});

    return bestRank;
}

int eval_5hand_fast(vector<int> best5)
{
    return eval_5hand_fast(best5[0],
                    best5[1],
                    best5[2],
                    best5[3],
                    best5[4]);
}

int convert(Card card)
{
    short suitCorrection[] = { 2, 1, 3, 4 };

    int cardInfo = 0;

//    cout << "beg" << endl;
//    printBinary(cardInfo);

    //  sets the rank bit
    short rank = card.value - 2;

    if (rank == -1)
        rank = 12;

    cardInfo += 1;
    cardInfo <<= rank;

//    cout << "\nafter rank\n";
//    printBinary(cardInfo);

    //  sets the suit bit
    short suitShift = suitCorrection[card.suit];

    cardInfo <<= suitShift;
    cardInfo += 1;
    cardInfo <<= (4 - suitShift);

//    cout << "\nafter suit\n";
//    printBinary(cardInfo);

    //  sets the rank 4bit pattern
    cardInfo <<= 4;
    cardInfo += rank;

//    cout << "\nafter rank4\n";
//    printBinary(cardInfo);

    //  sets the prime number 8bit pattern
    cardInfo <<= 8;
    cardInfo += primes[rank];

//    printBinary(cardInfo);
    return cardInfo;
}

void printBinary(int card)
{
    unsigned int mask = 1;
    mask <<= 31;

    short counter = 0;
    while (mask > 0)
    {
        cout << (card == (card | mask) ? "1" : "0");
        mask >>= 1;

        cout << (++counter % 8 == 0 ? " " : "");

    }
}

#endif // RANKFUNCTIONS_H
