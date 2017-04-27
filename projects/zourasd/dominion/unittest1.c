// unit testing the function buyCard (line 272)
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>

// int buyCard(int supplyPos, struct gameState *state)
// returns 0 on normal exit if a card was purchased
// returns -1 if a card could not be purchased
int main() {
    printf("####################\n");
    printf("Unit test 1 - buyCard()\n");

    struct gameState pre;



    // test if numBuys = 0
    // if returns -1, pass
    // if returns 0, fail

    // test if supplyCount(supplyPos, state) = 0
    // if returns -1, pass
    // if returns 0, fail

    // test if state->coins < getCost(supplyPos)
    // if returns -1, pass
    // if returns 0, fail

    // test a successful purchase
    // if returns -1, fail
    // if returns 0, check the current player's hand for the card
    // check that the supply count has been decreased

    return 0;
}
