/*
    @author Bruno Uhlmann Marcato
    @file DynamicQueue.c
    @date 10-12-2021
    @brief dynamic queue manipulation functions 
*/

#include "DynamicQueue.h"

//----------------------------------------------

void initQueue(DynamicQueue *queue) {
    queue -> size = 0;
    queue -> start = NULL;
    queue -> end = NULL;
}//initQueue

//----------------------------------------------

void enqueue(int x, DynamicQueue *queue) {
    Pointer aux;
    aux = malloc(sizeof(NodeQueue));
    aux -> item = x;
    if(isEmpty(queue)) {
        queue -> start = queue -> end = aux;
        aux -> next = NULL;    
    } else {
        aux -> next = NULL;
        queue -> end -> next = aux;
        queue -> end = queue -> end -> next; 
    }
    queue -> size++;
}//enqueue

//----------------------------------------------

int dequeue(DynamicQueue *queue) {
    int ret = -9999;
    //cannot remove if empty 
    if(!isEmpty(queue)) {
        Pointer aux = queue -> start;
        ret = aux -> item;
        queue -> start = queue -> start -> next;
        queue -> size--;
        free(aux);
    } else printf("The Queue is Empty!\n");
    return ret;
}//dequeue

//----------------------------------------------

void printQueue(DynamicQueue *queue) {
    Pointer ptr;
    printf("{ ");
    for(ptr = queue -> start; ptr != NULL; ptr = ptr -> next) {
        printf("%d ", ptr -> item);
    }
    printf(" }\n");
}//printQueue

//----------------------------------------------

void destroy(DynamicQueue *queue) {
    free(queue);
}//destroy

//----------------------------------------------

//To check if the queue is empty, just check if the size is 0 or if both the start and end pointers point to NULL
//In this case I use the first option 

int isEmpty(DynamicQueue *queue) {
    return (queue -> size == 0);
}//isEmpty

//----------------------------------------------

int queueSize(DynamicQueue *queue) {
    return (queue -> size);
}//size

//----------------------------------------------

int first(DynamicQueue *queue) {
    return (queue -> start -> item);
}//first

//----------------------------------------------

int last(DynamicQueue *queue) {
    return (queue -> end -> item);
}//last

//----------------------------------------------