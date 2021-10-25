#include "DoublyLL.c"

int main() {
    List list;
    int n, j;
    initList(&list);
    insert(&list, 1);
    insert(&list, 4);
    insert(&list, -20);
    insert(&list, 90);
    insert(&list, 40);
    printf("%d\n", sizeList(&list));
    removeElement(&list, 4, &j);
    printList(&list);
    printf("%d\n", sizeList(&list));
    removeElement(&list, 40, &j);
    printList(&list);
    printf("%d\n", sizeList(&list));
    removeElement(&list, -20, &j);
    printList(&list);
    printf("%d\n", sizeList(&list));
    removeElement(&list, 1, &j);
    printList(&list);
    printf("%d\n", sizeList(&list));
    removeElement(&list, 90, &j);
    printList(&list);
    printf("%d\n", sizeList(&list));
    destroyList(&list);
    return 0;
}