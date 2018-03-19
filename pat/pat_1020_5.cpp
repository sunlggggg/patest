/**
1020. Tree Traversals (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Suppose that all the keys in a binary tree are distinct positive integers. Given the postorder and inorder traversal sequences, you are supposed to output the level order traversal sequence of the corresponding binary tree.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the postorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding binary tree. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
Sample Output:
4 1 6 3 5 7 2
**/

#include<iostream>
#include<queue>
using namespace std;
struct Node{
	Node(){
		left = right = NULL;
	}
	int data;
	Node *left;
	Node *right;
};
int post[31];
int in[31];
int mpos(int inL, int inH , int vl){
	for(int i = inL; i < inH; i++){
		if(in[i]== vl)
			return i;
	}
}
Node *buildTree(int postL, int postH ,int inL,int inH){
	//2 3 1 5 7 6 4 post   pos:3
	//1 2 3 4 5 6 7 in
	Node *node = NULL;
	if(postL < postH){
		node = new Node();
		node->data = post[postH - 1];//根
		int pos = mpos(inL,inH,post[postH-1]);
		node->left = buildTree(postL,postL+(pos-inL), inL,pos);
		node->right = buildTree(postL+(pos-inL),postH-1, pos+1, inH);
	}
	return node;
}
int n;
void levelOrder(Node *node){
	queue<Node*> q;
	if(node!=NULL){
		q.push(node);
	}
	int c = 0 ;
	while(q.size()>0){
		Node *root = q.front();
		printf("%d",root->data);
		c++;
		if(c<n){
			printf(" ");
		}else{
			printf("\n");
		}
		q.pop();
		if(root->left){
			q.push(root->left);
		}
		if(root->right){
			q.push(root->right);
		}
	}
}
int main(){
#ifdef _DEBUG
	freopen("data.txt","r",stdin);
#endif
	//后序和中序 
	//给出层序

	scanf("%d",&n);
	for(int i = 0 ; i< n ; i++){
		scanf("%d",&post[i]);
	}

	for(int i = 0 ; i< n ; i++){
		scanf("%d",&in[i]);
	}
	Node *node = buildTree(0,n,0,n);
	levelOrder(node);
	return 0;
}