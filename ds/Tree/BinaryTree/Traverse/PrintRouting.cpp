//
// Created by sunlggggg on 2017/8/8.
//

#include<iostream>
#include <stack>
#include <vector>

using namespace std;
typedef struct Node {
    int data;
    struct Node *lChild;
    struct Node *rChild;
} *Tree;

void buildTree(Tree &t, char nodes[], int &i) {
    if (nodes[i] == '#')
        t = NULL;
    else {
        t = new Node;
        t->data = nodes[i] - '0';
        buildTree(t->lChild, nodes, ++i);
        buildTree(t->rChild, nodes, ++i);
    }
}

int sum = 0;
vector<Node> nodes;

void print() {
    for (int i = 0; i < nodes.size(); i++) {
        cout << nodes[i].data;
    }
    cout<<endl;
}

void count(Tree T, int value) {
    if (T != NULL) {
        nodes.push_back(*T);
        sum += T->data;
        if (sum == value && !T->lChild && !T->rChild) {
            print();
        }
        count(T->lChild,value);
        count(T->rChild,value);
        sum-=T->data;
        nodes.pop_back();
    }
}

int main() {
    Tree T;
    string str = "123##45###6##";
    char *preOrder = (char *) str.c_str();
    int i = 0;
    buildTree(T, preOrder, i);
    count(T,7);
    count(T,12);
    count(T,6);
    count(T,0);
    return 0;
}