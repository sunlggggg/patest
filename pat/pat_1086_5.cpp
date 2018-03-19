/**
1086. Tree Traversals Again (25)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. Your task is to give the postorder traversal sequence of this tree.


Figure 1
Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.

Output Specification:

For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist. All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:
3 4 2 6 5 1
**/

#include<iostream>
#include<stack>
#include<string>
using namespace std;
int in[31];
int pre[31];
int n;

struct Node{
	Node(){
		left = right = NULL;
	}
	int data;
	Node *left;
	Node *right;
};
int mpos(int inL, int inH , int vl){
	for(int i = inL; i < inH; i++){
		if(in[i]== vl)
			return i;
	}
}
Node *buildTree(int preL, int preH ,int inL,int inH){
	//1 2 3 4 5 6  pos:1
	//3 2 4 1 6 5  in
	Node *node = NULL;
	if(preL < preH){
		node = new Node();
		node->data = pre[preL];//根
		int pos = mpos(inL,inH,pre[preL]);
		node->left = buildTree(preL+1,preL+1+(pos-inL), inL,pos );
		node->right = buildTree(preL+1+(pos-inL),preH,pos+1,inH);
	}
	return node;
}
int c = 0 ;
void postOrder(Node *node){
	if(node!=NULL){
		if(node->left)
			postOrder(node->left);
		if(node->right)
			postOrder(node->right);
		printf("%d",node->data);
		c++;
		if(c != n){
			printf(" ");
		}
	}
}
int main() {
#ifdef _DEBUG
  freopen("data.txt","r",stdin);
#endif
	cin>>n;
	string s;
	int inc = 0 ;
	int prec = 0 ;
	int data;
	stack<int> sta;
	for(int i = 0 ; i < 2*n; i++){
		cin>>s;
		if(s[1] == 'u'){
			cin>>data;
			sta.push(data);
			pre[prec++] = data;
		}else {
			in[inc++] = sta.top();
			sta.pop();
		}
	}
	Node *node = buildTree(0,n,0,n);
	postOrder(node);
	return 0;
}