// unit testing for the getCost function (line 583)
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void checkCost(char* card, int cardName, int expectedCost) {
    if (getCost(cardName) == expectedCost)
        printf("getCost(): PASS cost of %s returned %d\n", card, expectedCost);
    else
        printf("getCost(): FAIL cost of %s returned %d, expected %d\n", card, getCost(cardName), expectedCost);

    return;
}

// getCost takes one parameter: int cardNumber
// it uses a switch to match the card with its cost, which is returned.
int main() {
    printf("\n####################\n");
    printf("Unit test 3 - getCost()\n");
    // to test these, we will simply pass any out of the 27 card types
    // and compare the results of the getCost function
    if (getCost(-1) == -1)
        printf("getCost(): PASS bad card name returns -1\n");
    else
        printf("getCost(): FAIL bad card name returned %d, expected -1\n", getCost(-1));

    checkCost("Curse", curse, 0);
    checkCost("Estate", estate, 2);
    checkCost("Duchy", duchy, 5);
    checkCost("Province", province, 8);
    checkCost("Copper", copper, 0);
    checkCost("Silver", silver, 3);
    checkCost("Gold", gold, 6);
    checkCost("Adventurer", adventurer, 6);
    checkCost("Council Room", council_room, 5);
    checkCost("Feast", feast, 4);
    checkCost("Gardens", gardens, 4);
    checkCost("Mine", mine, 5);
    checkCost("Remodel", remodel, 4);
    checkCost("Smithy", smithy, 4);
    checkCost("Village", village, 3);
    checkCost("Baron", baron, 4);
    checkCost("Great Hall", great_hall, 3);
    checkCost("Minion", minion, 5);
    checkCost("Steward", steward, 3);
    checkCost("Tribute", tribute, 5);
    checkCost("Ambassador", ambassador, 3);
    checkCost("Cutpurse", cutpurse, 4);
    checkCost("Embargo", embargo, 2);
    checkCost("Outpost", outpost, 5);
    checkCost("Salvager", salvager, 4);
    checkCost("Sea Hag", sea_hag, 4);
    checkCost("Treasure Map", treasure_map, 4);

    // if time to do it, add tests for each card.

    return 0;
}
