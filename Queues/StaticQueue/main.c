#include "StaticQueue.c"
#include <time.h>

int main(int argc, const char * argv[]) {
    //queue declaration
    StaticQueue squeue;

    int n, unqueued;
    //inicialize queue
    initQueue(&squeue);

    //put 8 values on queue
    for(int i = 0; i < 8; i++) {
        scanf("%d", &n);
        enqueue(n, &squeue);
        printQueue(&squeue);
    }//for
    
    //unqueue the 8 values and show the size, the element that was unqueued, the first and last element of the queue 
    for(int i = 0; i < 8; i++) {
        unqueued = dequeue(&squeue);
        sleep(2);
        printQueue(&squeue);
        sleep(2);
        printf("Value unqueued: %d\n", unqueued);
        sleep(2);
        printf("Size: %d\n", sizeQueue(&squeue));
        sleep(2);
        printf("First value: %d\n", first(&squeue));
        sleep(2);
        printf("Last value: %d\n\n", last(&squeue));
    }//for

    return 0;
}//main