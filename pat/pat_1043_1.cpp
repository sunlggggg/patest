/**
1043. Is It a Binary Search Tree (25)
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
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
If we swap the left and right subtrees of every node, then the resulting tree is called the Mirror Image of a BST.

Now given a sequence of integer keys, you are supposed to tell if it is the preorder traversal sequence of a BST or the mirror image of a BST.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N integer keys are given in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, first print in a line "YES" if the sequence is the preorder traversal sequence of a BST or the mirror image of a BST, or "NO" if not. Then if the answer is "YES", print in the next line the postorder traversal sequence of that tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input 1:
7
8 6 5 7 10 8 11
Sample Output 1:
YES
5 7 6 8 11 10 8
Sample Input 2:
7
8 10 11 8 6 7 5
Sample Output 2:
YES
11 8 10 7 5 6 8
Sample Input 3:
7
8 6 8 5 10 9 11
Sample Output 3:
NO
**/

#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;

struct Node{
	Node(){
		left = right = NULL;
	}
	int data;
	Node *left;
	Node *right;
};
const int maxn = 1010;
int  n ; 
//isM:是否是镜像
void preOrigin(Node *root,vector<int> &seq){
	if(root){
		seq.push_back(root->data);
	}
	if(root->left)
		preOrigin(root->left,seq);
	if(root->right)
		preOrigin(root->right,seq);
}
void preMirror(Node *root,vector<int> &seq){
	if(root){
		seq.push_back(root->data);
	}
	if(root->right)
		preMirror(root->right,seq);
	if(root->left)
		preMirror(root->left,seq);
}

int num = 0;
void postOrder(Node *node, bool isM){
	if(node){
		if(isM == false){
			postOrder(node->left,isM);
			postOrder(node->right,isM);
		}else{
			postOrder(node->right,isM);
			postOrder(node->left,isM);
		}
		printf("%d",node->data);
		num++;
		if(num<n){
			printf(" ");
		}else {
			printf("\n");
		}
	}
}
void insert(Node *&root, int vl){
	if(root == NULL){
		root = new Node();
		root->data = vl;
	}else{
		if(root->data <= vl){
			insert(root->right,vl);
		}else{
			insert(root->left,vl);
		}
	}
}
vector<int> getPre;//输入的
bool isSameSeq(vector<int> a, vector<int> b){
	for(int i = 0 ; i< a.size();i++){
		if(a[i]!= b[i])
			return false;
	}
	return true;
}
int main() {
#ifdef _DEBUG
	char _case;
	scanf("%c",&_case);
	string _case_s = "data";
	_case_s.push_back(_case);
	_case_s.append(".txt");
	freopen(_case_s.c_str(),"r",stdin);
#endif
	scanf("%d",&n);
	int vl;
	Node *root = NULL;
	for(int i = 0 ; i< n; i++){
		scanf("%d",&vl);
		getPre.push_back(vl);
		insert(root,vl);
	}
	vector<int> pre;
	preOrigin(root,pre);
	if(isSameSeq(pre,getPre)){
		printf("YES\n");
		postOrder(root,false);
	}else{
		pre.clear();
		preMirror(root,pre);
		if(isSameSeq(pre,getPre)){
			printf("YES\n");
			postOrder(root,true);
		}else {
			printf("NO\n");
		}
	}
	return 0;
}