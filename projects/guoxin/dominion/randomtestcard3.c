#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 1300

//This randomly tests tribute

int main() {
    
	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
    int *reveals = malloc(10 * sizeof(int));
    int rand = rand() % 10;
    for(i = 0; i<10; i++){
      reveals[i] = k[rand];
    }

	  int i, j, n, players, player, handCount, deckCount, seed, address;
	  //struct gameState state;
	  struct gameState state;
	  struct gameState stat;
	  struct gameState sta;
    

	  printf("Running Random Card Test for tribute\n");

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


		  tribute_effect(&state, 1, 2, reveals);		//Run card

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


		  tribute_effect(&stat, 1, 2, reveals);		//Run card

		  		  printf("%dB\n", i);

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

		  tribute_effect(&sta, 1, 2, reveals);		//Run card

		 printf("%dB\n", i);

	  }


	  printf("Tests Complete\n");

	  return 0;
}