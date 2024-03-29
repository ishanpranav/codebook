// Licensed under the MIT License.

// Monopoly Odds

#include "../lib/euler.h"
#include "../lib/priority_queue.h"
#include "../lib/random.h"

enum Square
{
    SQUARE_GO = 0,
    SQUARE_COMMUNITY_CHEST_1 = 2,
    SQUARE_CHANCE_1 = 7,
    SQUARE_JAIL = 10,
    SQUARE_ST_CHARLES_PLACE = 11,
    SQUARE_COMMUNITY_CHEST_2 = 17,
    SQUARE_CHANCE_2 = 22,
    SQUARE_ILLINOIS_AVENUE = 24,
    SQUARE_GO_TO_JAIL = 30,
    SQUARE_COMMUNITY_CHEST_3 = 33,
    SQUARE_CHANCE_3 = 36,
    SQUARE_BOARDWALK = 39,
    MAX_SQUARE = 40
};

struct Monopoly
{
    long long (*random)(void* instance, long long max);

    void* randomState;
    enum Square square;
    int doubles;
    int dieFaces;
};

typedef enum Square Square;
typedef struct Monopoly* Monopoly;

static Square square_next(Square square, Square others[])
{
    for (Square* other = others; *other; other++)
    {
        if (square < *other)
        {
            return *other;
        }
    }

    return others[0];
}

void monopoly(Monopoly instance, Random random, Object seed, int dieFaces)
{
    instance->random = random;
    instance->randomState = seed;
    instance->square = SQUARE_GO;
    instance->doubles = 0;
    instance->dieFaces = dieFaces;
}

static int monopoly_random(Monopoly instance, int max)
{
    return instance->random(instance->randomState, max);
}

Square monopoly_next_square(Monopoly instance)
{
    int a = monopoly_random(instance, instance->dieFaces) + 1;
    int b = monopoly_random(instance, instance->dieFaces) + 1;

    if (a == b)
    {
        instance->doubles++;

        if (instance->doubles == 3)
        {
            return SQUARE_JAIL;
        }
    }
    else
    {
        instance->doubles = 0;
    }

    Square square = (instance->square + a + b) % MAX_SQUARE;
    Square utilitySquares[] = { 12, 28, 0 };
    Square railroadSquares[] = { 5, 15, 25, 35, 0 };

    switch (square)
    {
        case SQUARE_GO_TO_JAIL:
            instance->doubles = 0;

            return SQUARE_JAIL;

        case SQUARE_CHANCE_1:
        case SQUARE_CHANCE_2:
        case SQUARE_CHANCE_3:
            switch (monopoly_random(instance, 16))
            {
                case 0: return SQUARE_GO;
                case 1: return SQUARE_JAIL;
                case 2: return SQUARE_ST_CHARLES_PLACE;
                case 3: return SQUARE_ILLINOIS_AVENUE;
                case 4: return SQUARE_BOARDWALK;
                case 5: return railroadSquares[0];
                case 6:
                case 7:
                    return square_next(square, railroadSquares);
                case 8: return square_next(square, utilitySquares);
                case 9: return square - 3;
            }
            break;

        case SQUARE_COMMUNITY_CHEST_1:
        case SQUARE_COMMUNITY_CHEST_2:
        case SQUARE_COMMUNITY_CHEST_3:
            switch (monopoly_random(instance, 16))
            {
                case 0: return SQUARE_GO;
                case 1: return SQUARE_JAIL;
            }
            break;

        default: break;
    }

    return square;
}

int main(void)
{
    long result = 0;
    struct Monopoly game;
    struct PriorityQueue priorityQueue;
    int counts[MAX_SQUARE] = { 0 };
    uint64_t seed[4] = { 12004, 1, 20, 2004 };
    clock_t start = clock();

    monopoly(&game, xoshiro256_star_star_random, seed, 4);

    for (long i = 0; i < 100000l; i++)
    {
        game.square = monopoly_next_square(&game);
        counts[game.square]++;
    }

    euler_ok(priority_queue(
        &priorityQueue,
        sizeof(Square),
        sizeof(int),
        MAX_SQUARE,
        reverse_int_comparer));

    for (Square square = 0; square < MAX_SQUARE; square++)
    {
        priority_queue_enqueue(&priorityQueue, &square, counts + square);
    }

    for (int i = 0; i < 3; i++)
    {
        Square square;

        priority_queue_try_dequeue(&priorityQueue, &square, NULL);

        result = result * 100 + square;
    }

    finalize_priority_queue(&priorityQueue);

    return euler_submit(84, result, start);
}
