#include "SinglyLL.c"

int main() {
    List lista;
    int n, j;
    initList(&lista);
    insert(&lista, 1);
    insert(&lista, 4);
    insert(&lista, -20);
    insert(&lista, 100);
    insert(&lista, 40);
    printList(&lista);
    removeElement(&lista, 4, &j);
    printf("%d\n", j);
    removeElement(&lista, 40, &j);
    printf("%d\n", j);
    removeElement(&lista, -20, &j);
    printf("%d\n", j);
    removeElement(&lista, 1, &j);
    printf("%d\n", j);
    removeElement(&lista, 100, &j);
    printf("%d\n", j);
    printList(&lista);
    return 0;
}//main