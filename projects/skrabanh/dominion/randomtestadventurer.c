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

	int rando;
	int handCount, deckCount, treasureCount, handTreasures, treasureCheck;
	int drawFail = 0;
	int treasureFail = 0;

	int treasures[3] = {copper, silver, gold};
	int k[10] = {adventurer, council_room, gardens, mine, smithy, village, great_hall, minion, tribute, ambassador };

	int i, n, p, j, card;

	for (n = 0; n < numTests; n++){
		for(i = 0; i < sizeof(struct gameState); i++){		//fill game stat with random data
			((char*)&G)[i] = floor(Random() * 256);
		}
		p = floor(rand() % 3 + 2  );				//between 2 and 4 players
		initializeGame(p, k, 1000, &G);			
		treasureCount = floor(rand() % 100 + 3);		//at least 2, but less than 100
		
		
		for(j = 0; j < treasureCount; j++){			//insert a random treasure into the deck
			rando = rand() % 3;
			G.deck[p][j] = treasures[rando];	
		}

		G.deckCount[p] = floor(rand() % 500 + 1);		//up to 500 cards in deck
		G.handCount[p] = floor(rand() % 500 + 1);		//up to 500 cards in hand
		G.whoseTurn = p;	

		handCount = G.handCount[p];				//save the random counts for comparison
		deckCount = G.deckCount[p];

		for(j = 0; j < handCount; j++){				//count the number of treasures in the hand
			card = G.hand[p][j];
			if( card == copper || card == silver || card == gold){
				handTreasures++;
			}
		} 

		cardEffect(adventurer, 0, 0, 0, &G, 0, 0);		//play the card
		
		if(G.handCount[p] != (handCount + 2)){			//check the new counts
			drawFail++;
		}

		if(treasureCheck != (handTreasures + 2)){
			treasureFail++;
		}
	}

	printf("Random testing completed\n");

	if(drawFail > 0){						//print results
		printf("%d failures from drawCard()\n", drawFail);
	}else{
		printf("No failures from drawCard()\n");
	}


	if(treasureFail > 0){						
		printf("%d failures from incorrect number of treasures\n", treasureFail);
	}else{
		printf("No failures from drawCard()\n");
	}

	return 0;
}
