// random test on playVillage function (line 1307)
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <studio.h>
#include <stdlib.h>
#include <math.h>

// int playVillage(struct gameState *state, int handPos, int currentPlayer)
// returns 0 on normal exit
// should add a card to hand and increase number of actions by 2
int main() {
    printf("\n####################\n");
    printf("Card test (random test) - Village\n");

    int i, p, n, numPlayer, count, badcount, index;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G, pre;

    for (n = 1; n < 10; n++) {
        count = 0;
        badcount = 0;

        // clear gamestate, set hand, deck, and discard
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

        if (playVillage(&G, index, p) == 0) {
            printf("PASS successful return\n");
            count++;
        }
        else {
            printf("FAIL unsuccessful return\n");
            badcount++;
        }

        if (G.hand[p][index] == pre.hand[p][index]) {
            printf("FAIL have not discarded card\n");
            badcount++;
            if (G.handCount[p] = pre.handCount[p] + 1) {
                printf("PASS new card in hand\n");
                count++;
            }
            else {
                printf("FAIL expected new card in hand\n");
                badcount++;
            }
        }
        else {
            printf("PASS successful discard\n");
            count++;
            if (G.handCount[p] == pre.handCount[p]) {
                printf("PASS added new card to hand\n");
                count++;
            }
            else {
                printf("FAIL expected new card in hand\n");
                badcount++;
            }
        }

        if (G.numActions == pre.numActions + 2) {
            printf("PASS two actions added\n");
            count++;
        }
        else {
            printf("FAIL expected two extra actions\n");
            badcount++;
        }

        printf("#TESTS PASSED: %d, TESTS FAILED: %d\n", count, badcount);
    }
    return 0;
}
