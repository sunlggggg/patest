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
#include<map>
using namespace std;

int mfind(int *v,int L,int H,int val){
	int  rt = -1;
	for(int i = L; i <H ; i++){
		if(v[i] == val){
			rt = i ;
			break;
		}
	}
	return rt;
}
//1 2 3 4 5 6 7 
//2 3 1 5 4 7 6
int firstPostOrder(int* pre, int* in, int preL, int preH, int inL , int inH ) {
	while(preL < preH  ){
		//1:2
		int rootPos = mfind(in,inL,inH, pre[preL]);//根位置
		if(rootPos>inL){//左子树非空 
			preL+=1;
			preH+=(rootPos-inL);
			//inL不变
			inH = rootPos;
		}else if(rootPos < inH -1){// 左空，右子树非空
			preL+=(rootPos-inL+1);
			//preH不变
			inL = rootPos+1;
			//inH不变
		}else{
			return pre[preL];
		}
	}
}
int main(){
#ifdef _DEBUG 
	freopen("data.txt","r",stdin);
#endif
	int n;
	int pre[50000],in[50000];
	scanf("%d",&n);
	for(int i = 0 ; i < n; i++){
		int t;
		scanf("%d",&t);	
		pre[i] = t;
	}
	for(int i = 0 ; i < n; i++){
		int t;
		scanf("%d",&t);	
		in[i] = t;
	}
	printf("%d\n",firstPostOrder(pre, in, 0, n, 0, n));

	return 0;
}