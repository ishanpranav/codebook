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

struct Frequency
{
    enum Rank rank;
    int count;
};

struct Hand
{
    struct Card cards[5];
    enum HandType type;
    enum Rank firstPair;
    enum Rank secondPair;
};

typedef enum HandType HandType;
typedef enum Rank Rank;
typedef enum Suit Suit;
typedef struct Card* Card;
typedef struct Frequency* Frequency;
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

    return rightCard->rank - leftCard->rank;
}

int frequency_compare(Object left, Object right)
{
    const struct Frequency* leftFrequency = (const struct Frequency*)left;
    const struct Frequency* rightFrequency = (const struct Frequency*)right;

    return rightFrequency->count - leftFrequency->count;
}

static bool hand_is_flush(int suits[])
{
    for (Suit i = 0; i < SIZE_SUIT; i++)
    {
        if (suits[i] == 5)
        {
            return true;
        }
    }

    return false;
}

static bool hand_is_straight(Hand instance)
{
    Rank rank = instance->cards[0].rank;

    for (int i = 1; i < 5; i++)
    {
        if (rank != instance->cards[i].rank + i)
        {
            return false;
        }
    }

    return true;
}

void hand_classify(Hand instance)
{
    qsort(instance->cards, 5, sizeof * instance->cards, card_compare);

    struct Frequency ranks[SIZE_RANK];
    int suits[SIZE_SUIT] = { 0 };

    for (Rank i = 0; i < SIZE_RANK; i++)
    {
        ranks[i].rank = i;
        ranks[i].count = 0;
    }

    for (int i = 0; i < 5; i++)
    {
        ranks[instance->cards[i].rank].count++;
        suits[instance->cards[i].suit]++;
    }

    bool flush = hand_is_flush(suits);

    if (flush &&
        ranks[RANK_ACE].count == 1 &&
        ranks[RANK_KING].count == 1 &&
        ranks[RANK_QUEEN].count == 1 &&
        ranks[RANK_JACK].count == 1 &&
        ranks[RANK_TEN].count == 1)
    {
        instance->type = HAND_TYPE_ROYAL_FLUSH;
        instance->firstPair = SIZE_RANK;
        instance->secondPair = SIZE_RANK;

        return;
    }

    bool straight = hand_is_straight(instance);

    if (straight && flush)
    {
        instance->type = HAND_TYPE_STRAIGHT_FLUSH;
        instance->firstPair = SIZE_RANK;
        instance->secondPair = SIZE_RANK;

        return;
    }

    qsort(ranks, SIZE_RANK, sizeof * ranks, frequency_compare);

    if (ranks[0].count == 4)
    {
        instance->type = HAND_TYPE_FOUR_OF_A_KIND;
        instance->firstPair = ranks[0].rank;
        instance->secondPair = SIZE_RANK;

        return;
    }

    if (ranks[0].count == 3 && ranks[1].count == 2)
    {
        instance->type = HAND_TYPE_FULL_HOUSE;
        instance->firstPair = ranks[0].rank;
        instance->secondPair = ranks[1].rank;

        return;
    }

    if (flush)
    {
        instance->type = HAND_TYPE_FLUSH;
        instance->firstPair = SIZE_RANK;
        instance->secondPair = SIZE_RANK;

        return;
    }

    if (straight)
    {
        instance->type = HAND_TYPE_STRAIGHT;
        instance->firstPair = SIZE_RANK;
        instance->secondPair = SIZE_RANK;

        return;
    }

    if (ranks[0].count == 3)
    {
        instance->type = HAND_TYPE_THREE_OF_A_KIND;
        instance->firstPair = ranks[0].rank;
        instance->secondPair = SIZE_RANK;

        return;
    }

    if (ranks[0].count == 2)
    {
        instance->firstPair = ranks[0].rank;

        if (ranks[1].count == 2)
        {
            instance->type = HAND_TYPE_TWO_PAIRS;
            instance->secondPair = ranks[1].rank;

            return;
        }

        instance->type = HAND_TYPE_ONE_PAIR;
        instance->secondPair = SIZE_RANK;

        return;
    }

    instance->type = HAND_TYPE_HIGH_CARD;
    instance->firstPair = SIZE_RANK;
    instance->secondPair = SIZE_RANK;
}

void hand_parse(Hand instance, LPString value)
{
    for (int i = 0; i < 5; i++)
    {
        instance->cards[i].rank = rank_parse(value[i * 3]);
        instance->cards[i].suit = suit_parse(value[i * 3 + 1]);
    }

    hand_classify(instance);
}

int hand_compare(Hand left, Hand right)
{
    int result = left->type - right->type;

    if (result)
    {
        return result;
    }

    if (left->firstPair != SIZE_RANK)
    {
        result = right->firstPair - left->firstPair;

        if (result)
        {
            return result;
        }
    }

    if (left->secondPair != SIZE_RANK)
    {
        result = right->secondPair - left->secondPair;

        if (result)
        {
            return result;
        }
    }

    for (int i = 0; i < 5; i++)
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
        
        if (hand_compare(&first, &second) < 0)
        {
            count++;
        }
    }

    return euler_submit(54, count, start);
}
