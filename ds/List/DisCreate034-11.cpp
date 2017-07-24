//
// Created by sunlggggg on 2017/7/24.
//
#include <stdlib.h>
#include <iostream>
typedef struct Node {
    int data;
    Node *next ;
}Node,*LinkedList;
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
 * division A(odd retail insert) and B(even head insert)
 */
LinkedList DisCreate(LinkedList A){
    int countOriginA = 0 ;
    Node * p = A->next ; //work ptr
    LinkedList B = (Node * )malloc(sizeof(Node));
    A->next = NULL;
    B->next = NULL;
    Node *ra = A;
    Node *tmp;
    //Node *rb = B;
    while(p!=NULL) {
        countOriginA++;
        ra->next = p;
        ra = p;
        p = p->next;
        tmp = p->next ; //*p is break , so save the next of *p
        p->next = B->next;
        B->next = p;
        p = tmp;
    }
    ra->next = NULL;
    // rb->next = NULL;
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


