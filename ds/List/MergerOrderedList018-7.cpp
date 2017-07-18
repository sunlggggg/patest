//
// Created by sunlggggg on 2017/7/16.
//
#include<stdio.h>
#include<malloc.h>
#define ElementType int
#define MAXSIZE 100
typedef struct {
    int length ;
    ElementType * data ;
}SeqList;
bool  MergerOrderedList(SeqList LFirst, SeqList LSecond, SeqList * newList);
int main(){
    SeqList  LFirst,LSecond, * LMerger;
    LMerger = (SeqList * )malloc(sizeof(SeqList));
    LMerger->data = (ElementType *)malloc(sizeof(ElementType) * MAXSIZE);
    LFirst.data = (ElementType *)malloc(sizeof(ElementType) * MAXSIZE);
    LFirst.length = 3;
    LSecond.data = (ElementType *)malloc(sizeof(ElementType) * MAXSIZE);
    LSecond.length = 3;
    LMerger->length = 0 ;
    LFirst.data[0] = 1;
    LFirst.data[1] = 3;
    LFirst.data[2] = 5;
    LSecond.data[0] = 2;
    LSecond.data[1] = 4;
    LSecond.data[2] = 6;
    ElementType * data =  LMerger->data;
    if(MergerOrderedList(LFirst,LSecond,LMerger)){
        printf("length of new list is:\n%d\nvalue is:\n",LMerger->length);
        for(int iLMergerIter = 0 ; iLMergerIter < LMerger->length; iLMergerIter++ ){
            printf("%d  ",LMerger->data[iLMergerIter]);
        }
    }else{
        printf("fail\n");
    }
    return 0 ;
}
bool MergerOrderedList(SeqList LFirst, SeqList LSecond, SeqList * newList){
    if(LFirst.length + LSecond.length> MAXSIZE) {
        return false;
    }else {
        int iLFirstIter = 0, iLSecondIter = 0, iLMergerIter = 0;
        while (iLFirstIter < LFirst.length && iLSecondIter < LSecond.length) {
            if (LFirst.data[iLFirstIter] < LSecond.data[iLSecondIter]) {
                newList->data[iLMergerIter++] = LFirst.data[iLFirstIter++];
            } else {
                newList->data[iLMergerIter++] = LSecond.data[iLSecondIter++];
            }
        }
        while (iLFirstIter < LFirst.length) {
            newList->data[iLMergerIter++] = LFirst.data[iLFirstIter++];
        }
        while (iLSecondIter < LSecond.length) {
            newList->data[iLMergerIter++] = LSecond.data[iLSecondIter++];
        }
        // [watch out] don't add 1 because of the iLMergerIter++
        // make the value of iLMergerIter equals to length of new list
        newList->length = iLMergerIter;
        return true;
    }
}