// unit testing the function isGameOver (line 390)
#include "dominion.h"
#include "rngs.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// int isGameOver(struct gameState *state)
// returns 0 if the game is not over
// returns -1 if the game is over:
// the province supply is empty
// or three of the supply piles are empty
int main() {
    printf("\n###################\n");
    printf("Unit test 4 - isGameOver()\n");

    int p, testOver;
    int seed = 999;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;

    for (p = 0; p < numPlayer; p++) {
        printf("\n--- Testing player %d\n", p);

        // clear the gameState
        memset(&G, 23, sizeof(struct gameState));
        initializeGame(numPlayer, k, seed, &G);

        printf("-- Testing incomplete game\n");
        testOver = isGameOver(&G);
        if (testOver == 0)
            printf("isGameOver(): PASS game will continue\n");
        else
            printf("isGameOver(): FAIL game ended incorrectly\n");

        printf("-- Testing empty Province pile\n");
        G.supplyCount[province] = 0;
        testOver = isGameOver(&G);
        if (testOver == 1)
            printf("isGameOver(): PASS game ended correctly\n");
        else
            printf("isGameOver(): FAIL game continues\n");

        printf("-- Testing two empty supply piles\n");
        G.supplyCount[province] = 1;
        G.supplyCount[2] = 0;
        G.supplyCount[6] = 0;
        testOver = isGameOver(&G);
        if (testOver == 0)
            printf("isGameOver(): PASS game will continue\n");
        else
            printf("isGameOver(): FAIL game ended incorrectly\n");

        printf("-- Testing three empty supply piles\n");
        G.supplyCount[4] = 0;
        testOver = isGameOver(&G);
        if (testOver == 1)
            printf("isGameOver(): PASS game ended correctly\n");
        else
            printf("isGameOver(): FAIL game continues\n");
    }
    return 0;
}
