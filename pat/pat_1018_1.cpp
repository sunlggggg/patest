/**
1018. Public Bike Management (30)
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
There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world. One may rent a bike at any
station and return it to any other stations in the city.

The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations. A station is said to be in perfect condition 
if it is exactly half-full. If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that station to perfect. And 
more, all the stations on the way will be adjusted as well.

When a problem station is reported, PBMC will always choose the shortest path to reach that station. If there are more than one shortest path, the 
one that requires the least number of bikes sent from PBMC will be chosen.


Figure 1
Figure 1 illustrates an example. The stations are represented by vertices and the roads correspond to the edges. The number on an edge is the time 
taken to reach one end station from another. The number written inside a vertex S is the current number of bikes stored at S. Given that the maximum
capacity of each station is 10. To solve the problem at S3, we have 2 different shortest paths:

1. PBMC -> S1 -> S3. In this case, 4 bikes must be sent from PBMC, because we can collect 1 bike from S1 and then take 5 bikes to S3, so that both 
stations will be in perfect conditions.

2. PBMC -> S2 -> S3. This path requires the same time as path 1, but only 3 bikes sent from PBMC and hence is the one that will be chosen.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 numbers: Cmax (<= 100), always an even number, is the maximum 
capacity of each station; N (<= 500), the total number of stations; Sp, the index of the problem station (the stations are numbered from 1 to N, and
PBMC is represented by the vertex 0); and M, the number of roads. The second line contains N non-negative numbers Ci (i=1,...N) where each Ci is the
current number of bikes at Si respectively. Then M lines follow, each contains 3 numbers: Si, Sj, and Tij which describe the time Tij taken to move
betwen stations Si and Sj. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print your results in one line. First output the number of bikes that PBMC must send. Then after one space, output the path in 
the format: 0->S1->...->Sp. Finally after another space, output the number of bikes that we must take back to PBMC after the condition of Sp is 
adjusted to perfect.

Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC. The judge's data 
guarantee that such a path is unique.

Sample Input:
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
Sample Output:
3 0->2->3 0

**/

#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<stack>
#include<cmath>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
const int MaxN  = 510;
int Cmax,  staN ,  Sp , edgeN;
const int MAXDIS = 100000;
int StaNum[MaxN];
int Map[MaxN][MaxN];
int Dis[MaxN];
int IsFind[MaxN];
vector<int> pre[MaxN];//用来保存路径
void dijstra(int start ){
	Dis[start] = 0;
	while(true){
		int _min = MAXDIS;
		int _minInd = -1;
		for(int i = 0; i <= staN; i++){
			if(IsFind[i] == false && Dis[i] < _min ){
				_min = Dis[i];
				_minInd = i;
			}
		}
		if(_minInd == -1){
			break;
		}else{
			IsFind[_minInd] = true;
			for(int i = 0 ; i<= staN ; i++){
				if(IsFind[i] == false && Map[_minInd][i] != MAXDIS){
					if(Dis[_minInd] + Map[_minInd][i] < Dis[i]){
						Dis[i] = Dis[_minInd] + Map[_minInd][i];
						pre[i].clear();
						pre[i].push_back(_minInd);
					}else if(Dis[_minInd] + Map[_minInd][i] == Dis[i]){
						pre[i].push_back(_minInd);
					}
				}
			}
		}
	}
}
int minTake = 0 ;
//计算所有路径
vector<int> tmp;
vector<vector<int>> paths;
void getPath(int node){
	if(pre[node].size() == 0 ){
		tmp.push_back(node);
		paths.push_back(tmp);
		tmp.pop_back();
	}else{
		for(int i = 0 ; i < pre[node].size(); i++){
			tmp.push_back(node);
			getPath(pre[node][i]);
			tmp.pop_back();
		}
	}
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
	scanf("%d%d%d%d",&Cmax,&staN,&Sp,&edgeN);
	for(int i = 1; i<= staN ; i++){
		scanf("%d",&StaNum[i]);
	}
	fill(Map[0],Map[0] + MaxN*MaxN , MAXDIS);
	fill(Dis,Dis + MaxN , MAXDIS);
	for(int i = 0 ; i < edgeN; i++){
		int f, t , w;
		scanf("%d%d%d",&f,&t,&w);
		Map[f][t] = Map[t][f] = w;
	}
	dijstra(0); //计算出所有的最短路径
	getPath(Sp); //计算出所有的paht 3 1 0 3 2 0 
	int minget = MAXDIS;
	vector<int> ans;
	int minRemain = MAXDIS;
	for(int i = 0 ; i < paths.size();i++ ){ 
		int remain = 0 ;
		int get = 0 ;
		for(int k = paths[i].size() -2 ; k>= 0 ; k--){
			int nowNeed = Cmax/2 - StaNum[paths[i][k]] ;
			if(nowNeed >= 0){//少了
				if(nowNeed > remain){
					get+=nowNeed - remain;
					remain = 0;
				}else{
					remain-= nowNeed;
				}
			}else {//多了
				remain+= abs(nowNeed);
			}
		}
		if(get<minget){
			ans = paths[i];
			minget= get;
			minRemain = remain;
		}else if(get == minget){
			if(remain < minRemain){
				minRemain = remain;
				minget = get;
				ans = paths[i];
			}
		}
	}
	printf("%d ", minget);	
	for(int i = ans.size()-1 ; i>=0; i--){
		printf("%d", ans[i]);	
		if(i != 0){
			printf("->");
		}else{
			printf(" ");
		}
	}
	printf("%d\n", minRemain);	
	return 0;
}
