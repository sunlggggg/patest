#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
struct A{
	A(){
		pc = 0 ;
		t = 0 ;
		isout = false;
		//r = -1;
		memset(pr,-1,sizeof(pr));
	}
	int t;
	//int r;
	int id;
	int pc ;
	int pr[10];
	int isout ;
};
int ps[10];
//map<int ,A> m;
A as[10100];
bool cmp(A a, A b){
	if(a.isout != b.isout ) return a.isout > b.isout;
	else if(a.t != b.t ) return a.t > b.t;
	else if(a.pc != b.pc ) return a.pc > b.pc ; 
	else return a.id < b.id ; 
}
int main(){
	int n,c,m; 
	scanf("%d%d%d",&n,&c,&m);
	for(int i = 1 ; i<= c ; i++){
		scanf("%d",&ps[i]);
	}
	for(int i = 0 ; i< m;i++){
		int id, pid, s;
		scanf("%d%d%d",&id,&pid,&s);
		as[id].id = id;
		if(s>= 0) as[id].isout = true;
		if(s == -1&& as[id].pr[pid]<= 0  ){
			as[id].pr[pid] = 0; 
		}
		else if(s > as[id].pr[pid] ){//update t ps
			if(as[id].pr[pid] > 0 )
				as[id].t += s - as[id].pr[pid];
			else 
				as[id].t += s ;
			if(s == ps[pid]  )
				as[id].pc++;
			as[id].pr[pid] = s; 
		}
	}
	stable_sort(as+1,as+n+1,cmp);
	int ls_r = 1; //第一个人的名次
	for(int i = 1 ; i<= n; i++){
		if(as[i].isout){
			if(i != 1 && (as[i].t < as[i - 1].t )  ) {
				printf("%d %05d %d ", i,as[i].id,as[i].t);
				ls_r = i;
			}
			else { //i= 0 输出第一个人的名次 否则当同分时输出
				printf("%d %05d %d ", ls_r ,as[i].id,as[i].t);
			}
			for(int k = 1 ; k <= c ; k++){
				if(as[i].pr[k] == -1) printf("-");
				else printf("%d", as[i].pr[k]);
				if(k != c) printf(" ");
			}
			printf("\n");
		}
	}
	return 0 ;
}
/*

2 2 11
20 25 
00001 2 12
00001 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00002 2 25


2 2 4
10 10 
00001 1 5
00001 2 5
00002 1 0
00002 1 10
10002 1 10
10001 1 10
10001 1 10
10002 1 10
10002 1 10
10003 1 9
4 3 8 
20 30 40 
00001 1 15
00001 3 20 
00002 2 0 
00002 3 0
00003 1 20 
00003 2 15 
00004 1 -1
00004 3 
*/