#include<iostream>
#include<set>
#include<vector>
using namespace std;
/**
6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
6
7 5 1 4 3 6 2 5
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 3 4 5 2 6
7 6 1 2 5 4 3 1
**/
int n;
int Map[300][300];
bool isRouter(vector<int> v, int f ){
	if(f != v.size() ){
		if(Map[v[f-1]][v[f]] == 0 ){
			return false;
		}else{
			return isRouter(v,f+1);
		}
	}else{
		return true;
	}
}
int main(){

	int m;
	cin>>n>>m;
	int f,t;
	while(m--){
		cin>>f>>t;
		Map[f][t] = Map[t][f] = 1;
	}
	int ts;
	cin>>ts;
	while(ts--){
		int l;
		set<int> _set;
		vector<int> v;
		cin>>l;
		while(l--){
			int node;
			cin>>node;
			_set.insert(node);
			v.push_back(node);
		}
		if(v.size() > n +1 || _set.size() < n || v[0] != v[v.size()-1] ){
			cout<<"NO"<<endl;
		}else{
			cout<<(isRouter(v,1)?"YES":"NO")<<endl;
		}
	}
	return 0;
}