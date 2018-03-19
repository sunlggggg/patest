/**
1053. Path of Equal Weight (30)
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
Given a non-empty tree with root R, and with weight Wi assigned to each tree node Ti. The weight of a path from R to L is defined to be the sum of the weights of all the nodes along the path from R to any leaf node L.

Now given any weighted tree, you are supposed to find all the paths with their weights equal to a given number. For example, let's consider the tree showed in Figure 1: for each node, the upper number is the node ID which is a two-digit number, and the lower number is the weight of that node. Suppose that the given number is 24, then there exists 4 different paths which have the same given weight: {10 5 2 7}, {10 4 10}, {10 3 3 6 2} and {10 3 3 6 2}, which correspond to the red edges in Figure 1.


Figure 1
Input Specification:

Each input file contains one test case. Each case starts with a line containing 0 < N <= 100, the number of nodes in a tree, M (< N), the number of non-leaf nodes, and 0 < S < 230, the given weight number. The next line contains N positive numbers where Wi (<1000) corresponds to the tree node Ti. Then M lines follow, each in the format:

ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 00.

Output Specification:

For each test case, print all the paths with weight S in non-increasing order. Each path occupies a line with printed weights from the root to the leaf in order. All the numbers must be separated by a space with no extra space at the end of the line.

Note: sequence {A1, A2, ..., An} is said to be greater than sequence {B1, B2, ..., Bm} if there exists 1 <= k < min{n, m} such that Ai = Bi for i=1, ... k, and Ak+1 > Bk+1.

Sample Input:
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
Sample Output:
10 5 2 7
10 4 10
10 3 3 6 2
10 3 3 6 2
**/
#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;
int n;//节点个数
int m ;//非叶子节点数目
int w;//总权重
const int maxn = 110;
struct Node{
	int wei;
	vector<int> childs;
};
Node tree[maxn];
int levelLeafNum[maxn] = {0};//每一层叶子数目 
int maxL = 0;
vector<vector<int>> ans;
int staW(vector<int> sta){
	int w = 0 ;
	for(int i = 0 ; i< sta.size() ; i++){
		w+=tree[sta[i]].wei;
	}
	return w;
}
bool cmp(vector<int> a, vector<int> b){
	int minL = min(a.size(),b.size());
	for(int i =0 ; i< minL; i++){
		if(a[i]!= b[i]){
			return a[i] > b[i];
		}
	}
	return false;
}

bool cmp2(int a, int b){
	return tree[a].wei>tree[b].wei;
}
//递归法 主要是保存路径
void dfs(int root,int _w,vector<int> router){
	if(_w+tree[root].wei == w && tree[root].childs.size() == 0 ) {
		router.push_back(tree[root].wei);
		ans.push_back(router);
	}else {
		router.push_back(tree[root].wei);
		for(int i = 0 ; i< tree[root].childs.size(); i++){
			dfs(tree[root].childs[i],_w+tree[root].wei,router);
		}
	}
}
int path[maxn];
void dfs(int root,int _w, int pathNum){
	if(_w+tree[root].wei == w && tree[root].childs.size() == 0 ) {//叶子
		for(int i = 0 ; i < pathNum ; i++){
			printf("%d ", tree[path[i]].wei);
		}
		printf("%d\n",tree[root].wei);
		return ;
	}else {
		for(int i = 0 ; i< tree[root].childs.size(); i++){
			path[pathNum] = root;
			dfs(tree[root].childs[i],_w+tree[root].wei, pathNum+1);
		}
	}
}
int main() {
#ifdef _DEBUG
	freopen("data.txt","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&w);
	int Id,cn;
	int chi;
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&tree[i].wei);
	}
	for(int i = 0 ; i < m ; i++) { //建立树
		
		scanf("%d%d",&Id, &cn);
		for(int k = 0 ; k < cn ; k ++){
			scanf("%d",&chi);
			tree[Id].childs.push_back(chi);
		}
		sort(tree[Id].childs.begin(),tree[Id].childs.end(),cmp2); //另一种写法
	}
	vector<int> router;
	//dfs(0,0,router);   我的写法比较耗费内存
	dfs(0,0,0);
	//for(int i = 0 ; i < ans.size() ;i++){
	//	for(int k = 0 ; k < ans[i].size(); k++){
	//		printf("%d", ans[i][k]);
	//		if(k!=ans[i].size()-1){
	//			printf(" ");
	//		}else {
	//			printf("\n");
	//		}
	//	}
	//}
	return 0;
}

