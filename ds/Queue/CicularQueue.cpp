//
// Created by sunlggggg on 2017/11/21.
//
#include<stdio.h>
#include <malloc.h>

typedef int ElementType;
typedef struct {
    int size;
    int rear ;
    int front;
    ElementType *data;
} Queue;

Queue* CreateQ(int size){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->size = size;
    q->rear = 0;
    q->front = 0 ;
    q->data = (ElementType *) malloc(sizeof(ElementType) * size );
    return  q;
}
Queue* FreeQ(Queue *q){
    free(q->data);
    free(q);
    q = NULL;//值传递
    return q;
}

bool IsFull(Queue *q){
    return (q->rear + 1)%q->size == q->front;
}

bool IsEmpty(Queue *q ){
    return q->rear == q->front;
}

bool AddQ(Queue *q, ElementType item ){
    if(IsFull(q)){
        return false;
    }else {
        q->data[++q->rear%q->size] = item;
    }
}

ElementType *DeleteQ(Queue *q){
    if(IsEmpty(q)) {
        return NULL;
    }else{
        return &q->data[++q->front];
    }
}

int main(void) {
    Queue *q = CreateQ(3);
    AddQ(q, 1);
    AddQ(q, 2);
    AddQ(q, 2);
    q = FreeQ(q);//q= NULL 如果不赋返回值 q并非NULL只是释放了对应的空间
    printf("%d\n", q);

}

