#include<iostream>
#include<string>
#include<set>
using namespace std;
int main(){
	int n;
	set<int> _set;
	set<int>::iterator it;
	cin>>n;
	while(n--){
		string num;
		cin>>num;
		int sum = 0 ;
		for(int i = 0 ; i < num.length(); i++){
			sum+= int(num[i] - '0');
		}
		_set.insert(sum);
	}
	cout<<_set.size()<<endl;
	it = _set.begin();
	int ind = 0 ;
	while(it!=_set.end() ){
		cout<<*it;
		if(ind != _set.size()-1){
			cout<<" ";
		}
		it++;
		ind++;
	}
	return 0;
}