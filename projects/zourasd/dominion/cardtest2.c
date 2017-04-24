// unit test on playSmithy function (line 1294)
#include "dominion.h"
#include <stdio.h>
#include <assert.h>

int main() {
    // set function paramaters
    struct gameState* state = malloc(sizeof(struct gameState));
    int handPos = 0;
    int currentPlayer = 0;

    printf("Card test (unit test) - Smithy\n");

    // test return 
    assert(playSmithy(state, handPos, currentPlayer) == 0);
    printf("Function exists correctly\n");

    // check that it is discarded

    printf("All tests passed!\n\n");
    return 0;
}
