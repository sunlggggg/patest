#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct A{
	int id;
	int g1,g2;
	int scs[6] ;
};
struct S{
	S(){
		cc = 0 ;
	}
	int id; 
	A last;
	int cc;
	int as[35000];
	int pe; 
};
A as[40010];
S ss[110];
bool cmpA(A a, A b){
	if(a.g1 + a.g2 != b.g1 + b.g2) return a.g1 + a.g2 > b.g1 + b.g2;
	else return a.g1 > b.g1;
}
bool cmpID(int a, int b){
	return a < b;
}
int main(){
	int n1; //0to n-1
	int n2; 
	int n3;
	scanf("%d%d%d",&n1,&n2,&n3);
	for(int i = 0 ; i< n2; i++){
		S s;
		s.id = i ;
		scanf("%d",&s.pe);
		ss[i] = s; 
	}
	for(int i = 0 ; i< n1; i++){
		A a; 
		a.id = i; 
		scanf("%d%d",&a.g1,&a.g2);
		for(int k = 0 ; k < n3;k++){
			int t;
			scanf("%d",&t);
			a.scs[k] = t;
		}
		as[i] = a;
	}
	//ccc
	sort(as ,as+n1,cmpA);
	for(int i = 0 ; i< n1 ;i++){
		A a = as[i];
		for(int k = 0 ; k < n3 ; k++){
			if(ss[a.scs[k]].pe > ss[a.scs[k]].cc ){ //有配额
				ss[a.scs[k]].as[ss[a.scs[k]].cc++] = a.id; // 加入到该学校
				ss[a.scs[k]].last = a; 
				break;
			}
			else if(ss[a.scs[k]].last.g1 == a.g1 && ss[a.scs[k]].last.g2 == a.g2 ){//完全相同
				ss[a.scs[k]].as[ss[a.scs[k]].cc++] = a.id;
				break;
			}
		}
	}
	//out
	for(int i = 0 ; i< n2 ;i++){
		if(ss[i].cc){
			sort(ss[i].as ,ss[i].as+ss[i].cc,cmpID);
			for(int k = 0 ; k< ss[i].cc ;k++){
				printf("%d", ss[i].as[k] );
				if(k!=  ss[i].cc-1 )
					printf(" ");
			}
		}
		printf("\n");
	}
	return 0 ;
}
/**
11 6 3
2 1 2 2 2 3
100 100 0 1 2
60 60 2 3 5
100 90 0 3 4
90 100 1 2 0
90 90 5 1 3
80 90 1 0 2
80 80 0 1 2
80 80 0 1 2
80 70 1 3 2
70 80 1 2 3
100 100 0 2 4
*/