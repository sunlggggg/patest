//
// Created by sunlggggg on 2017/8/10.
//

//
// Created by sunlggggg on 2017/8/10.
//

#include<iostream>
#include <stack>

using namespace std;

typedef struct Node {
    Node(char data) :
            data(data), leftChild(NULL), rightChild(NULL) {}

    char data;
    Node *leftChild;
    Node *rightChild;
} *
        BiTree;
char preOrder[10] = {'A', 'B', 'D', 'E', 'F', 'C'};
char inOrder[10] = {'D', 'B', 'F', 'E', 'A', 'C'};

Node *CreateTreeByLevelOrderAndInOrder(int preOrder_from,
                                       int preOrder_to,
                                       int inOrder_from,
                                       int inOrder_to) {
    Node *root = NULL;
    if (preOrder_from <= preOrder_to) {
        //当前子树的根 root
        root = new Node(preOrder[preOrder_from]);

        //找到中序中根的位置
        int root_inOrder_index;
        for (int i = inOrder_from; i <= inOrder_to; i++) {
            if (inOrder[i] == preOrder[preOrder_from]) {
                root_inOrder_index = i;
                break;
            }
        }
        //递归建立root的左子树
        root->leftChild = CreateTreeByLevelOrderAndInOrder(preOrder_from + 1,
                                                           preOrder_from + (root_inOrder_index - inOrder_from),
                                                           inOrder_from, root_inOrder_index - 1);


        //递归建立root的右子树
        root->rightChild = CreateTreeByLevelOrderAndInOrder(preOrder_to - (inOrder_to - root_inOrder_index) + 1,
                                                            preOrder_to,
                                                            root_inOrder_index + 1, inOrder_to);

    }
    return root;
}

int main() {
    ios::sync_with_stdio(false);
    BiTree Tree;
    Tree = CreateTreeByLevelOrderAndInOrder(0, 5, 0, 5);

    flush(cout);
    return 0;
}