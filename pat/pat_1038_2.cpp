#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(string a, string b){
	return a+b < b+a;
}

bool cmp2(string a,string b){
	int a_length=a.size();
	int b_length=b.size();
	int i=0,j=0;
	while(1){
		if(a[i]!=b[j])
			return a[i]<b[j];
		else{
			++i;
			++j;
			if(i==a_length&&j == b_length )
				return false;
			if(i==a_length&&j<b_length){
				i=0;
			}
			else if(i<a_length&&j==b_length){
				j=0;
			}
		}
	}
}

int main() {
	int n;
	string as[10010];
	cin >> n;
	for(int i = 0; i < n ;i++){
		cin>>as[i] ;
	}
	sort(as,as+n,cmp2);
	for(int i = 1 ; i < n ;i++ ){
		as[0].append(as[i]);
	}
	while(as[0].size()>0 && as[0][0] == '0'){
		as[0].erase(as[0].begin());
	}
	if(as[0].size() == 0 )cout<<0<<endl;
	else cout<<as[0]<<endl;
	return 0;
}