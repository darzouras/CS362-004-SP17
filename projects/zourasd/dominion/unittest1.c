// unit testing the function fullDeckCount (line 324)
#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>

// The fullDeckCount function requires three parameters: int player, int cards, and struct Gamestate *state.
// It returns an int count, which is the total number that a particular card appears in a player's complete deck.
// The function counts the deck by incrementing through these parts of the gameState, comparing against the int card:
//      state->deckCount[player],
//      state->handCount[player],
//      and state->discardCount[player].
int main() {
    int p = 1;      // for our test, player number 1 should be fine
    int c = 7;      // let's say we are counting how many adventurer cards are found in player 1's deck

    // the gameState is built all with acceptable
    struct gameState *state = malloc(sizeof(struct gameState));


}
