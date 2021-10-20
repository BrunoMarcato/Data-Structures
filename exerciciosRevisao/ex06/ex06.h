/*
    @author Bruno Uhlmann Marcato
    @date 04-10-2021
    @file ex06.h
    @brief header archive of exercise 6
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>

#ifndef ex06_h
#define ex06_h

//Card abstract type
typedef struct {
    char value;
    char suit;
    bool wasPlayed;
} Card;

//Deck abstract type
typedef struct {
    Card array[54];
} Deck;

//manipulation functions
void createDeck(Deck *deck);
void printCard(Card c);
void printDeck(Deck deck);
int unplayedCards(Deck *deck);
Card* top(Deck *deck);
Card* bottom(Deck *deck);
Card* carding(Card cards[], Deck *deck);

#endif
