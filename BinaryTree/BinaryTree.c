/*
    @author Bruno Uhlmann Marcato
    @file BinaryTree.c
    @date 11-18-2021
    @brief Binary Tree manipulation functions 
*/

#include "BinaryTree.h"

//----------------------------------------

void initTree(PtrTreeNode *tree) {
    *tree = NULL;
}

//----------------------------------------

bool isEmpty(PtrTreeNode *tree) {
    return (*tree == NULL);
}

//----------------------------------------

bool push(PtrTreeNode *tree, int x) {
    //tree is empty (recursion stop condition)
    if((*tree) == NULL) {
        (*tree) = malloc(sizeof(TreeNode));
        (*tree) -> right = (*tree) -> left = NULL;
        (*tree) -> key = x;
        return true;
    } 
    //duplicate number (recursion stop condition)
    if((*tree) -> key == x) {
        printf("Warning: Key already existing in the tree");
        return false;
    }

    if(x > (*tree) -> key) {
        //go to right node
        return (push(&(*tree) -> right, x));
    } else {
        //go to left node
        return (push(&(*tree) -> left, x));
    }
}

//----------------------------------------

void preOrder(PtrTreeNode *tree) {
    if((*tree) == NULL) return;

    printf("%d ", (*tree) -> key); //Pre-Order

    preOrder(&(*tree) -> left);

    preOrder(&(*tree) -> right);

}

//----------------------------------------

void postOrder(PtrTreeNode *tree) {
    if((*tree) == NULL) return;

    postOrder(&(*tree) -> left);

    postOrder(&(*tree) -> right);

    printf("%d ", (*tree) -> key); //Post-Order

}

//----------------------------------------

void inOrder(PtrTreeNode *tree) {
    if((*tree) == NULL) return;

    inOrder(&(*tree) -> left);

    printf("%d ", (*tree) -> key); //In-Order

    inOrder(&(*tree) -> right);

}

//----------------------------------------

bool search(PtrTreeNode *tree, int x) {
    //did not find the element (end case of recursion -> negative)
    if((*tree) == NULL) return (false);

    //found the element (end case of recursion -> positive)
    if((*tree) -> key == x) return (true);

    //recursion
    if(x < (*tree) -> key) {
        search(&(*tree) -> left, x);
    } else {
        search(&(*tree) -> right, x);
    }

}

//----------------------------------------

void destroy(PtrTreeNode *tree) {
    if((*tree) != NULL) {
        destroy(&(*tree) -> left);
        destroy(&(*tree) -> right);
        free(*tree);
        (*tree) = NULL;
    }
}

//----------------------------------------