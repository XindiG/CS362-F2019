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
    int handpos = 0, choice1 = 0, choice2 =1;
    int seed = 1000;
    //int numPlayers = 2;
    int player=0;
	struct gameState state, test;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	for(a = 0; a < 10000; a++)
	{
		int numPlayers = (rand() % 50);
		//int seed = (rand() % 100);
	
		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &state);

		printf("\n----------Testing Minion Card Pass %d/10000----------\n", a+1);


		memcpy(&test, &state, sizeof(struct gameState));
		minion_effect(choice1,choice2, player, handpos, &state);

		player = whoseTurn(&test);
		
		//Check players hand
		if(state.hand[player][test.handCount[player]-1] != -1)
			printf("Passed where minion card was added to the players hand\n");
		else
			printf("Failed where minion card was not added to the players hand\n");

		if(test.playedCardCount+1 == state.playedCardCount)
			printf("Passed where player played minion card\n");
		else
			printf("Failed where player did not play minion card\n");
			
		if(test.discardCount[player] == state.discardCount[player])
			printf("Passed where the minion was discarded\n");	
		else	
		{
			printf("Failed where the minion was not discarded.\n");
		}
		
		//Action Test: Check if the +3coins was added
		if(test.numActions+1 == state.numActions)
			printf("Passed where an extra action was added\n");
		else
			printf("Failed where an extra action was not added\n");
	}
	printf("----------End Testing Card----------\n");
}
