/**
1004. Counting Leaves (30)
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
A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
Input

Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:

ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.
Output

For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.

Sample Input
2 1
01 1 02
Sample Output
0 1
**/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n;//节点个数
int m ;//非叶子节点数目
const int maxn = 110;
vector<int> childs[maxn];//从01开始
int levelLeafNum[maxn] = {0};//每一层叶子数目 
int maxL = 0;
void dfs(int root, int depth){
	if(depth > maxL){
		maxL = depth;
	}
	if(childs[root].size() == 0 ){
		levelLeafNum[depth]++;
	}else{
		for(int i=  0 ; i < childs[root].size(); i++){
			dfs(childs[root][i],depth+1);
		}
	}
}
int main() {
#ifdef _DEBUG
	freopen("data.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	int Id,cn;
	int chi;
	for(int i = 0 ; i < m ; i++){//建立树
		scanf("%d%d",&Id, &cn);
		for(int k = 0 ; k < cn ; k ++){
			scanf("%d",&chi);
			childs[Id].push_back(chi);
		}
	}
	dfs(1,0);
	for(int i = 0 ; i <= maxL ;i++){
		printf("%d",levelLeafNum[i]);
		if(i!=maxL) printf(" ");
		else printf("\n");
	}
	return 0;
}