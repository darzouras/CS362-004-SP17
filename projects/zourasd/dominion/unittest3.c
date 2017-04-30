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

    /* if (getCost(curse) == 0)
        printf("getCost(): PASS cost of Curse is correct\n");
    else
        printf("getCost(): FAIL cost of Curse returned %d, expected 0\n", getCost(curse)); */

    if (getCost(estate) == 2)
        printf("getCost(): PASS cost of Estate is correct\n");
    else
        printf("getCost(): FAIL cost of Estate returned %d, expected 2\n", getCost(estate));

    if (getCost(duchy) == 5)
        printf("getCost(): PASS cost of Dutchy is correct\n");
    else
        printf("getCost(): FAIL cost of Dutchy returned %d, expected 5\n", getCost(duchy));

    if (getCost(province) == 8)
        printf("getCost(): PASS cost of Province is correct\n");
    else
        printf("getCost(): FAIL cost of Province returned %d, expected 8\n", getCost(province));

    if (getCost(copper) == 0)
        printf("getCost(): PASS cost of Copper is correct\n");
    else
        printf("getCost(): FAIL cost of Copper returned %d, expected 0\n", getCost(copper));

    if (getCost(silver) == 3)
        printf("getCost(): PASS cost of Silver is correct\n");
    else
        printf("getCost(): FAIL cost of Silver returned %d, expected 3\n", getCost(silver));

    if (getCost(gold) == 6)
        printf("getCost(): PASS cost of Gold is correct\n");
    else
        printf("getCost(): FAIL cost of Gold returned %d, expected 6\n", getCost(gold));

    if (getCost(adventurer) == 6)
        printf("getCost(): PASS cost of Adventurer is correct\n");
    else
        printf("getCost(): FAIL cost of Adventurer returned %d, expected 6\n", getCost(adventurer));

    if (getCost(council_room) == 5)
        printf("getCost(): PASS cost of Council Room is correct\n");
    else
        printf("getCost(): FAIL cost of Council Room returned %d, expected 5\n", getCost(council_room));

    if (getCost(feast) == 4)
        printf("getCost(): PASS cost of Feast is correct\n");
    else
        printf("getCost(): FAIL cost of Feast returned %d, expected 4\n", getCost(feast));

    if (getCost(gardens) == 4)
        printf("getCost(): PASS cost of Gardens is correct\n");
    else
        printf("getCost(): FAIL cost of Gardens returned %d, expected 4\n", getCost(gardens));

    if (getCost(mine) == 5)
        printf("getCost(): PASS cost of Mine is correct\n");
    else
        printf("getCost(): FAIL cost of Mine returned %d, expected 5\n", getCost(mine));

    if (getCost(remodel) == 4)
        printf("getCost(): PASS cost of Remodel is correct\n");
    else
        printf("getCost(): FAIL cost of Remodel returned %d, expected 4\n", getCost(remodel));

    if (getCost(smithy) == 4)
        printf("getCost(): PASS cost of Smithy is correct\n");
    else
        printf("getCost(): FAIL cost of Smithy returned %d, expected 4\n", getCost(smithy));

    if (getCost(village) == 3)
        printf("getCost(): PASS cost of Village is correct\n");
    else
        printf("getCost(): FAIL cost of Village returned %d, expected 3\n", getCost(village));

    if (getCost(baron) == 4)
        printf("getCost(): PASS cost of Baron is correct\n");
    else
        printf("getCost(): FAIL cost of Barn returned %d, expected 4\n", getCost(baron));

    if (getCost(great_hall) == 3)
        printf("getCost(): PASS cost of Great Hall is correct\n");
    if (getCost())

    // if time to do it, add tests for each card.

    return 0;
}
