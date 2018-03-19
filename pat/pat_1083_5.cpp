#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct A{
	char n[11];
	char c[11];
	int g;
};
bool cmp(A a, A b){
	return a.g > b.g ;
}
vector<A> v;
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0 ; i< n ; i++){
		A  a; 
		scanf("%s %s %d", a.n, a.c,&a.g);
		v.push_back(a);
	}
	stable_sort(v.begin(),v.end(),cmp);
	int L, H ; 
	scanf("%d%d",&L,&H);
	bool f = false ;
	for(int i = 0 ; i< v.size();i++){
		if(v[i].g > H )	continue;
		else if(v[i].g < L) break;
		else {
			printf("%s %s\n", v[i].n ,v[i].c);
			f = true;
		}
	}
	if(!f)
		printf("NONE\n");
}