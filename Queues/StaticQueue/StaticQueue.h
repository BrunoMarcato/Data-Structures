//
//  staticQueue.h
//  Queues
//
//  Created by Bruno Uhlmann Marcato on 10-11-21.
//

#ifndef staticQueue_h
#define staticQueue_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXTAM  8

typedef struct {
  int array[MAXTAM];
  int size;
  int start;
  int end;
} StaticQueue;

void initQueue(StaticQueue *queue);
void enqueue(int key, StaticQueue *queue);
void printQueue(StaticQueue *queue);
bool isEmpty(StaticQueue *queue);
bool isFull(StaticQueue *queue);
int sizeQueue(StaticQueue *queue);
int increaseIndex(int i);
int dequeue(StaticQueue *queue);
int first(StaticQueue *queue);
int last(StaticQueue *queue);

#endif