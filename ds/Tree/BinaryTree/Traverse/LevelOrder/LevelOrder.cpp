//
// Created by sunlggggg on 2017/8/10.
//

#include<iostream>
#include <stack>
#include <queue>

using namespace std;

typedef struct Node {
    Node(char data) :
            data(data), leftChild(NULL), rightChild(NULL) {}

    char data;
    Node *leftChild;
    Node *rightChild;
} *
        BiTree;
int ch_nodes_index = 0;
stack<Node> sta_nodes_save;

void buildBinary(BiTree &tree, char *ch_nodes) {
    char data = ch_nodes[ch_nodes_index++];
    if (data != '#') {
        tree = new Node(data);
        buildBinary(tree->leftChild, ch_nodes);
        buildBinary(tree->rightChild, ch_nodes);
    }
}

void levelOrder(BiTree tree) {
    if (!tree) {
        return;
    }
    queue<Node> que_nodes_traverse;
    que_nodes_traverse.push(*tree);
    while (que_nodes_traverse.size() > 0) {
        Node node = que_nodes_traverse.front();
        cout<<node.data;
        sta_nodes_save.push(node);
        if (node.leftChild)
            que_nodes_traverse.push(*node.leftChild);
        if(node.rightChild)
            que_nodes_traverse.push(*node.rightChild);
        que_nodes_traverse.pop();
    };
    cout<<endl;
};

int main() {
    ios::sync_with_stdio(false);
    string str = "ABD##EF###C##";
    char *preOrder = (char *) str.c_str();
    BiTree tree;
    buildBinary(tree, preOrder);
    levelOrder(tree);
    while(sta_nodes_save.size()>0){
        cout<<sta_nodes_save.top().data;
        sta_nodes_save.pop();
    }
    cout<<endl;
    return 0;
}