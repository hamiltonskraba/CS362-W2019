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
	printf("---Random tests for Smithy---\n");

	struct gameState G;
	srand(time(0));

	int handCount, deckCount, discardCount;
	int drawFail = 0;
	int discardFail = 0;

	int k[10] = {adventurer, council_room, gardens, mine, smithy, village, great_hall, minion, tribute, ambassador };

	int i, n, p;

	for (n = 0; n < numTests; n++){
		for(i = 0; i < sizeof(struct gameState); i++){		//fill game stat with random data
			((char*)&G)[i] = floor(Random() * 256);
		}
		p = floor(rand() % 3 + 2  );				//between 2 and 4 players
		initializeGame(p, k, 1000, &G);			
		G.deckCount[p] = floor(rand() % 500 + 1);		//up to 500 cards in deck
		G.discardCount[p] = floor(rand() % 500 + 1);		//up to 500 cards in discard
		G.handCount[p] = floor(rand() % 500 + 1);		//up to 500 cards in hand
		G.whoseTurn = p;	

		handCount = G.handCount[p];				//save the random counts for comparison
		deckCount = G.deckCount[p];
		discardCount = G.discardCount[p];

		cardEffect(smithy, 0, 0, 0, &G, 0, 0);			//play the card
		
		if(G.handCount[p] != (handCount + 2)){			//check the new counts
			drawFail++;
		}

		if(G.deckCount[p] != (deckCount - 3)){
			drawFail++;
		}

		if(G.discardCount[p] != (discardCount + 1)){
			discardFail++;
		}		
	}

	printf("Random testing completed\n");

	if(drawFail > 0){						//print results
		printf("%d failures from drawCard()\n", drawFail);
	}else{
		printf("No failures from drawCard()\n");
	}

	if(discardFail > 0){
		printf("%d failures of %d from discardCard()\n", discardFail, numTests);
	}else{
		printf("No failures from discardCard()\n");
	}

	return 0;
}
