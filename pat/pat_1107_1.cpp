/**
1107. Social Clusters (30)
时间限制
1000 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
When register on a social network, you are always asked to specify your hobbies in order to find some potential friends with the same hobbies. A "social cluster" is a set of people who have some of their hobbies in common. You are supposed to find all the clusters.

Input Specification:

Each input file contains one test case. For each test case, the first line contains a positive integer N (<=1000), the total number of people in a social network. Hence the people are numbered from 1 to N. Then N lines follow, each gives the hobby list of a person in the format:

Ki: hi[1] hi[2] ... hi[Ki]

where Ki (>0) is the number of hobbies, and hi[j] is the index of the j-th hobby, which is an integer in [1, 1000].

Output Specification:

For each case, print in one line the total number of clusters in the network. Then in the second line, print the numbers of people in the clusters in non-increasing order. The numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
Sample Output:
3
4 3 1
**/

#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 2020;
int  n ; 
int father[maxn] = {0};
int isRoot[maxn]= {0};
int course[maxn]={0};
int findFather(int x){
	int a = x;
	while(x!=father[x]){
		x = father[x];//向上寻找
	}
	//知道x是指向自己的根
	while(a!=father[a]){//路径压缩
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void init(int n ){
	for(int i = 1; i <= n ; i++){
		father[i] = i ;
		isRoot[i] = false;
	}
}
void Union(int a, int b){//合并a b 所在的集合
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB){
		father[faA] = faB;//将A添加到B
	}
}
bool cmp(int a,int b){
	return a>b;
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
	init(n);//初始化
	int hb;
	int h ;
	for(int i = 1; i <= n ; i++){
		scanf("%d:",&hb);//活动个数
		for(int k = 0 ; k< hb ; k++){
			scanf("%d",&h);
			if(course[h] == 0 ){
				course[h] = i ;//记录当前的人为结合的根
			}
			Union(i,findFather(course[h]));
		}
	}

	for(int i = 1; i<= n ; i++){
		isRoot[findFather(i)]++;
	}
	int ans = 0 ;
	for(int i = 1; i <= n ;i++){
		if(isRoot[i]!=0){
			ans++;
		}
	}
	printf("%d\n",ans);
	sort(isRoot+1,isRoot+n+1,cmp);
	for(int i = 1 ; i <= ans ; i++){
		printf("%d", isRoot[i]);
		if(i < ans)
			printf(" ");
	}
	return 0;
}