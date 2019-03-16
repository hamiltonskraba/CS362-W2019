#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"


//unit test for getCost()

int main(){	
	printf("---Testing getCost()---\n");
	printf("Checking that curse cards cost nothing: ");
	if(getCost(curse) == 0){
		printf("Passed!\n");
	} else{
		printf("Failed!\n");
	}

	printf("Checking that province cards cost 8: ");
	if(getCost(province) == 8){
		printf("Passed!\n");
	} else{
		printf("Failed!\n");
	}

	printf("Checking that village cards cost 3: ");
	if(getCost(village) == 3){
		printf("Passed!\n");
	} else{
		printf("Failed!\n");
	}

	printf("Checking that council room cards cost 5: ");
	if(getCost(council_room) == 5){
		printf("Passed!\n");
	} else{
		printf("Failed!\n");
	}

	return 0;
}
