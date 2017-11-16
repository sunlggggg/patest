//
// Created by sunlggggg on 2017/10/17.
//

#include<iostream>
#include"malloc.h"
using namespace std;
typedef struct NODE{
    struct NODE *next ;
    int data ;
}Node , *List  ;
Node *list_addlast(List list, int data){
    if(list != NULL){
        Node *node  = (Node *) malloc(sizeof(Node));
        node->data = data;
        list->next = node;
        return node;
    }
    return NULL;
}
void list_traverse(List list ){
    Node * p = list;
    while(p){
        cout<< p->data << " " ;
        p = p->next ;
    }
    cout<<endl;
}
int main(){

    List list = (List)malloc(sizeof(Node));
    list->data = 0 ;
    list_addlast(list_addlast(list_addlast(list_addlast(list,4),3),2),1);
    List &p = list;
    list_traverse(list);
    /**
     * 这一语句是用了引用 p 一开始引用的的是指向list头节点的指针，
     * 而p->next指的是头节点的下一个节点的指针
     * 因此这里的赋值操作就是将指向头节点的指针指向后续节点
     *
     */
    p = p->next ;
    list_traverse(list);
    return 0 ;
}
