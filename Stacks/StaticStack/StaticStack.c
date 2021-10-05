/*
    @author Bruno Uhlmann Marcato
    @file StaticStack.c
    @date 05-10-2021
    @brief static stack manipulation functions 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StaticStack.h"

//----------------------------------------------------------

//assign 'top' with 0 (beginning of the stack) 

void inicializeStack(staticStack *stack) {
    stack -> top = 0;
}//inicializeStack

//----------------------------------------------------------

//returns conditional test result: 'top' pointing to stack position 0

bool isEmpty(staticStack *stack) {
    return (stack -> top == 0);
}//isEmpty

//----------------------------------------------------------

//returns conditional test result: 'top' pointing to maximum stack size + 1

bool isFull(staticStack *stack) {
    return (stack -> top == MAXTAM);
}//isFull

//----------------------------------------------------------

// Test if the stack is already completely filled
// If not, the stack receives 'item' at the position indicated by 'top'
// Increment 'top' so that it points to the next space on the stack

void push(int item, staticStack *stack) {

    if(!isFull(stack)) {
        stack -> array[stack -> top] = item;
        stack -> top++;
    } else {
        printf("The stack is already full\n");
    }

}//push

//----------------------------------------------------------

// Test if the stack is empty
// If not, the auxiliary variable receives the object at the top of the stack and decrements the top index
// Finally, returns the value stored in the auxiliary variable.

int pop(staticStack *stack) {

    int aux = -9999;

    if(!isEmpty(stack)) {
        aux = stack -> array[stack -> top-1];
        stack -> top--;
    } else {
        printf("nao ta dando");
    }

    return aux;
}//pop

//----------------------------------------------------------

//return the stack length (return the index that the top is pointing to)

int stackLength(staticStack *stack) {
    return (stack -> top);
}//stackLength

//----------------------------------------------------------

// Returns the object at the top of the stack
// The top indicates the index of the last element + 1, the object will receive the item with the index top - 1

int top(staticStack *stack) {
    int item;
    item = stack -> array[stack -> top - 1];
    return item;
}//top

//----------------------------------------------------------

//print stack elements using a loop to the current value of the top of the stack - 1

void printStack(staticStack *stack) {
    printf("{ ");
    for(int i = 0; i < stack -> top; i++) {
        printf("%d ", stack -> array[i]);
    }//for
    printf("}\n");
}//printStack

//----------------------------------------------------------