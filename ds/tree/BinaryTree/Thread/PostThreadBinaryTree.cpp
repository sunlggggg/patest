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
                while (pCur->pLeft != Prev && pCur->lTag == Link) //左子树
                {
                    pCur = pCur->pLeft;
                }
                //循环结束后 pCur== Root 或者为空

                //第二步：访问后继
                while (pCur && pCur->rTag == Thread) {
                    cout << pCur->_data << ' ';
                    Prev = pCur;
                    pCur = pCur->pRight;
                }
                //判断此时pCur是不是指向了根节点
                if (pCur == Root) {
                    cout << pCur->_data << ' ';
                    return;
                }
                while (pCur && pCur->pRight == Prev) {
                    cout << pCur->_data << ' ';
                    Prev = pCur;
                    pCur = pCur->pParent;  //往上一级走
                }
                //这里不能用NULL判断，而是用rTag
                if (pCur && pCur->rTag == Link) {
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

void Test() {
    char *arr = (char *) "013##4##25##6##";
    PostThread_BiTree tree(arr, strlen(arr)); //构建三叉树
    tree.PostTreading();
    tree.PostOrder();//arr 3 4 1  5 6 2  0
    cout << endl << "______________________" << endl;

    char *arr2 = (char *) "12#3##4##";
    PostThread_BiTree tree1(arr2, strlen(arr2));
    tree1.PostTreading();
    tree1.PostOrder();
    cout << endl << "______________________" << endl;

    char *arr3 = (char *) "12#3#4##5##";
    PostThread_BiTree tree2(arr3, strlen(arr3));
    tree2.PostTreading();
    tree2.PostOrder();
    cout << endl << "______________________" << endl;

    char *arr4 = (char *) "126##3#4##5##";
    PostThread_BiTree tree3(arr4, strlen(arr4));
    tree3.PostTreading();
    tree3.PostOrder();
    cout << endl << "______________________" << endl;

}

int main() {
    Test();
    return 0;
}
