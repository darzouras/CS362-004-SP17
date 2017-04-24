// unit test on playGreatHall function (line 1319)
#include "dominion.h"
#include <stdio.h>
#include <assert.h>

int main() {
    // set function parameters
    struct gameState *state = malloc(sizeof(struct gameState));
    int handPos = 0;
    int currentPlayer = 0;

    printf("Card test (unit test) - Great Hall\n");

    // test return
    assert(playGreatHall(state, handPos, currentPlayer) == 0);
    printf("Function exits correctly\n");

    // check that the card was discarded

    printf("All tests passed!\n\n");
    return 0;
}
