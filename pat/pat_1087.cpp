#include<iostream>
#include<cstring>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 210;
const int INF = 100000;
int n,m;
map<string,int> nametoid;
map<int,string> idtoname;
int Map[N][N];
int vl[N];
int cost[N]; 
int hp[N];
int isv[N];
vector<int> pre[N];
void dij(int start){
	cost[start] = 0 ; 
	while(true){
		int minc = INF;
		int mincx = -1;
		for(int i = 0; i< n; i++){
			if(isv[i] == false && cost[i] < minc){
				minc = cost[i];
				mincx = i;
			}
		}
		if(mincx == -1){
			break;
		}else{
			isv[mincx] = true;
			for(int i = 0 ; i < n;i++){
				if(isv[i] == false && Map[mincx][i] != INF){
					if(Map[mincx][i] + cost[mincx] < cost[i]){
						cost[i] = Map[mincx][i] + cost[mincx];
						pre[i].clear();
						pre[i].push_back(mincx);
					}else if(Map[mincx][i] + cost[mincx] == cost[i]){
						//if( hp[mincx] + vl[i]  < hp[i]){
						//	hp[i] = hp[mincx] + vl[i];
						//	pre[i].clear();
						//	pre[i].push_back(mincx);
						//}else{//cost 相同 hp 相同
						pre[i].push_back(mincx);
						//}
					}
				}
			}
		}
	}
}
//cost 相同
bool cmp(vector<int> a, vector<int> b){
	int hpa_a = 0 ;
	int hpa_b = 0 ; 
	for(int i = 0 ; i < a.size();i++){
		hpa_a += vl[a[i]];
	}
	for(int i = 0 ; i < b.size();i++){
		hpa_b += vl[b[i]];
	}
	if(hpa_a != hpa_b ){
		return hpa_a> hpa_b ;
	}else{
		return a.size() < b.size();
	}
}
vector<vector<int>> routers;
vector<int>tmp;
void dfs(int s,int e){
	if(s == e){
		tmp.insert(tmp.begin(),s);
		routers.push_back(tmp);
		tmp.erase(tmp.begin());
	}else{
		for(int i = 0 ;i<pre[s].size() ; i++){
			tmp.insert(tmp.begin(),s);
			dfs(pre[s][i],e);
			tmp.erase(tmp.begin());
		}
	}
}
int main() {
#ifdef _DEBUG
	freopen("data.txt","r",stdin);
#endif
	fill(cost,cost+N,INF);
	fill(Map[0],Map[0] + N *N,INF);
	cin>>n>>m;
	string srt;
	cin>>srt;
	nametoid.insert(make_pair(srt,0));
	idtoname.insert(make_pair(0,srt));
	for(int i = 1 ; i < n ; i++){
		string ci;
		int hp;
		cin>>ci>>hp;
		nametoid.insert(make_pair(ci,i));
		idtoname.insert(make_pair(i,ci));
		vl[i] = hp;
	}

	for(int i = 0 ; i < m ; i++){
		string f,t;
		cin>>f>>t;
		int _f = nametoid.find(f)->second;
		int _t = nametoid.find(t)->second;
		int cost;
		cin>>cost;
		Map[_f][_t] = Map[_t][_f] = cost;
	}
	int _st = nametoid.find(srt)->second;
	dij(_st);

	int _et = nametoid.find("ROM")->second;

	dfs(_et,_st);
	sort(routers.begin(),routers.end(),cmp);

	vector<int> ans = routers[0];

	// least cost, the cost, the happiness, and the average happiness (take the integer part only) of the recommended route.
	int lc = cost[_et];
	int lcn = routers.size();
	int ahp = 0;

	for(int i = 0 ; i < ans.size(); i++){
		ahp += vl[ans[i]];
	}

	int av = ahp/(ans.size()-1);
	cout<<lcn << " " << lc <<" "  << ahp <<" " << av <<endl;
	for(int i = 0 ; i < ans.size();i++){
		cout<<idtoname[ans[i]];
		if(i != ans.size() - 1){
			cout<<"->";
		}else{
			cout<<endl;
		}
	}
	return 0;
}

/**
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1
**/