#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "StaticStack.c"

int main() {

    staticStack sstack;
    int n, popped;

    inicializeStack(&sstack);

    //insert 8 objects in the stack
    for(int i = 0; i < 8; i++) {
        scanf("%d", &n);
        push(n, &sstack);
        printStack(&sstack);
    }//for

    //pop the 8 objects, show the value that was returned, show the top value in the current loop and the size of the stack in this loop
    for(int i = 0; i < 8; i++) {
        popped = pop(&sstack);
        sleep(2);
        printf("\nValue popped: %d\n", popped);
        printf("Top value at this time: %d\n\n", top(&sstack));
        printf("Size of the stack at this moment: %d\n\n", stackLength(&sstack));
        printStack(&sstack);
    }//for
    
    return 0;
}//main