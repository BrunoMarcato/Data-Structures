/*
    @author Bruno Uhlmann Marcato
    @date 04-10-2021
    @file main.c
    @brief main function and aplications of exercise 6
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ex06.c"

int main(int argc, const char * argv[]) {
    //declaration of variables
    Deck deck;
    Card cards[3], *topCard, *bottomCard;
    int unplayed, players;

    //create a deck
    printf("Creating deck...\n");
    sleep(3);
    createDeck(&deck);

    //print the deck
    printf("Printing deck...\n\n");
    sleep(1);
    printDeck(deck);

    printf("Number of players: ");
    scanf("%d", &players);
    printf("Carding 3 cards of the deck for each player...\n\n");
    sleep(3);
    for(int i = 0; i < players; i++) {
        //carding 3 cards for each player
        carding(cards, &deck);
        printf("Player %d: ", i+1);
        //print the cards
        for(int j = 0; j < 3; j++) {
            printf(" %c%c ", cards[j].value, cards[j].suit);
        }//for
        printf("\n");
    }//for
    sleep(1);

    //calculating the amount of unplayed cards
    unplayed = unplayedCards(&deck);
    printf("There are %d unplayed cards\n", unplayed);

    //Which card is at the top of the deck?
    topCard = top(&deck);
    printf("\nCard at the top of the deck:\nValue: %c\nSuit: %c\n", topCard->value, topCard->suit);

    //which card is at the bottom of the deck?
    bottomCard = bottom(&deck);
    printf("\nCard at the bottom of the deck:\nValue: %c\nSuit: %c\n", bottomCard->value, bottomCard->suit);
    return 0;
}//main