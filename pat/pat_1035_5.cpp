#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

struct A{
	A(bool ism){isM = ism;};
	string a,b ;
	bool isM ;
};
int c_m = 0;

int main(){
	while(1)
	{
	map<char,char> m_;
	map<char,char>::iterator it_m;
	ios::sync_with_stdio(false);
	m_.insert(make_pair('1','@'));
	m_.insert(make_pair('l','L'));
	m_.insert(make_pair('0','%'));
	m_.insert(make_pair('O','o'));
	int m ;
	vector<A> v;
	cin>>m;
	int t = m;
	while(m--){
		A a(false) ;
		cin>>a.a >>a.b;
		//1 (one) by @, 0 (zero) by %, l by L, and O by o.
		for(int i = 0 ; i< a.b.length();i++){
			if((it_m = m_.find(a.b[i]))!=m_.end()){
				a.b[i] =it_m->second;
				a.isM = true;
			}
		}
		if(a.isM)
			v.push_back(a);
	}
	
	if(v.size()){

		cout<<v.size()<<endl;
		for(int i = 0 ; i <v.size();i++){
			cout<<v[i].a <<" "<<v[i].b<<endl;
		}
	}else{
		if(t<=1)
			printf("There is %d account and no account is modified", t);
		else {
			printf("There are %d accounts and no account is modified", t);
		}
	}
	}
	return 0;

}