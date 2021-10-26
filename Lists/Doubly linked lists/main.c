#include "DoublyLL.c"

int main() {
    List list;
    int n, j;
    initList(&list);
    insert(&list, 1);
    printList(&list);
    reversePrintList(&list);
    insert(&list, 4);
    printList(&list);
    reversePrintList(&list);
    insert(&list, -20);
    printList(&list);
    reversePrintList(&list);
    insert(&list, 90);
    printList(&list);
    reversePrintList(&list);
    insert(&list, 40);
    printList(&list);
    reversePrintList(&list);
    removeElement(&list, 4, &j);
    printList(&list);
    reversePrintList(&list);
    removeElement(&list, 40, &j);
    printList(&list);
    reversePrintList(&list);
    removeElement(&list, -20, &j);
    printList(&list);
    reversePrintList(&list);
    removeElement(&list, 1, &j);
    printList(&list);
    reversePrintList(&list);
    removeElement(&list, 90, &j);
    printList(&list);
    reversePrintList(&list);
    destroyList(&list);
    return 0;
}