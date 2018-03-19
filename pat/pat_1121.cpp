#include<iostream>
#include<vector>
#include<set>
using namespace std;
/**
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
Sample Output:
5
10000 23333 44444 55555 88888
**/
int CA[100000];//Í¨¹ýBÕÒA
int CB[100000];//AÕÒB
bool isSignal[100000];
int main(){
	int n ;
	cin>>n;
	int a,b;
	for(int i = 0 ; i< n ; i++){
		cin>>a>>b;
		CA[b] = a; 
		CB[a] = b; 
		isSignal[a] = isSignal[b] = 1;
	}
	int m;
	int ts;
	set<int> _set,ans;
	set<int>::iterator it;
	cin>>m;
	while(m--){
		cin>>ts;
		ans.insert(ts);
		_set.insert(ts);
	}
	it = _set.begin();
	while(it!=_set.end() ){
		int now = *it;
		int copB = CA[now];
		int copA = CB[now];
		if(_set.count(copB) == 1 && isSignal[now] == 1 && isSignal[copB] == 1 ){
			ans.erase(now);
			ans.erase(copB);
		}else if(_set.count(copA) == 1 && isSignal[now] == 1 && isSignal[copA] == 1 ){
			ans.erase(now);
			ans.erase(copA);
		}
		it++;
	}
	int ind = 0 ;
	cout<<ans.size()<<endl;
	it= ans.begin();
	while(it!=ans.end() ){
		printf("%05d",*it);
		if(ind != ans.size()-1){
			cout<<" ";
		}
		it++;
		ind++;
	}
	return 0;
}