#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct A{
	string n;
	int c , m, e, a;
	int cr,mr,er,ar;
};
bool cmpC(const A  &a ,const A  &b){
	return a.c > b.c;
}
bool cmpM(const A  &a , const A  &b){
	return a.m > b.m;
}
bool cmpE(const A  &a ,const  A  &b){
	return a.e > b.e;
}
bool cmpA(const A  &a , const A  &b){
	return a.a > b.a;
}
vector<A>::iterator f_if(vector<A> &v,string n){
	vector<A>::iterator vt = v.begin();
	while(vt!=v.end()){
		if(vt->n == n){
			break;
		}
		vt++;
	}
	return vt;
}
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<A> v;
	vector<A>::iterator vt;
	vector<A>::iterator vt_pre;
	while(n--){
		A a; 
		cin >>a.n>>a.c>>a.m>>a.e;
		a.a = a.c+a.m+a.e;
		v.push_back(a);
	}
	vt = v.begin();

	//sort
	stable_sort(v.begin(),v.end(),cmpC);
	vt = v.begin();
	int r = 1;
	int rk = 1;
	int last_s = -1;
	while(vt!=v.end()){
		if(last_s == vt->c) {
			(vt++)->cr = rk ;
			r++;
		}
		else {
			rk = r;
			last_s = vt->c;
			(vt++)->cr = r++;
		}
	}
	stable_sort(v.begin(),v.end(),cmpM);
	vt = v.begin();
	r =1;
	rk = 1;
	last_s = -1;
	while(vt!=v.end()){
		if(last_s == vt->m) {
			(vt++)->mr = rk ;
			r++;
		}
		else {
			rk = r;
			last_s = vt->m;
			(vt++)->mr = r++;
		}
	}
	stable_sort(v.begin(),v.end(),cmpE);
	vt = v.begin();
	r =1;
	rk = 1;
	last_s = -1;
	while(vt!=v.end()){
		if(last_s == vt->e) {
			(vt++)->er = rk;
			r++;
		}
		else {
			rk = r;
			last_s = vt->e;
			(vt++)->er = r++;
		}
	}

	stable_sort(v.begin(),v.end(),cmpA);
	vt = v.begin();
	r =1;
	rk = 1;
	last_s = -1;
	while(vt!=v.end()){
		if(last_s == vt->a) {
			(vt++)->ar = rk;
			r++;
		}
		else {
			rk = 1;
			last_s = vt->a;
			(vt++)->ar = r++;
		}
	}
	while(m--){
		string n ;
		cin >> n ; 
		if((vt =  f_if(v,n)) != v.end()){
			//找到最大的
			A a = *vt;
			//A>C>M>E
			if(a.ar<= a.cr&&a.ar<=a.mr&&a.ar<=a.er){
				cout<<a.ar<<" A"<<endl;
			}else if(a.cr<= a.mr&&a.cr<=a.er){
				cout<<a.cr<<" C"<<endl;
			}else if(a.mr<= a.er){
				cout<<a.mr<<" M"<<endl;
			}else{
				cout<<a.er<<" E"<<endl;
			}
		}else 
			cout<<"N/A"<<endl;
	}
	return 0;
}
