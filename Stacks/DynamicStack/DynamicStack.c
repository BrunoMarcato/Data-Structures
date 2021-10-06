/*
    @author Bruno Uhlmann Marcato
    @file StaticStack.c
    @date 10-06-2021
    @brief dynamic stack manipulation functions 
*/

#include "DynamicStack.h"

//----------------------------------------

void initializeStack(DynamicStack *stack) {
    stack -> top = NULL;
    stack -> size = 0;
}//inicializeStack

//----------------------------------------

bool isEmpty(DynamicStack *stack) {
    return (stack -> size == 0);
}//isEmpty

//----------------------------------------

void push(int item, DynamicStack *stack) {
    PtrStackNode aux = (PtrStackNode) malloc(sizeof(aux));
    aux -> key = item;
    aux -> next  = stack -> top;
    stack -> top = aux;
    stack-> size++;
}//push

//----------------------------------------

int pop(DynamicStack *stack) {
    int ret = -9999;

    if(!isEmpty(stack)) {
        PtrStackNode aux;
        aux = stack -> top;
        stack -> top = aux -> next;
        ret = aux -> key;
        free(aux);
        stack -> size--;
    } else {
        printf("The stack is already empty");
    }

    return ret;
}//pop

//----------------------------------------

int stackSize(DynamicStack *stack) {
    return (stack -> size);
}//stackSize

//----------------------------------------

int top(DynamicStack *stack) {
    int key = stack -> top -> key;
    return key;
}//top

//----------------------------------------

void printStack(DynamicStack *stack) {
    PtrStackNode walk;
    printf("{ ");
    for(walk = stack -> top; walk != NULL; walk = walk -> next) {
        printf("%d ", walk -> key);
    }//for
    printf(" }\n");
}//printStack

//----------------------------------------

void destroyStack(DynamicStack *stack) {
    PtrStackNode walk;
    for(walk = stack -> top; walk != NULL; walk = walk -> next) {
        free(walk);
    }//for
}//destroy

//----------------------------------------