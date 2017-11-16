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
    //导致断链
    Node *p;
    if (L == NULL) {
        return;
    }
    if (L->data == x) {
        p = L;
        L=L->next;
        free(p); //释放L原来指向的节点
        Dex_X(L, x);
    } else {
        Dex_X(L->next, x);
    }
}
void Dex_X_(LinkedList L, int x) {  //如果未使用引用，那么是值传递,节点是被释放掉了，但是L = L->next 的赋值却没有传递到原来的L链表上，
    //导致断链
    Node *p;
    if (L == NULL) {
        return;
    }
    if (L->data == x) {
        p = L;
        L = L->next;//对L的修改不会保留
        free(p); //释放L原来指向的节点
        Dex_X_(L, x);
    } else {
        Dex_X_(L->next, x);
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
    Dex_X_(L, 4);
    return 0;
}