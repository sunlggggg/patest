#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 550;
const int INF =  10000;
int n,m;
struct Info{
	Info(){
		len = ti = INF;
	}
	int len;
	int ti;
};

Info Map[N][N];
int dis[N];
int isV[N];
int pre1Len[N];
int pre1Time[N];
int _time[N];
vector<int> pre2Time[N];
bool cmp(vector<int > a, vector<int> b){
	return a.size() < b.size();
}

void dij(int s){
	dis[s] = 0 ;
	while(true){
		int mind = INF;
		int mindInx = -1 ;
		for(int i = 0 ; i < n ; i++){
			if(dis[i]< mind && isV[i] == false){
				mind= dis[i];
				mindInx = i;
			}
		}
		if(mindInx == -1){
			return ;
		}else{
			isV[mindInx] = true;
			for(int i = 0 ; i < n ; i++){
				if(isV[i] == false && Map[mindInx][i].len != INF) {//可达且未加入
					if(Map[mindInx][i].len + dis[mindInx] < dis[i]){
						dis[i] = (Map[mindInx][i].len + dis[mindInx]);
						pre1Len[i] = mindInx;//前驱
						pre1Time[i] = pre1Time[mindInx] + Map[mindInx][i].ti;
					}else if(Map[mindInx][i].len + dis[mindInx] == dis[i]){
						if(pre1Time[mindInx] + Map[mindInx][i].ti < pre1Time[i]  ){
							pre1Time[i] = pre1Time[mindInx] + Map[mindInx][i].ti;
							pre1Len[i] = mindInx;
						}
					}
				}
			}
		}
	}
}
void dij2(int s){
	_time[s] = 0 ;
	while(true){
		int mind = INF;
		int mindInx = -1 ;
		for(int i = 0 ; i < n ; i++){
			if(_time[i]< mind && isV[i] == false){
				mind= dis[i];
				mindInx = i;
			}
		}
		if(mindInx == -1){
			return ;
		}else{
			isV[mindInx] = true;
			for(int i = 0 ; i < n ; i++){
				if(isV[i] == false && Map[mindInx][i].ti != INF) {//可达且未加入
					if(Map[mindInx][i].ti + _time[mindInx] < _time[i]){
						_time[i] = (Map[mindInx][i].ti + _time[mindInx]);
						pre2Time[i].clear();
						pre2Time[i].push_back(mindInx);
					}else if(Map[mindInx][i].ti + _time[mindInx] == _time[i]){
						pre2Time[i].push_back(mindInx);
					}
				}
			}
		}
	}
}
//dfs
vector<vector<int>> routers;
vector<int> tmp;
void allrouter(int e,int s){
	tmp.insert(tmp.begin(),e);
	if(e == s){
		routers.push_back(tmp);
	}else{
		for(int i = 0 ; i < pre2Time[e].size();i++){
			allrouter(pre2Time[e][i],s);
		}
	}
}
bool same(vector<int> a,vector<int> b){
	if(a.size() != b.size() ){
		return false;
	}else{
		for(int i = 0 ; i < a.size() ; i++){
			if(a[i] != b[i]){
				return false;
			}
		}
	}
	return true;
}
int main(){
	fill(dis,dis+N,INF);
	fill(_time,_time+N,INF);
	cin>>n>>m;
	for(int i = 0 ; i<m;i++){
		int v1,v2,ok,len,ti;
		cin>>v1>>v2>>ok>>len>>ti;
		Info info;
		info.len = len;
		info.ti = ti;
		if(ok == 1){
			Map[v1][v2] =  info;
		}else{
			Map[v1][v2] =  info;
			Map[v2][v1] =  info;
		}
	}
	int s,e;
	cin>>s>>e;
	dij(s);
	vector<int> ans1,ans2;
	int tmpe = e;
	do{
		ans1.insert(ans1.begin(),tmpe);
		tmpe = pre1Len[tmpe];
	} while(tmpe != s );
	ans1.insert(ans1.begin(),tmpe);


	//
	fill(isV,isV+N,0);
	dij2(s);

	allrouter(e,s);

	sort(routers.begin(),routers.end(),cmp);
	ans2 = routers[0];
	if(!same(ans1,ans2)){
		printf("Distance = %d: ",dis[e]);
		for(int i = 0 ; i < ans1.size();i++){
			printf("%d",ans1[i]);
			if(i!=ans1.size()-1){
				printf(" -> ");
			}else{
				printf("\n");
			}
		}
		printf("Time = %d: ",_time[e]);
		for(int i = 0 ; i < ans2.size();i++){
			printf("%d",ans2[i]);
			if(i!=ans2.size()-1){
				printf(" -> ");
			}else{
				printf("\n");
			}
		}
	}else{
		printf("Distance = %d; Time = %d: ",dis[e],_time[e]);
		for(int i = 0 ; i < ans2.size();i++){
			printf("%d",ans2[i]);
			if(i!=ans2.size()-1){
				printf(" -> ");
			}else{
				printf("\n");
			}
		}
	}
	
	return 0;
}

/**
10 15
0 1 0 1 1
8 0 0 1 1
4 8 1 1 1
3 4 0 3 2
3 9 1 4 1
0 6 0 1 1
7 5 1 2 1
8 5 1 2 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
1 4 0 1 1
9 7 1 3 1
5 1 0 5 2
6 5 1 1 2
3 5
**/