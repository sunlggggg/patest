#include<iostream>
#include<vector>
#include<set>
using namespace std;
const int N = 100010;
int father[N];//树的father
int birds[N];//鸟所在的树
int isRoot[N];//计算树的个数
set<int> _set;//计算鸟的个数
int n ;
void init(){
	for(int i = 1 ; i<=n;i++){
		father[i] = i ; 
	}
}
int getFather(int x){
	int a = x; 
	while(father[x]!= x){
		x = father[x];
	}
	//路径压缩
	while(a != father[a]){
		father[a] = x;
		a = father[a];
	}
	return x;
}
int main(){
#ifdef _DEBUG
	freopen("data.txt","r",stdin);
#endif
	cin>>n;
	init();
	int num;
	for(int i= 1 ; i <= n ; i++){
		cin>>num;
		int birdId;
		while(num--){
			cin>>birdId;
			_set.insert(birdId);
			if(birds[birdId] == false){  //暂时该树独有
				birds[birdId] = i;//属于该树
			}else{//
				int faA = getFather(birds[birdId]);//查
				int faB = getFather(i);
				if(faA != faB) {
					father[faA] = faB;//并
				}
			}
		}
	}
	//计算
	for(int i = 1 ; i <= n; i++){
		isRoot[getFather(i)]++;
	}
	int ans1 = 0 ; 
	for(int i =1 ; i <= n; i++){
		if(isRoot[i]>0){
			ans1++;
		}
	}
	cout<<ans1<<" "<<_set.size() <<endl;
	int t;
	cin>>t;
	while(t--){
		int a;
		int b;
		cin>>a>>b;
		if(getFather(birds[a]) == getFather(birds[b])){
			cout<<"Yes"<<endl;
		}else {
			cout<<"No" <<endl;
		}
	}
	return 0;
}