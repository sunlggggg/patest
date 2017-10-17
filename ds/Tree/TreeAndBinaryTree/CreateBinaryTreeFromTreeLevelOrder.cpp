//
// Created by sunlggggg on 2017/8/18.
//
#include <iostream>

using namespace std;

typedef struct Node {
    Node() {}

    Node(int data) : value(data), lChild(NULL), rChild(NULL) {}

    int value;
    Node *lChild;
    Node *rChild;
} Node, *NodePtr;

class BT {
private:
    Node *root;

public:

    BT() {
        root = NULL;
    }

    void createBTFromTreeLevelOrder(int levelOrder[], int degree[], int n) {
        Node *nodes = new Node[n];
        for (int i = 0; i < n; i++) {
            nodes[i] = Node(levelOrder[i]);
        }
        int d, k = 0;
        for (int i = 0; i < n; i++) {
            d = degree[i];
            if (d) {
                k++;
                nodes[i].lChild = &nodes[k];
                for (int j = 1; j < d; j++) {
                    nodes[k].rChild = &nodes[++k];
                }
            }
        }
        root = &nodes[0];
    }
};

int main() {
    BT bt;
    int levelOrder[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int degree[] = {3, 2, 1, 1, 0, 0, 0, 1, 0};
    bt.createBTFromTreeLevelOrder(levelOrder, degree, 9);
    return 0;
}
