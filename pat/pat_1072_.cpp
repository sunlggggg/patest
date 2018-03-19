/**
1072. Gas Station (30)
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
A gas station has to be built at such a location that the minimum distance between the station and any of the residential housing is as far away as possible. However it must guarantee that all the houses are in its service range.

Now given the map of the city and several candidate locations for the gas station, you are supposed to give the best recommendation. If there are more than one solution, output the one with the smallest average distance to all the houses. If such a solution is still not unique, output the one with the smallest index number.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive integers: N (<= 103), the total number of houses; M (<= 10), the total number of the candidate locations for the gas stations; K (<= 104), the number of roads connecting the houses and the gas stations; and DS, the maximum service range of the gas station. It is hence assumed that all the houses are numbered from 1 to N, and all the candidate locations are numbered from G1 to GM.

Then K lines follow, each describes a road in the format
P1 P2 Dist
where P1 and P2 are the two ends of a road which can be either house numbers or gas station numbers, and Dist is the integer length of the road.

Output Specification:

For each test case, print in the first line the index number of the best location. In the next line, print the minimum and the average distances between the solution and all the houses. The numbers in a line must be separated by a space and be accurate up to 1 decimal place. If the solution does not exist, simply output “No Solution”.

Sample Input 1:
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2
Sample Output 1:
G1
2.0 3.3
Sample Input 2:
2 1 2 10
1 G1 9
2 G1 20
Sample Output 2:
No Solution
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