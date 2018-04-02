#include "pokerDealer.h"
#include "rankFunctions.h"
#include "poker.h"

pokerDealer::pokerDealer(int _startChips, int _min)
{
    srand(time(NULL));

    startChips = _startChips;
    minimum = _min;
}

pokerDealer::~pokerDealer()
{
    //  deletes dynamic memory
    for (int i = ai.size() - 1; i >= 0; i--)
        delete ai[i];
}

//ACCESSORS
int pokerDealer::getMin()
{
    return minimum;
}

int pokerDealer::getStartChips()
{
    return startChips;
}

//MUTATORS
void pokerDealer::push_back(pokerAI* _ai, string _name)
{
    int playerSize = players.size();

    Player player(startChips, playerSize, _name);
    players.push_back(player);

    ai.push_back(_ai);
}

void pokerDealer::setMin(int min)
{
    minimum = min;
}

void pokerDealer::setStartChips(int chips)
{
    startChips = chips;
}

//GAME FUNCTIONS
void pokerDealer::handByHand(int maxGame)
{
    int playerSize = players.size();

    if (playerSize <= 1)
    {
        cout << "Not enough players to play a tournament" << endl;
        return;
    }

    int minBet = getMin();

    reset();

    vector<int> gross;
    for (int i = 0; i < playerSize; i++)
        gross.push_back(0);

    // game loop
    while(game <= maxGame)
    {
        //  check to see if there's only one player
        if (onlyOne())
            break;

        cout << "\n********************** GAME " << game << " **********************\n";

        chipReset();

        newGame(minBet);
        preflopToRiver(minBet);

//        cout << "minBet: " << minBet * 2 << endl;

        //  determining winner
        //  and revealed cards
        showdown();

        //  distribute winnings
        giveWinning();

        //  reveal cards to ai
        revealToAI();

        cout << "----------WINNER----------" << endl;
        //  outputs to console winner of hand
        outputCommunity();
        outputRevealedCards();
        outputWinner();
        updateGross(gross);
        cout << "--------------------------" << endl;

        cout << "\n*****************************************************\n";
    }

    for (int i = 0; i < playerSize; i++)
    {
        cout << players[i].getName() << " has a grossed " << gross[i] << endl << endl;
    }
}

void pokerDealer::updateGross(vector<int>& gross)
{
    int playerSize = players.size();
    for (int i = 0; i < playerSize; i++)
        gross[i] += (players[i].total_money - startChips);
}

void pokerDealer::tournament(int maxGame)
{
    int playerSize = players.size();

    if (playerSize <= 1)
    {
        cout << "Not enough players to play a tournament" << endl;
        return;
    }

    int minBet = getMin();

    reset();

    // game loop
    while(game <= maxGame)
    {
        //  check to see if there's only one player
        if (onlyOne())
            break;

        cout << "\n********************** GAME " << game << " **********************\n";

        newGame(minBet);

        preflopToRiver(minBet);

//        cout << "minBet: " << minBet * 2 << endl;

        //  determining winner
        //  and revealed cards
        showdown();

        //  distribute winnings
        giveWinning();

        //  reveal cards to ai
        revealToAI();

        cout << "----------WINNER----------" << endl;
        //  outputs to console winner of hand
        outputCommunity();
        outputRevealedCards();
        outputWinner();
        cout << "--------------------------" << endl;

        cout << "\n*****************************************************\n";

        if (game % 20 == 0)
            minBet *= 2;
    }

    for (int i = 0; i < playerSize; i++)
    {
        cout << players[i].getName() << " has " << players[i].total_money << " chips" << endl << endl;
    }
}

void pokerDealer::preflopToRiver(int minBet)
{
    // create a new deck
    Deck deck;
    pot = 0;

    int playerSize = players.size();

    //  count num of players before the game
    for (int i = 0; i < playerSize; i++)
    {
        hands.push_back(vector<Card>());
        //  reset live players to true
        if (players[i].total_money > 0)
            players[i].inRound = true;
        else
            players[i].inRound = false;
    }

    // for each round....
    for(int round = PreFlop; round <= River; ++round)
    {
        if (round == PreFlop)
        {
            //  deal each player cards
            for (int i = 0; i < playerSize; i++)
                //  deal 2 cards per player
                for (int j = 0; j < 2; j++)
                    hands[i].push_back(deck.deal());
        }
        else if (round == Flop)
        {
            // deal the community cards
            for(int i=0; i<3; ++i)
                community.push_back(deck.deal());
        }
        // (round == Turn || round == River)
        else
            community.push_back(deck.deal());

        //  keeps track of highest bet
        int highBet;
        if (round == PreFlop)
            highBet = minBet * 2;
        else
            highBet = 0;

        //  keeps track of number in round
        int numPlaying;

        int adj = adjust(round);

        do
        {

            //  needs to assign small and big blind using bigBlindPos
            for (int j = 0; j < playerSize; j++)
            {
                int i = (dealerPos + j + adj) % playerSize;

                if (!players[i].inRound)
                    continue;
                else if (players[i].bet_amount != 0)
                    if (players[i].bet_amount == highBet)
                        continue;

                numPlaying = 0;
                for (int k = 0; k < playerSize; k++)
                    if (players[k].inRound)
                        numPlaying++;

                //                cout << "numplaying: " << numPlaying << endl;
                //  check to make sure more than one person playing
                if (numPlaying == 1)
                    break;

                //  calls for ai's bet
                int betAmt = 0;
                if (players[i].inRound)
                    betAmt = ai[i]->bet(game, round,
                                        dealerPos, i,
                                        players, community,
                                        max(minBet*2, highBet), pot, hands[i]);

                //  make sure bet is valid
                //  set bet to 0 if not
                //  subtract bet from total money
                checkBet(betAmt, highBet, players[i]);
            }
        } while(stillBetting(highBet) && numPlaying > 1);

        // after all the bets, clear everyone's bet, add it to the pot
        for (int i = 0; i < players.size(); i++)
        {
            //  update player money & pot
            int betAmt = players[i].bet_amount;
            pot += betAmt;
            players[i].bet_amount = 0;
        }

        //        cout << "num playing: " << numPlaying << endl;
        if (numPlaying == 1)
            break;
    }
}

//POSITION FUNCTIONS
void pokerDealer::updateDealer()
{
    int playerSize = players.size();

    //  check later slice of table
    for (int i = dealerPos + 1; i < playerSize; i++)
    {
        if (players[i].inRound)
        {
            dealerPos = i;
            return;
        }
    }

    //  check beginning slice of table
    for (int i = 0; i < dealerPos; i++)
    {
        if (players[i].inRound)
        {
            dealerPos = i;
            return;
        }
    }
}

void pokerDealer::setBlind(int minBet)
{
    int smallPos, bigPos;
    smallPos = bigPos = -1;

    int playerSize = players.size();
    for (int i = dealerPos + 1; i < playerSize; i++)
    {
        if (players[i].total_money)
        {
            smallPos = i;
            break;
        }
    }
    if (smallPos == -1)
    {
        for (int i = 0; i < dealerPos; i++)
        {
            if (players[i].total_money)
            {
                smallPos = i;
                break;
            }
        }
    }

    for (int i = smallPos + 1; i < playerSize; i++)
    {
        if (players[i].total_money)
        {
            bigPos = i;
            break;
        }
    }

    if (bigPos == -1)
    {
        for (int i = 0; i < smallPos; i++)
        {
            if (players[i].total_money)
            {
                bigPos = i;
                break;
            }
        }
    }

    int small = min(minBet, players[smallPos].total_money);
    int big = min(minBet * 2, players[bigPos].total_money);

    players[smallPos].bet_amount = small;
    players[smallPos].total_money -= small;

    players[bigPos].bet_amount = big;
    players[bigPos].total_money -= big;
}

int pokerDealer::adjust(int round)
{
    int adj = 0;
    int work = 0;

    if (round == PreFlop)
    {
        int playerSize = players.size();
        for (int i = dealerPos + 1; i < playerSize; i++)
        {
            adj++;
            if (players[i].inRound)
            {
                if (work < 2)
                    work++;
                else
                    break;
            }
        }

        if (work == 2)
            return adj;

        for (int i = 0; i < dealerPos; i++)
        {
            adj++;
            if (players[i].inRound)
            {
                if (work < 2)
                    work++;
                else
                    break;
            }
        }
    }
    else
        adj = 1;

    return adj;
}

//NEW GAME FUNCTIONS
//  reset all stats so new game can continue
void pokerDealer::reset()
{
    // setup
    game = 0;
    dealerPos = -1;

    chipReset();

    clearCards();
}

void pokerDealer::newGame(int minBet)
{
    game++;

    pot = 0;

    clearCards();

    updateDealer();
    setBlind(minBet);
}

void pokerDealer::chipReset()
{
    int playerSize = players.size();
    for (int i = 0; i < playerSize; i++)
    {
        players[i].inRound = true;
        players[i].bet_amount = 0;
        players[i].total_money = startChips;
    }
}

void pokerDealer::clearCards()
{
    hands.clear();
    community.clear();

    winner.clear();
    playerReveal.clear();
    handReveal.clear();
}

//WINNER FUNCTIONS
//Returns the number of the player who won the round
void pokerDealer::showdown()
{
    winner.clear();
    //  counting to see how man players in game
    int playerSize = players.size();

    for (int k = 0; k < playerSize; k++)
    {
        int i = (k + dealerPos) % playerSize;

        if (players[i].inRound)
            winner.push_back(i);
    }

    if (winner.size() == 1)
        return;
    else
    {
        int bestHand = 10000;
        int rk;
        //adds the community cards to remaining players hands
        //sorts and evaluates
        int handSize = hands.size();
        for (int k = 0; k < hands.size(); k++)
        {
            int i = (k + dealerPos) % handSize;

            if (players[i].inRound == true)
            {
                rk = rank(hands[i], community);

                if (rk <= bestHand)
                {
                    //  adds revealed player/cards to list
                    playerReveal.push_back(players[i]);
                    handReveal.push_back(hands[i]);

                    if (rk < bestHand)
                    {
                        winner.clear();
                        bestHand = rk;
                    }

                    winner.push_back(i);
                }
            }
        }

        return;
    }
}

void pokerDealer::giveWinning()
{
    //  splitting pot if necessary
    int winnerSize = winner.size();
    int potShare = pot / winnerSize;

//        cout << "here ======" << endl;
//        for (int i = 0; i < winnerSize; i++)
//            cout << winner[i] << " ";
//        cout << "done ======" << endl;


    for (int i = 0; i < winnerSize; i++)
    {
//        cout << players[winner[i]].getName() << " won " << potShare << endl;
        players[winner[i]].total_money += potShare;
    }
}

//CHECK FUNCTIONS
bool pokerDealer::onlyOne()
{
    int playing = 0;
    for (int i = players.size() - 1; i >= 0; i--)
        if (players[i].total_money > 0)
            playing++;

    if (playing == 1)
        return true;
    return false;
}

void pokerDealer::checkBet(int &betAmt, int &highBet, Player& player)
{
//        cout << "highbet: " << highBet << " bet: " << betAmt << endl;
    //  make sure bet is valid
    //  set bet to 0 if not
    //  subtract bet from total money
    if (betAmt < player.bet_amount)
        betAmt = player.bet_amount;

    if (betAmt >= 0)
    {
        //  keeping track of highest bet (raise)
        if (betAmt > highBet)
        {
            if (betAmt > player.total_money + player.bet_amount)
                betAmt = player.total_money + player.bet_amount;
            highBet = betAmt;
        }
        //  checking bets underneath high bet
        else if (betAmt < highBet)
        {
            //  determine if player folded, or all in
            // if player made a bet below the last one... automatically fold
            if (betAmt != player.total_money)
            {
                player.inRound = false;
                betAmt = 0;
                cout<<"\n" << player.getName() <<" has folded!\n";
            }
        }
        //  else player called


        //  remove bet from total of all players
        if (player.inRound)
        {
            player.total_money -= (betAmt - player.bet_amount);
            player.bet_amount = betAmt;
        }
    }
    else
    {
        player.bet_amount = 0;
        player.inRound = false;
    }
}

bool pokerDealer::stillBetting(int highBet)
{
    int playerSize = players.size();

    //  goes through all players and checks if they have finished betting
    for (int i = playerSize - 1; i >= 0; i--)
    {
        //  if player is still in the round
        if (players[i].inRound)
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

//OUTPUT FUNCTIONS
void pokerDealer::outputRevealedCards()
{
    int playerSize = playerReveal.size();


    for (int i = 0; i < playerSize; i++)
    {
        cout << playerReveal[i].getName();
        cout << "\'s hand: ";
        for (int j = 0; j < 2; j++)
            cout << handReveal[i][j];
        cout << endl;
    }
}

void pokerDealer::outputWinner()
{
    int winnerSize = winner.size();
    int potShare = pot / winnerSize;

    if (community.size() == 0 || playerReveal.size() == 0)
    {
        for (int i = 0; i < winnerSize; i++)
            cout << players[winner[i]].getName() << " won " << potShare << " chips" << endl;
    }
    else
    {
        for (int i = 0; i < winnerSize; i++)
        {
            int r = rank(hands[winner[i]], community);
            cout << players[winner[i]].getName() << " won " << potShare << " chips with a " << value_str[fiveRank(r)] << endl;
        }
    }

}

void pokerDealer::outputCommunity()
{
    cout << endl << "community: ";
    for (int i = community.size() - 1; i >= 0; i--)
        cout << community[i];
    cout << endl;
}

void pokerDealer::revealToAI()
{
    //  reveals cards to ai
    int winnerSize = winner.size();
    for (int i = 0; i < winnerSize; i++)
    {
        if (players[i].inRound)
            ai[i]->reveal(playerReveal, handReveal);
    }
}
