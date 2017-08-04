//
// Created by sunlggggg on 2017/8/2.
//
#include <iostream>
#include <malloc.h>
using namespace std;
typedef struct Node{
    Node(char ch):data(ch),lChild(NULL),rChild(NULL){}
    char data;
    struct Node *lChild;
    struct Node *rChild;
}Node, *Tree;

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
Node *CreateTree(Node * T, char p[], int &i){
    char data = p[i];
    if(data == '#'){
        return NULL;
    } else{
        T = (Node *)malloc(sizeof(Node));
        T->data = data;
        T->lChild = CreateTree(T->lChild,p,++i);
        T->rChild = CreateTree(T->rChild,p,++i);
        return T;
    }
}

/**
 * train of though: 当前的子树的根节点就是层次遍历的最前的节点，我们的目标是
 * 在中序遍历中用该节点去分割为左右子树的序列
 * @return
 */
Node * CreateTreeByLevelOrderAndInOrder(char levelOrder[],char inOrder[],
                                        int inOderFrom, int inOrderTo, int levelOrder ){

}
int main(){
    Tree T;
    char levelOrder[10]={'A','B','E','C','D'};
    char inOrder[10] = {'C','B','D','A','C'};
    int i = 0 ;
    T = CreateTree(T,p,i);
    return 0 ;
}