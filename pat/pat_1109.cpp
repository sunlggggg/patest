#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct A{
	string s;
	int h;
};
bool cmp1(A a, A b){
	if(a.h != b.h ){
		return a.h > b.h;
	}else{
		return a.s.compare(b.s)  < 0 ;
	}
}
//bool cmp2(A a, A b){
//	if(a.h != b.h ){
//		return a.h < b.h;
//	}else{
//		return a.s.compare(b.s)  < 0 ;
//	}
//}

int main(){
	int n,k;
	vector<A> v;
	cin>>n>>k;
	for(int i = 0 ; i< n; i++){
		A a;
		cin>>a.s>>a.h;
		v.push_back(a);
	}
	sort(v.begin(),v.end(),cmp1);
	int eve = int(n/k);
	int last = n - eve*(k-1);
	for(int i = 0 ; i < k ; i++){
		if(i == 0 ){
		//	sort(v.begin(),v.begin() + last,cmp2);
			vector<A> ans;
			int cnt = 0 ;
			for(int j = 0  ; j < last ; j++){
				if(cnt % 2 == 0 ){
					ans.push_back(v[j]);
				}else{
					ans.insert(ans.begin(),v[j]);
				}
				cnt++;
			}

			for(int m = 0; m < ans.size() ; m++){
				cout<<ans[m].s;
				if(m!= ans.size() -1 ){
					cout<<" ";
				}else{
					cout<<endl;
				}
			}

		}else{
		//	sort(v.begin()+last+(i-1)*eve,v.begin() + last+i*eve,cmp2);
			vector<A> ans;
			int cnt = 0 ;
			for(int j = last+(i-1)*eve  ; j < last+i*eve  ; j++){
				if(cnt % 2 == 0 ){
					ans.push_back(v[j]);
				}else{
					ans.insert(ans.begin(),v[j]);
				}
				cnt++;
			}

			for(int m = 0; m < ans.size() ; m++){
				cout<<ans[m].s;
				if(m!= ans.size() -1 ){
					cout<<" ";
				}else{
					cout<<endl;
				}
			}
		}
	}
	return 0;
}
/**
10 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159
**/