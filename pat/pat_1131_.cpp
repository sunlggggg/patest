#include<iostream>
#include<cstdint>
#include<limits>
#include<vector>
using namespace std;
const int maxn = 10010;
int ln;
int lineMap[maxn][maxn];//判断两个节点在哪条线上
vector<int> Map[10000];//邻接表
struct Route{
	Route(int _f,int _t,int _line){
		f = _f;
		t = _t;
		line = _line;
	}
	int f;
	int t;
	int line;
};
vector<Route> ans,tmp;
//dfs
int minDepth = 0x7fffffff;
int isFind[maxn];

void dfs(int f, int t ,int dep){
	if(f == t){//到达终点
		if(dep < minDepth){
			minDepth = dep;
			ans = tmp;
		}else if(dep == minDepth && tmp.size() < ans.size() ){
			ans = tmp;
		}
	}else{
		
		dep++;
		isFind[f] = 1;
		for(int i = 0 ; i < Map[f].size() ; i++){
			if(isFind[Map[f][i]] == false ){
				if(tmp.size() == 0 || tmp[tmp.size()- 1].line != lineMap[f][Map[f][i]] ){//开始时 或者 不在同一条线路上
					tmp.push_back(Route(f, Map[f][i],lineMap[f][Map[f][i]]));
					dfs(Map[f][i],t,dep);
					tmp.pop_back();
				} else {//在同一条线路上
					tmp[tmp.size() - 1].t = Map[f][i];//修改当前的终点
					dfs(Map[f][i],t,dep);
				}
			}
		}
		isFind[f] = 0 ;
	}
}

void findRouter(int f,int t){
	//dfs
	minDepth =  0x7fffffff;
	fill(isFind,isFind+maxn,0);
	tmp.clear();
	dfs(f,t,0);
	//print
	printf("%d\n",minDepth);
	for(int i = 0 ; i < ans.size() ; i++)
		printf("Take Line#%d from %04d to %04d.\n",ans[i].line,ans[i].f,ans[i].t);
}

int main(){
	cin>>ln;
	for(int  lineN = 1 ; lineN <= ln ; lineN ++ ){
		int stas;
		cin>>stas;
		int pre;
		cin >>pre;
		int cur;
		for(int i = 1 ; i < stas; i++){
			cin>>cur;
			lineMap[pre][cur] = lineMap[cur][pre] = lineN;
			Map[pre].push_back(cur);
			Map[cur].push_back(pre);
			pre = cur;
		}
	}
	int tc;
	cin>>tc;
	while(tc--){
		int f, t;
		cin>>f>>t;
		findRouter(f,t);
	}
	return 0;
}