#ifndef SPENCERAI
#define SPENCERAI

#include "pokerClasses.h"
#include "pokerai.h"
#include "time.h" //using a random number generator based off time
#include <cstdlib>



//----------------------------HAND EVAULTATION CODE------------------------------------


#include <cmath> // use for absolute value

enum position{early, middle, late}; //will use this to determine my position

int HandPotential(vector<Card> hand, vector<Card> communityCards);
int HandStrength(vector<Card> hand); // i will be implementing the chen method of hand strength
int PotOdds(int pot, int bet); // this function will be used to determine the pot odds for my rate of return, which will dictate whether
// i fold call or raise
int RateOfReturn(int HandStrength, int PotOdds); //
double LearningModifier(); // this will change the rate of return by a fraction based on opponents decision
int ReEvaluation(vector<Player>players, int handStrength, int minBet);
position mylocation(vector<Player> players, int playernum); //this will determine where i sit and how it will affect my betting;
// this will count as my hand re-evaluation as well
int CurrentBet(vector<Player>players); //keeps track of the current bet
void MergeSort(vector<Card> &A, int low, int high); // will be using a sort to find straights for hand potential
void merge(vector<Card> &A, int low, int high, int mid);
vector<Card> CombinedCards(vector<Card> hand, vector<Card> communityCards);

//-------------txt files for learning
//void writeBinaryTree(binary_tree_node<string> *p, ofstream &toFile);
//void loadBinaryTree(binary_tree_node<string> *&current_ptr, ifstream &fromFile);
//----------------------------------

int HandPotential(vector<Card> hand, vector<Card> communityCards){
    //checking for same value cards..
    //initializing booleans....

    bool fourofakind = false;
    bool threeofakind = false;
    //    bool fullhouse = false;
    bool Pair = false;
    int score = 0;

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


    if(fourofakind)
        score = 10;
    else if (threeofakind)
        score = 7;
    else if (Pair)
        score = 4;

    //    return score;
    //now we need a way to calculate straights and flushes
    //first ill join hand with community cards, and sort them; then compare each one with the next. increase a counter if there is no gap.
    //if there is a gap reset the counter... if the counter hits 5, then we have a straight.

    vector<Card> Combined; //combining both the hand and community cards into one vector for evaulation
    Combined = CombinedCards(hand,communityCards);
    int StraightCounter = 0;
    int LargestStraight = 0; //7 being the highest (nearly impossible)... 5 being preferable... anything below 4 isnt worthwhile

    for(int i = 0; i < Combined.size(); i++){
        if(Combined[i+1].value){//dont run into the null...
            if(Combined[i].value == Combined[i+1].value + 1) // if pair do nothing
            {
                StraightCounter++; //as soon as we find a connector, we increase the counter
                if(StraightCounter > LargestStraight) //if the counter is higher than the largest linked straight counter, then it is our new largest connector
                    LargestStraight = StraightCounter;
            }
            else if(Combined[i].value == Combined[i+1].value) // if pair do nothing
            {}
            else
                StraightCounter = 0;
        }
    }

    //now i know a straight is worth more than a 3 of a kind... but less than a 4 of a kind.... this gives
    //me an idea of how i should value straights
    if(LargestStraight >= 4)
        score = score + 3 + LargestStraight;
    else if(LargestStraight == 3)
        score = score + 3;


    int NumSpade = 0;
    int NumClub = 0;
    int NumHeart = 0;
    int NumDiamond = 0;

    //now lastly, i need check suits.
    for(int i = 0; i < Combined.size(); i++){
        switch(Combined[0].suit){
        case Spade:
            NumSpade++;
            break;
        case Club:
            NumClub++;
            break;
        case Heart:
            NumHeart++;
            break;
        case Diamond:
            NumDiamond++;
            break;
        default:
            cout << "Error Suit Does not exist!!" << endl;
            break;
        }
    }
    //i know that flush is worth just abit more than a straight,
    if(NumSpade || NumClub || NumHeart || NumDiamond > 2)
        score = score +  8;

    return score; //any worthwhile hand is > 6.


}

int HandStrength(vector<Card> hand){
    //using the bill chen formula

    int score = 0;

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
    int total_players = 0;
    total_players = players.size();

    int earlyseat = 0; // these ints will be the threshold before early becomes middle
    int middleseat = 0;
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


int PotOdds(int pot, int bet){
    int pot_odds = 0;

    if(pot == 0)
        return 0;
    else
        pot_odds = bet/(bet+pot);
    return pot_odds;

}


int RateOfReturn(int HandStrength, int PotOdds){
    int RR = 0;

    if(PotOdds == 0)
        return 0;
    else
        RR = HandStrength/PotOdds;

    return RR;

}

int ReEvaluation(vector<Player> players, int handStrength, int minBet){

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

int CurrentBet(vector<Player> players){
    int largest_bet = 0;
    //I need a way to keep track of the current bet.... minbet does not correlate to previous bets
    for(int i = 0; i != players.size(); i++){ // check everyones bet so i dont bet under them...
        //        cout << "everyones bet amount: " <<  players[i].bet_amount << endl;
        if(players[i].bet_amount > largest_bet)
            largest_bet = players[i].bet_amount;
    }
    return largest_bet;

}

vector<Card> CombinedCards(vector<Card> hand, vector<Card> communityCards){
    vector<Card> temp;
    temp = hand;
    for(int i = 0; i < communityCards.size(); i++)
        temp.push_back(communityCards[i]);

    return temp;
}

void MergeSort(vector<Card> &A, int low, int high){
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        merge(A,low,high,mid);
    }
    return;
}

void merge(vector<Card> &A, int low, int high, int mid){
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (A[i].value < A[j].value)
        {
            c[k] = A[i].value;
            k++;
            i++;
        }
        else
        {
            c[k] = A[j].value;
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = A[i].value;
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = A[j].value;
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        A[i].value = c[i];
    }
}



//--------------------------------------------------------------------------------------------------------



class SpencerAI : public pokerAI
{
    int bet(int game, int round, int dealerNum, int playerNum,
            vector<Player> players, vector<Card> communityCards,
            int minBet, int pot, vector<Card> hand){

        //-------------initialize random number and seed for anti-prediction
        srand(time(NULL));
        int randomNum = rand() % 100;
//        cout << "randomNum: " << randomNum << endl;

        //--------------------------------

        int bet_amount = 0;
        int Pot_odds = 0;
        int hand_strength = 0;
        int Rate_Of_Return = 0;
        int largest_bet = 0; // this is to keep track of what the current bet is at in game
        //now where going to use our hand evaluator score with our seating position to alter our chances of raising/calling/folding
        hand_strength = HandStrength(hand);
        largest_bet = CurrentBet(players);

        //using chen's formula ... position will alter my decision
        if(location(players,playerNum) == early){
            if(hand_strength >= 8)
                bet_amount = minBet + largest_bet + pot*0.25; // raise
            else if(hand_strength == 7)
                bet_amount = largest_bet; // call
            else
                bet_amount = 0;
        }


        else if(location(players,playerNum) == middle){
            if(hand_strength >= 8)
                bet_amount = minBet + largest_bet + pot*0.25; //raise
            else if(hand_strength == 6)
                bet_amount =  largest_bet; //call
            else
                bet_amount = 0;
        }

        else if(location(players,playerNum) == late){
            if(hand_strength >= 8)
                bet_amount = minBet + largest_bet + pot*0.25; //raise
            else if(hand_strength == 5)
                bet_amount = largest_bet; //call
            else
                bet_amount = 0;
        }

        // if chen's formula went through well start using hand potential...
        if(bet_amount > 0){

        }

        //-------------------------------
        //Rate of Return = Hand Strength / Pot Odds.
        Pot_odds = PotOdds(pot, bet_amount);
        Rate_Of_Return = RateOfReturn(hand_strength, Pot_odds);

        //-------rate of return will determine whether or not i can (somewhat) safely bluff------

//        cout << "Pot Odds: " << Pot_odds << endl;
//        cout << "hand_strength: " << hand_strength << endl;

//        cout << "Rate of Return: " << Rate_Of_Return << endl;


        if(Rate_Of_Return < 40) //based on testing, 100 is greatest odds, 10 is lowest odds
        {
            //unfavorable odds, low chance of bluffing but still possible
            if(randomNum < 2) //1% chance of all in
                bet_amount = players[playerNum].total_money;
            else if(randomNum < 10) //10% chance of bluffing
                bet_amount = bet_amount + minBet + pot*0.25;
        }

        else if(Rate_Of_Return >= 40 && Rate_Of_Return <= 70){
            if(randomNum < 5) //5% chance of all in
                bet_amount = players[playerNum].total_money;
            else if(randomNum < 25) //25% chance of bluffing
                bet_amount = bet_amount + minBet + pot*0.25;
        }

        else if(Rate_Of_Return > 70){
            if(randomNum < 10) //10% chance of all in
                bet_amount = players[playerNum].total_money;
            else if(randomNum < 50){ //50% of raising
                bet_amount = bet_amount + minBet + pot*0.50;
            }
        }

        //so basically rate of return is a modifier to my betting that keeps the AI from being too predictable
        //it will preferrable to stay in hands where the return is favorable as well as giving itself a small
        //chance to even bluff a raise, and in even more rare cases, all in.



        //now i have to fit in hand potential to see if i want to stay in the game or fold based on my opponents bets
        //first i have to assume i was going to bet to begin with....

        //first create the text files

//        if (bet_amount > 0){
//            while(round > 0) //if were going deeper into the round...
//                if(largest_bet > 0){

//                    if(HandPotential(hand,communityCards) > 6){
//                       //do nothing
//                    }
//                    else{
//                        //implement learning algo

//                    }

//            }
//        }



        //now i have to make sure i didnt bet more than what i have
        if(bet_amount > players[playerNum].total_money)
            bet_amount = players[playerNum].total_money;

        //---------------------------TESTING PURPOSES IGNORE-------------------------

//        cout << endl;

//        cout << "------------------SPENCER AI-------------------" << endl;

//        cout << "Spencer's Hand: " << hand[0] << "|" << hand[1] << endl;
//        cout << "SpencerAI, Hand Strength: " << hand_strength << endl;
//        cout << "SpencerAI, Player[" << playerNum << "] is betting: " << bet_amount << endl;
//        cout << "Spencer's Total Money: " << players[playerNum].total_money << endl;
//        cout << "Spencer's Bet Amount: " << bet_amount << endl;
//        cout << "-----------------------------------------------" << endl;

        //---------------------------------------------------------------------------

        return bet_amount;
    }
    void reveal(vector<Player> players, vector<vector<Card> > revealedHand){}
};

#endif // SPENCERAI
