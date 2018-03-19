#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;
struct A{
	char n[9];
	int a,w;
};
//vector<A> v;
A as[100010];
bool cmp(A a, A b){
	if(a.w != b.w ) return a.w> b.w;
	else if(a.a != b.a ) return a.a < b.a;
	else return strcmp(a.n,b.n) < 0 ;
}
int main(){
	int n = 0 ,c = 0;
	scanf("%d%d",&n,&c);
	for(int i = 0 ;i<n;i++){
		A a ;
		scanf("%s%d%d",&a.n,&a.a,&a.w);
		//v.push_back(a);
		as[i] = a;
	}
	//sort(v.begin(),v.end(),cmp);
	sort(as,as+n,cmp);
	for(int i = 0 ; i < c;i++){
		int r , l, h; 
		scanf("%d%d%d",&r,&l,&h);
		printf("Case #%d:\n",i+1);
		int count = 0 ;
		for(int k = 0 ; k < n ;k ++){
			if(count< r&&as[k].a <= h && as[k].a >= l) {
				count++;
				printf("%s %d %d\n",as[k].n, as[k].a, as[k].w);
			}
		}
		if(!count)
			printf("None\n");
	}
	return 0;
}
