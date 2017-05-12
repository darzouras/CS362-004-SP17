// random test on playAdventurer function (line 1268)
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

// int playAdventurer (struct gameState *state, int currentPlayer, int drawntreasure, int* temphand, int z, int cardDrawn)
// returns 0 for a successful return
int main() {
    printf("\n###################\n");
    printf("Card test (random test) - Adventurer\n");

    // set function parameters
    int i, n, p, z, cardDrawn, numPlayer, drawntreasure, count, badcount, seed;
    struct gameState G;
    int tempHand[MAX_HAND];
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    int handCount, deckCount;
    int silvers[MAX_HAND];
    int estates[MAX_HAND];
    int adventurers[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++) {
        silvers[i] = silver;
        estates[i] = estate;
        adventurers[i] = adventurer;
    }

    // test multiple players with multiple seeds
    for (n = 0; n < 10; n++) {
        // testing for multiple hand counts
        for (handCount = 1; handCount < MAX_HAND; handCount++) {
            // also for multiple deck counts
            for (deckCount = 1; deckCount < MAX_DECK; deckCount++) {
                // and multiple players 
                for (p = 0; p < MAX_PLAYERS; p++) {
                    printf("\n--- Testing player %d\n", p);

                    count = 0;
                    badcount = 0;
                    for (i = 0; i = )
                    // clear gameState, set the hand
                    memset(&G, 23, sizeof(struct gameState));
                    intiializeGame(numPlayer, k, n, &G);


                }
            }
        }
    }

}
