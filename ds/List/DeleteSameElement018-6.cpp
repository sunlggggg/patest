//
// Created by sunlggggg on 2017/7/15.
//
#include<stdio.h>
#include<malloc.h>
using namespace std;

#define ElementType int
#define InitSize 100

typedef struct {
    ElementType * data;
    int MaxSize, length;
}SeqList;
void Init(SeqList * L);
int DelSameElement(SeqList * L, int Length);
int main(){
    //指针初始化
    SeqList * L = (SeqList *)malloc(sizeof(L));
    Init(L);
    ElementType * data = L->data;
    data[0] = 1;
    data[1] = 2;
    data[2] = 2;
    data[3] = 4;
    printf("%d\n", DelSameElement(L, 4));
    free(L);
}
void Init(SeqList * L){
    L->data = (ElementType *)malloc(sizeof(ElementType)*InitSize);
}

/**
 * delete same element.
 * @param L
 * @param Length
 * @return the length of new List
 */
int DelSameElement(SeqList * L, int Length){
    if (!Length){
        return 0;
    }
    ElementType * data = L->data;
    int lastElementIndex = 0;
    int newLength = 1;
    for (int lIndex = 1; lIndex < Length; lIndex++){
        if (data[lIndex] != data[lastElementIndex]){
            data[++lastElementIndex] = data[lIndex];
            newLength++;
        }
    }
    return newLength;
}