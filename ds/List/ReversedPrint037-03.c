//
// Created by sunlggggg on 2017/7/23.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node, *LinkedList;

/**
 * 1.transmission by value, LinkedList L　is equals to Node * L
 * if we need transmission by address, we should use LinkedList * L
 */
Node * buildList(LinkedList L, int data[], int i, int n) {
    if (i == n){
        return NULL;
    }
    else {
        L = (Node *)malloc(sizeof(Node));
        L->data = data[i];
        L->next = buildList(L->next, data, ++i, n);
        return L;
    }
}


void ReversedPrint(LinkedList L){
    if(L->next != NULL ){
        ReversedPrint(L->next);
    }
    printf("%d  ", L->data);
}
int main() {
    int data[10] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
    LinkedList L = NULL ;
    L = buildList(L, data, 0, 10);
    ReversedPrint(L);
    return 0;
}