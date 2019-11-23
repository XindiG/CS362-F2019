#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 1300

//This randomly tests minion
int main() {

	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	  int i, j, n, players, player, handCount, deckCount, seed, address;
	  struct gameState state;
	  struct gameState stat;
	  struct gameState sta;

	  printf("Running Random Card Test for minion\n");

	  for (i = 0; i < MAX_TESTS; i++) {

		  
		 players = rand() % 4;
		 seed = rand();		//pick random seed
		
		 initializeGame(players, k, seed, &state);	//initialize Gamestate

		  //Initiate valid state variables
		  state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  state.discardCount[player] = rand() % MAX_DECK;
		  state.handCount[player] = rand() % MAX_HAND;


		  //Copy state variables
		  handCount = state.handCount[player];
		  deckCount = state.deckCount[player];

		  		  	  		  		  printf("%d\n", i);


		  minion_effect(1, 1, 1, 1, &state);		//Run card

		  printf("%dB\n", i);
	  }


	   for (i = 0; i < MAX_TESTS; i++) {

		   
	  printf("PRE2\n");

	  initializeGame(players, k, seed, &stat);	//initialize Gamestate

	printf("POST\n");
		
		  //Initiate valid state variables
		  stat.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  stat.discardCount[player] = rand() % MAX_DECK;
		  stat.handCount[player] = rand() % MAX_HAND;


		  //Copy state variables
		  handCount = stat.handCount[player];
		  deckCount = stat.deckCount[player];

   		  printf("%d\n", i);


		  minion_effect(1, 1, 1, 1, &stat);		//Run card

		  		  printf("%dB\n", i);
                                 
      if(stat.numActions+1 == stat.numActions)
			  printf("Passed where extra action was added\n");
		  else
			  printf("Failed where extra action was not added\n");

	  }


	   for (i = 0; i < MAX_TESTS; i++) {


		   	   	  printf("PRE2\n");


 	  initializeGame(players, k, seed, &sta);	//initialize Gamestate

	  	printf("POST2\n");

		  //Initiate valid state variables
		  sta.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
		  sta.discardCount[player] = rand() % MAX_DECK;
		  sta.handCount[player] = rand() % MAX_HAND;


		  //Copy state variables
		  handCount = sta.handCount[player];
		  deckCount = sta.deckCount[player];

		  printf("%d\n", i);

		  minion_effect(1, 1, 1, 1, &sta);		//Run card

		 printf("%dB\n", i);
      
      if(sta.coins+2 == sta.coin)
			  printf("Passed where two coins was added\n");
		  else
			  printf("Failed where two coins was not added\n");

	  }


	  printf("Tests Complete\n");
}
