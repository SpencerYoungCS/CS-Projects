#ifndef HANDEVALUATOR
#define HANDEVALUATOR

#include "pokerClasses.h"
#include "pokerai.h"

#include <cmath> // use for absolute value

enum position{early, middle, late}; //will use this to determine my position

double HandPotential(vector<Card> hand, vector<Card> communityCards);
double HandStrength(vector<Card> hand); // i will be implementing the chen method of hand strength
double PotOdds(double pot, double bet); // this function will be used to determine the pot odds for my rate of return, which will dictate whether
// i fold call or raise
double RateOfReturn(double HandStrength, double PotOdds); //
double LearningModifier(); // this will change the rate of return by a fraction based on opponents decision
double ReEvaluation(vector<Player>players, double handStrength, double minBet);
position mylocation(vector<Player> players, int playernum); //this will determine where i sit and how it will affect my betting;
// this will count as my hand re-evaluation as well
double CurrentBet(vector<Player>players); //keeps track of the current bet

void MergeSort(vector<Card> &A, int low, int high); // will be using a sort to find straights for hand potential
void merge(vector<Card> &A, int low, int high, int mid);
vector<Card> CombinedCards(vector<Card> hand, vector<Card> communityCards);



double HandPotential(vector<Card> hand, vector<Card> communityCards){
    //checking for same value cards..

    //initializing booleans....
    bool fourofakind = false;
    bool threeofakind = false;
    //    bool fullhouse = false;
    bool Pair = false;

    //    for(int i = 0; i < 2; i++){
    for(int j = 0; j < communityCards.size(); j++){ //evaluating first card with the rest of the community cards
        if(hand[0].value == hand[j].value){
            if(threeofakind) //if three of a kind already exists....
                fourofakind = true; //then there is 4!
            else if(Pair) //if pair exists.. then three of a kind exists
                threeofakind = true;
            else //if none existed before, we now have a pair
                Pair = true;
        }
    }

    //lets make sure both cards werent pairs...
    if(hand[0].value == hand[1].value){
        if(threeofakind)
            fourofakind = true;
        else if(Pair)
            threeofakind = true;
        else
            Pair = true;
    }

    for(int j = 0; j < communityCards.size(); j++){
        if(hand[1].value == hand[j].value){
            if(threeofakind) //if three of a kind already exists....
                fourofakind = true; //then there is 4!
            else if(Pair) //if pair exists.. then three of a kind exists
                threeofakind = true;
            else //if none existed before, we now have a pair
                Pair = true;
        }
    }

    //will have to make my own scoring rubic...
    //four of a kind will be highest .... 10 points....
    //pair will be 2 points... 3 of a kind will be 7 points....

    double score = 0.0;

    if(fourofakind)
        score = 10;
    else if (threeofakind)
        score = 7;
    else if (Pair)
        score = 4;
    else
        score = 2;

    //    return score;
    //now we need a way to calculate straights and flushes
    //first ill join hand with community cards, and sort them; then compare each one with the next. increase a counter if there is no gap.
    //if there is a gap reset the counter... if the counter hits 5, then we have a straight.


}

double HandStrength(vector<Card> hand){
    //using the bill chen formula

    double score = 0.0;

    //determining score for highest card and suit.....

    int highercard = 0;

    if(hand[1].value > hand[0].value){
        highercard++;
    }

    if(hand[highercard].value == 1)
        score = score + 10;
    else if(hand[highercard].value == 13)
        score = score + 8;
    else if(hand[highercard].value == 12)
        score = score + 7;
    else if(hand[highercard].value == 11)
        score = score + 6;
    else if(hand[highercard].value >= 2 && hand[highercard].value <= 10)
        score = score + hand[highercard].value/2;

    //if pairs, multiply score by 2
    if(hand[0].value == hand[1].value)
        score = score*2;

    //gap and suited analysis...

    //if suited, add 2 points to highest card score
    if(hand[0].suit == hand[1].suit)
        score = score + 2;

    //if connector, add 1 point and take into account ace and king are connectors
    if(abs(hand[0].value - hand[1].value) == 1
                    || abs(hand[0].value - hand[1].value == 12))//absolute value of difference
        score = score + 1;
    //basically if the gap is 12, then it has to be ace and king


    //now to subtract the scores based on the size of the gap
    //since this will weaken our hand strength


    if(abs(hand[0].value - hand[1].value) == 2)
        score--; // 1 gap
    else if(abs(hand[0].value - hand[1].value) == 3)
        score = score - 2; // 2 gap
    else if(abs(hand[0].value - hand[1].value) == 4)
        score = score - 4; // 3 gap
    else if(abs(hand[0].value - hand[1].value) >= 5)
        score = score - 5; // 4 or more gap


    return score;

}

position location(vector<Player> players, int playernum){
    double total_players = 0.0;
    total_players = players.size();

    double earlyseat = 0.0; // these doubles will be the threshold before early becomes middle
    double middleseat = 0.0;
    //any seat after middle seat is late
    //now divide by 3 since there is only early, middle, and late

    earlyseat = total_players/3;
    middleseat = earlyseat * 2;

    //now compare my seat to the 3 locations
    if(playernum <= earlyseat)
        return early;
    else if(playernum > earlyseat && playernum <= middleseat)
        return middle;
    else
        return late;

}


double PotOdds(double pot, double bet){
    double pot_odds = 0.0;
    pot_odds = bet/(bet+pot);
    return pot_odds;

}


double RateOfReturn(double HandStrength, double PotOdds){
    double RR = 0.0;
    RR = HandStrength/PotOdds;

    return RR;

}

double ReEvaluation(vector<Player> players, double handStrength, double minBet){

    for(int i = 0; i != players.size(); i++){
        if(players[i].bet_amount > minBet)
            cout<< endl;//load learning file. if they tend to bluff then go ahead with bet
        else if(players[i].bet_amount == 0)
            cout << endl;//load learning file. if they tend to fold then bluff
    }
}

//make a function that takes a player. from there it will read and write a txt file using using a tree. a txt file for each player;

double LearningModifier(){
    double returnModifier = 0.0;


}

double CurrentBet(vector<Player> players){
    double largest_bet = 0.0;
    //I need a way to keep track of the current bet.... minbet does not correlate to previous bets
    for(int i = 0; i != players.size(); i++){ // check everyones bet so i dont bet under them...
        cout << "everyones bet amount: " <<  players[i].bet_amount << endl;
        if(players[i].bet_amount > largest_bet)
            largest_bet = players[i].bet_amount;
    }

    return largest_bet;

}

vector<Card> CombinedCards(vector<Card> hand, vector<Card> communityCards){
    vector<Card> temp = new vector<Card>;
    //first put hand into the temp
    for(int i = 0; i < hand.size(); i++){
        temp[i] = hand[i];
    }


    int i = hand.size(); // now add on the community cards to temp

    for(int j = 0; j < communityCards.size(); i++){
        temp[i] = communityCards[j];
        i++;
    }
    return temp;
}

void MergeSort(vector<Card> &A, int low, int high){
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(A,low,mid);
        mergesort(A,mid+1,high);
        merge(A,low,high,mid);
    }
    return;
}

void merge(vector<Card> &A, int low, int high, int mid){
    //spencer! look here! to do....
    //finish merge sort then use the sorted list to determine if i have a straight by using a counter that increases each time the next
    //number is greater by 1. if the counter is 5, use max score. etc. use this in the hand potential function above!
    //basically if high potential... then we will stay in game.
    // then finish implementing my tree where it will adjust bluffs or folds.

}

#endif // HANDEVALUATOR

