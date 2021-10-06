//
//  staticStack.h
//  Stacks
//
//  Created by Bruno Uhlmann Marcato on 10-05-21.
//

#ifndef staticStack_h
#define staticStack_h

#define MAXTAM 100

//Stack abstract type
typedef struct {
    int array[MAXTAM];
    int top;
} staticStack;

//manipulation functions
void inicializeStack(staticStack *stack);
bool isEmpty(staticStack *stack);
bool isFull(staticStack *stack);
void push(int item, staticStack *stack);
int pop(staticStack *stack);
int stackLength(staticStack *stack);
int top(staticStack *stack);
void printStack(staticStack *stack);

#endif