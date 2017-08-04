//
// Created by sunlggggg on 2017/8/3.
//

#include <iostream>
#include <malloc.h>
#include <string>
#include <stack>

using namespace std ;
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
Node *CreateTree(Node * T, char *p, int &i){
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

void PostOrderNoRecursion(Tree T){
    Node *preVisited = NULL ;
    stack<Node*> stackParents ;
    while(T!= NULL ||stackParents.size()>0){
        if(T!= NULL){
            stackParents.push(T);
            T = T->lChild ;
        } else {
            T = stackParents.top();
            //1. T form right child and right child is NULL
            //2. if T form left child and now's right child is NULL
            if(T->rChild== NULL || T->rChild == preVisited){
                cout<<T->data<<endl;
                preVisited = T ;
                stackParents.pop();
                T= NULL;
            }else{
                T = T->rChild; //the right child is no visited
            }
        }
    }
};
int main(){
    Tree T;
    string str = "ABD##EF###C##";
    char * preOrder = (char *) str.c_str();
    int i = 0 ;
    T = CreateTree(T,preOrder,i);
    PostOrderNoRecursion(T);
    return 0 ;
}
