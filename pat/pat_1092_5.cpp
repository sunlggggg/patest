#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
	//while(1)
	{
	string have,need;
	cin>>have>>need;
	map<char,int> hav;
	map<char,int> miss;
	map<char,int>::iterator it;
	for(int i = 0 ; i < have.size();i++){
		if(hav.count(have[i]) == 0 )
			hav[have[i]] = 1;
		else 
			hav[have[i]] ++ ;
	}
	for(int i = 0 ; i < need.size();i++){
		it = hav.find(need[i]);
		if(it == hav.end() || it->second == 0  ) {
			if(miss.count(need[i]) == 0 ){
				miss[need[i]] = 1;
			}else {
				miss[need[i]]++;
			}
		}
		else 
			it->second --;
	}
	if(miss.size() == 0) {
		cout<<"Yes" << " " << have.size() - need.size()<<endl;
	}else {
		int c = 0 ;
		it = miss.begin();
		while(it!=miss.end()){
			c+=it++->second;
		}
		cout<<"No"<<" " << c <<endl;
	}
	}
	return 0;
}