#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"

//card test for Village

int main(){
	struct gameState G;

	int k[10] = { adventurer, council_room, gardens, mine, smithy, village, great_hall, minion, tribute, ambassador };

	printf("---Testing Village Card---\n");

	initializeGame(2, k, 1000, &G);

	//play village card
	cardEffect(village, 0, 0, 0, &G, 0, 0);
	printf("Testing for +1 card and Village discard: ");
	int handCount = G.handCount[0];
	if(handCount == 5){
		printf("Passed! The hand has %d cards\n", handCount);
	} else{
		printf("Failed! The hand has %d cards\n", handCount);
	}

	printf("Testing for +2 actions: ");
	int actionCount = G.numActions;
	if(actionCount == 3){
		printf("Passed! Player has another action available\n");
	} else{
		printf("Failed! The player has %d actions available\n", actionCount);
	}


	printf("Testing to see if new cards are from own draw pile: ");
	int i, card;
	int b = 1;
	for(i = 0; i < handCount; i++){
		card = handCard(i, &G);
		switch(card){
			case 1:
			case 4:
				break;
			default:
			printf("Failed! Hand contains card enum #%d\n", card);
			b = 0;
		}
	}
	if(b){
		printf("Passed! Hand only contains coppers and estates\n");
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
