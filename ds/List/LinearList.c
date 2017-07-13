//
// Created by sunlggggg on 2017/7/13.
//
#include<stdbool.h>

#define ElementType int
#define ERROR NULL
typedef struct LNode * PtrLNode ; //alias of "LNode * " is "PtrLNode"
struct LNode {
    ElementType Data ;
    PtrLNode Next ;
} ;
typedef PtrLNode CurNode ; //the position the current node
typedef PtrLNode List ; //
List L;

int Length(List L) ;
List Insert(List L , ) ;
bool Delete(List L) ;
ElementType GetKth(List L, int Kth) ;
ElementType FindByValue();
int
int main (){

    return 0 ;
}
