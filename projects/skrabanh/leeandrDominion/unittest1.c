#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

//unit testing for isGameOver()

int main() {
	int seed = 1000;
	int k[10] = { adventurer, council_room, gardens, mine, smithy, village, great_hall, minion, tribute, ambassador };
	struct gameState G;

	printf("---Testing isGameOver()---\n");

	initializeGame(MAX_PLAYERS, k, seed, &G);

	printf("Testing Province count != 0: ");		//should return false
	G.supplyCount[province] = 1;

	if (isGameOver(&G)) {
		printf("Failed\n");
	}
	else {
		printf("Passed\n");
	}

	printf("Testing Province count = 0: ");		//should return true
	G.supplyCount[province] = 0;

	if (isGameOver(&G)) {
		printf("Passed\n");
	}
	else {
		printf("Failed\n");
	}

	printf("Testing 1 empty supply pile with providences still in play: ");		//should return false
	G.supplyCount[province] = 4;
	G.supplyCount[1] = 0;

	if (isGameOver(&G)) {
		printf("Failed\n");
	}
	else {
		printf("Passed\n");
	}

	printf("Testing 3 empty supply piles with providences still in play: ");		//should return true
	G.supplyCount[0] = 0;
	G.supplyCount[2] = 0;

	if (isGameOver(&G)) {
		printf("Passed\n\n");
	}
	else {
		printf("Failed\n\n");
	}

	return 0;
}
