#include <iostream>
#include "pokerDealer.h"
#include "humanplayer.h"

//  ALEX DUNN's

//#include "alexAI/alexpokerai.h"
//#include "dunnAI/AlexDunnPokerAI.h"
//#include "benAI/benPoker.h"
#include "spencerai.h"
//#include "emmaAI/ai_eb.h"

using namespace std;

// Instantiate your classes here if necessary

int main()
{
    //            startchips, chip amount
    pokerDealer dealer(20000, 100);

    //                  ai,             name of ai
//    dealer.push_back(new alexPokerAI, "Loc");
    dealer.push_back(new SpencerAI , "Spencer");
    dealer.push_back(new SpencerAI , "Young");
    dealer.push_back(new SpencerAI , "Younger");
//    dealer.push_back(new Human, "Alex");
//    dealer.push_back(new Human, "Jason");

    //  last man standing
    dealer.tournament(3000);

    //  different play style
    //  chips reset after every hand
//    dealer.handByHand(3000);
}
