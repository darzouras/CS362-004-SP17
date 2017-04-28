// unit test on playAdventurer function (line 1268)
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

// int playAdventurer (struct gameState *state, int currentPlayer, int drawntreasure, int* temphand, int z, int cardDrawn)
// returns 0 for a successful return
int main() {
    printf("\n####################\n");
    printf("Card test (unit test) - Adventurer\n");

    // set function parameters
    struct gameState* state = malloc(sizeof(struct gameState));
    int i, p, z, cardDrawn;
    int seed = 999;
    int numPlayer = 2;
    int currentPlayer = 0;
    int drawntreasure = 0;
    int temphand[MAX_HAND];
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    int handCount = 5;
    int deckCount = 3;

    for (p = 0; p < numPlayer; p++) {
        printf("\n-- Testing player %d\n", p);

        // clear gameState, set the hand
        memset(&G, 23, sizeof(struct gameState));
        intializeGame(numPlayer, k, seed, &G);
        G.handCount[p] = handCount;
        memcpy(G.hand[p][0], adventurer, sizeof(int));      // 0st card in hand is adventurer!
        for (i = 1; i < 5; i++)
            memcpy(G.hand[p][i], copper, sizeof(int));      // the rest of the cards are coppers
        G.deckCount[p] = deckCount;
        memcpy(G.deck[p][0], estate, sizeof(int));          // this estate will be drawn but should not remain in hand
        for (i = 1; i < 3; i++)
            memcpy(G.deck[p][i], silver, sizeof(int));      // the cards we are looking for in hand will be silvers

        assert(playAdventurer(&G, p, drawntreasure, &tempHand, z, cardDrawn) == 0);
        printf("playAdventurer(): PASS successful return\n");

        int count = 0;
        for (i = 0; i < G.handCount[p]; i++) {
            if (G.hand[p][i] == adventurer)
                count++;
        }
        if (count == 0)
            printf("playAdventurer(): PASS adventurer discarded from hand\n");
        else
            printf("playadventurer(): FAIL adventurer card is still in hand\n");

        count = 0;
        for (i = 0; i < G.handCount[p]; i++) {
            if (G.hand[p][i] == silver)
                count++;
        }
        if (count == 2)
            printf("playAdventurer(): PASS 2 silvers found in hand\n");
        else
            printf("playAdventurer(): FAIL expected 2 silvers in hand, found %d\n", count);
    }

    return 0;
}
