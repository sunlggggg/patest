/**
1097. Deduplication on a Linked List (25)
时间限制
300 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Given a singly linked list L with integer keys, you are supposed to remove the nodes with duplicated absolute values of the keys. That is, for each value K, only the first node of which the value or absolute value of its key equals K will be kept. At the mean time, all the removed nodes must be kept in a separate list. For example, given L being 21→-15→-15→-7→15, you must output 21→-15→-7, and the removed list -15→15.

Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, and a positive N (<= 10^5) which is the total number of nodes. The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Key Next

where Address is the position of the node, Key is an integer of which absolute value is no more than 10^4, and Next is the position of the next node.

Output Specification:

For each case, output the resulting linked list first, then the removed list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854
Sample Output:
00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1
**/

#include<iostream>
using namespace std;
const  int maxn = 100010;
const int table = 100010;
bool isExisted[table]  = {false};
struct A{
	int add;
	int data;
	int next;
};

A list[maxn];
int main(){
#ifdef _DEBUG
	freopen("data.txt","r",stdin);
#endif

	int s;
	int n;
	scanf("%d%d",&s,&n);
	int add;
	for(int i = 0 ; i < n ; i++){
		scanf("%d ",&add);
		scanf("%d %d",&list[add].data,&list[add].next);
		list[add].add =add;
	}
	int delStart = -1;
	int delNow = -1;
	int pre = s;
	isExisted[abs(list[pre].data)] = true;
	int now = list[pre].next;
	while(now!=-1) {
		if(isExisted[abs(list[now].data)] == false) { //当前节点 未出现过
			isExisted[abs(list[now].data)] = true;
			list[pre].next = list[now].add;
			pre = list[now].add;
			now = list[now].next;
		}else{//删除
			if(delStart == -1){
				delStart = list[now].add;//当前地址
				delNow = list[now].add;
			}else {
				list[delNow].next = list[now].add;
				delNow = list[now].add;
			}
			now = list[now].next;//先到下一节点
			list[delNow].next = -1;
		}
		
	}
	list[pre].next = -1;//一旦最后一个节点需要删去，处理最后一个节点

	now = s;
	while(now!=-1) {
		if(list[now].next != -1){
			printf("%05d %d %05d\n",list[now].add,list[now].data,list[now].next);
		}
		else {
			printf("%05d %d -1\n",list[now].add,list[now].data);
			break;
		}
		now = list[now].next;
	}
	now = delStart;
	while(now!=-1) {
		if(list[now].next != -1){
			printf("%05d %d %05d\n",list[now].add,list[now].data,list[now].next);
		}
		else {
			printf("%05d %d -1\n",list[now].add,list[now].data);
			break;
		}
		now = list[now].next;
	}
	return 0;
}