//
// Created by sunlggggg on 2017/8/17.
//

#include <iostream>
#include <malloc.h>
#include <vector>
#include <list>

using namespace std;

typedef struct Node {
    Node() {}

    Node(int data) : value(data), lChild(NULL), rChild(NULL) {}

    int value;
    Node *lChild;
    Node *rChild;
} Node, *NodePtr;

class BST {
private:
    Node *root;
    int preValue = -32767;

    void _buildSearch(int *data, int data_length) {
        for (int i = 0; i < data_length; i++) {
            _insert(root, data[i]);
        }
    }

    void _insert(NodePtr &node, int data) {
        if (node == NULL) {
            //插入
            node = new Node(data);
        } else {
            if (node->value < data)
                //插入到左边的
                _insert(node->rChild, data);
            else if (node->value > data)
                _insert(node->lChild, data);

        }
    }

    void _inOrder(NodePtr root) {
        if (!root) {
            return;
        } else {
            _inOrder(root->lChild);
            cout << root->value << " ";
            _inOrder(root->rChild);
        }
    }

    void _recipInOrder(NodePtr root, int key) {
        if (!root) {
            return;
        } else {
            _recipInOrder(root->rChild, key);
            if (root->value < key)
                return;
            cout << root->value << " ";
            _recipInOrder(root->lChild, key);
        }
    }

    int _judgeBST(NodePtr root) {
        int b1, b2;
        if (root == NULL) {
            //平衡的
            return 1;
        } else {
            //判断左子树是否是排序二叉树
            b1 = _judgeBST(root->lChild);
            //左子树不是一个排序二叉树 或者 当前的节点小于等于上一个节点
            if (b1 == 0 || preValue >= root->value) {
                return 0;
            }
            preValue = root->value;
            //判断右子树是否是排序二叉树
            return _judgeBST(root->rChild);
        }
    }

    void _buildCommon(Node *&node, list<int> &data) {
        if (data.size() == 0) {
            return;
        }
        int value = data.front();
        data.pop_front();
        if (value == -1) {
            node = NULL;
            return;
        }
        node = new Node(value);
        _buildCommon(node->lChild, data);
        _buildCommon(node->rChild, data);
    }

public:

    BST() {
        root = NULL;
    }

    void buildSearchTree(int *data, int data_length) {
        root = NULL;
        //建立树
        _buildSearch(data, data_length);
    }

    void buildCommonTree(list<int> data) {
        _buildCommon(root, data);
    }

    bool JudgeBST() {
        return _judgeBST(root) == 1;
    }

    void inOrder() {
        _inOrder(root);
        cout << endl;
    }

    void recipInOrder(int key) {
        _recipInOrder(root, key);
        cout << endl;
    }


};

int main() {
    int arr_data[8] = {10, 2, 4, 5, 67, 8, 12, 22};
    list<int> l_data = {10, 5, -1, 4, -1, -1, 12, -1, -1};
    BST bst;
    // bst.buildSearchTree(arr_data, 8);
    bst.buildCommonTree(l_data);
    bst.JudgeBST();
    bst.inOrder();
    bst.recipInOrder(8);
    return 0;
}