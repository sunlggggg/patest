#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cstdio>
#include<stdlib.h>
using namespace std;

/*
description:
1. The second line gives the inorder sequence and the third line gives the postorder sequence.

2. Suppose that all the keys in a binary tree are distinct positive integers. A unique binary tree can be determined by a given pair of postorder and inorder traversal sequences. And it is a simple standard routine to print the numbers in level-order. However, if you think the problem is too simple, then you are too naive. This time you are supposed to print the numbers in "zigzagging order" -- that is, starting from the root, print the numbers level-by-level, alternating between left to right and right to left.

test example :
8
12 11 20 17 1 15 8 5
12 20 17 11 15 8 5 1
Sample Output:
1 11 5 8 17 12 20 15
*/


typedef struct Node
{
	int data;
	int level;
	struct Node * leftChild;
	struct Node * rightChild;
};

int findRootIndexFormInOrderSqu(int data, int * inOrderSqu, int inorderSqueStartIndex, int inorderSqueEndIndex){
	int ret = -1;
	for (int i = inorderSqueStartIndex; i <= inorderSqueEndIndex; i++){
		if (inOrderSqu[i] == data){
			ret = i;
			break;
		}
	}
	return ret;
}

Node *  bulidTree(int * inOrderSqu, int inOrderSquStartIndex, int inorderSquEndIndex, int * postOrderSqu, int postOrderSquStartIndex, int postOrderSquEndIndex, int level){
	//if (postOrderSquStartIndex <= postOrderSquEndIndex){
	int rootIndex = findRootIndexFormInOrderSqu(postOrderSqu[postOrderSquEndIndex], inOrderSqu, inOrderSquStartIndex, inorderSquEndIndex);
	Node * root = NULL;
	if (rootIndex != -1){
		root = new Node();
		root->level = level;
		root->data = postOrderSqu[postOrderSquEndIndex];
		root->rightChild = bulidTree(inOrderSqu, rootIndex + 1, inorderSquEndIndex, postOrderSqu, postOrderSquStartIndex + (rootIndex - inOrderSquStartIndex), postOrderSquEndIndex - 1, level + 1);
		root->leftChild = bulidTree(inOrderSqu, inOrderSquStartIndex, rootIndex - 1, postOrderSqu, postOrderSquStartIndex, postOrderSquStartIndex + (rootIndex - inOrderSquStartIndex - 1), level + 1);
	}
	return root;
	//}
}

//level traversal
void ZigZaggingOrder(Node * root){
	vector<int> ret[30];
	queue<Node *> q;
	if (root != NULL){
		q.push(root);
	}
	while (!q.empty()){
		while (!q.empty()){
			Node * node = q.front();
			ret[node->level].push_back(node->data);
			q.pop();
			if (node->leftChild){
				q.push((node->leftChild));
			}
			if (node->rightChild){
				q.push((node->rightChild));
			}
		}
	}
	for (int i = 0; i < 30 ; i++ ){
		if (ret[i].size() > 0){
			if (i % 2 == 0){
				for (int j = ret[i].size() - 1; j >= 0; j--){
					if (i == 0 && j == 0)
						cout << ret[i][j];
					else
						cout << " " << ret[i][j];
				}
			}
			else{
				for (int j = 0; j < ret[i].size(); j++){
					cout << " " << ret[i][j];
				}
			}
		}
		else{
			break;
		}
	}
}
int main(){

	ios::sync_with_stdio(false);
	int n = 0;
	cin >> n;
	int inOrderSqu[30];
	int postOrderSqu[30];
	for (int i = 0; i < n; i++){
		cin >> inOrderSqu[i];
	}
	for (int i = 0; i < n; i++){
		cin >> postOrderSqu[i];
	}
	Node * node;
	node = bulidTree(inOrderSqu, 0, n - 1, postOrderSqu, 0, n - 1, 0);
	ZigZaggingOrder(node);
	return 0;
}
