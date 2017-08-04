//
// Created by sunlggggg on 2017/7/31.
//

#include<iostream>
#include <cstring>

using namespace std;

typedef enum {
    Link,
    Thread
} Pointer;

typedef struct TriTreeNode {
    TriTreeNode(const char data)
            : _data(data), pLeft(NULL), pRight(NULL), pParent(NULL), lTag(Link), rTag(Link) {}

    char _data;
    struct TriTreeNode *pLeft;
    struct TriTreeNode *pRight;
    struct TriTreeNode *pParent;//双亲
    Pointer lTag, rTag;
} TriTreeNode;

class PostThread_BiTree {
public://先序遍历创建树
    PostThread_BiTree(const char arr[], size_t size) {
        size_t index = 0;
        TriTreeNode *parent = NULL;
        _Create_BiTree(_pRoot, arr, size, index, parent);
    }

protected:
    void _Create_BiTree(TriTreeNode *&Root, const char *arr, size_t size, size_t &index, TriTreeNode *&parent) {
        if (arr && size > index && arr[index] != '#') {
            Root = new TriTreeNode(arr[index]);
            Root->pParent = parent;

            _Create_BiTree(Root->pLeft, arr, size, ++index, Root);  //每次传双亲节点
            _Create_BiTree(Root->pRight, arr, size, ++index, Root);
        }
    }

public:
    //后序线索化
    void PostTreading() {
        _PostThreading(this->_pRoot);
        //最后一个节点一定是根节点
        if (this->Prev->pRight == NULL) {
            this->Prev->rTag = Thread;
        }
    }

protected:
    void _PostThreading(TriTreeNode *&Root) {
        if (Root) {
            _PostThreading(Root->pLeft);
            _PostThreading(Root->pRight);
            if (Root->pLeft == NULL) {
                Root->pLeft = Prev;
                Root->lTag = Thread;
            }
            if (Prev && Prev->pRight == NULL) //条件 Prev
            {
                Prev->pRight = Root;
                Prev->rTag = Thread;
            }
            Prev = Root;
        }
    }

public:
    void PostOrder() {
        _PostOrder(this->_pRoot);
    }

protected:
    void _PostOrder(TriTreeNode *Root) {
        if (Root) {
            TriTreeNode *pCur = Root;
            Prev = NULL;
            while (pCur != NULL) {
                //第一步：找树最左边的节点
                //modify 说明,左孩子非空一定能够找到现先续节点，因此条件1不需要
                //while (pCur->pLeft != Prev && pCur->lTag == Link) //左子树
                while (pCur->lTag == Link) //左子树
                    pCur = pCur->pLeft;
                //循环结束后 pCur== Root

                //第二步：访问后继 ，有上可知道 pCur必定为非空
                while ( pCur->rTag == Thread) {
                    cout << pCur->_data << ' ';
                    Prev = pCur;
                    pCur = pCur->pRight;
                }
                //无后继了 pCur

                //只有根节点的rTag 等于Thread的同时他的右孩子还是NULL
                //判断此时pCur是不是指向了根节点
                if (pCur == Root) {
                    cout << pCur->_data << ' ';
                    return;
                }

                //pCur非空
                while (pCur->pRight == Prev) {
                    cout << pCur->_data << ' ';
                    Prev = pCur;
                    pCur = pCur->pParent;  //往上一级走
                }
                //这里不能用NULL判断，而是用rTag
                if (pCur->rTag == Link) {
                    pCur = pCur->pRight;
                }
            }
            //end-while
        }
    }

private:
    TriTreeNode *_pRoot;
    TriTreeNode *Prev;
};


int main() {

    char *arr2 = (char *) "A##";
    PostThread_BiTree tree1(arr2, strlen(arr2));
    tree1.PostTreading();
    tree1.PostOrder();
    cout << endl << "______________________" << endl;

    return 0;
}
