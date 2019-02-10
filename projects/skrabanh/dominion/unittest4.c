#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"


//unit test for scoreFor()

int main(){	
	int seed = 1000;
	struct gameState G;

	int k[10] = { adventurer, council_room, gardens, mine, smithy, village, great_hall, minion, tribute, ambassador };

	initializeGame(2, k, seed, &G);

	printf("Player 1 initial score should be 3: ");
	int score1 = scoreFor(0, &G);
	if(score1 == 3){
		printf("Passed!");
	} else{
		printf("Failed! Score is %d\n", score1);
	}

	printf("Player 2 initial score should be 3: ");
	int score2 = scoreFor(1, &G);
	if(score2 == 3){
		printf("Passed!");
	} else{
		printf("Failed! Score is %d\n", score1);
	}
	
	printf("Player 1 gains a province: ");
	gainCard(province, &G, 2, 0);
	score1 += 6;
	if(scoreFor(0, &G) == score1){
		printf("Passed! Score is %d\n", score1);
	} else{
		printf("Failed! Score is %d\n", score1);
	}

	printf("Player 2 gains a curse: ");
	gainCard(curse, &G, 2, 1);
	score2 -= 1;
	if(scoreFor(1, &G) == score2){
		printf("Passed! Score is %d\n", score2);
	} else{
		printf("Failed! Score is %d\n", score2);
	}
	
	return 0;
}
