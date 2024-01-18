// Licensed under the MIT License.

// Poker Hands

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/euler.h"
#include "../lib/lp_string.h"

enum HandType
{
    HAND_TYPE_ROYAL_FLUSH = 0,
    HAND_TYPE_STRAIGHT_FLUSH = 1,
    HAND_TYPE_FOUR_OF_A_KIND = 2,
    HAND_TYPE_FULL_HOUSE = 3,
    HAND_TYPE_FLUSH = 4,
    HAND_TYPE_STRAIGHT = 5,
    HAND_TYPE_THREE_OF_A_KIND = 6,
    HAND_TYPE_TWO_PAIRS = 7,
    HAND_TYPE_ONE_PAIR = 8,
    HAND_TYPE_HIGH_CARD = 9
};

enum Rank
{
    RANK_TWO = 0,
    RANK_THREE = 1,
    RANK_FOUR = 2,
    RANK_FIVE = 3,
    RANK_SIX = 4,
    RANK_SEVEN = 5,
    RANK_EIGHT = 6,
    RANK_NINE = 7,
    RANK_TEN = 8,
    RANK_JACK = 9,
    RANK_QUEEN = 10,
    RANK_KING = 11,
    RANK_ACE = 12,
    SIZE_RANK = 13
};

enum Suit
{
    SUIT_SPADES = 0,
    SUIT_DIAMONDS = 1,
    SUIT_CLUBS = 2,
    SUIT_HEARTS = 3,
    SIZE_SUIT = 4
};

struct Card
{
    enum Rank rank;
    enum Suit suit;
};

struct Hand
{
    struct Card cards[5];
    enum HandType type;
    enum Rank rank;
};

typedef enum HandType HandType;
typedef enum Rank Rank;
typedef enum Suit Suit;
typedef struct Card* Card;
typedef struct Hand* Hand;

Rank rank_parse(char value)
{
    switch (value)
    {
        case 'A': return RANK_ACE;
        case 'K': return RANK_KING;
        case 'Q': return RANK_QUEEN;
        case 'J': return RANK_JACK;
        case 'T': return RANK_TEN;
    }

    return value - '2';
}

Suit suit_parse(char value)
{
    switch (value)
    {
        case 'S': return SUIT_SPADES;
        case 'D': return SUIT_DIAMONDS;
        case 'C': return SUIT_CLUBS;
        case 'H': return SUIT_HEARTS;
    }

    return SIZE_SUIT;
}

int card_compare(Object left, Object right)
{
    const struct Card* leftCard = (const struct Card*)left;
    const struct Card* rightCard = (const struct Card*)right;

    return leftCard->rank - rightCard->rank;
}

HandType hand_classify(Hand instance, Rank* rank)
{
    int min = 5;
    int max = 0;
    int ranks[SIZE_RANK] = { 0 };
    int suits[SIZE_SUIT] = { 0 };

    for (int i = 0; i < 5; i++)
    {
        ranks[instance->cards[i].rank]++;
        suits[instance->cards[i].suit]++;
    }

    for (Rank i = 0; i < SIZE_RANK; i++)
    {
        if (ranks[i] > max)
        {
            max = ranks[i];
            *rank = i;
        }

        if (max == 4)
        {
            return HAND_TYPE_FOUR_OF_A_KIND;
        }

        if (ranks[i] && ranks[i] < min)
        {
            min = ranks[i];
        }
    }

    assert(min <= 4);
    assert(max >= 1);

    switch (max)
    {
        case 2:
            if (min == 2)
            {
                return HAND_TYPE_TWO_PAIRS;
            }
            return HAND_TYPE_ONE_PAIR;

        case 3:
            if (min == 2)
            {
                return HAND_TYPE_FULL_HOUSE;
            }
            
            return HAND_TYPE_THREE_OF_A_KIND;
    }

    bool flush = false;
    
    for (Suit i = 0; i < SIZE_SUIT; i++)
    {
        if (suits[i] == 5)
        {
            flush = true;

            break;
        }
    }

    if (flush && ranks[RANK_ACE] == 1 && ranks[RANK_KING] == 1 && 
        ranks[RANK_QUEEN] == 1 && ranks[RANK_JACK] == 1 && ranks[RANK_TEN] == 1)
    {
        return HAND_TYPE_ROYAL_FLUSH;
    }

    *rank = instance->cards[4].rank;
    
    if (*rank - instance->cards[0].rank == 4)
    {
        if (flush)
        {
            return HAND_TYPE_STRAIGHT_FLUSH;
        }

        return HAND_TYPE_STRAIGHT;
    }

    if (flush)
    {
        return HAND_TYPE_FLUSH;
    }

    return HAND_TYPE_HIGH_CARD;
}

void hand_parse(Hand instance, LPString value)
{
    for (int i = 0; i < 5; i++)
    {
        instance->cards[i].rank = rank_parse(value[i * 3]);
        instance->cards[i].suit = suit_parse(value[i * 3 + 1]);
    }

    qsort(instance->cards, 5, sizeof * instance->cards, card_compare);
    
    instance->type = hand_classify(instance, &instance->rank);
}

void dbg(Hand instance)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d.%d ", instance->cards[i].rank, instance->cards[i].suit);
    }

    printf("\n");
}

int hand_compare(Hand left, Hand right)
{
    int result = left->type - right->type;

    if (result)
    {
        return result;
    }

    result = right->rank - left->rank;

    if (result)
    {
        return result;
    }

    for (int i = 4; i >= 0; i--)
    {
        result = right->cards[i].rank - left->cards[i].rank;

        if (result)
        {
            return result;
        }
    }

    return 0;
}

int main(void)
{
    int count = 0;
    char buffer[64];
    clock_t start = clock();

    while (fgets(buffer, sizeof buffer, stdin))
    {
        struct Hand first;
        struct Hand second;

        hand_parse(&first, buffer);
        hand_parse(&second, buffer + 15);
        dbg(&first);
        dbg(&second);
        printf("%d VS %d : %d\n\n", first.type, second.type, hand_compare(&first, &second));

        if (hand_compare(&first, &second) < 0)
        {
            count++;
        }
    }

    return euler_submit(54, count, start);
}
