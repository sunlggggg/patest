//
// Created by sunlggggg on 2017/7/23.
//
#include <stdio.h>
#include <stdlib.h>

#define MINIMUN_NUMBER -9999
typedef struct Node {
    int data;
    struct Node *next;
} Node, *LinkedList;

/**
 * assume the minimum number is unique
 * has the head node
 */
void DeleteMin(LinkedList &L) {
    Node *pre = L, *p = pre->next, *minpre = pre, *minp = p;
    while (p != NULL) {
        if (p->data < minp->data) {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    minpre->next = minp->next;
    free(minp);
}

Node *buildList(LinkedList L, int data[], int i, int n) {
    if (i == n) {
        return NULL;
    } else {
        L = (Node *) malloc(sizeof(Node));
        L->data = data[i];
        L->next = buildList(L->next, data, ++i, n);
        return L;
    }
}

int main() {
    int data[10] = {3, 2, 3};
    LinkedList L = NULL;
    L = (Node * )malloc(sizeof(Node));
    L->next = buildList(L->next, data, 0, 3);
    DeleteMin(L);
    return 0;
}