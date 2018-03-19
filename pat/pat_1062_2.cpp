#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct A{
	char n[10];
	int T,V;
	int G;  //1(a.T >= H && a.V>=H ) 2 (a.T < H && a.V>=H ) 3 (a.T < H &&a.V<H && a.V>=a.T ) 4  small man 5 no ranked
};
bool cmpTotal(const A &a , const A &b){
	if(a.G != b.G)
		return a.G < b.G;
	else if(a.T+a.V != b.T+b.V)
		return a.T+a.V > b.T+b.V;
	else if(a.V != b.V)
		return a.V > b.V;
	else return strcmp(a.n,b.n) < 0;
}
int main(){
	//ios::sync_with_stdio(false);
	int n,L,H;
	vector<A> v;
	scanf("%d%d%d",&n,&L,&H);
	//cin >> n>> L>> H;
	while(n--){
		A a; 
		scanf("%s%d%d",&a.n,&a.V,&a.T);
		//cin >>a.n >> a.V >> a.T ;
		if(a.T < L || a.V <L ) a.G = 5;
		else if(a.T >= H && a.V>=H ) a.G = 1;
		else if(a.T < H && a.V >=H ) a.G = 2;
		else if(a.V >=a.T ) a.G = 3;
		else  a.G = 4 ;
		if(a.G < 5) v.push_back(a);
	}
	sort(v.begin(),v.end(), cmpTotal); 
	cout<<v.size()<<endl;
	for(int i = 0 ; i< v.size();i++){
		printf("%s %d %d\n",v[i].n ,v[i].V, v[i].T);
		//cout<<v[i].n << " "<<v[i].V <<" "<<v[i].T <<endl;
	}
	return 0;
}
