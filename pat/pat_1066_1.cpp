/**
1066. Root of AVL Tree (25)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
An AVL tree is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Figures 1-4 illustrate the rotation rules.



Now given a sequence of insertions, you are supposed to tell the root of the resulting AVL tree.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=20) which is the total number of keys to be inserted. Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print ythe root of the resulting AVL tree in one line.

Sample Input 1:
5
88 70 61 96 120
Sample Output 1:
70
Sample Input 2:
7
88 70 61 96 120 90 65
Sample Output 2:
88
**/
#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 2020;
int n;
struct Node{
	Node(int _data){
		height = 1;//叶子节点高度为1
		data = _data;
		left = right = NULL;
	}
	int data;
	int height ;
	Node* left;
	Node* right;
};
//获取节点的高度
int getHeight(Node *root){
	if(root==NULL){
		return 0 ;
	}else {
		return root->height;
	}
}
//更新树高
void updataHeight(Node * root){
	root->height = max(getHeight(root->left),getHeight(root->right)) + 1;
}
//获取平衡因子
int getBalanceFactor(Node * root){
	return getHeight(root->left) - getHeight(root->right);
}
//右旋
//   A
//  B
//C   X
//----------
//  B
//C     A
//     X
void R(Node * &root){
	Node *temp= root->left;
	root->left = temp->right;
	temp->right = root;
	updataHeight(root);
	updataHeight(temp);
	root = temp;
}
//左旋
//A 
// B
//X  C
//--------
// B
//A    C
//  X 
void L(Node * &root){
	Node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updataHeight(root);
	updataHeight(temp);
	root = temp;
}
//插入操作并结合旋转
void insert(Node * &root , int v){
	if(root==NULL){
		root = new Node(v);
	}else if(root->data <= v){ //插入右子树
		insert(root->right,v);
		//更新高度
		updataHeight(root);
		//由于是插入右子树 那么平衡因子 不平衡时是-2
		if(getBalanceFactor(root) == -2){//R
			if(getBalanceFactor(root->right) == -1){ //R 
				//RR
				L(root);
			}else if(getBalanceFactor(root->right) == 1){ //L
				//RL 
				R(root->right);
				L(root);
			}
		}
	}else{ //插入左子树
		insert(root->left,v);
		//更新高度
		updataHeight(root);
		//由于是插入左子树 那么平衡因子 不平衡时是2
		if(getBalanceFactor(root) == 2){//L
			if(getBalanceFactor(root->left) == 1){ //L
				//LL 右旋
				R(root);
			}else if(getBalanceFactor(root->left) == -1){ //R
				//LR 
				L(root->left);
				R(root);
			}
		}
	}
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
	Node *root = NULL;
	int vl;
	for(int i = 0 ; i< n ; i++){
		scanf("%d",&vl);
		insert(root,vl);
	}
	printf("%d\n", root->data);
	return 0;
}