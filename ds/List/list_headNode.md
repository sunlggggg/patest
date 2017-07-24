对于有头结点的链表可以方便操作

否在在以下问题时:一旦存在空链表的情况时，是无法找到pre和minp

为了防止最后一个节点是最小的问题，考虑使用两组指针，每次找到当前最小值，则更新最小指针和最小前驱指针

这样就杜绝了最后一个节点是最小的问题，否则一旦通过pre->next = pre->next->next 的语句需要考虑这种情况，而现在不需要考虑这种情况，不出现pre->next->next这种写法

```C++
//
// Created by sunlggggg on 2017/7/23.
//
#include <stdio.h>
#include <stdlib.h>

#define MINIMUN_NUMBER -9999
typedef struct Node { 
    int data;
    struct Node *next;
} Node, *LinkedList;

/**
 * assume the minimum number is unique
 * has the head node
 */
void DeleteMin(LinkedList &L) {
    Node *pre = L, *p = pre->next, *minpre = pre, *minp = p;
    while (p != NULL) {
        if (p->data < minp->data) {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    minpre->next = minp->next;
    free(minp);
}

Node *buildList(LinkedList L, int data[], int i, int n) {
    if (i == n) {
        return NULL;
    } else {
        L = (Node *) malloc(sizeof(Node));
        L->data = data[i];
        L->next = buildList(L->next, data, ++i, n);
        return L;
    }
}

int main() {
    int data[10] = {3, 2, 3};
    LinkedList L = NULL;
    L = (Node * )malloc(sizeof(Node));
    L->next = buildList(L->next, data, 0, 3);
    DeleteMin(L);
    return 0;
}
```