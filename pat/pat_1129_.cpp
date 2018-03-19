#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int MAXN = 50010;
int n,k;
int num[MAXN];
vector<int> _rank;
bool cmp(int a, int b){
	if(num[a] != num[b])
		return num[a] > num[b];
	else 
		return a < b;
}
bool isExisted(int now){
	for(int i= 0 ; i < _rank.size();i++){
		if(_rank[i] == now){
			return true;
		}
	}
	return false;
}
int main(){
#ifdef _DEBUG
	freopen("data.txt","r",stdin);
#endif
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= n ; i++){
		int now;
		scanf("%d",&now);
		if(_rank.size()>0){
			printf("%d:",now);
			for(int j = 0 ; j < _rank.size() ; j++){
				printf(" %d",_rank[j]);
			}
			printf("\n");
		}
		num[now]++;
		//ÅÐ¶ÏÊÇ·ñ´æÔÚ
		if(!isExisted(now)){
			_rank.push_back(now);
		}
		sort(_rank.begin(),_rank.end(),cmp);
		if(_rank.size()>k)
			_rank.pop_back();
	}
	return 0;
}