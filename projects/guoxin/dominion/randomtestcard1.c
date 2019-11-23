#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include<time.h>

int main() 
{
	srand(time(NULL));
	
    int a;
    int handpos = 0, choice1 = 0;
    int seed = 1000;
    //int numPlayers = 2;
    int player=0;
	struct gameState state, test;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, baron, council_room};

	for(a = 0; a < 10000; a++)
	{
		int numPlayers = (rand() % 50);
		//int seed = (rand() % 100);
	
		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &state);

		printf("\n----------Testing baron card Pass %d/10000----------\n", a+1);


		memcpy(&test, &state, sizeof(struct gameState));
		baron_effect(choice1, player, handpos, &state);

		player = whoseTurn(&test);
		
		//Check players hand
		if(state.hand[player][test.handCount[player]-1] != -1)
			printf("Passed where baron card was added to the players hand\n");
		else
			printf("Failed where baron card was not added to the players hand\n");

		if(test.playedCardCount+1 == state.playedCardCount)
			printf("Passed where player played baron card\n");
		else
			printf("Failed where player did not play baron card\n");
			
		if(test.numBuys == state.numBuys)
			printf("Passed where numbuys was added\n");	
		else	
		{
			printf("Failed where the numbuys was not added.\n");
		}
		
		//Action Test: Check if the +3coins was added
		if(test.coins+4 == state.coins)
			printf("Passed where coins was added\n");
		else
			printf("Failed where coins was not added\n");
	}
	printf("----------End Testing Card----------\n");
}
