#include "BinaryTree.c"

int main() {    
    PtrTreeNode root;

    initTree(&root);

    if(isEmpty(&root)) {
        printf("The structure is empty\n");
    }

    push(&root, 5);
    push(&root, 3);
    push(&root, 1);
    push(&root, 12);
    push(&root, 4);

    if(!isEmpty(&root)) {
        printf("There is something in the structure\n");
    }

    //Pre-Order: [5, 3, 1, 4, 12]
    printf("Pre-Order Route: ");
    preOrder(&root);
    printf("\n");

    //Post-Order: [1, 4, 3, 12, 5]
    printf("Post-Order Route: ");
    postOrder(&root);
    printf("\n");

    //In-Order: [1, 3, 4, 5, 12]
    printf("In-Order Route: ");
    inOrder(&root);
    printf("\n");

    //Search for elements: 3, 1, 7, 10, 12, 45 and 5
    int test[] = {3, 1, 7, 10, 12, 45, 5};
    for(int i = 0; i < 7; i++) {
        if(search(&root, test[i])) {
            printf("%d -> found\n", test[i]);
        } else {
            printf("%d -> did not found\n", test[i]);
        }
    }

    destroy(&root);

    if(isEmpty(&root)) {
        printf("The structure is empty\n");
    }

    return 0;
}


//        5
//      /  \
//     3    12
//    / \
//   1   4