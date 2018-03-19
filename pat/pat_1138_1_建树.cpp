/**
1138. Postorder Traversal (25)
时间限制
600 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Suppose that all the keys in a binary tree are distinct positive integers. Given the preorder and inorder traversal sequences, you are supposed to output the first number of the postorder traversal sequence of the corresponding binary tree.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=50000), the total number of nodes in the binary tree. The second line gives the preorder sequence and the third line gives the inorder sequence. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the first number of the postorder traversal sequence of the corresponding binary tree.

Sample Input:
7
1 2 3 4 5 6 7
2 3 1 5 4 7 6
Sample Output:
3
**/

#include<iostream>
#include<vector>
using namespace std;
struct Node{
	Node(){
		left = NULL;
		right = NULL;
	}
	Node(int i){
		num = i;
		left = NULL;
		right = NULL;
	}
	int num;
	Node *left,*right;
};
//pre in
//
int mfind(vector<int> v,int val){
	int  rt = -1;
	for(int i = 0 ; i < v.size(); i++){
		if(v[i] == val){
			rt = i ;
			break;
		}
	}
	return rt;
}
int mfind(vector<int> v,int L,int H,int val){
	int  rt = -1;
	for(int i = L; i <H ; i++){
		if(v[i] == val){
			rt = i ;
			break;
		}
	}
	return rt;
}
//构建
Node* preAndInBuild(vector<int> pre,vector<int> in){
	Node *node = NULL;
	if(pre.size()>0){
		int root = pre[0];
		node = new Node(pre[0]);
		int pos = mfind(in,pre[0]);
		vector<int> inLeftChildTree(in.begin(),in.begin()+pos);
		vector<int> inRightChildTree( in.begin()+pos+1,in.end());
		vector<int> preLeftChildTree(pre.begin()+1,pre.begin()+1+inLeftChildTree.size());
		vector<int> preRightChildTree(pre.end() - inRightChildTree.size(),pre.end());
		node->left = preAndInBuild(preLeftChildTree,inLeftChildTree); //左子树
		node->right = preAndInBuild(preRightChildTree,inRightChildTree); //右子树
		return node;
	}
	return node;
}
//构建
Node* preAndInBuild(vector<int> pre,vector<int> in,int preL,int preH , int inL,int inH){
	Node *node = NULL;
	if(preL<preH){
		int root = pre[preL];
		node = new Node(pre[preL]);
		int pos = mfind(in, inL,inH,pre[preL]);
		//12345 231(pos:2)45  preL:0 preH:5 pos:2 inL:0 inH:5 npreL:1 npreH:3 0+2-0+1 ninL:0  ninH:0+2-
		node->left = preAndInBuild(pre,in,preL+1, preL+ pos-inL+1,inL, pos); //左子树
		node->right = preAndInBuild(pre,in,preL+1+(pos-inL),preH, pos+1, inH); //右子树  3-5
		return node;
	}
	return node;
}
void p(Node *tree){
	while(tree !=NULL){
		if(tree->left !=NULL)
			tree = tree->left;
		else if(tree->right!=NULL)
			tree = tree->right;
		else{ 
			printf("%d\n",tree->num);
			break;
		}

	}
}

//取巧
bool flag = false;
void postOrder(Node *T){
	if(T!=NULL){
		postOrder(T->left);
		postOrder(T->right);
		if(flag == false){
			printf("%d\n",T->num);
			flag = true;
		}
	}
}
int main(){
	int n;
	vector<int> pre,in;
	scanf("%d",&n);
	for(int i = 0 ; i < n; i++){
		int t;
		scanf("%d",&t);	
		pre.push_back(t);
	}
	for(int i = 0 ; i < n; i++){
		int t;
		scanf("%d",&t);	
		in.push_back(t);
	}
	Node *Tree;
	Tree= preAndInBuild(pre,in,0,pre.size(),0,in.size());
	p(Tree);
	return 0;
}