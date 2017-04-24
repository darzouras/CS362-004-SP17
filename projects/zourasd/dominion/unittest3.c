// unit testing for the getCost function (line 583)
#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// getCost takes one parameter: int cardNumber
// it uses a switch to match the card with its cost, which is returned.
int main() {
    printf("Unit test - getCost\n");
    // to test these, we will simply pass any out of the 27 card types
    // and compare the results of the getCost function
    assert(getCost(0) == 0);
    printf("Cost of Curse (0) is correct\n");

    assert(getCost(1) == 2);
    printf("Cost of Estate (1) is correct\n");

    assert(getCost(2) == 5);
    printf("Cost of Dutchy (2) is correct\n");

    assert(getCost(3) == 8);
    printf("Cost of Province (3) is correct\n");

    assert(getCost(4) == 0);
    printf("Cost of Copper (4) is correct\n");

    assert(getCost(5) == 3);
    printf("Cost of Silver (5) is correct\n");

    printf("All tests passed!\n\n");

    return 0;
}
