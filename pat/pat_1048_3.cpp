#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	vector<int> v;
	vector<int>::iterator ite;
	int a, s;
	cin>>a>>s;
	while(a--){
		int a; 
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	//找到比一半大 比一半小的两个数
	ite = v.begin();
	while(ite != v.end()){
		if(*ite> s/2+1){
			cout<<"No Solution";
			return 0;
		}else
		{
			if(binary_search(ite+1,v.end(),s-*ite)){
				cout<<*ite<<" " <<s-*ite;
				return 0;
			}
		}
		ite++;
	}
	cout<<"No Solution";
	return 0 ; 
}
