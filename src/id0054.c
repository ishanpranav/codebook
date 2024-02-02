// Licensed under the MIT License.

// Poker Hands

#include "../lib/euler.h"

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
    RANK_ACE = 0,
    RANK_KING = 1,
    RANK_QUEEN = 2,
    RANK_JACK = 3,
    RANK_TEN = 4,
    RANK_NINE = 5,
    RANK_EIGHT = 6,
    RANK_SEVEN = 7,
    RANK_SIX = 8,
    RANK_FIVE = 9,
    RANK_FOUR = 10,
    RANK_THREE = 11,
    RANK_TWO = 12,
    MAX_RANK = 13
};

enum Suit
{
    SUIT_SPADES = 0,
    SUIT_DIAMONDS = 1,
    SUIT_CLUBS = 2,
    SUIT_HEARTS = 3,
    MAX_SUIT = 4
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
    enum Rank pairs[2];
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
        case '9': return RANK_NINE;
        case '8': return RANK_EIGHT;
        case '7': return RANK_SEVEN;
        case '6': return RANK_SIX;
        case '5': return RANK_FIVE;
        case '4': return RANK_FOUR;
        case '3': return RANK_THREE;
        case '2': return RANK_TWO;
        default: return MAX_RANK;
    }
}

Suit suit_parse(char value)
{
    switch (value)
    {
        case 'S': return SUIT_SPADES;
        case 'D': return SUIT_DIAMONDS;
        case 'C': return SUIT_CLUBS;
        case 'H': return SUIT_HEARTS;
        default: return MAX_SUIT;
    }
}

int card_compare(const void* left, const void* right)
{
    const struct Card* leftCard = (const struct Card*)left;
    const struct Card* rightCard = (const struct Card*)right;

    return leftCard->rank - rightCard->rank;
}

int frequency_compare(const void* left, const void* right)
{
    const struct Frequency* leftFrequency = (const struct Frequency*)left;
    const struct Frequency* rightFrequency = (const struct Frequency*)right;

    return rightFrequency->count - leftFrequency->count;
}

static bool hand_is_flush(int suits[])
{
    for (Suit i = 0; i < MAX_SUIT; i++)
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
    if (instance->cards[0].rank == RANK_ACE &&
        instance->cards[1].rank == RANK_FIVE &&
        instance->cards[2].rank == RANK_FOUR &&
        instance->cards[3].rank == RANK_THREE &&
        instance->cards[4].rank == RANK_TWO)
    {
        return true;
    }

    Rank rank = instance->cards[0].rank;

    for (int i = 1; i < 5; i++)
    {
        if (rank != instance->cards[i].rank - i)
        {
            return false;
        }
    }

    return true;
}

void hand_classify(Hand instance)
{
    struct Frequency ranks[MAX_RANK];
    int suits[MAX_SUIT] = { 0 };

    for (Rank i = 0; i < MAX_RANK; i++)
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
        instance->pairs[0] = MAX_RANK;
        instance->pairs[1] = MAX_RANK;

        return;
    }
    
    qsort(instance->cards, 5, sizeof * instance->cards, card_compare);

    bool straight = hand_is_straight(instance);

    if (straight && flush)
    {
        instance->type = HAND_TYPE_STRAIGHT_FLUSH;
        instance->pairs[0] = MAX_RANK;
        instance->pairs[1] = MAX_RANK;

        return;
    }

    qsort(ranks, MAX_RANK, sizeof * ranks, frequency_compare);

    if (ranks[0].count == 4)
    {
        instance->type = HAND_TYPE_FOUR_OF_A_KIND;
        instance->pairs[0] = ranks[0].rank;
        instance->pairs[1] = MAX_RANK;

        return;
    }

    if (ranks[0].count == 3 && ranks[1].count == 2)
    {
        instance->type = HAND_TYPE_FULL_HOUSE;
        instance->pairs[0] = ranks[0].rank;
        instance->pairs[1] = ranks[1].rank;

        return;
    }

    if (flush)
    {
        instance->type = HAND_TYPE_FLUSH;
        instance->pairs[0] = MAX_RANK;
        instance->pairs[1] = MAX_RANK;

        return;
    }

    if (straight)
    {
        instance->type = HAND_TYPE_STRAIGHT;
        instance->pairs[0] = MAX_RANK;
        instance->pairs[1] = MAX_RANK;

        return;
    }

    if (ranks[0].count == 3)
    {
        instance->type = HAND_TYPE_THREE_OF_A_KIND;
        instance->pairs[0] = ranks[0].rank;
        instance->pairs[1] = MAX_RANK;

        return;
    }

    if (ranks[0].count == 2)
    {
        instance->pairs[0] = ranks[0].rank;

        if (ranks[1].count == 2)
        {
            instance->type = HAND_TYPE_TWO_PAIRS;
            instance->pairs[1] = ranks[1].rank;

            return;
        }

        instance->type = HAND_TYPE_ONE_PAIR;
        instance->pairs[1] = MAX_RANK;

        return;
    }

    instance->type = HAND_TYPE_HIGH_CARD;
    instance->pairs[0] = MAX_RANK;
    instance->pairs[1] = MAX_RANK;
}

void hand_parse(Hand instance, String value)
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

    for (int i = 0; i < 2; i++)
    {
        if (left->pairs[i] != MAX_RANK)
        {
            result = left->pairs[i] - right->pairs[i];

            if (result)
            {
                return result;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        result = left->cards[i].rank - right->cards[i].rank;

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
