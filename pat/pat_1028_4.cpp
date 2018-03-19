#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct A{
	int c1;
	char c2[9];
	int c3;
};
vector<A> v;
bool cmpC1(A a, A b) {
	return a.c1<b.c1;
}
bool cmpC2(A a, A b) {
	int c = strcmp(a.c2,b.c2) ;
	if(c!= 0 ) return  c < 0;
	else return a.c1 <b.c1 ;
}
bool cmpC3(A a, A b) {
	if(a.c3 != b.c3) return a.c3<b.c3;
	else return a.c1 <b.c1 ;
}
int main(){
	int n,c;
	scanf("%d%d", &n ,&c);
	int t = n ;
	while(t--){
		A a;
		scanf("%d%s%d", &a.c1 ,&a.c2 ,& a.c3);
		v.push_back(a);
	}
	switch(c){
	case 1:sort(&v[0],&v[0]+n,cmpC1);break;
	case 2:sort(&v[0],&v[0]+n,cmpC2);break;
	case 3:sort(&v[0],&v[0]+n,cmpC3);break;
	}
	for(int i = 0 ; i< n;i++){
		printf("%06d %s %d\n",v[i].c1,v[i].c2 , v[i].c3 );
	}
}
