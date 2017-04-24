// unit test on playAdventurer function (line 1268)
#include "dominion.h"
#include <stdio.h>
#include <assert.h>

int main() {
    // set function parameters
    struct gameState* state = malloc(sizeof(struct gameState));
    int currentPlayer = 0;
    int drawntreasure = 0;
    int temphand[500];
    int z = 0;
    int cardDrawn = 0;

    printf("Card test (unit test) - Adventurer\n");

    // test return
    assert(playAdventurer(state, currentPlayer, drawntreasure, temphand, z, cardDrawn) == 0);
    printf("Function exits correctly\n");

    // check that the card was discarded

    printf("All tests passed!\n\n");
    return 0;
}
