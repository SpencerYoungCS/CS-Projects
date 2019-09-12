#define	STRAIGHT_FLUSH	1
#define	FOUR_OF_A_KIND	2
#define	FULL_HOUSE	3
#define	FLUSH		4
#define	STRAIGHT	5
#define	THREE_OF_A_KIND	6
#define	TWO_PAIR	7
#define	ONE_PAIR	8
#define	HIGH_CARD	9

#define	RANK(x)		((x >> 8) & 0xF)

#include <iostream>
using namespace std;

static string value_str[] = {
    "",
    "Straight Flush",
    "Four of a Kind",
    "Full House",
    "Flush",
    "Straight",
    "Three of a Kind",
    "Two Pair",
    "One Pair",
    "High Card"
};

int fiveRank(int x)
{
    return x <= 10 ? 1 :
            x <= 166 ? 2 :
            x <= 322 ? 3 :
            x <= 1599 ? 4 :
            x <= 1609 ? 5 :
            x <= 2467 ? 6 :
            x <= 3325 ? 7 :
            x <= 6185 ? 8 :
            x <= 7462 ? 9 :
                        0;
}

#define CLUB	0x8000
#define DIAMOND 0x4000
#define HEART   0x2000
#define SPADE   0x1000

#define Deuce	0
#define Trey	1
#define Four	2
#define Five	3
#define Six	4
#define Seven	5
#define Eight	6
#define Nine	7
#define Ten	8
#define Jack	9
#define Queen	10
#define King	11
#define Ace	12
