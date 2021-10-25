//
//  Lists
//  Singly Linked Lists
//
//  Created by Bruno Uhlmann Marcato on 10/20/2021

#ifndef DynamicList_h
#define DynamicList_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NodeList *Pointer;

typedef struct NodeList {
  int element;
  Pointer next;
} NodeList;

typedef struct {
  Pointer first;
  int size;
} List;


void initList(List *list);
void insert(List *list, int x);
void printList(List *list);
void destroyList(List *list);
bool isEmpty(List *list);
bool search(List *list, int key);
int size(List *list);
bool removeElement(List *list, int key, int *item);
void removeFirst(List *list, int *item);
void removeLast(List *list, int *item);
int first(List *list);
int last(List *list);

#endif