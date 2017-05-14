// random test on playSmithy funciton (line 1294)
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

// int playSmithy(struct gameState *state, int handPos, int currentPlayer)
// returns 0 on normal exit
// should add three cards to hand
int main() {
    printf("\n####################\n");
    printf("Card test (random test) - Smithy\n");

    int i, p, n, numPlayer, count, badcount, index;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G, pre;

    for (n = 1; n < 10; n++) {
        count = 0;
        badcount = 0;

        // clear gameState, set hand, deck, and discard
        memset(&G, 23, sizeof(struct gameState));
        initializeGame(numPlayer, k, n, &G);
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

        if (playSmithy(&G, index, p) == 0) {
            printf("PASS successful return\n");
            count++;
        }
        else {
            printf("FAIL unsuccessful return\n");
            badcount++;
        }

        if (G.hand[p][index] == pre.hand[p][index]) {
            printf("FAIL smithy card has not been discarded\n");
            badcount++;
            if (G.handCount[p] == pre.handCount[p] + 3) {
                printf("PASS added three new cards to hand\n");
                count++;
            }
            else {
                printf("FAIL expected three new cards in hand\n");
                badcount++;
            }
        }
        else {
            printf("PASS smithy card has been discarded\n");
            count++;
            if (G.handCount[p] == pre.handCount[p] + 2) {
                printf("PASS added three new cards to hand\n");
                count++;
            }
            else {
                printf("FAIL expected three new cards in hand\n");
                badcount++;
            }
        }

        printf("#TESTS PASSED: %d, TESTS FAILED: %d\n", count, badcount);
    }

    return 0;
}
