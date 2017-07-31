//
// Created by sunlggggg on 2017/7/31.
//
/**
 * 中序线索化
 * 1.基本思路
 */
#include <iostream>

using namespace std;


#define END '#'
typedef enum {
    Link,
    Thread
} PointTag;

typedef struct Node {
    Node(char data)
            : data(data),
              lChild(NULL),
              rChild(NULL),
              lTag(Link),
              rTag(Link) {}

    char data;
    Node *lChild, *rChild;
    int lTag, rTag;
} *ThreadTree;


void CreateInThread(ThreadTree T) {
    ThreadTree pre = NULL;
}

/**
 * C++ 写法
 */
void createBiTreeCpp(ThreadTree &T, const char *p, int i) {
    if (*(p + i) == END)
        T = NULL;
    else {
        T = new Node;
        T->data = *(p + i);
        createBiTreeCpp(T->lChild, p, ++i);
        createBiTreeCpp(T->rChild, p, ++i);
    }
}

/**
 * C 语言写法
 * @param T
 * @param p
 * @param i
 * @return
 */
Node *createBiTreeC(ThreadTree T, const char *p, int i) {
    if (*(p + i) == END)
        return NULL;
    else {
        T = new Node;
        T->data = *(p + i);
        T->lChild = createBiTreeC(T->lChild, p, ++i);
        T->rChild = createBiTreeC(T->rChild, p, ++i);
        return T;
    }
}

int main() {
    string str = "ab#d##C#e##";
    const char *p = str.c_str();
    ThreadTree T;
    createBiTreeCpp(T, p, 0);
    return 0;
}
