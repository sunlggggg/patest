/**
1094. The Largest Generation (25)
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
A family hierarchy is usually presented by a pedigree tree where all the nodes on the same level belong to the same generation. Your task is to find the generation with the largest population.

Input Specification:

Each input file contains one test case. Each case starts with two positive integers N (<100) which is the total number of family members in the tree (and hence assume that all the members are numbered from 01 to N), and M (<N) which is the number of family members who have children. Then M lines follow, each contains the information of a family member in the following format:

ID K ID[1] ID[2] ... ID[K]

where ID is a two-digit number representing a family member, K (>0) is the number of his/her children, followed by a sequence of two-digit ID's of his/her children. For the sake of simplicity, let us fix the root ID to be 01. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the largest population number and the level of the corresponding generation. It is assumed that such a generation is unique, and the root level is defined to be 1.

Sample Input:
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18
Sample Output:
9 4
**/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n;//节点个数
int m ;//非叶子节点数目
const int maxn = 110;
vector<int> childs[maxn];//从0开始
int levelNum[maxn] = {0};
void dfs(int root , int depth){
	levelNum[depth]+=1;
	if(childs[root].size()>0){
		for(int i = 0 ; i < childs[root].size();i++){
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
  int maxL= 0;
  int max = 0 ;
  for(int i = 0 ; i <= n ;i++){
	  if(levelNum[i]>max){
		  max = levelNum[i];
		  maxL = i ;
	  }
  }
  printf("%d %d\n",max,maxL+1);
  return 0;
}