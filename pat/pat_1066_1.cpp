/**
1066. Root of AVL Tree (25)
ʱ������
100 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
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
		height = 1;//Ҷ�ӽڵ�߶�Ϊ1
		data = _data;
		left = right = NULL;
	}
	int data;
	int height ;
	Node* left;
	Node* right;
};
//��ȡ�ڵ�ĸ߶�
int getHeight(Node *root){
	if(root==NULL){
		return 0 ;
	}else {
		return root->height;
	}
}
//��������
void updataHeight(Node * root){
	root->height = max(getHeight(root->left),getHeight(root->right)) + 1;
}
//��ȡƽ������
int getBalanceFactor(Node * root){
	return getHeight(root->left) - getHeight(root->right);
}
//����
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
//����
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
//��������������ת
void insert(Node * &root , int v){
	if(root==NULL){
		root = new Node(v);
	}else if(root->data <= v){ //����������
		insert(root->right,v);
		//���¸߶�
		updataHeight(root);
		//�����ǲ��������� ��ôƽ������ ��ƽ��ʱ��-2
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
	}else{ //����������
		insert(root->left,v);
		//���¸߶�
		updataHeight(root);
		//�����ǲ��������� ��ôƽ������ ��ƽ��ʱ��2
		if(getBalanceFactor(root) == 2){//L
			if(getBalanceFactor(root->left) == 1){ //L
				//LL ����
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