#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include <math.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>


#define numTests 100

int main(){
	printf("---Random tests for Village---\n");

	struct gameState G;
	srand(time(0));

	int actionFail = 0, deckFail = 0, drawFail = 0, discardFail = 0;
	int handCount, deckCount, discardCount, actionCount;

	int k[10] = {adventurer, council_room, gardens, mine, smithy, village, great_hall, minion, tribute, ambassador };

	int i, n, p;

	for (n = 0; n < numTests; n++){
		for(i = 0; i < sizeof(struct gameState); i++){		//fill game stat with random data
			((char*)&G)[i] = floor(Random() * 256);
		}
		p = floor(rand() % 3 + 2  );				//between 2 and 4 players
		initializeGame(p, k, 1000, &G);	
		G.numActions = floor(rand() % 50 + 1);			//up to 50 actions		
		G.deckCount[p] = floor(rand() % 500 + 1);		//up to 500 cards in deck
		G.discardCount[p] = floor(rand() % 500 + 1);		//up to 500 cards in discard
		G.handCount[p] = floor(rand() % 500 + 1);		//up to 500 cards in hand
		G.whoseTurn = p;	

		handCount = G.handCount[p];				//save the random counts for comparison
		deckCount = G.deckCount[p];
		discardCount = G.discardCount[p];
		actionCount = G.numActions;

		//printf("Test #%d deck=%d hand=%d discard=%d actions=%d\n", n, deckCount, handCount, discardCount, actionCount);

		cardEffect(village, 0, 0, 0, &G, 0, 0);			//play the card

		if(G.numActions != (actionCount + 2)){
			actionFail++;
		}

		if(G.deckCount != (deckCount - 1)){
			deckFail++;
		}

		if(G.discardCount != (discardCount + 1)){
			discardFail++;
		}

		if(G.handCount != (handCount + 1)){
			drawFail++;
		}

	}


		if(actionFail > 0){
			printf("Incorrect actions attributed %d of %d tests\n", actionFail, numTests);
		}else{
			printf("Actions attributed as expected\n");
		}

		if(deckFail > 0){
			printf("Incorrect number of cards drawn from deck %d of %d tests\n", deckFail, numTests);
		}else{
			printf("Cards drawn from deck as expected\n");
		}

		if(drawFail > 0){
			printf("Incorrect number of cards in hand %d of %d tests\n", drawFail, numTests);
		}else{
			printf("Cards drawn into hand as expected\n");
		}

		if(discardFail > 0){
			printf("Incorrect card count in discard pile %d of %d tests\n", discardFail, numTests);
		}else{
			printf("Cards discarded as expected\n");
		}

	return 0;
}	
