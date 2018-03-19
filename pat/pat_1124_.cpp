#include<iostream>
#include<string>
#include<set>
using namespace std;
int main(){
#ifdef _DEBUG
	string _str;
	cin>>_str;
	freopen(_str.c_str(),"r",stdin);
#endif
	int n, k , s;
	cin>>n>>k>>s;
	set<string> _set;
	string str;
	for(int i = 1; i< s; i++){
		cin>>str;
	}
	bool f = false;
	for(int i = s ; i <= n ; ){
		cin>>str;
		if(_set.count(str) == 0){
			cout<<str<<endl;
			f = true;
			i+=k;
			int tmp = k -1;
			string _tmps;
			while(tmp--){
				cin>>_tmps;
			}
		}else{
			i++;
		}
		_set.insert(str);
	}
	if(!f){
		cout<<"Keep going..."<<endl;
	}
	return 0;
}