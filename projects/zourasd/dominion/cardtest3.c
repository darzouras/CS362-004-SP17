// unit test on playVillage function (line 1307)
#include "dominion.h"
#include <stdio.h>
#include <assert.h>

int main() {
    // set function parameters
    struct gameState* state = malloc(sizeof(struct gameState));
    int currentPlayer = 0;
    int handPos = 0;

    printf("Card test (unit test) - Village\n");

    // test return
    assert(playVillage(state, handPos, currentPlayer) == 0);
    printf("Function exits correctly\n");

    // check that the card was discarded

    // confirm that there state->numActions has incrememnted by 2

    // confirm that there is 1 more card in hand 

    printf("All tests passed!\n\n");
    return 0;
}
