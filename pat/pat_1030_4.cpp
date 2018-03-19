/**
1030. Travel Plan (30)
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
A traveler's map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.

Input Specification:

Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); M is the number of highways; S and D are the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:

City1 City2 Distance Cost

where the numbers are all integers no more than 500, and are separated by a space.

Output Specification:

For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.

Sample Input
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output
0 2 3 3 40
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
int M,  N ,  S , D;
const int INF = 100000;
struct Node{
	int wei;
	int cost;
};
Node Map[MaxN][MaxN];
int Dis[MaxN];
int Find[MaxN];
int Cost[MaxN];
int pre[MaxN];
void dijstra(int start ){
	Dis[start] = 0 ;
	Cost[start] = 0 ;
	while(true){
		int _min = INF;
		int _min_index = -1;
		for(int i = 0 ; i < N ; i++ ){
			if(Find[i] == false && Dis[i] < _min){
				_min = Dis[i];
				_min_index = i;
			}
		}
		if(_min_index == -1) return ;
		else{
			Find[_min_index] = true;
			for(int i = 0 ; i<N; i++){
				if(Find[i] == false && Map[_min_index][i].wei != INF){
					if(Dis[_min_index] + Map[_min_index][i].wei < Dis[i]){
						Dis[i] = Dis[_min_index] + Map[_min_index][i].wei;
						Cost[i] = Cost[_min_index] + Map[_min_index][i].cost;
						pre[i] = _min_index;
					}else if(Dis[_min_index] + Map[_min_index][i].wei == Dis[i]){
						if(Cost[_min_index] + Map[_min_index][i].cost < Cost[i]){
							Cost[i] = Cost[_min_index] + Map[_min_index][i].cost;
							pre[i] = _min_index;
						}
					}
				}
			}
		}
	}
}
void init(){
	for(int i = 0; i < N; i++){
		for(int k = 0 ; k < N ;k++){
			Map[i][k].wei = INF;
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
	scanf("%d%d%d%d",&N,&M,&S,&D);
	int f,t,w,c;
	init();
	fill(Dis,Dis + MaxN , INF);
	fill(pre,pre + MaxN , -1);
	for(int i = 1; i<= M; i++){
		scanf("%d%d%d%d",&f,&t,&w,&c);
		Map[f][t].wei = w;
		Map[f][t].cost= c;
		Map[t][f].wei = w;
		Map[t][f].cost= c;
	}
	dijstra(S);
	vector<int> v;
	int node = D;
	do{
		v.insert(v.begin(),node);
	}while((node = pre[node])!=-1);
	for(int i = 0 ; i< v.size(); i++){
		printf("%d ", v[i]);
	}
	printf("%d ", Dis[D]);
	printf("%d\n", Cost[D]);
	return 0;
}