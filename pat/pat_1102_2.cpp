/**
1102. Invert a Binary Tree (25)
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
The following is from Max Howell @twitter:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can't invert a binary tree on a whiteboard so fuck off.

Now it's your turn to prove that YOU CAN invert a binary tree!

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N-1. Then N lines follow, each corresponds to a node from 0 to N-1, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.

Output Specification:

For each test case, print in the first line the level-order, and then in the second line the in-order traversal sequences of the inverted tree. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:
3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1
**/

#include<iostream>
#include<queue>
using namespace std;
const int maxn = 10;
struct Node{
	int left;
	int right;
};
Node Tree[maxn];
bool notRoot[maxn] = {false};
int n, num = 0 ;//n为节点个数 num为当前已经输出的节点个数
//print 函数输出节点id的编号
void print(int id){
	printf("%d",id);
	num++;
	if(num!=n){
		printf(" ");
	}else {
		printf("\n");
	}
}
int strToNum(char c){
	if(c=='-'){
		return -1;
	}else{
		notRoot[c-'0'] = true;
		return c -'0';
	}
}

int findRoot(){
	for(int i= 0 ; i< n ; i++){
		if(notRoot[i] == false){
			return i;
		}
	}
}
void inOrder(int root){
	if(root == -1){
		return ;
	}
	inOrder(Tree[root].left);
	print(root);
	inOrder(Tree[root].right);
}
void postOrder(int root){
	if(root == -1){
		return ;
	}
	postOrder(Tree[root].left);
	postOrder(Tree[root].right);
	swap(Tree[root].left,Tree[root].right);
}
void levelOrder(int root){
	queue<int> q;
	if(root!=-1)
		q.push(root);
	while(q.size()){
		int root = q.front();
		if(Tree[root].left!=-1){
			q.push(Tree[root].left);
		}
		if(Tree[root].right!=-1){
			q.push(Tree[root].right);
		}
		q.pop();
		print(root);
	}
}
int main(){
#ifdef _DEBUG
	freopen("data.txt","r",stdin);
#endif
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		char left , right;
		getchar();//读取换行
		scanf("%c %c",&left,&right);
		Tree[i].left = strToNum(left);
		Tree[i].right = strToNum(right);
	}
	int root = findRoot();
	//后序遍历中反转
	postOrder(root);
	levelOrder(root);
	num = 0 ;
	inOrder(root);
	return 0;
}