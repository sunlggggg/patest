/**
1021. Deepest Root (25)
时间限制
1500 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
A graph which is connected and acyclic can be considered a tree. The height of the tree depends on the selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called the deepest root.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the number of nodes, and hence the nodes are numbered from 1 to N. Then N-1 lines follow, each describes an edge by given the two adjacent nodes' numbers.

Output Specification:

For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their numbers. In case that the given graph is not a tree, print "Error: K components" where K is the number of connected components in the graph.

Sample Input 1:
5
1 2
1 3
1 4
2 5
Sample Output 1:
3
4
5
Sample Input 2:
5
1 3
1 4
2 5
3 4
Sample Output 2:
Error: 2 components
**/

#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 10000;
vector<int> map[N+1];
int _maxDepth[N] = {-1};
bool isFind[N];
int NodeNum;
int maxDepth = -1;
void dfs(int s, int depth  ){
	if(depth > maxDepth){
		maxDepth = depth;
	}
	isFind[s] = 1;
	for(int i = 0 ; i < map[s].size(); i++){
		if(isFind[map[s][i]] == false){
			dfs(map[s][i],depth+1);
		}
	}
}
bool cmp(int a, int b){
	return a>b;
}
bool isAllFind(){
	for(int i = 1; i <= NodeNum ; i++){
		if(isFind[i] == false){
			return false;
		}
	}
	return true;
}
int FirstNotFind(){
	for(int i = 1; i <= NodeNum ; i++){
		if(isFind[i] == false){
			return i;
		}
	}
	return -1;
}
int main(){
#ifdef _DEBUG
	char _case;
	scanf("%c",&_case);
	string _case_s = "data";
	_case_s.push_back(_case);
	_case_s.append(".txt");
	freopen(_case_s.c_str(),"r",stdin);
#endif
	scanf("%d",&NodeNum );
	memset(map,0,sizeof(map));//初始化
	int f, t;
	for(int i = 0 ; i < NodeNum -1; i ++){
		scanf("%d%d",&f,&t);
		map[f].push_back(t);
		map[t].push_back(f);
	}
	bool  flag = false;
	for(int i = 1 ; i <= NodeNum ; i++) {
		memset(isFind,0,sizeof(isFind));
		maxDepth = -1;
		dfs(i,1);
		if(i == 1 && !isAllFind()) { 
			flag = true;
			break;
		}
		_maxDepth[i] = maxDepth;
	}

	if(flag){
		memset(isFind,0,sizeof(isFind));
		int c = 0;
		while(isAllFind() == false){
			int fnf  = FirstNotFind();
			dfs(fnf,1);
			c++;
		}
		printf("Ereror: %d components",c);
	}else{
		int _max = -1;
		for(int i = 1 ; i <= NodeNum ; i++) {
			if(_maxDepth[i]>_max){
				_max = _maxDepth[i];
			}
		}
		int _count = 0 ;
		for(int i = 1 ; i <= NodeNum ; i++) {
			if(_maxDepth[i] == _max){
				printf("%d\n",i);
			}
		}
	}
	return 0;
}
