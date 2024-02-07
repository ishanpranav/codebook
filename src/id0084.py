# Licensed under the MIT License.

# Monopoly Odds

from collections import defaultdict
from itertools import islice
from random import randrange
from time import time

SQUARE_GO = 0
SQUARE_JAIL = 10
SQUARE_ST_CHARLES_PLACE = 11
SQUARE_ILLINOIS_AVENUE = 24
SQUARE_GO_TO_JAIL = 30
SQUARE_BOARDWALK = 39
CHANCE_SQUARES = [ 7, 22, 36 ]
COMMUNITY_CHEST_SQUARES = [ 2, 17, 33 ]
UTILITY_SQUARES = [ 12, 28 ]
RAILROAD_SQUARES = [ 5, 15, 25, 35 ]

def monopoly_next(square, squares) -> int:
    for other in range(0, len(squares)):
        if square < squares[other]:
            return squares[other]
    return squares[0]
    
def monopoly_play_turn(dieFaces, square, doubles) -> (int, int):
    a = randrange(1, dieFaces + 1)
    b = randrange(1, dieFaces + 1)
    
    if a == b:
        doubles += 1
    
        if doubles == 3: return SQUARE_JAIL, 0
    else:
        doubles = 0

    square = (square + a + b) % 40
    
    if square == SQUARE_GO_TO_JAIL:return SQUARE_JAIL, 0
    
    if square in CHANCE_SQUARES:
        match randrange(16):
            case 0: return SQUARE_GO, doubles
            case 1: return SQUARE_JAIL, doubles
            case 2: return SQUARE_ST_CHARLES_PLACE, doubles
            case 3: return SQUARE_ILLINOIS_AVENUE, doubles
            case 4: return SQUARE_BOARDWALK, doubles
            case 5: return RAILROAD_SQUARES[0], doubles
            case 6: return monopoly_next(square, RAILROAD_SQUARES), doubles
            case 7: return monopoly_next(square, RAILROAD_SQUARES), doubles
            case 8: return monopoly_next(square, UTILITY_SQUARES), doubles
            case 9: return square - 3, doubles
        
    if square in COMMUNITY_CHEST_SQUARES:
        match randrange(16):
            case 0: return SQUARE_GO, doubles
            case 1: return SQUARE_JAIL, doubles
    
    return square, doubles

turns = 1000000
frequencies = defaultdict(int)
square = 0
doubles = 0
start = time()

for i in range(turns):
    square, doubles = monopoly_play_turn(4, square, doubles)
    frequencies[square] += 1
    
result = 0
frequencies = islice(sorted(frequencies.items(), key=lambda item: -item[1]), 3)

for square, _ in frequencies:
    result = result * 100 + square
        
print(f"0084{result:>64}    {time() - start:.6f}")
