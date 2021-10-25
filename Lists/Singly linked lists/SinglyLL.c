/*
    @author Bruno Uhlmann Marcato
    @file StaticQueue.c
    @date 10-25-2021
    @brief Singly Linked Lists manipulation functions 
*/

#include "SinglyLL.h"

//----------------------------------------

//To initialize the list, the pointer to the first element points to NULL and zero is assigned to the size
void initList(List *list) {
    list -> first = NULL;
    list -> size = 0;
}//initList

//----------------------------------------

bool isEmpty(List *list) {
    return (list -> first == NULL);
    //return (list -> size == 0);
}//isEmpty

//----------------------------------------

int size(List *list) {
    return (list -> size);
}//size

//----------------------------------------

void printList(List *list) {
    Pointer aux;
    printf("List = { "); 
    for(aux = list -> first; aux != NULL; aux = aux -> next) {
        printf("%d ", aux -> element);
    }
    printf("}\n");
}//printList

//----------------------------------------

void insert(List *list, int x) {
    //Create a pointer to list node and bind the value passed as argument as a key of this new node 
    Pointer newNode = malloc(sizeof(Pointer));
    newNode -> element = x;
    //case 1: First element or x lower than the first element
        //Check if the list is empty
        //next of new node points to who the first is pointing to
        //first point to the new node
    if(isEmpty(list) || x < list -> first -> element) {
        newNode -> next = list -> first;
        list -> first = newNode;
    } else {
        //case 2: Not the first element 
        //As the list must be sorted, we will iterate through its elements until we find the "snap" point of the new node
        // the next of new node assign to the next of the auxiliar pointer
        //the next of auxiliar pointer assign to the new node
        Pointer aux = list -> first;
        while(aux -> next != NULL && x > aux -> next -> element) {
            aux = aux -> next;
        }
        
        newNode -> next = aux -> next;
        aux -> next = newNode;
    }
    //Increase the size list
    list -> size++;
}

//----------------------------------------

void destroyList(List *list) {
    Pointer aux;
    for(aux = list -> first; aux != NULL; aux = aux -> next) {
        free(aux);
    }
}//destroyList

//----------------------------------------

//If the list is empty, the element doesn't exist, so return false
//If the list is not empty:
//  iterates through the list until it finds the point where the element might be 
//  if the pointer is null or its element is greater than the number passed as argument, then the element does not exist in the list 
//  if the last topic is false, so the element exist
bool search(List *list, int key) {
    if(!isEmpty) {
        Pointer aux = list -> first;
        while(aux != NULL || key > aux -> element) {
            aux -> next;
        }
        if(aux == NULL || aux -> element > key) {
            return false;
        } else {
            return true;
        }
    } else {
        return false;
    }
}//search

//----------------------------------------

//4 casos:
//1) Lista vazia
//2) Elemento a ser removido é menor que o primeiro da lista
//3) Elemento a ser removido é o primeiro
//4) Elemento a ser removido não é o primeiro 
//  4.1) Elemento não está na lista depois de percorrer
//  4.2) Elemento está na lista depois de percorrer

bool removeElement(List *list, int key, int *item) {
    //case 1 and 2
    if(isEmpty(list) || key < list -> first -> element) {
        printf("Unable to remove element (empty list or non-existent element)\n");
        return false;     
    }
    //case 3
    if(list -> first -> element == key) {
        Pointer aux = list -> first;
        list -> first = aux -> next;
        *item = aux -> element;
        free(aux);
        list -> size--;
        return true;
    } 
    //case 4
    Pointer walk = list -> first;
    while(walk -> next != NULL && (key > walk -> next -> element)) {
        walk = walk -> next;
    }
    //case 4.1
    if(walk == NULL || key < walk -> next -> element) {
        printf("The element does not exist in the list\n");
        return false;
    }
    //case 4.2
    Pointer aux = walk -> next;
    walk -> next = aux -> next;
    *item = aux -> element;
    free(aux);
    list -> size--;
    return true;
    
}//removeElement

//----------------------------------------