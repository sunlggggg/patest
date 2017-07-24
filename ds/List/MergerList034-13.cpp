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
LinkedList MergerList(LinkedList A, LinkedList B) {

    Node *ra = A->next, *rb = B->next, *tmp;
    A->next = NULL; //all insert into A
    while (ra && rb) {
        if (ra->data < rb->data) {
            tmp = ra->next;
            ra->next = A->next;
            A->next = ra;
            ra = tmp;
        } else {
            tmp = rb->next;
            rb->next = A->next;
            A->next = rb;
            rb = tmp;
        }
    }
    //or if(ra){
    //       rb = ra;
    while(ra){
        tmp = ra->next;
        ra->next = A->next;
        A->next = ra;
        ra = tmp;
    }
    while (rb){
        tmp = rb->next;
        rb->next = A->next;
        A->next = rb;
        rb = tmp;
    }
    free(rb);
}
int main(){
    int data1[10] = {1,3,5,5,7,9,10,11,12,13};
    int data2[10] = {1,4,5,6,7,8,9,10,11,35 };
    LinkedList L1 = NULL, L2 = NULL;
    L1 = (Node * )malloc(sizeof(Node));
    L2 = (Node * )malloc(sizeof(Node));
    L1->next = buildLinkedList(L1->next, data1, 0, 10);
    L2->next = buildLinkedList(L2->next, data2, 0, 10);
    LinkedList B = MergerList(L1,L2);
    return  0 ;
}
