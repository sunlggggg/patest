/**
1133. Splitting A Linked List (25)
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
Given a singly linked list, you are supposed to rearrange its elements so that all the negative values appear before all of the non-negatives, and all the values in [0, K] appear before all those greater than K. The order of the elements inside each class must not be changed. For example, given the list being 18→7→-4→0→5→-6→10→11→-2 and K being 10, you must output -4→-6→-2→7→0→5→10→18→11.

Input Specification:

Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (<= 105) which is the total number of nodes, and a positive K (<=1000). The address of a node is a 5-digit nonnegative integer, and NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Data Next

where Address is the position of the node, Data is an integer in [-105, 105], and Next is the position of the next node. It is guaranteed that the list is not empty.

Output Specification:

For each case, output in order (from beginning to the end of the list) the resulting linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 9 10
23333 10 27777
00000 0 99999
00100 18 12309
68237 -6 23333
33218 -4 00000
48652 -2 -1
99999 5 68237
27777 11 48652
12309 7 33218
Sample Output:
33218 -4 68237
68237 -6 48652
48652 -2 12309
12309 7 00000
00000 0 99999
99999 5 23333
23333 10 00100
00100 18 27777
27777 11 -1
**/

#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<map>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;
const int maxn = 100010;
int s,n,k;
struct Node{
	int add;
	int data;
	int next;
};
Node nodes[maxn];
vector<Node> v1,v2,v3;
int main(){
#ifdef _DEBUG
	char _case;
	scanf("%c",&_case);
	string _case_s = "data";
	_case_s.push_back(_case);
	_case_s.append(".txt");
	freopen(_case_s.c_str(),"r",stdin);
#endif
	scanf("%d%d%d",&s,&n,&k);
	int start,data,next;
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d%d",&start,&data,&next);
		nodes[start].add = start;
		nodes[start].data = data;
		nodes[start].next = next;
	}
	while(s!=-1){
		if(nodes[s].data < 0 ){
			v1.push_back(nodes[s]);
		}else if(nodes[s].data>=0 && nodes[s].data <= k ){
			v2.push_back(nodes[s]);
		}else{
			v3.push_back(nodes[s]);
		}
		s = nodes[s].next;
	}
	v1.insert(v1.end(),v2.begin(),v2.end());
	v1.insert(v1.end(),v3.begin(),v3.end());
	for(int i = 0 ; i < v1.size() -1 ; i++){
		printf("%05d %d %05d\n", v1[i].add,v1[i].data,v1[i+1].add);
	}
	printf("%05d %d -1\n", v1[v1.size()-1].add,v1[v1.size() -1].data);
	return 0;
}
