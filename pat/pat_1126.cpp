#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int maxn = 510 ;
int n , m ;
int d[maxn];
int Map[maxn][maxn];
//判断是否有欧拉路径
bool isFind[maxn];

void dfs(int s){
	isFind[s] = true;
	for(int i = 1; i <= n ; i++){
		if(isFind[i] == false && Map[s][i] == 1){
			dfs(i);
		}
	}
}
void judge(){
	int even = 0 ; 
	int odd = 0 ;
	int s,e;
	for(int i = 1; i<= n ; i++){
		if(d[i]%2 != 0 ){
			if(odd == 0){
				s = i;
			}else if(odd == 1){
				e = i;
			}
			odd++;
		}else{
			even++;
		}
	}
	dfs(1);
	bool f = true;
	for(int i = 1; i<=n; i++) {
		if(isFind[i] == false){
			f = false;
			break;
		}
	}
	if(f == false){
		cout<<"Non-Eulerian"<<endl;
	}else{
	if(even == n || n == 1){
		cout<<"Eulerian"<<endl;
	}
	else if(odd == 2){
		cout<<"Semi-Eulerian"<<endl;
	}else{
		cout<<"Non-Eulerian"<<endl;
	}
	}
}
int main(){
	cin>>n>>m;
	int f,t;
	for(int i = 1; i <= m ; i++){
		cin>>f>>t;
		d[f]++;
		d[t]++;
		Map[f][t] = Map[t][f] = 1;
	}
	for(int i = 1; i <= n ; i++){
		cout<<d[i];
		if(i!=n){
			cout<<" ";
		}else{
			cout<<endl;
		}
	}
	judge();
	return 0;
}