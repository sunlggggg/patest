//不输出无效用户
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
struct A{
	char n[30];
	int mon,d,h,m;
	int on_l;
};
struct P{
	P(){
		amount = 0 ;
	}
	char n[30];
	vector<pair<A , A>> as;//record 
	vector<pair<int , double> > timeAndMoney;
	double amount ; 
};
bool cmpT(A a, A b){
	if(strcmp(a.n,b.n) != 0 ) return strcmp(a.n,b.n) < 0  ;
	else if(a.d !=b.d) return a.d<b.d;
	else if(a.h != b.h) return a.h<b.h;
	else return a.m<b.m;
}
int p[24];
pair<int,int> cAmu(int h1, int m1, int h2 ,int m2 ){
	pair<int , int > rt;
	int t = 0 ;
	int amu = 0 ; 
	if(h1 == h2){
		amu += (m2-m1)*p[h1];
		t += m2-m1;
	}
	else {
		//处理第一个小时
		amu += p[h1]*(60 - m1);
		t += 60 - m1;
		for(int i = h1+1; i < h2 ;i++ ){
			amu+=60*p[i];
			t += 60 ;
		}
		//
		t += m2;
		amu += p[h2]* m2;
	}
	rt.first = t;
	rt.second = amu;
	return rt;
}
pair<int,int> cAmuDay(int d1, int h1, int m1, int d2 , int h2 ,int m2){
	pair<int , int > rt;
	int amu = 0 ;
	int t = 0 ; 
	if(d1 == d2 ){
		rt = cAmu( h1,  m1,  h2 , m2 );
	}else {
		rt = cAmu( h1,  m1, 23, 60 );
		int damu = 0 ;
		
		for(int i = 0 ; i< 24 ;i++){
			damu += p[i]*60;
		}
		rt.second+= damu*(d2-d1-1); 
		rt.first += 60*24*(d2-d1-1); ;
		pair<int , int > rtt = cAmu( 0,  0, h2, m2 );
		rt.first += rtt.first;
		rt.second += rtt.second;
	}
	return rt ;
}


vector<A> v;
int main(){
	ios::sync_with_stdio(true);
	for(int i = 0 ; i<24;i++)
		cin>>p[i];
	int n ;
	cin >> n ; 
	while(n--)	{
		A a;
		char on_l[30];
		scanf("%s%d:%d:%d:%d%s",&a.n, &a.mon,&a.d,&a.h,&a.m,&on_l);
		a.on_l = (strcmp(on_l,"on-line") == 0 ?1:0);
		v.push_back(a);
	} 
	sort(v.begin(),v.end(),cmpT);
	//case 1
	if(v.size() < 2 ){
		return 0 ; 
	}
	vector<P> ps;
	for(int i = 1 ; i< v.size();i++){
		if(strcmp(v[i].n,v[i - 1].n) == 0 ){//同个人 
			if(!v[i].on_l  && v[i-1].on_l ){//pair
					//printf("%s %02d\n",v[i].n, v[i].mon );				
				pair<int,int> rt = cAmuDay(v[i-1].d,v[i-1].h,v[i-1].m,v[i].d,v[i].h,v[i].m);
				if(ps.size() > 0 && strcmp(ps[ps.size() - 1].n,v[i].n ) == 0){ 
					ps[ps.size() - 1].as.push_back(make_pair(v[i-1],v[i]));
					ps[ps.size() - 1].amount += rt.second;
				}else {
					P p;
					p.amount += rt.second;
					p.as.push_back(make_pair(v[i-1],v[i]));
					strcpy(p.n, v[i].n);
					ps.push_back(p);
				}
				ps[ps.size() - 1].timeAndMoney.push_back(make_pair(rt.first,rt.second));
			}
		} 
	}

	for(int i = 0 ; i < ps.size(); i++ ){
		printf("%s %02d\n",ps[i].n, ps[i].as[0].first.mon );    
		for(int k = 0; k < ps[i].as.size(); k ++ ){
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
				ps[i].as[k].first.d,ps[i].as[k].first.h,ps[i].as[k].first.m,
				ps[i].as[k].second.d,ps[i].as[k].second.h,ps[i].as[k].second.m,
				ps[i].timeAndMoney[k].first,
          ps[i].timeAndMoney[k].second/100.0);
		}
		printf("Total amount: $%.2f\n", ps[i].amount/100.0);
	}
	return 0;
}



/**
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
8
CYLL 01:01:06:01 off-line
CYLL 01:01:06:05 off-line
CYJJ 01:01:07:00 on-line
CYJJ 01:01:08:00 off-line
CYFF 01:01:05:59 on-line
CYFF 01:01:05:59 off-line
aaa 01:01:00:00 on-line
aaa 01:02:00:00 on-line


*/