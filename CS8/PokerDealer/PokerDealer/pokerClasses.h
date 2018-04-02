#ifndef pokerClasses_h
#define pokerClasses_h
#include <cstdlib>
#include <list>
#include <iostream>

using namespace std;

enum Suit { Diamond, Club, Heart, Spade };
enum Round { PreFlop, Flop, Turn, River };

struct Card
{
    Card(int val, int s)
    {
        value = val;
        suit = Suit(s);
    }
    int value;
    Suit suit;

    //  prints out card
    friend ostream& operator<<(ostream& outs, Card card)
    {
        outs <<"["<<card.value;
        switch(card.suit)
        {
        case Diamond:
            outs << (char)3;
            break;
        case Club:
            outs << (char)4;
            break;
        case Heart:
            outs << (char)5;
            break;
        case Spade:
            outs << (char)6;
        }
        outs<< "] ";
        return outs;
    }

    friend bool operator==(const Card& c1, const Card& c2)
    {
        return (c1.suit == c2.suit && c1.value == c2.value);
    }
};



class Deck
{
    public:
        Deck()
        {
            regenerate();
        }

        void regenerate()
        {
            // create a deck of cards
            deck.clear();
            for(int i = 1; i <= 13; ++i)
                for(int j = 0; j < 4; ++j)
                    deck.push_back(Card(i,j));
        }

        Card deal()
        {
            int pos = rand() % deck.size();

            list<Card>::iterator it = deck.begin();

            for(int i = 0; i < pos; ++i, ++it);

            Card card = *it;
            deck.erase(it);
            return card;
        }

        // member var
        list<Card> deck;
};

struct Player
{
    Player(int total, int num, string _name = "")
    {
        total_money = total;
        bet_amount = 0;
        inRound = true;
        handString = "";
        number = num;
        name = _name;
    }

    int getNum()
    {
        return number;
    }

    string getName()
    {
        return name;
    }


    string handString;
    int total_money;
    int bet_amount;
    bool inRound;

private:
    int number;
    string name;
};

#endif
