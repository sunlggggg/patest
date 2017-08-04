//
// Created by sunlggggg on 2017/8/3.
//

#include <iostream>
#include <malloc.h>
#include <string>
#include <stack>

using namespace std;
typedef struct Node {
    Node(char ch) : data(ch), lChild(NULL), rChild(NULL) {}

    char data;
    struct Node *lChild;
    struct Node *rChild;
} Node, *Tree;

/**
 *
 * @param T
 * @param p
 * @param i  pointer of attention is a '&' variable.if no use the '&', along with the
 *           left tree's depth increasing , the i should have benn auto-increment
 *           in every invoke the CreateTree, but it didn't due to value transfer.For
 *           the same root's leftChild and rightChild , the i always is rightChild's
 *           greater than leftChild only 1.
 * @return
 */
Node *CreateTree(Node *T, char *p, int &i) {
    char data = p[i];
    if (data == '#') {
        return NULL;
    } else {
        T = (Node *) malloc(sizeof(Node));
        T->data = data;
        T->lChild = CreateTree(T->lChild, p, ++i);
        T->rChild = CreateTree(T->rChild, p, ++i);
        return T;
    }
}

/**
 * 前提      1.对于叶子节点是可以直接访问的
 *            2.访问是左右中的顺序 如何做到只有叶
 * 解决方案  1走到最左，如果有右就往右走  （记录来的路径（栈））
 *           2.找到一个叶子节点，访问她，在这之前我们是左右左右左这样的方向来的
 *          3.取出栈顶元素 上一个节点，我们判断是上一个被访问节点是左孩子还是
 *            右孩（问你从哪里来），如果是右孩子说明当前节点的左右访问完毕，
 *            否则不行。。。当然右孩子还可以是没有，，，
 *
 */
void PostOrderNoRecursion(Tree T) {
    Node *preVisited = NULL;
    stack<Node *> stackParents;
    while (T != NULL || stackParents.size() > 0) {
        if (T != NULL) {
            stackParents.push(T);
            T = T->lChild;
        } else {
            T = stackParents.top();
            //1. T form right child and right child is NULL
            //2. if T form left child and now's right child is NULL
            if (T->rChild == NULL || T->rChild == preVisited) {
                cout << T->data << endl;
                preVisited = T;
                stackParents.pop();
                T = NULL;
            } else {
                T = T->rChild; //the right child is no visited
            }
        }
    }
};

int main() {
    Tree T;
    string str = "ABD##EF###C##";
    char *preOrder = (char *) str.c_str();
    int i = 0;
    T = CreateTree(T, preOrder, i);
    PostOrderNoRecursion(T);
    return 0;
}
