#include <time.h>
#include "DynamicStack.c"


int main(int argc, const char * argv[]) {
    //dynamic stack declaration and variables
    DynamicStack dstack;
    int size, element;

    //init
    initializeStack(&dstack);

    //push n elements on the stack and print the intermediate states
    printf("Stack size: ");
    scanf("%d", &size); 
    for(int i = 0; i < size; i++) {
        printf("Element: ");
        scanf("%d", &element);
        push(element, &dstack);
        printStack(&dstack);
    }//for

    //pop the n elements and print the intermediate states, the stack size and the top value
    for(int i = 0; i < size; i++) {
        pop(&dstack);
        printStack(&dstack);
        printf("Current Stack Size: %d\n", stackSize(&dstack));
        printf("Current top value: %d\n", top(&dstack));
        sleep(1);
    }//for

    //kill the stack to deallocate memory
    destroyStack(&dstack);

    return 0;
}//main