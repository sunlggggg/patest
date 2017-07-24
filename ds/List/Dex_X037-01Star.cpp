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
 * why LinkedList &L and LinkedList L lead to  diverse consequences ,
 * use the & express the reference, &L == **Node operate the *Node,
 *
 */
void Dex_X(LinkedList &L, int x) {
    Node *p;
    if (L == NULL) {
        return;
    }
    if (L->data == x) {
        p = L;
        //由于L是Node * L的地址 ，于是 此处直接修改了L指向的节点的的后续
        //但是如果不使用&则实际上是将L向后移动造成断链
        L = L->next; //if use 'LinkedList L' , the list is breakage
                     //but use the 'LinkedList &L, the list is continuous '
                     //when use 'LinkedList &L' , 'L = L->next' is equals to
                     //'L->...->next = L->...->next->next'

        free(p);
        Dex_X(L, x);
    }
    else {
        Dex_X(L->next, x);
    }
}
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

int main() {
    int data[10] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
    LinkedList L = NULL ,P;
    L = buildList(L, data, 0, 10);
    Dex_X(L, 5);
    return 0;
}