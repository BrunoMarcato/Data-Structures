//
//  DynamicStack.h
//  Stacks
//
//  Created by Bruno Uhlmann Marcato on 10-06-21.
//

#ifndef dynamicStack_h
#define dynamicStack_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StackNode *PtrStackNode;

typedef struct StackNode{
    int key;
    PtrStackNode next;
} StackNode;

typedef struct {
    PtrStackNode top;
    int size;
} DynamicStack;

void initializeStack(DynamicStack *stack);
bool isEmpty(DynamicStack *stack);
void push(int key, DynamicStack *stack);
int pop(DynamicStack *stack);
int stackSize(DynamicStack *stack);
int top(DynamicStack *stack);
void printStack(DynamicStack *stack);
void destroyStack(DynamicStack *stack);

#endif