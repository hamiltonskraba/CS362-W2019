#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"


//unit test for supplyCount()

int main(){	
	int seed = 1000;
	int k[10] = { adventurer, council_room, gardens, mine, smithy, village, great_hall, minion, tribute, ambassador };
	struct gameState G2, G3;

	printf("---Testing supplyCount()---\n");

	initializeGame(2, k, seed, &G2);	//initialize 2 seperate games with different amount of players
	initializeGame(3, k, seed, &G3);

	//game initialized to 2 players; there should be 10 curse cards available
	printf("Curse cards for a 2 player game should be 10: ");
	if(G2.supplyCount[curse] == 10){
		printf("Passed\n");
	} else {
		printf("Failed\n");
	}	

	printf("Curse cards for a 3 player game should be 20: ");
	if(G3.supplyCount[curse] == 20){
		printf("Passed\n");
	} else {
		printf("Failed\n");
	}
	
	printf("A player gains a curse in the 2 player game, resulting in a count of 9 available in the supply pile: ");
	gainCard(curse, &G2, 0, 0);
	if(G2.supplyCount[curse] == 9){
		printf("Passed\n");
	} else {
		printf("Failed\n");
	}	

	printf("Testing a pile after all cards drawn: ");
	int i;
	for(i = 0; i < 20; i++){			//draw 20 curse cards
		gainCard(curse, &G3, 0, 0);
	}
	if(G3.supplyCount[curse] == 0){
		printf("Passed\n");
	} else {
		printf("Failed\n");
	}	

	printf("Testing for an invalid number of curse cards avilable: ");
	G2.supplyCount[curse] = -1;
	if(G2.supplyCount[curse] == -1){
		printf("Passed\n");
	} else {
		printf("Failed\n");
	}


	return 0;
}
