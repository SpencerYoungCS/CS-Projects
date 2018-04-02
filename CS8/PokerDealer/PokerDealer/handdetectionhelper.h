#ifndef HANDDETECTIONHELPER
#define HANDDETECTIONHELPER

#include <sstream>
#include "pokerClasses.h"

enum Type {HighCard, Pair, TwoPair, Trip, Straight, Flush, FullHouse, Quad, StraightFlush};

bool checkPair(int& pairRank, vector<Card> hand, string& handString);
bool checkTwoPair(vector<Card> hand, string& handString);
bool checkTrips(int& tripRank, vector<Card> hand, string& handString);
bool checkStraight(vector<Card> hand, string& handString);
bool checkFlush(vector<Card> hand, string& handString);
bool checkFullHouse(vector<Card> hand, string& handString);
bool checkQuads(vector<Card> hand, string& handString);
bool checkStraightFlush(vector<Card> hand, string& handString);
int findHighCardInFlush(Suit s, vector<Card> hand);

//converts a vector of cards into a handString.
//handString is based on the type of hand and descriptive features of that hand


bool checkStraight(vector<Card> hand, string& handString)
{
    stringstream s;
    int lineEmUp = 0;
    int highCard;
    bool straight = false;

    for (int i = 0; i < 4; i++)
    {
        if (hand[i+1].value == hand[i].value+1)
            lineEmUp++;

        if (lineEmUp == 4)
        {
            highCard = hand[4].value;
            straight = true;
        }
    }
    lineEmUp = 0;
    for (int i = 1; i < 5; i++)
    {
        if (hand[i+1].value == hand[i].value+1)
            lineEmUp++;

        if (lineEmUp == 4)
        {
            highCard = hand[5].value;
            straight = true;
        }
    }
    lineEmUp = 0;
    for (int i = 2; i < 6; i++)
    {
        if (hand[i+1].value == hand[i].value+1)
            lineEmUp++;

        if (lineEmUp == 4)
        {
            highCard = hand[6].value;
            straight = true;
        }
    }
    if (straight)
    {
        s<<Straight<<hex<<highCard;
        s>>handString;
        return true;
    }
    return false;
}

bool checkQuads(vector<Card> hand, string& handString)
{
    stringstream s;
    int quads = 0;
    for (int i = 0; i < hand.size(); i++)
    {
        int current = hand[i].value;
        for (int j = 0; j < hand.size(); j++)
        {
            if (j != i && hand[j].value == current)
                quads++;
        }
        if(quads == 3)
        {
            s<<Quad<<current;
            s>>handString;
            return true;
        }
        quads = 0;
    }
    return false;
}

bool checkFullHouse(vector<Card> hand, string& handString)
{
    stringstream s;
    int tripRank;
    int dummy;
    if (checkTrips(tripRank, hand, handString))
    {
        if (checkPair(dummy, hand, handString))
        {
            s<<FullHouse<<hex<<tripRank;
            s>>handString;
            return true;
        }
    }
    return false;
}

bool checkTwoPair(vector<Card> hand, string& handString)
{
    stringstream s;
    int pair1Rank;

    if (checkPair(pair1Rank, hand, handString))
    {
        int pair = 0;
        for (int i = 0; i < hand.size(); i++)
        {
            int current = hand[i].value;
            for (int j = 0; j < hand.size(); j++)
            {
                if (j != i && hand[j].value == current && hand[j].value != pair1Rank)
                    pair++;
            }
            if(pair == 1)
            {
                s<<TwoPair;
                if(current>pair1Rank)
                    s<<hex<<current<<hex<<pair1Rank;
                else
                    s<<hex<<pair1Rank<<hex<<current;
                s>>handString;
                return true;
            }
            pair = 0;
        }
    }
    return false;
}

bool checkPair(int& pairRank, vector<Card> hand, string& handString)
{
    stringstream s;
    int pair = 0;
    for (int i = 0; i < hand.size(); i++)
    {
        int current = hand[i].value;
        for (int j = 0; j < hand.size(); j++)
        {
            if (j != i && hand[j].value == current)
                pair++;
        }
        if(pair == 1)
        {
            pairRank = current;
            s<<Pair<<hex<<current;
            s>>handString;
            return true;
        }
        pair = 0;
    }
    return false;
}

bool checkTrips(int& tripRank, vector<Card> hand, string& handString)
{
    stringstream s;
    int trips = 0;
    for (int i = 0; i < hand.size(); i++)
    {
        int current = hand[i].value;
        for (int j = 0; j < hand.size(); j++)
        {
            if (j != i && hand[j].value == current)
                trips++;
        }
        if(trips == 2)
        {
            tripRank = current;
            s<<Trip<<hex<<current;
            s>>handString;
            return true;
        }
        trips = 0;
    }
    return false;
}

bool checkStraightFlush(vector<Card> hand, string& handString)
{
    if (checkFlush(hand, handString))
    {
        if (checkStraight(hand, handString))
        {
            handString[0] = '8';
            return true;
        }
    }
    return false;
}

bool checkFlush(vector<Card> hand, string& handString)
{
    stringstream s;
    int diamond = 0, club  = 0, heart = 0, spade = 0;
    for (int i = 0; i < hand.size(); i++)
    {
        Suit s = hand[i].suit;
        switch (s)
        {
        case Diamond:
            diamond++;
            break;
        case Club:
            club++;
            break;
        case Heart:
            heart++;
            break;
        case Spade:
            spade++;
            break;
        }
    }
    if (diamond > 4)
    {
        s << FullHouse << hex<<findHighCardInFlush(Diamond, hand);
        s >> handString;
        return true;
    }
    else if (club > 4)
    {
        s << FullHouse << hex<<findHighCardInFlush(Club, hand);
        s >> handString;
        return true;
    }
    else if (heart > 4)
    {
        s << FullHouse << hex<<findHighCardInFlush(Heart, hand);
        s >> handString;
        return true;
    }
    else if (spade > 4)
    {
        s << FullHouse << hex<<findHighCardInFlush(Spade, hand);
        s >> handString;
        return true;
    }
    return false;
}

int findHighCardInFlush(Suit s, vector<Card> hand)
{
    int highCard = 0;
    for (int i = 0; i < hand.size(); i++)
    {
        if (hand[i].suit == s)
            if(hand[i].value > highCard)
                highCard = hand[i].value;
    }
    return highCard;
}

#endif // HANDDETECTIONHELPER

