//
// Created by sunlggggg on 2017/11/16.
// 从二叉查找树种删除 X
//

#include<stdio.h>
#include <malloc.h>

typedef struct TreeNode *NodePointer;
typedef NodePointer Tree;

struct TreeNode {
    int data;
    NodePointer leftChild;
    NodePointer rightChild;
};

//建立二叉查找树
void _insert(Tree &node, int data);
void _buildSearch(Tree &T, int *data, int data_length);

// 删除X节点
//使用左子树中最大节点 或者右子树中最小节点来代替 待删除节点
bool DeleteX(Tree &T, int X) {
    if (T == NULL) {
        return false;
    } else {
        bool isDeleteX;
        if (T->data == X) {
            isDeleteX = true;
            //找到左边最大的元素  或者 右边最小的元素
            //左子树从根开始 一直向右边找 直到一个节点右子树为空将其删除其值直接赋给 原来节点
            //右子树从根开始一直向左边找 直到一个节点左子树为空将其删除其值直接赋给原来节点
            //删除一个只有一个孩子的节点将是十分简单的
            //delete X
            if (T->leftChild) {   //左子树不为空
                //   4    待删除                     4 待删除 pre
                //  2        pre                   3  子树最大节点   p
                //      3  子树最大节点   p        1
                //   2.5
                // pre->rightChild = p->leftChild   pre->leftChild = p->leftChild
                NodePointer p = T->leftChild;
                NodePointer pre = T;
                while (p->rightChild) {
                    pre = p;
                    p = p->rightChild;
                }
                if(pre == T) {
                    pre->leftChild = p->leftChild;
                }else {
                    pre->rightChild = p->leftChild;
                }
                T->data = p->data;
                free(p);//free 待删除节点左子树中最大节点
            } else if (T->rightChild) { //右子树不为空
                NodePointer p = T->rightChild;
                NodePointer pre = T;
                while (T->leftChild) {
                    pre = p ;
                    p = T->leftChild;
                }
                if(pre == T) {
                    pre->rightChild = p->rightChild;
                }else {
                    pre->leftChild = p->rightChild;
                }
                T->data = p->data;
                free(p);//free 待删除节点右子树中最大节点
            } else { //左右子树都为空
                NodePointer tmp = T;
                T = NULL;
                free(tmp);
            }
        } else if (T->data < X) {
            isDeleteX = DeleteX(T->rightChild, X);
        } else {
            isDeleteX = DeleteX(T->leftChild, X);
        }
        return isDeleteX;
    }
}

int main() {

    int a[] = {9, 2, 4, 4, 3, 8, 1};
    Tree T = NULL;
    _buildSearch(T, a, 7);
    DeleteX(T, 4);
    DeleteX(T,9);
    DeleteX(T,1);
    DeleteX(T,3);
    DeleteX(T,8);
    DeleteX(T,2);
    return 0;
}

void _insert(Tree &node, int data) {
    if (node == NULL) {
        node = (Tree) malloc(sizeof(TreeNode));
        node->data = data;
        node->leftChild = NULL;
        node->rightChild = NULL;
    } else {
        if (node->data < data)
            //插入到左边的
            _insert(node->rightChild, data);
        else if (node->data > data)
            _insert(node->leftChild, data);
    }
}

void _buildSearch(Tree &T, int *data, int data_length) {
    for (int i = 0; i < data_length; i++) {
        _insert(T, data[i]);
    }
}