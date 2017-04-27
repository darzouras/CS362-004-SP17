// unit testing the function buyCard (line 272)
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

// int buyCard(int supplyPos, struct gameState *state)
// returns 0 on normal exit if a card was purchased
// returns -1 if a card could not be purchased
int main() {
    printf("####################\n");
    printf("Unit test 1 - buyCard()\n");

    int i, p, r, testReturn;
    int seed = 999;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int handCount = 5;
    int coppers[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++) {
        coppers[i] = copper;
    }

    // FIXME if time, create loop t hrough each possible supplyPos
    // cycle through each player.
    for (p = 0; p < numPlayer; p++) {
        printf("--- Testing player %d\n", p);

        // clear the gameState for each character, then set relevant variables
        memset(&G, 23, sizeof(struct gameState));
        r = initializeGame(numPlayer, k, seed, &G);
        G.handCount[p] = handCount;
        memcpy(G.hand[p], coppers, sizeof(int) * handCount);
        G.whoseTurn = p; // FIXME do I need this?????
        // there are 5 coppers in hand to start

        // attempt two buys for each player
        G.numBuys = 2;

        // first, test situation where a buy can happen.
        // if returns 0, check the current player's hand for the card
        // check that the supply count has been decreased

        // the first buy attempts to buy a council_room, which will cost all 5 coppers in hand
        testReturn = buyCard(1, &G);
        if (testReturn == -1)
            printf("buyCard(): FAIL expected function to return 0\n");
        else {
            printf("buyCard(): PASS function exited without error\n");

            // test numBuys decrement
            if (G.numBuys == 1)
                printf("buyCard(): PASS numBuys decremented after buy\n");
            else
                printf("buyCard(): FAIL numBuys did not decrement\n");

            // test that payment has been taken
            if (G.coins == 0)
                printf("buyCard(): PASS currency was removed from hand\n");
            else
                printf("buyCard(): FAIL currency was not removed from hand\n");

            if (G.handCount[p] > 0) {
            if (G.hand[p][0] == k[1])
                printf("buyCard(): PASS the correct card is found in hand\n");
            else
                printf("buyCard(): FAIL incorrect card added to hand\n");
            }
            else
                printf("buyCard(): FAIL no card added to hand\n");
        }

        // the second buy attempts to buy a council_room again, but not enough coin in hand
            // test if state->coins < getCost(supplyPos)
            // if returns -1, pass
            // if returns 0, fail

        // and then test for b = 0
        // if returns -1, pass
        // if returns 0, fail
    }


    // test if supplyCount(supplyPos, state) = 0
    // if returns -1, pass
    // if returns 0, fail

    return 0;
}
