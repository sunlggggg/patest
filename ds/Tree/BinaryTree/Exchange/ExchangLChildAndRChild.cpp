//
// Created by sunlggggg on 2017/8/10.
//

//
// Created by sunlggggg on 2017/8/10.
//

#include<iostream>
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

void buildBinary(BiTree &tree, char *ch_nodes) {
    char data = ch_nodes[ch_nodes_index++];
    if (data != '#') {
        tree = new Node(data);
        buildBinary(tree->leftChild, ch_nodes);
        buildBinary(tree->rightChild, ch_nodes);
    }
}
void exchange(BiTree biTree ){
    if(biTree ){
        Node * tmp = biTree->rightChild;
        biTree->rightChild = biTree->leftChild ;
        biTree->leftChild = tmp ;
        exchange(biTree->rightChild);
        exchange(biTree->leftChild);
    }
}
int main() {
    ios::sync_with_stdio(false);
    string str = "ABD##EF###C##";
    //string str = "A##";
    char *preOrder = (char *) str.c_str();
    BiTree tree;
    buildBinary(tree, preOrder);
    exchange(tree);
    flush(cout);
    return 0;
}