// unit test on playAdventurer function (line 1268)
#include "dominion.h"
#include "dominion_helpers.h"
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

    printf("####################\n");
    printf("Card test (unit test) - Adventurer\n");

    // test return
    if(playAdventurer(state, currentPlayer, drawntreasure, temphand, z, cardDrawn) == 0);
        printf("Function exits correctly\n");
    else
        printf("ERROR: Function does not exit correctly\n");

    // check that the card was discarded
    // do this by knowing where this adventurer card was, and that it was the only adventurer in hand
    // check if the card in that handPos is different.
    // if different, pass
    // else fail

    // count passed and failed tests?
    return 0;
}
