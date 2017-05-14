// random test on playAdventurer function (line 1268)
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

// this function compares values
// returns 0 if values are equal,
// returns 1 if values are inequal
int testvals(int * v1, int* v2, int size) {
    if (memcmp(v1, v2, size) == 0)
        return 0;
    else {
        return 1;
}

// int playAdventurer (struct gameState *state, int currentPlayer, int drawntreasure, int* temphand, int z, int cardDrawn)
// returns 0 for a successful return
int main() {
    printf("\n###################\n");
    printf("Card test (random test) - Adventurer\n");

    // set function parameters
    int n, p, cardDrawn, numPlayer, drawntreasure, count, badcount, seed, index;
    struct gameState G, pre, post;
    int tempHand[MAX_HAND];
    int z = 0;
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
    // n will serve as the seed to randomize each iteration
    for (n = 0; n < 10; n++) {
        // these counters are saved
        count = 0;
        badcount = 0;

        // clear gameState, set the hand
        memset(&G, 23, sizeof(struct gameState));
        intiializeGame(numPlayer, k, n, &G);
        p = floor(Random() * 2);
        G.deckCount[p] = floor(Random() * MAX_DECK);
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() * MAX_DECK);
        index = floor(Random() * G.handCount[p]);
        pre = G;
        printf("-- Seed[%d] -- Handsize[%d] -- Decksize[%d]\n", n, G.handCount, G.deckCounts);

        // check for correct return value
        if (playAdventurer(&G, p, drawntreasure, tempHand, z, cardDrawn) == 0) {
            printf("PASS successful return\n");
            count++;
        }
        else {
            printf("FAIL unsuccessful return\n");
            badcount++;
        }

        if (testVals((int*)G.hand[p][index], (int*)pre.hand[p][index], sizeof(int)) == 0) {
            printf("FAIL have not discarded card\n");
            badcount++;
            if (G.handCount[p == pre.handCount[p] + 2) {
                printf("PASS added two new cards in hand\n");
                count++;
            }
            else {
                printf("FAIL expected two new cards in hand\n");
                count++;
            }
        }
        else {
            printf("PASS successful discard\n");
            count++;
            if (G.handCount[p] == pre.handCount[p] + 1) {
                printf("PASS added two new cards in hand\n");
                count++;
            }
            else {
                printf("FAIL expected two new cards in hand\n");
                badcount++;
            }
        }

        printf("#TESTS PASSED: %d, TESTS FAILED: %d\n", count, badcount);
    }

}
