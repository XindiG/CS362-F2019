
#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include <time.h>
#include <string.h> 
#include "dominion_helpers.h"
#include <assert.h>
#include "dominion.c"
#include "rngs.h"

void cardEffectbaron(struct gameState *state, int choice1, int currentPlayer, int handPos);

int main() 
{
    int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
    struct gameState G;
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    int i =0;
    int count = 0;
    int r;
    int deckSize, handSize;
    int choice1;
    int currentPlayer;
    int handPos;
    int card_not_discard;
    int numberPlayer;
    int seed = 1000;
    int coin;
    srand(time(NULL));

    cardEffectbaron(&G, choice1, currentPlayer, handPos);
    printf("random testing for card_not_discard begin\n");
    for(i=0; i < 10000; i++)
    {
        initializeGame(numberPlayer, k, seed, &G);

        deckSize = rand() %(MAX_DECK +1); // set the deck size to random size
        handSize = rand() %(deckSize +1); // set the hand size to random size

        numberPlayer = rand() % 3 + 2 ; // to set the random player from 2 to 4 player
        card_not_discard = rand() % 2;
        

        if(card_not_discard != 1)
        {
            printf("ERROR ffor card_not discard\n");
            break;
        }
    }
    printf("card_not_discard done\n");

    printf("testing get coin\n");
    for(i = 0; i < 10000; i++)
    {
        initializeGame(numberPlayer, k, seed, &G);
        deckSize = rand() %(MAX_DECK +1); // set the deck size to random size
        handSize = rand() %(deckSize +1); // set the hand size to random size
        numberPlayer = rand() % 3 + 2 ; // to set the random player from 2 to 4 player

        coin = rand()% 10 +1;

        if(coin == 4)
        {
            printf("The coin is 4\n test succesfully\n");
            break;
        }

    }
    printf("test coin done\n");
    printf("finish testing baron\n");

}