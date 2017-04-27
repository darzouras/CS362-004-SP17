// unit testing for the shuffle function (line 201)
#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// int shuffle(int player, struct gameState *state)
// returns 0 when successful
int main() {
    printf("###################\n");
    printf("Unit test 4 - shuffle()\n");

    // first test situation where state->deckCount[player] is 0
    // assert that first test is -1
    // if return is -1, pass
    // else fail

    // second test situation for a full deck.
    // save the early gamestate for comparison
    // assert that this test returns 0
    // discard pile should now be empty.
    // compare the old deck positions with new deck positions.
    // if they are different, pass.
    // else fail

    return 0;
}
