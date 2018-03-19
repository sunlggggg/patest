/**
1135. Is It A Red-Black Tree (30)
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
There is a kind of balanced binary search tree named red-black tree in the data structure. It has the following 5 properties:

(1) Every node is either red or black.
(2) The root is black.
(3) Every leaf (NULL) is black.
(4) If a node is red, then both its children are black.
(5) For each node, all simple paths from the node to descendant leaves contain the same number of black nodes.

For example, the tree in Figure 1 is a red-black tree, while the ones in Figure 2 and 3 are not.




Figure 1
Figure 2
Figure 3
For each given binary search tree, you are supposed to tell if it is a legal red-black tree.

Input Specification:

Each input file contains several test cases. The first line gives a positive integer K (<=30) which is the total number of cases. For each case, the first line gives a positive integer N (<=30), the total number of nodes in the binary tree. The second line gives the preorder traversal sequence of the tree. While all the keys in a tree are positive integers, we use negative signs to represent red nodes. All the numbers in a line are separated by a space. The sample input cases correspond to the trees shown in Figure 1, 2 and 3.

Output Specification:

For each test case, print in a line "Yes" if the given tree is a red-black tree, or "No" if not.

Sample Input:
3
9
7 -2 1 5 -4 -11 8 14 -15
9
11 -2 1 -7 5 -4 8 14 -15
8
10 -7 5 -6 8 15 -11 17
Sample Output:
Yes
No
No
**/

#include<iostream>
#include<queue>
#include<set>
#include<cstring>
#include<stack>
#include<cmath>
#include<map>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
const int N = 30;
int n ;
struct Node {
	Node(){
		left = right = NULL;
	}
	int data;//负数为red
	Node *left;
	Node *right;
};
//3 1 2 4
//1 2 3 4
bool flag = true;
int blackNum(Node *root){
	if(!flag ){
		return 0;
	}
	if(root == NULL){
		return 0;
	}
	int ln = blackNum(root->left);
	int rn = blackNum(root->right);
	if(ln != rn){
		flag = false;
		return ln;
	}else if(ln == rn &&root->data>0 ){
		return ln+1;
	}else{
		return ln;
	}
}
bool isALLBlack(Node *root){
	if(root==NULL) return true;
	else if(root->data < 0&&((root->left&&root->left->data < 0)||(root->right&&root->right->data < 0)) )
		return false;
	else return isALLBlack(root->left)&&isALLBlack(root->right);
}

//正数是black
bool isRedAndBlackTree(Node *root){
	flag = true;
	if(root->data < 0 ){
		return false;
	}else{
		//计算节点数目
		blackNum(root);
		//深度遍历
		return flag&&isALLBlack(root->left)&&isALLBlack(root->right);
	}
}
void _insert(Node *&root,int vl){
	if(root == NULL){
		root = new Node();
		root->data = vl;
		return;
	}else if(abs(vl) >= abs(root->data)){
		_insert(root->right,vl);
	}else{
		_insert(root->left,vl);
	}
}
int main(){
#ifdef _DEBUG
	char _case;
	scanf("%c",&_case);
	string _case_s = "data";
	_case_s.push_back(_case);
	_case_s.append(".txt");
	freopen(_case_s.c_str(),"r",stdin);
#endif
	int k ;
	scanf("%d", &k );
	for(int i = 0 ;i < k ; i++){
		Node *node = NULL;
		scanf("%d",&n);
		int data;
		for(int k = 0 ; k< n; k++){
			scanf("%d",&data);
			_insert(node,data);
		}
		if(isRedAndBlackTree(node) ){
			printf("Yes\n");
		}else {
			printf("No\n");
		}
	}
	return 0 ;
}
