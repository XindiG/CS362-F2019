#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>	

 
#define TESTCARD "ambassador"


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
	myRandNum = (rand() %(2 - 1 + 1)) + 1; // 2 is upper, 1 is lower 				
				
	// Initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
		
	printf("------------- Testing Card: %s ------------\n", TESTCARD);
	
	// Copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	
 	minionEffect(choice1, choice2, thisPlayer, handpos, &testG);
		
	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + 1 - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - 1 + shuffledCards);
	printf("number of actions = %d, expected = %d\n", testG.numActions[thisPlayer], G.numActions[thisPlayer] + myRandNum); // 2 is replaced by myRandNum

	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + 1 - discarded);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - 1 + shuffledCards);
	assert(testG.numActions[thisPlayer] == G.numActions[thisPlayer] + myRandNum);
		
	return 0;
}