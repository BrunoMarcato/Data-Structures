/*
    @author Bruno Uhlmann Marcato
    @date 04-10-2021
    @file ex06.c
    @brief methods archive of exercise 6
*/

#include "ex06.h"

//global variables
char symbols[13] = {'A','2','3','4','5','6','7','8','9','10','J','Q','K'};
char suits[4] = {'E','P','O','C'};

//------------------------------------------------

void createDeck(Deck *deck) {

    for(int i = 0; i < 52; i++) {

            deck -> array[i].value = symbols[i % 13];
            deck -> array[i].suit = suits[i % 4];
            deck->array[i].wasPlayed = false;

    }//for

    //inicialize the jokers
    deck -> array[53].value = 'C';
    deck -> array[53].suit = ' ';
    deck -> array[53].wasPlayed = false;

    deck -> array[54].value = 'C';
    deck -> array[54].suit = ' ';
    deck -> array[54].wasPlayed = false;
}//createDeck

//------------------------------------------------

void printDeck(Deck deck) {

  for(int i = 0; i < 54; i++){
    printCard(deck.array[i]);
  }//for
}//printDeck

//------------------------------------------------

void printCard(Card c) {
  printf("======================\n");
  printf("Value = %c\n", c.value);
  printf("Suit = %c\n", c.suit);
  printf("Was played? = %d\n", c.wasPlayed);
  printf("======================\n");
}//printCard

//------------------------------------------------

int unplayedCards(Deck *deck) {

    int cardCounter = 0;

    for(int i = 0; i < 54; i++) {
        if(!deck -> array[i].wasPlayed) {
            cardCounter++;
        }//if
    }//for

    return cardCounter;

}//unplayedCards

//------------------------------------------------

Card* top(Deck *deck) {
    for(int i = 54; i >= 0; i--) {
        if(!deck -> array[i].wasPlayed) {
            return(&deck -> array[i]);
        }//if
    }//for
    printf("there is no card to be consulted");
    return NULL;
}//top

//------------------------------------------------

Card* bottom(Deck *deck) {
    for(int i = 0; i <= 54; i++) {
        if(!deck -> array[i].wasPlayed) {
            return(&deck -> array[i]);
        }//if
    }//for
    printf("there is no card to be consulted");
    return NULL;
}//bottom

//------------------------------------------------

Card* carding(Card cards[], Deck *deck) {
    
    int randCard;

    time_t t;
    srand((unsigned) time(&t));

    int i = 0;
    while(i != 3) {
        randCard = rand() % 54;
        if(!deck -> array[randCard].wasPlayed) {

            deck -> array[randCard].wasPlayed = true;
            cards[i] =  deck -> array[randCard];
            i++;

        }//if

    }//while

    
    return cards;

}//carding

//------------------------------------------------
