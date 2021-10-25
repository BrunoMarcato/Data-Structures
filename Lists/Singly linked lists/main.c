#include "SinglyLL.c"

int main() {
    List list;
    int n, j;
    initList(&list);
    insert(&list, 1);
    insert(&list, 4);
    insert(&list, -20);
    insert(&list, 100);
    insert(&list, 40);
    printList(&list);
    removeElement(&list, 4, &j);
    printf("%d\n", j);
    removeElement(&list, 40, &j);
    printf("%d\n", j);
    removeElement(&list, -20, &j);
    printf("%d\n", j);
    removeElement(&list, 1, &j);
    printf("%d\n", j);
    removeElement(&list, 100, &j);
    printf("%d\n", j);
    printList(&list);
    destroyList(&list);
    return 0;
}//main