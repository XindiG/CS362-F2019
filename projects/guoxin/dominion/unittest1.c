
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>		// From study of random in lectures and work


#define TESTCARD "baron"

int main()
{
    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
	int numActions = 1;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, village, council_room, embargo, minion, mine, 
				cutpurse, sea_hag, tribute, smithy};

	int myRandNum;	
	myRandNum = (rand() %(5 - 2 + 1)) + 2; // 5 is upper, 2 is lower 
				
	// Initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
		
	printf("------------- Testing Card: %s ------------\n", TESTCARD);
	
	// Copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	
	baronEffect(choice1, thisPlayer, handpos, &testG);

	if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) 
	{
		printf("Drawn Card = %d, expected = %d\n", myRandNum, drawntreasure); // cardDrawn is replaced by myRandNum
		// drawntreasure++;
	}
	assert(myRandNum == drawntreasure);
	
	// THIS IS MY CODE FROM ASSIGNMENT 3: 
	// cardResult_Adventurer(&myTestGameState, 0);
	// printf("Expected: %d, Versus What We Get: %d\n", myGameState.handCount[myGameState.whoseTurn] + 2, myTestGameState.handCount[myTestGameState.whoseTurn]);
		
	return 0;
}