/**
1074. Reversing Linked List (25)
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
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 1→2→3→4→5→6, if K = 3, then you must output 3→2→1→6→5→4; if K = 4, you must output 4→3→2→1→5→6.

Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (<= 10^5) which is the total number of nodes, and a positive K (<=N) which is the length of the sublist to be reversed. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next

where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:

For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218
Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
**/
//有无效节点
//计算有效长度
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100010;
struct A{
	A(){
		order = maxn;
	}
	int add;
	int data;
	int next;
	int order;
};
A list[maxn];
bool cmp( A a,  A b){
	return a.order < b.order;
}
int main(){
#ifdef _DEBUG
	freopen("data.txt","r",stdin);
#endif
	int sadd, len, k;
	scanf("%d%d%d",&sadd,&len,&k);
	int add;
	for(int i = 0 ; i < len; i++){
		scanf("%d",&add);
		scanf("%d%d",&list[add].data,&list[add].next);
		list[add].add = add;
	}
	int usefulLen = 0 ;
	int next = sadd;// 1 2 3 ... k 
	while(next!=-1) { //计算有效长度
		usefulLen++;
		next = list[list[next].add].next;
	}
	len = usefulLen;

	//找到开始
	next = sadd;// 1 2 3 ... k 
	int c = len/k;//反转的次数
	int order = 0 ;
	while(next!=-1) {
		if(order >= c*k){
			list[list[next].add].order = order;
		}
		else {
			list[list[next].add].order = (order/k)*k + (k-1 - order%k) ;//12345 3 2 1
		}
		order++;
		next = list[list[next].add].next;
	}

	sort(list,list + maxn,cmp);
	for(int i = 0; i < order; i++){
		printf("%05d %d ",list[i].add,list[i].data);
		if(i != order -1){
			printf("%05d\n",list[i+1].add);
		}else{
			printf("-1\n");
		}
	}
	return 0;
}