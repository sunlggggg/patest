//
// Created by sunlggggg on 2017/10/21.
//
#include <stdio.h>
#include <malloc.h>

typedef struct NODE {
    struct NODE *leftChild;
    struct NODE *rightChild;
    char data;
} Node, *BiTree;

BiTree BuildTree(BiTree biTree) {
    char ch;
    scanf("%c", &ch);
    if (ch == '#') {
        biTree = NULL;
    } else {
        biTree = (Node *) malloc(sizeof(Node));
        biTree->data = ch;
        biTree->leftChild = BuildTree(biTree->leftChild);
        biTree->rightChild = BuildTree(biTree->rightChild);
    }
    return biTree;
}

void PostTraverse(BiTree biTree) {
    if (biTree != NULL) {
        printf("%c", biTree->data);
        PostTraverse(biTree->leftChild);
        PostTraverse(biTree->rightChild);
    }
}



int isBalance(BiTree t) {
    if (t == NULL)
        return 0;
    else {
        int leftSubtreeHeight = isBalance(t->leftChild);
        int rightSubtreeHeight = isBalance(t->rightChild);
        if (leftSubtreeHeight == -1 || rightSubtreeHeight == -1)
            return -1;
        else if (abs(leftSubtreeHeight - rightSubtreeHeight) > 1) {
            return -1;
        } else
            return (leftSubtreeHeight >= rightSubtreeHeight?leftSubtreeHeight : rightSubtreeHeight) +1;
    }
}

int main() {
    //input: AB#C##DE###
    //output: ABCFGDE
    BiTree biTree = NULL;
    biTree = BuildTree(biTree);
    PostTraverse(biTree);
    printf("%d", isBalance(biTree));
    return 0;
}