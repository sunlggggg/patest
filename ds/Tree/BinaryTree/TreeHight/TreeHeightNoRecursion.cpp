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
int ch_nodes_index = 0;

void buildBinary(BiTree &tree, char *ch_nodes) {
    char data = ch_nodes[ch_nodes_index++];
    if (data != '#') {
        tree = new Node(data);
        buildBinary(tree->leftChild, ch_nodes);
        buildBinary(tree->rightChild, ch_nodes);
    }
}

/*利用后续遍历进行计算行高（非递归）*/
int treeHeight(BiTree biTree) {
    int height = 0;
    stack<Node *> sta_nodes_postOrder;
    Node *prePtr = NULL;
    Node *nowPtr = biTree;
    //当前节点非空 栈中有元素
    while (nowPtr || sta_nodes_postOrder.size() > 0) {
        //走到最左
        while (nowPtr != NULL) {
            sta_nodes_postOrder.push(nowPtr);
            nowPtr = nowPtr->leftChild;
        }//nowPtr 为空
        height = max(height, (int)sta_nodes_postOrder.size());
        nowPtr = sta_nodes_postOrder.top();
        //栈顶元素右子树已经访问 或者为空
        if (nowPtr->rightChild == prePtr || !nowPtr->rightChild) {
            cout << nowPtr->data;
            sta_nodes_postOrder.pop();
            //左子树已经访问过 ，一旦非空又会到最左
            prePtr = nowPtr;
            nowPtr = NULL;
        } else //右子树未访问 将右子树 根节点 设为当前节点 并在此走到最左
            nowPtr = nowPtr->rightChild;
    }
    cout << endl;
    return height;
}

int main() {
    ios::sync_with_stdio(false);
    string str = "ABD##EF###C##";
    //string str = "A##";
    char *preOrder = (char *) str.c_str();
    BiTree tree;
    buildBinary(tree, preOrder);
    cout << treeHeight(tree);
    flush(cout);
    return 0;
}