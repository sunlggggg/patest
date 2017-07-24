//
// Created by sunlggggg on 2017/7/24.
//
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <malloc.h>
typedef struct Node {
    int data;
    Node *next ;
}Node;
typedef Node *LinkedList;
Node * buildLinkedList(Node * node, int data[], int i , int n ){
    if(i == n ){
        return NULL;
    } else {
        node = (Node *) malloc(sizeof(Node));
        node->data = data[i];
        node->next = buildLinkedList(node->next,data, ++i, n);
        return node;
    }
}
/**
 * division A(odd) and B(even)
 */
LinkedList DisCreate(LinkedList A){
    int countOriginA = 0 ;
    Node * p = A->next ;
    LinkedList B = (Node * )malloc(sizeof(Node));
    A->next = NULL;
    B->next = NULL;
    Node *ra = A;
    Node *rb = B;
    while(p!=NULL){
        countOriginA ++ ;
        if(countOriginA%2==1) {
            ra->next = p;
            ra = p ;
        } else{
            rb->next = p ;
            rb = p ;
        }
        p = p->next;
    }
    ra->next = NULL;
    rb->next = NULL;
    return B;
}
int main(){
    int data[10] = {1,2,3,4,5,6,7,8,9,10};
    LinkedList L = NULL;
    L = (Node * )malloc(sizeof(Node));
    L->next = buildLinkedList(L->next, data, 0, 10);
    LinkedList B = DisCreate(L);
    return  0 ;
}
