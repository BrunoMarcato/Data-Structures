//
//  BinaryTree.h
//  Binary Trees
//
//  Created by Bruno Uhlmann Marcato on 11-18-21.
//

#ifndef binaryTree_h
#define binaryTree_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode* PtrTreeNode;

typedef struct TreeNode {
    int key;
    PtrTreeNode right;
    PtrTreeNode left;
} TreeNode;

//manipulation functions
void initTree(PtrTreeNode *tree);
bool isEmpty(PtrTreeNode *tree);
bool push(PtrTreeNode *tree, int x);
bool pop(PtrTreeNode *tree, int x);
void preOrder(PtrTreeNode *tree);
void inOrder(PtrTreeNode *tree);
void postOrder(PtrTreeNode *tree);
bool search(PtrTreeNode *tree, int x);
void destroy(PtrTreeNode *tree);

#endif