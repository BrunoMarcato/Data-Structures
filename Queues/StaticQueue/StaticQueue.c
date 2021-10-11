/*
    @author Bruno Uhlmann Marcato
    @file StaticQueue.c
    @date 10-11-2021
    @brief static queue manipulation functions 
*/

#include "StaticQueue.h"

//----------------------------------------

//to start the queue, set start and length to 0 and the end to -1 (because it is empty and therefore there is no "end" yet)

void initQueue(StaticQueue *queue) {
    queue-> start = 0;
    queue -> end = -1;
    queue -> size = 0;
}//initQueue

//----------------------------------------

int sizeQueue(StaticQueue *queue) {
    return queue -> size;
}//sizeQueue

//----------------------------------------

//if the queue size is 0 then it is full

bool isEmpty(StaticQueue *queue) {
    return (queue -> size == 0);
}//isEmpty

//----------------------------------------

//if the queue size is MAXTAM then it is full

bool isFull(StaticQueue *queue) {
    return (queue -> size == MAXTAM);
}//isFull

//----------------------------------------

//Checks whether the value passed as a parameter is equal to the queue size - 1, 
//simulating a circular buffer to reuse the memory of invalidated values

int increaseIndex(int i) {
    int newValue = (i+1) % MAXTAM;
    return newValue;
}//increaseIndex

//----------------------------------------

void enqueue(int key, StaticQueue *queue) {
    if(!isFull(queue)) {
        queue -> end = increaseIndex(queue -> end);
        queue -> array[queue -> end] = key;
        queue -> size++;
    } else printf("The queue is Full!");
}//enqueue

//----------------------------------------

int dequeue(StaticQueue *queue) {
    int aux = -999;
    if(!isEmpty(queue)) {
        aux = queue -> array[queue -> start];
        queue -> start = increaseIndex(queue -> start);
        queue -> size--;
        return aux;
    } else printf("Queue is Empty!");
}//dequeue

//----------------------------------------

void printQueue(StaticQueue *queue) {
    printf("{ ");
    int n = sizeQueue(queue);
    for(int i = 0; i < n; i++) {
        int index = (queue -> start + i) % MAXTAM;
        printf("%d ", queue -> array[index]);
    }//for
    printf(" }\n");
}//printQueue

//----------------------------------------

int first(StaticQueue *queue) {
    return (queue -> array[queue -> start]);
}//first

//----------------------------------------

int last(StaticQueue *queue) {
    return (queue -> array[queue -> end]);
}//last

//----------------------------------------