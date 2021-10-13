#include "DynamicQueue.c"
#include <time.h>

int main(int argc, const char * argv[]) {
    //Queue declaration
    DynamicQueue dqueue;

    int n;

    //inicialize queue
    initQueue(&dqueue);

    //put 8 values on queue
    for(int i = 0; i < 8; i++) {
        scanf("%d", &n);
        enqueue(n, &dqueue);
        printQueue(&dqueue);
    }//for 

    //unqueue the 8 values and show the size, the element that was unqueued, the first and last element of the queue 
    for(int i = 0; i < 8; i++) {
        printQueue(&dqueue);
        sleep(2);
        printf("Value dequeued: %d\n", dequeue(&dqueue));
        sleep(2);
        printf("Size: %d\n", queueSize(&dqueue));
        sleep(2);
        printf("First value: %d\n", first(&dqueue));
        sleep(2);
        printf("Last value: %d\n\n", last(&dqueue));
    }

    return 0;
}