// random test on playAdventurer function (line 1268)
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

// int playAdventurer (struct gameState *state, int currentPlayer, int drawntreasure, int* temphand, int z, int cardDrawn)
// returns 0 for a successful return
int main() {
    printf("\n###################\n");
    printf("Card test (random test) - Adventurer\n");

    // set function parameters
    int i, n, p, cardDrawn, numPlayer, drawntreasure, count, badcount, index;
    struct gameState G, pre;
    int tempHand[MAX_HAND];
    int z = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

    // test multiple players with multiple seeds
    // n will serve as the seed to randomize each iteration
    for (n = 1; n < 1000; n++) {
        count = 0;
        badcount = 0;

        // clear gameState, set the hand, deck, and discard
        memset(&G, 23, sizeof(struct gameState));
        initializeGame(MAX_PLAYERS, k, n, &G);
        p = floor(Random() * 2);
        G.deckCount[p] = floor(Random() * MAX_DECK);
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() * MAX_HAND);
    	for (i = 0; i < G.handCount[p]; i++) {
    		G.hand[p][i] = floor(Random() * 26);
    	}
    	for (i = 0; i < G.deckCount[p]; i++) {
    		G.deck[p][i] = floor(Random() * 26);
    	}
    	for (i = 0; i < G.discardCount[p]; i++) {
    		G.discard[p][i] = floor(Random() * 26);
    	}
        index = floor(Random() * G.handCount[p]);
        pre = G;
        printf("-- Seed[%d] -- Handsize[%d] -- Decksize[%d]\n", n, G.handCount[p], G.deckCount[p]);

        // check for correct return value
        if (playAdventurer(&G, p, drawntreasure, tempHand, z, cardDrawn) == 0) {
            // printf("PASS successful return\n");
            count++;
        }
        else {
            // printf("FAIL unsuccessful return\n");
            badcount++;
        }

	if (G.hand[p][index] == pre.hand[p][index]) {
            // printf("FAIL have not discarded card\n");
            badcount++;
            if (G.handCount[p] == pre.handCount[p] + 2) {
                // printf("PASS added two new cards in hand\n");
                count++;
            }
            else {
                // printf("FAIL expected two new cards in hand\n");
                badcount++;
            }
        }
        else {
            // printf("PASS successful discard\n");
            count++;
            if (G.handCount[p] == pre.handCount[p] + 1) {
                // printf("PASS added two new cards in hand\n");
                count++;
            }
            else {
                // printf("FAIL expected two new cards in hand\n");
                badcount++;
            }
        }

        printf("#TESTS PASSED: %d, TESTS FAILED: %d\n", count, badcount);
    }
    return 0;
}
