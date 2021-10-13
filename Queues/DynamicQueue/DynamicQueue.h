//
//  dynamicQueue.h
//  Queues
//
//  Created by Bruno Uhlmann Marcato on 10-12-21.
//

#ifndef dynamicQueue_h
#define dynamicQueue_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NodeQueue *Pointer;

typedef struct NodeQueue{
    int item;
    Pointer next;
} NodeQueue;

typedef struct {
    Pointer start;
    Pointer end;
    int size;
} DynamicQueue;

void initQueue(DynamicQueue *queue);
void enqueue(int x, DynamicQueue *queue);
int dequeue(DynamicQueue *queue);
void printQueue(DynamicQueue *queue);
void destroy(DynamicQueue *queue);
int isEmpty(DynamicQueue *queue);
int queueSize(DynamicQueue *queue);
int first(DynamicQueue *queue);
int last(DynamicQueue *queue);

#endif