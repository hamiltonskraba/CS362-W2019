#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

//card test for Adventurer

int main(){
	struct gameState G;

	int k[10] = { adventurer, council_room, gardens, mine, smithy, village, great_hall, minion, tribute, ambassador };

	printf("---Testing Adventurer Card---\n");

	initializeGame(2, k, 1000, &G);

	//play smithy card
	cardEffect(adventurer, 0, 0, 0, &G, 0, 0);
	printf("Testing for +2 treasures added: ");
	int handCount = G.handCount[0];
	if(handCount == 7){
		printf("Passed! The hand has %d cards\n", handCount);
	} else{
		printf("Failed! The hand has %d cards\n", handCount);
	}

	printf("Testing if copper deck count was altered: ");
	int fullCount = fullDeckCount(0, copper, &G);
	if(fullCount == 7){
		printf("Passed! The hand has %d coppers\n", fullCount);
	} else{
		printf("Failed! The hand has %d coppers\n", fullCount);
	}

	//end turn so opponent can draw
	endTurn(&G);
	
	printf("Testing if Opponent's deck count was altereted: ");
	int opCount = G.handCount[1];
	if(opCount == 5){
		printf("Passed! Opponent's deck count unaltered\n");
	} else{
		printf("Failed! Opponent's deck count is %d", opCount);
	}

	printf("Testing for change in Victory supply cards: ");
	if(G.supplyCount[estate] != 8){
		printf("Failed! Estate supply altered\n");
	}
	else if(G.supplyCount[duchy] != 8){
		printf("Failed! Duchy supply altered\n");
	}
	else if(G.supplyCount[province] != 8){
		printf("Failed! Province supply altered\n");
	}
	else {
		printf("Passed! Correct Victory card supply maintained\n");
	}

	return 0;
}
