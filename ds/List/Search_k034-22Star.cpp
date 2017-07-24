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

int Search_k(LinkedList A, int k) {
    Node *p, *q ;
    p = A;
    q = A;
    int count = 0 ;
    while(p->next != NULL ){
        if(count < k - 1){
            count++;
        }else{
            q = q->next;
        }
        p = p->next;
    }
    if(q != A ){
        std::cout << q->data << std::endl;
        return 1;
    }
    else {
        std::cout << "not find!"<< std::endl;
        return 0 ;
    }
}
int main() {
    int data1[10] = {1, 3, 5};
    LinkedList L1 = NULL;
    L1 = (Node *) malloc(sizeof(Node));
    L1->next = buildLinkedList(L1->next, data1, 0, 3);
    std::cout << Search_k(L1, 1) << std::endl;
    return 0;
}
