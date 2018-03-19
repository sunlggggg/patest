#include<iostream>
#include<map>
#include<set>
#include<cmath>
using namespace std;
int n;
map<int , int> _map;
set<int> _set;
bool isPrime(int num){
	if(num == 2)
		return true;
	for(int i = 2; i < (int)sqrt(1.0*num) +2;i++){
		if(num%i == 0 ){
			return false;
		}
	}
	return true;
}
int main(){
#ifdef _DEBUG
	freopen("data.txt","r",stdin);
#endif
	cin>>n;
	int num;
	for(int i =1 ; i<= n; i++){
		cin>>num;
		_map.insert(make_pair(num,i));
	}
	int t;
	cin>>t;
	while(t--){
		cin>>num;
		printf("%04d",num);
		cout<<": ";
		if(_map.count(num) == 0 ){
			cout<<"Are you kidding?"<<endl;
		}else if(_set.count(num) == 1){
			cout<<"Checked"<<endl;
		}else if(_map.find(num)->second == 1){
			cout<<"Mystery Award"<<endl;
		}else if(isPrime(_map.find(num)->second) ){
			cout<<"Minion"<<endl;
		}else{
			cout<<"Chocolate"<<endl;
		}
		_set.insert(num);
	}
	return 0;
}