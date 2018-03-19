/**
1064. Complete Binary Search Tree (30)
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
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the bottom level, which is filled from left to right.

Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that the tree must also be a CBT. You are supposed to output the level order traversal sequence of this BST.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N distinct non-negative integer keys are given in the next line. All the numbers in a line are separated by a space and are no greater than 2000.

Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input:
10
1 2 3 4 5 6 7 8 9 0
Sample Output:
6 3 8 1 5 7 9 0 2 4
**/

#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn = 2020;
int  n ; 
int tree[maxn] = {-1};//tree[i] = -1 表示
int in[maxn];
int num = 0;
void inOrder(int rootID){ //0 1 2 
	if(rootID*2+1<n){
		inOrder(rootID*2+1);
	}
	if(rootID < n){
		tree[rootID] = in[num++];
	}
	if(rootID*2+2<n){
		inOrder(rootID*2+2);
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
	for(int i = 0 ; i< n; i++){
		scanf("%d",&in[i]);
	}
	sort(in,in+n);
	inOrder(0);
	for(int i = 0 ; i < n ; i++){
		printf("%d",tree[i]);
		if(i!=n-1){
			printf(" ");
		}else {
			printf("\n");
		}
	}
	return 0;
}